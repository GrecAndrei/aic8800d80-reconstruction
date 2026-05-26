#!/usr/bin/env python3
"""Run queue-driven smoke probes and record outcomes for dynamic learning.

This utility is intentionally generic:
- reads mining queue JSONL
- skips already checkpointed functions from README
- probes top targets with unicorn_smoke.py
- appends machine-readable outcomes for pipeline ingestion
"""

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from collections import Counter, defaultdict
from datetime import datetime, timezone
from pathlib import Path
from typing import Optional

DEF_RE = re.compile(r"^\s*(?:[A-Za-z_][A-Za-z0-9_\s\*]+)\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*\)\s*\{")


def normalize_addr(value: str) -> str:
    raw = (value or "").strip().lower()
    if not raw:
        return ""
    if raw.startswith("0x"):
        try:
            return hex(int(raw, 16))
        except ValueError:
            return ""
    try:
        return hex(int(raw, 0))
    except ValueError:
        return ""


def identity_key(name: str, image: str = "", address: str = "") -> str:
    n = (name or "").strip().lower()
    if not n:
        return ""
    img = (image or "").strip().lower()
    addr = normalize_addr(address)
    if img or addr:
        return f"id|{img}|{addr}|{n}"
    return f"name|{n}"


def normalize_token(value: str) -> str:
    return re.sub(r"[^a-z0-9]+", "_", (value or "").strip().lower()).strip("_")


def load_contract_hints(path: Path) -> dict[str, list[str]]:
    if not path.is_file():
        return {}
    try:
        rows = json.loads(path.read_text(encoding="utf-8", errors="ignore"))
    except json.JSONDecodeError:
        return {}
    if not isinstance(rows, list):
        return {}
    out: dict[str, list[str]] = {}
    for row in rows:
        if not isinstance(row, dict):
            continue
        fn = str(row.get("function", "")).strip()
        image = str(row.get("image", "")).strip()
        address = str(row.get("address", "")).strip()
        seeds = row.get("seed_hints", [])
        if not isinstance(seeds, list):
            continue
        normalized = []
        for s in seeds:
            text = str(s).strip()
            if not text or "=" not in text:
                continue
            normalized.append(text)
        if not normalized:
            continue
        ik = identity_key(fn, image, address)
        nk = identity_key(fn)
        if ik:
            out[ik] = normalized
        if nk and nk not in out:
            out[nk] = normalized
    return out


def load_queue_records(path: Path) -> list[dict]:
    rows: list[dict] = []
    seen: set[str] = set()
    for line in path.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError:
            continue
        name = str(row.get("name", "")).strip()
        image = str(row.get("image", "")).strip()
        address = str(row.get("address", "")).strip()
        key = identity_key(name, image, address)
        if not key or key in seen:
            continue
        seen.add(key)
        rows.append(row)
    return rows


def load_checkpointed(readme: Path) -> set[str]:
    text = readme.read_text(encoding="utf-8", errors="ignore")
    return {n.lower() for n in re.findall(r"`([A-Za-z0-9_]+)`", text)}


def parse_iso_time(s: str) -> datetime | None:
    s = (s or "").strip()
    if not s:
        return None
    if s.endswith("Z"):
        s = s[:-1] + "+00:00"
    try:
        dt = datetime.fromisoformat(s)
    except ValueError:
        return None
    if dt.tzinfo is None:
        dt = dt.replace(tzinfo=timezone.utc)
    return dt.astimezone(timezone.utc)


def load_outcome_stats(path: Path, min_success_insns: int) -> tuple[dict[str, dict[str, int]], dict[str, list[tuple[str, int]]], dict[str, datetime]]:
    stats: dict[str, dict[str, int]] = defaultdict(
        lambda: {
            "attempts": 0,
            "returned": 0,
            "capped": 0,
            "fault": 0,
            "missing_symbol": 0,
            "shallow_return": 0,
            "evidence_score_total": 0,
        }
    )
    fault_by_prefix: dict[str, Counter[str]] = defaultdict(Counter)
    last_seen: dict[str, datetime] = {}
    if not path.is_file():
        return stats, {}, last_seen
    for line in path.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError:
            continue
        fn = str(row.get("function", "")).strip()
        if not fn:
            continue
        st = str(row.get("status", "")).strip().lower()
        if st == "success":
            st = "returned"
        image = str(row.get("image", "")).strip()
        address = str(row.get("address", "")).strip()
        k = identity_key(fn, image, address)
        if not k:
            continue
        stats[k]["attempts"] += 1
        by_name = identity_key(fn)
        if by_name and by_name != k:
            stats[by_name]["attempts"] += 1
        dt = parse_iso_time(str(row.get("generated_at", "")))
        if dt is not None:
            prev = last_seen.get(k)
            if prev is None or dt > prev:
                last_seen[k] = dt
            if by_name:
                prev_name = last_seen.get(by_name)
                if prev_name is None or dt > prev_name:
                    last_seen[by_name] = dt
        if st in stats[k]:
            stats[k][st] += 1
            if by_name and by_name != k:
                stats[by_name][st] += 1
        evidence_score = 0
        mmio = int(row.get("mmio_read_count", 0) or 0) + int(row.get("mmio_write_count", 0) or 0)
        helper = int(row.get("helper_touch_count", 0) or 0)
        branch = int(row.get("branch_depth_max", 0) or 0)
        evidence_score += min(max(mmio, 0), 16)
        evidence_score += min(max(helper, 0), 8) * 2
        evidence_score += min(max(branch, 0), 6) * 2
        if st == "returned":
            evidence_score += 6
        elif st == "capped":
            evidence_score += 2
        stats[k]["evidence_score_total"] += evidence_score
        if by_name and by_name != k:
            stats[by_name]["evidence_score_total"] += evidence_score
        if st == "returned":
            try:
                insns = int(row.get("instructions", -1))
            except (TypeError, ValueError):
                insns = -1
            if 0 <= insns < max(0, min_success_insns):
                stats[k]["shallow_return"] += 1
                if by_name and by_name != k:
                    stats[by_name]["shallow_return"] += 1
        if st == "fault":
            addr = str(row.get("fault_address", "")).strip().lower()
            if addr.startswith("0x"):
                fault_by_prefix[prefix(fn)][addr] += 1
    top_faults = {
        p: sorted(counter.items(), key=lambda kv: (-kv[1], kv[0]))[:3]
        for p, counter in fault_by_prefix.items()
        if counter
    }
    return stats, top_faults, last_seen


def index_functions(sources: list[Path]) -> tuple[dict[str, Path], dict[str, str], dict[str, set[str]]]:
    out: dict[str, Path] = {}
    canon: dict[str, str] = {}
    by_source: dict[str, set[str]] = {}
    for src in sources:
        if not src.is_file():
            continue
        src_key = str(src.resolve())
        names = by_source.setdefault(src_key, set())
        for line in src.read_text(encoding="utf-8", errors="ignore").splitlines():
            m = DEF_RE.match(line)
            if not m:
                continue
            name = m.group(1)
            out.setdefault(name, src)
            lower = name.lower()
            canon.setdefault(lower, name)
            names.add(lower)
    return out, canon, by_source


def pick_source_for_target(resolved_fn: str, image: str, fn_index: dict[str, Path], by_source: dict[str, set[str]], default: Path) -> Path:
    fn_lower = resolved_fn.lower()
    image_token = normalize_token(image)
    image_candidates: list[Path] = []
    if image_token:
        for src_key, fn_names in by_source.items():
            src_name = Path(src_key).name
            if image_token not in normalize_token(src_name):
                continue
            src_path = Path(src_key)
            image_candidates.append(src_path)
            if fn_lower not in fn_names:
                continue
            return src_path
    if image_candidates:
        # Keep image identity strict: if the function is missing in this image,
        # return the image-specific source anyway so smoke reports missing symbols
        # instead of silently probing a different image's implementation.
        return image_candidates[0]
    return fn_index.get(resolved_fn, default)


def compute_frontier_score(row: dict) -> float:
    attempts = int(row.get("attempts", 0))
    priority = float(row.get("priority", 0.0))
    returned = int(row.get("returned", 0))
    capped = int(row.get("capped", 0))
    fault = int(row.get("fault", 0))
    missing = int(row.get("missing_symbol", 0))
    shallow = int(row.get("shallow_return", 0))
    evidence_total = int(row.get("evidence_score_total", 0))
    evidence_avg = float(evidence_total) / float(max(1, attempts))

    score = 0.0
    score += priority
    if attempts == 0:
        score += 1.0
    score += min(fault, 4) * 0.6
    score -= min(missing, 4) * 0.7
    score -= min(capped, 4) * 0.35
    score -= min(shallow, 4) * 0.3
    if returned == 0:
        score += 0.8
    score += min(evidence_avg, 10.0) * 0.12
    score -= min(attempts, 10) * 0.08
    bc = row.get("behavior_class")
    if isinstance(bc, dict):
        boost = float(bc.get("priority_boost", 1.0))
        conf = float(bc.get("confidence", 0.0))
        score *= max(0.3, boost)
        score += conf * 0.5
    return score


def prefix(name: str) -> str:
    n = name.strip().lower()
    if "_" in n:
        return n.split("_", 1)[0]
    return n


def parse_seed(seed: str) -> tuple[str, str]:
    if "=" not in seed:
        raise ValueError(f"invalid seed {seed!r}, expected ADDR=VALUE")
    a, v = seed.split("=", 1)
    return a.strip(), v.strip()


def extract_json_objects(text: str) -> list[dict]:
    out: list[dict] = []
    dec = json.JSONDecoder()
    i = 0
    n = len(text)
    while i < n:
        j = text.find("{", i)
        if j < 0:
            break
        try:
            obj, k = dec.raw_decode(text, j)
        except json.JSONDecodeError:
            i = j + 1
            continue
        if isinstance(obj, dict):
            out.append(obj)
        i = k
    return out


def extract_return_insns(rows: list[dict]) -> int:
    for row in rows:
        status_value = str(row.get("status", "")).strip().lower()
        if status_value not in {"returned", "success"}:
            continue
        try:
            return int(row.get("instructions", -1))
        except (TypeError, ValueError):
            return -1
    return -1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--source", type=Path, required=True, help="Primary recovered C source path")
    ap.add_argument(
        "--source-glob",
        action="append",
        default=[],
        help="Extra glob(s) for source pool selection (repeatable), e.g. 'extraction_out/reconstruction/mega7/**/*.c'",
    )
    ap.add_argument("--queue", type=Path, required=True, help="mining_queue_top300.jsonl or similar")
    ap.add_argument("--outcomes", type=Path, required=True, help="smoke_observations.jsonl path")
    ap.add_argument("--contract-hints", type=Path, default=Path("extraction_out/reconstruction/mega7/synth/implsynth_contract_hints.json"), help="Optional implsynth contract hints JSON")
    ap.add_argument("--readme", type=Path, default=Path("README.md"), help="README to mine known checkpoints")
    ap.add_argument("--limit", type=int, default=12, help="maximum functions to probe")
    ap.add_argument("--max-insns", type=int, default=120, help="instruction cap per probe")
    ap.add_argument("--min-success-insns", type=int, default=8, help="treat success below this instruction count as shallow")
    ap.add_argument("--shallow-cooldown", type=int, default=3, help="skip targets with this many shallow successes")
    ap.add_argument("--retry-shallow-success", action="store_true", help="retry shallow successes once with a larger instruction cap")
    ap.add_argument("--shallow-retry-max-insns", type=int, default=512, help="instruction cap for shallow-success retry")
    ap.add_argument("--retry-capped-once", dest="retry_capped_once", action="store_true", help="retry capped probes once with a larger instruction cap")
    ap.add_argument("--no-retry-capped-once", dest="retry_capped_once", action="store_false", help="disable capped probe retry")
    ap.add_argument("--capped-retry-max-insns", type=int, default=1024, help="instruction cap for capped probe retry")
    ap.add_argument("--missing-cooldown", type=int, default=3, help="skip targets with this many missing_symbol hits")
    ap.add_argument("--fault-seed-top", type=int, default=2, help="learn up to this many historical fault addresses per prefix as seeds")
    ap.add_argument("--retry-fault-once", action="store_true", help="on fault, retry once with the reported fault address seeded")
    ap.add_argument("--recent-window-min", type=int, default=30, help="skip functions attempted within this many minutes")
    ap.add_argument("--image-balance", dest="image_balance", action="store_true", help="enforce per-image pick balancing")
    ap.add_argument("--no-image-balance", dest="image_balance", action="store_false", help="disable per-image pick balancing")
    ap.add_argument("--image-cap-ratio", type=float, default=0.5, help="max fraction of picks from one image when image balancing is on")
    ap.add_argument("--min-distinct-images", type=int, default=2, help="minimum distinct images preferred in selected targets")
    ap.add_argument("--probe-state-profile", choices=["basic", "rich"], default="rich", help="state profile passed to unicorn_smoke")
    ap.add_argument("--probe-mmio-autopage", dest="probe_mmio_autopage", action="store_true", help="enable MMIO auto-mapping in unicorn_smoke")
    ap.add_argument("--no-probe-mmio-autopage", dest="probe_mmio_autopage", action="store_false", help="disable MMIO auto-mapping in unicorn_smoke")
    ap.add_argument("--probe-mmio-default", default="0", help="default MMIO value used with auto-mapping")
    ap.add_argument("--deep-pass", dest="deep_pass", action="store_true", help="run deeper second-pass probes for promising targets")
    ap.add_argument("--no-deep-pass", dest="deep_pass", action="store_false", help="disable deeper second-pass probes")
    ap.add_argument("--deep-top-k", type=int, default=3, help="max number of promising targets to run in deep pass")
    ap.add_argument("--deep-max-insns", type=int, default=512, help="instruction cap for deep-pass probes")
    ap.add_argument("--deep-on-capped", dest="deep_on_capped", action="store_true", help="always run deep pass for capped targets")
    ap.add_argument("--no-deep-on-capped", dest="deep_on_capped", action="store_false", help="disable deep pass for capped targets")
    ap.add_argument(
        "--seed",
        action="append",
        default=[],
        help="global default seed ADDR=VALUE, repeatable",
    )
    ap.add_argument("--embedder-model", default="", help="Path to GGUF embedding model for behavioral classification")
    ap.set_defaults(image_balance=True)
    ap.set_defaults(probe_mmio_autopage=True)
    ap.set_defaults(deep_pass=True)
    ap.set_defaults(deep_on_capped=True)
    ap.set_defaults(retry_capped_once=True)
    args = ap.parse_args()

    if not args.source.is_file():
        raise SystemExit(f"source not found: {args.source}")
    if not args.queue.is_file():
        raise SystemExit(f"queue not found: {args.queue}")
    if not args.readme.is_file():
        raise SystemExit(f"readme not found: {args.readme}")

    global_seeds = [parse_seed(s) for s in args.seed]
    contract_hints = load_contract_hints(args.contract_hints)
    checkpointed = load_checkpointed(args.readme)
    queue_rows = load_queue_records(args.queue)
    outcomes, top_faults, last_seen = load_outcome_stats(args.outcomes, args.min_success_insns)

    embedder = None
    if args.embedder_model and Path(args.embedder_model).is_file():
        try:
            import importlib.util, os as _os
            _embedder_path = _os.path.join(_os.path.dirname(_os.path.abspath(__file__)), "embedder.py")
            _spec = importlib.util.spec_from_file_location("embedder", _embedder_path)
            _embedder_module = importlib.util.module_from_spec(_spec)
            _spec.loader.exec_module(_embedder_module)
            BehaviorEmbedder = _embedder_module.BehaviorEmbedder

            cache_path = (Path(args.outcomes).parent / "embedder_cache.json") if args.outcomes else Path("extraction_out/reconstruction/mega7/embedder_cache.json")
            embedder = BehaviorEmbedder(args.embedder_model, cache_path)
            # Classify all uncached queue entries upfront for a noticeable speed-up.
            uncached = []
            for row in queue_rows:
                name = str(row.get("name", "")).strip()
                image = str(row.get("image", "")).strip()
                address = str(row.get("address", "")).strip()
                if not name or name.startswith("sub_"):
                    continue
                if embedder.cache.has(name, image, address):
                    continue
                uncached.append({"name": name, "image": image, "address": address, "pseudocode": ""})
            if uncached:
                print(f"classifying {len(uncached)} new functions with embedder...", file=sys.stderr)
                embedder.classify_batch(uncached)
                embedder.save_cache()
                print(f"  cached: {embedder.cache.stats()}", file=sys.stderr)
        except ImportError as e:
            print(f"embedder not available: {e}", file=sys.stderr)
    now = datetime.now(timezone.utc)
    source_pool: list[Path] = [args.source]
    for pattern in args.source_glob:
        source_pool.extend(sorted(Path(".").glob(pattern)))
    # Keep order stable and dedupe.
    seen_src: set[str] = set()
    uniq_pool: list[Path] = []
    for p in source_pool:
        rp = str(p.resolve())
        if rp in seen_src:
            continue
        seen_src.add(rp)
        uniq_pool.append(p)
    fn_index, fn_canon, fn_by_source = index_functions(uniq_pool)

    # Small generic seed hints by prefix. These are intentionally conservative.
    prefix_seeds: dict[str, list[tuple[str, str]]] = {
        "rf": [("0x40010000", "0"), ("0x40000000", "0")],
        "sdio": [("0x40020000", "0"), ("0x40000000", "0")],
        "irq": [("0xe000ed08", "0x20000000"), ("0x40000000", "0")],
        "msg": [("0x40000000", "0")],
        "log": [("0x40000000", "0")],
        "tx": [("0x40000000", "0")],
    }
    # Learn additional seeds from prior unmapped-fault addresses.
    for pfx, rows in top_faults.items():
        learned = []
        for addr, _count in rows[: max(0, args.fault_seed_top)]:
            learned.append((addr, "0"))
        if learned:
            prefix_seeds.setdefault(pfx, [])
            prefix_seeds[pfx].extend(learned)

    queue_name_counts: Counter[str] = Counter()
    for row in queue_rows:
        name = str(row.get("name", "")).strip()
        if name:
            queue_name_counts[name.lower()] += 1

    candidates: list[dict] = []
    for row in queue_rows:
        name = str(row.get("name", "")).strip()
        image = str(row.get("image", "")).strip()
        address = str(row.get("address", "")).strip()
        if name.startswith("sub_"):
            continue
        if name.lower() in checkpointed and queue_name_counts[name.lower()] == 1:
            continue
        id_key = identity_key(name, image, address)
        name_key = identity_key(name)
        stat = outcomes.get(id_key) or outcomes.get(name_key) or {
            "attempts": 0,
            "returned": 0,
            "capped": 0,
            "fault": 0,
            "missing_symbol": 0,
            "shallow_return": 0,
            "evidence_score_total": 0,
        }
        seen_key = id_key if id_key in last_seen else name_key
        candidate = {
            "id_key": id_key,
            "name": name,
            "image": image,
            "address": normalize_addr(address) if address else "",
            "priority": float(row.get("priority_score", 0.0)),
            "attempts": int(stat.get("attempts", 0)),
            "returned": int(stat.get("returned", 0)),
            "capped": int(stat.get("capped", 0)),
            "fault": int(stat.get("fault", 0)),
            "missing_symbol": int(stat.get("missing_symbol", 0)),
            "shallow_return": int(stat.get("shallow_return", 0)),
            "evidence_score_total": int(stat.get("evidence_score_total", 0)),
            "prefix": prefix(name),
            "recent_min": int((now - last_seen[seen_key]).total_seconds() // 60) if seen_key in last_seen else 10**9,
        }
        # Look up behavioral classification if embedder is active.
        behavior_info = None
        if embedder is not None:
            bc = embedder.cache.get_classification(name, image, address)
            if bc:
                behavior_info = {
                    "primary_class": bc.get("primary_class", "unknown"),
                    "priority_boost": bc.get("priority_boost", 1.0),
                    "min_probe_budget": bc.get("min_probe_budget", 1),
                    "synth_role": bc.get("synth_role", "leaf_wrapper"),
                    "confidence": bc.get("confidence", 0.0),
                }
        candidate["behavior_class"] = behavior_info
        candidate["frontier_score"] = compute_frontier_score(candidate)
        candidates.append(candidate)

    # Prefer under-tested, high-priority candidates and avoid immediate repeats.
    candidates.sort(
        key=lambda c: (
            -c["frontier_score"],
            c["recent_min"],
            c["missing_symbol"],
            c["shallow_return"],
            c["name"].lower(),
            c["image"].lower(),
            c["address"],
        )
    )

    # Staged selector:
    #  1) strict cooldown+recency with prefix diversity
    #  2) strict cooldown+recency without prefix diversity
    #  3) strict cooldown with softer recency (half window)
    #  4) strict cooldown with no recency
    #  5) one extra missing-symbol strike with no recency
    picked: list[dict] = []
    picked_set: set[str] = set()

    def pick_stage(missing_max: int, recent_min: int, enforce_prefix_cap: bool, enforce_image_cap: bool) -> None:
        prefix_counts: dict[str, int] = defaultdict(int)
        image_counts: dict[str, int] = defaultdict(int)
        for c in picked:
            prefix_counts[c["prefix"]] += 1
            image_counts[c["image"].lower()] += 1
        image_cap = max(1, int(max(1, args.limit) * max(0.1, min(1.0, args.image_cap_ratio))))
        for c in candidates:
            if len(picked) >= args.limit:
                return
            if c["id_key"] in picked_set:
                continue
            if c["missing_symbol"] >= missing_max:
                continue
            if c["shallow_return"] >= max(0, args.shallow_cooldown):
                continue
            if c["recent_min"] < recent_min:
                continue
            if args.image_balance and enforce_image_cap:
                ik = c["image"].lower()
                if ik and image_counts[ik] >= image_cap:
                    continue
            if enforce_prefix_cap:
                p = c["prefix"]
                if prefix_counts[p] >= max(1, args.limit // 3):
                    continue
                prefix_counts[p] += 1
            picked.append(c)
            picked_set.add(c["id_key"])
            image_counts[c["image"].lower()] += 1

    strict_recent = max(0, args.recent_window_min)
    soft_recent = strict_recent // 2
    pick_stage(args.missing_cooldown, strict_recent, True, True)
    pick_stage(args.missing_cooldown, strict_recent, False, True)
    pick_stage(args.missing_cooldown, soft_recent, False, True)
    pick_stage(args.missing_cooldown, 0, False, True)
    pick_stage(args.missing_cooldown + 1, 0, False, False)

    if args.image_balance and args.min_distinct_images > 1 and picked:
        distinct = {c["image"].lower() for c in picked if c["image"]}
        if len(distinct) < args.min_distinct_images:
            for c in candidates:
                if len(distinct) >= args.min_distinct_images:
                    break
                ik = c["image"].lower()
                if not ik or ik in distinct or c["id_key"] in picked_set:
                    continue
                replaced = False
                for i in range(len(picked) - 1, -1, -1):
                    tail = picked[i]
                    tk = tail["image"].lower()
                    if tk and tk in distinct and tk != ik:
                        picked_set.discard(tail["id_key"])
                        picked[i] = c
                        picked_set.add(c["id_key"])
                        replaced = True
                        break
                if replaced:
                    distinct = {p["image"].lower() for p in picked if p["image"]}

    # Class diversity: encourage at least 2 distinct behavioral classes in selection.
    class_diversity_enforce = embedder is not None and len(picked) >= 3
    if class_diversity_enforce:
        sel_classes = {c.get("behavior_class", {}).get("primary_class", "") for c in picked if c.get("behavior_class")}
        sel_classes.discard("")
        sel_classes.discard("unknown")
        if len(sel_classes) < 2:
            for c in candidates:
                bc = c.get("behavior_class", {})
                if not isinstance(bc, dict):
                    continue
                pc = bc.get("primary_class", "")
                if not pc or pc in sel_classes or c["id_key"] in picked_set:
                    continue
                # Replace the lowest-frontier picked entry that shares its class.
                replaced = False
                for i in range(len(picked) - 1, -1, -1):
                    tc = picked[i].get("behavior_class", {}).get("primary_class", "")
                    if tc and tc in sel_classes and len(sel_classes) < 2 + (1 if len(picked) >= 4 else 0):
                        picked_set.discard(picked[i]["id_key"])
                        picked[i] = c
                        picked_set.add(c["id_key"])
                        replaced = True
                        break
                if replaced:
                    sel_classes = {p.get("behavior_class", {}).get("primary_class", "") for p in picked if p.get("behavior_class")}
                    sel_classes.discard("")
                    sel_classes.discard("unknown")

    selected_distinct_images = len({c["image"].lower() for c in picked if c["image"]})
    selected_distinct_classes = len({c.get("behavior_class", {}).get("primary_class", "") for c in picked if c.get("behavior_class")})
    print(
        json.dumps(
            {
                "selected": [
                    {
                        "name": c["name"],
                        "image": c["image"],
                        "address": c["address"],
                        "frontier_score": round(float(c.get("frontier_score", 0.0)), 3),
                        **({"behavior_class": c["behavior_class"]["primary_class"], "synth_role": c["behavior_class"]["synth_role"], "class_confidence": round(float(c["behavior_class"]["confidence"]), 3)}
                           if c.get("behavior_class") else {}),
                    }
                    for c in picked
                ],
                "count": len(picked),
                "candidates": len(candidates),
                "distinct_images": selected_distinct_images,
                "distinct_classes": selected_distinct_classes,
                "embedder_active": embedder is not None,
            },
            indent=2,
        )
    )

    summary = {
        "probed": 0,
        "returned": 0,
        "capped": 0,
        "success": 0,
        "deep_probed": 0,
        "deep_returned": 0,
        "deep_capped": 0,
        "deep_fault": 0,
        "fault": 0,
        "missing_symbol": 0,
        "other_nonzero": 0,
        "retried": 0,
        "retry_recovered": 0,
        "shallow_return": 0,
        "shallow_success": 0,
        "shallow_retry_upgraded": 0,
        "capped_retried": 0,
        "capped_recovered": 0,
        "trace_mmio_read_count": 0,
        "trace_mmio_write_count": 0,
        "trace_helper_touch_count": 0,
        "trace_branch_depth_max": 0,
        "mmio_touch_probes": 0,
        "rich_trace_probes": 0,
        "nontrivial_return": 0,
        "selected_count": len(picked),
        "selected_distinct_images": selected_distinct_images,
        "selected_distinct_classes": selected_distinct_classes,
        "candidate_count": len(candidates),
        "embedder_active": embedder is not None,
    }
    primary_status_by_id: dict[str, str] = {}
    for target in picked:
        summary["probed"] += 1
        fn = target["name"]
        image = target["image"]
        address = target["address"]
        resolved_fn = fn_canon.get(fn.lower(), fn)
        source = pick_source_for_target(resolved_fn, image, fn_index, fn_by_source, args.source)
        cmd = [
            "python3",
            "tools/unicorn_smoke.py",
            str(source),
            resolved_fn,
            "--image",
            image,
            "--address",
            address,
            "--state-profile",
            args.probe_state_profile,
            "--max-insns",
            str(args.max_insns),
            "--record-outcome",
            str(args.outcomes),
        ]
        if args.probe_mmio_autopage:
            cmd.append("--mmio-autopage")
            cmd.extend(["--mmio-default", args.probe_mmio_default])
        merged = {}
        for a, v in global_seeds + prefix_seeds.get(prefix(fn), []):
            merged[a.lower()] = v
        hint_seeds = contract_hints.get(target["id_key"], []) or contract_hints.get(identity_key(fn), [])
        for hs in hint_seeds:
            try:
                a, v = parse_seed(hs)
            except ValueError:
                continue
            merged[a.lower()] = v
        for a, v in merged.items():
            cmd.extend(["--seed", f"{a}={v}"])

        print(f"== probe {fn} -> {resolved_fn} @ {source}")
        proc = subprocess.run(cmd, text=True, capture_output=True, timeout=90)
        if proc.stdout:
            print(proc.stdout.strip())
        if proc.stderr:
            print(proc.stderr.strip())
        print(f"rc={proc.returncode}")

        parsed_objs = extract_json_objects(proc.stdout or "")
        primary_status = ""
        for row in parsed_objs:
            status_value = str(row.get("status", "")).strip().lower()
            if status_value in {"returned", "capped", "fault", "missing_symbol", "success"}:
                primary_status = "returned" if status_value == "success" else status_value
                break

        if primary_status == "returned":
            summary["returned"] += 1
            summary["success"] += 1
        elif primary_status == "capped":
            summary["capped"] += 1
        elif primary_status == "fault":
            summary["fault"] += 1
        elif primary_status == "missing_symbol":
            summary["missing_symbol"] += 1
        elif proc.returncode == 2:
            summary["fault"] += 1
        elif proc.returncode == 3:
            summary["missing_symbol"] += 1
        elif proc.returncode == 4:
            summary["capped"] += 1
        elif proc.returncode == 0:
            summary["returned"] += 1
            summary["success"] += 1
        else:
            summary["other_nonzero"] += 1
        primary_status_by_id[target["id_key"]] = primary_status

        trace_obj = None
        for row in parsed_objs:
            if str(row.get("status", "")).strip().lower() in {"returned", "capped", "success", "fault"}:
                trace_obj = row
                break
        if isinstance(trace_obj, dict):
            mmio_reads = int(trace_obj.get("mmio_read_count", 0) or 0)
            mmio_writes = int(trace_obj.get("mmio_write_count", 0) or 0)
            helper_touches = int(trace_obj.get("helper_touch_count", 0) or 0)
            summary["trace_mmio_read_count"] += mmio_reads
            summary["trace_mmio_write_count"] += mmio_writes
            summary["trace_helper_touch_count"] += helper_touches
            branch_depth = int(trace_obj.get("branch_depth_max", 0) or 0)
            if branch_depth > summary["trace_branch_depth_max"]:
                summary["trace_branch_depth_max"] = branch_depth
            if (mmio_reads + mmio_writes) > 0:
                summary["mmio_touch_probes"] += 1
            if (mmio_reads + mmio_writes) > 0 or helper_touches > 0 or branch_depth > 0:
                summary["rich_trace_probes"] += 1
        if primary_status == "returned":
            insns = extract_return_insns(parsed_objs)
            if 0 <= insns < max(0, args.min_success_insns):
                summary["shallow_return"] += 1
                summary["shallow_success"] += 1
                if args.retry_shallow_success:
                    retry_cmd = list(cmd)
                    for i, tok in enumerate(retry_cmd):
                        if tok == "--max-insns" and i+1 < len(retry_cmd):
                            retry_cmd[i+1] = str(max(args.max_insns, args.shallow_retry_max_insns))
                            break
                    print(f"== retry shallow-success {fn} with max-insns={max(args.max_insns, args.shallow_retry_max_insns)}")
                    retry = subprocess.run(retry_cmd, text=True, capture_output=True, timeout=120)
                    if retry.stdout:
                        print(retry.stdout.strip())
                    if retry.stderr:
                        print(retry.stderr.strip())
                    print(f"retry_shallow_rc={retry.returncode}")
                    if retry.returncode == 0:
                        r_insns = extract_return_insns(extract_json_objects(retry.stdout or ""))
                        if r_insns > insns:
                            summary["shallow_retry_upgraded"] += 1
            elif insns >= max(0, args.min_success_insns):
                summary["nontrivial_return"] += 1

        if primary_status == "capped" and args.retry_capped_once:
            summary["capped_retried"] += 1
            retry_cmd = list(cmd)
            for i, tok in enumerate(retry_cmd):
                if tok == "--max-insns" and i + 1 < len(retry_cmd):
                    retry_cmd[i + 1] = str(max(args.max_insns, args.capped_retry_max_insns))
                    break
            print(f"== retry capped {fn} with max-insns={max(args.max_insns, args.capped_retry_max_insns)}")
            retry = subprocess.run(retry_cmd, text=True, capture_output=True, timeout=150)
            if retry.stdout:
                print(retry.stdout.strip())
            if retry.stderr:
                print(retry.stderr.strip())
            print(f"retry_capped_rc={retry.returncode}")
            retry_objs = extract_json_objects(retry.stdout or "")
            retry_status = ""
            for row in retry_objs:
                status_value = str(row.get("status", "")).strip().lower()
                if status_value in {"returned", "success", "capped", "fault", "missing_symbol"}:
                    retry_status = "returned" if status_value == "success" else status_value
                    break
            if retry_status == "returned":
                summary["capped_recovered"] += 1
                summary["success"] += 1
                summary["returned"] += 1
                summary["capped"] = max(0, summary["capped"] - 1)
                r_insns = extract_return_insns(retry_objs)
                if r_insns >= max(0, args.min_success_insns):
                    summary["nontrivial_return"] += 1
                else:
                    summary["shallow_return"] += 1
                    summary["shallow_success"] += 1
                for row in retry_objs:
                    if str(row.get("status", "")).strip().lower() not in {"returned", "success", "capped", "fault"}:
                        continue
                    mmio_reads = int(row.get("mmio_read_count", 0) or 0)
                    mmio_writes = int(row.get("mmio_write_count", 0) or 0)
                    helper_touches = int(row.get("helper_touch_count", 0) or 0)
                    summary["trace_mmio_read_count"] += mmio_reads
                    summary["trace_mmio_write_count"] += mmio_writes
                    summary["trace_helper_touch_count"] += helper_touches
                    branch_depth = int(row.get("branch_depth_max", 0) or 0)
                    if branch_depth > summary["trace_branch_depth_max"]:
                        summary["trace_branch_depth_max"] = branch_depth
                    if (mmio_reads + mmio_writes) > 0:
                        summary["mmio_touch_probes"] += 1
                    if (mmio_reads + mmio_writes) > 0 or helper_touches > 0 or branch_depth > 0:
                        summary["rich_trace_probes"] += 1
                    break

        if not args.retry_fault_once:
            continue
        if primary_status != "fault" and proc.returncode != 2:
            continue
        summary["retried"] += 1
        fault_addr = ""
        for row in parsed_objs:
            addr = str(row.get("fault_address", "")).strip().lower()
            if addr.startswith("0x"):
                fault_addr = addr
                break
        if not fault_addr:
            continue
        retry_cmd = list(cmd)
        retry_cmd.extend(["--seed", f"{fault_addr}=0"])
        print(f"== retry {fn} with learned seed {fault_addr}=0")
        retry = subprocess.run(retry_cmd, text=True, capture_output=True, timeout=90)
        if retry.stdout:
            print(retry.stdout.strip())
        if retry.stderr:
            print(retry.stderr.strip())
        print(f"retry_rc={retry.returncode}")
        if retry.returncode == 0:
            summary["retry_recovered"] += 1

        # Keep flow moving even when fault retry is processed.

    # Deep pass for promising targets (R4): use richer instruction budget and
    # optional alternate seed profile for additional behavior evidence.
    if args.deep_pass and args.deep_top_k > 0 and picked:
        deep_targets = sorted(picked, key=lambda c: c.get("frontier_score", 0.0), reverse=True)[: max(0, args.deep_top_k)]
        alt_prefix_seeds: dict[str, list[tuple[str, str]]] = {
            "rf": [("0x40010010", "0x1"), ("0x40010014", "0x1")],
            "sdio": [("0x40020010", "0x1"), ("0x40020014", "0x1")],
            "irq": [("0xe000e100", "0xffffffff")],
            "msg": [("0x20000040", "0x1")],
        }
        for target in deep_targets:
            prior_status = primary_status_by_id.get(target.get("id_key", ""), "")
            if prior_status not in {"returned", "capped", "fault"}:
                continue
            if prior_status == "capped" and not args.deep_on_capped:
                continue
            fn = target["name"]
            image = target["image"]
            address = target["address"]
            resolved_fn = fn_canon.get(fn.lower(), fn)
            source = pick_source_for_target(resolved_fn, image, fn_index, fn_by_source, args.source)

            deep_cmd = [
                "python3",
                "tools/unicorn_smoke.py",
                str(source),
                resolved_fn,
                "--image",
                image,
                "--address",
                address,
                "--state-profile",
                args.probe_state_profile,
                "--max-insns",
                str(max(args.max_insns, args.deep_max_insns)),
                "--record-outcome",
                str(args.outcomes),
            ]
            if args.probe_mmio_autopage:
                deep_cmd.append("--mmio-autopage")
                deep_cmd.extend(["--mmio-default", args.probe_mmio_default])
            merged = {}
            for a, v in global_seeds + prefix_seeds.get(prefix(fn), []) + alt_prefix_seeds.get(prefix(fn), []):
                merged[a.lower()] = v
            hint_seeds = contract_hints.get(target["id_key"], []) or contract_hints.get(identity_key(fn), [])
            for hs in hint_seeds:
                try:
                    a, v = parse_seed(hs)
                except ValueError:
                    continue
                merged[a.lower()] = v
            for a, v in merged.items():
                deep_cmd.extend(["--seed", f"{a}={v}"])

            print(f"== deep probe {fn} -> {resolved_fn} @ {source}")
            deep_proc = subprocess.run(deep_cmd, text=True, capture_output=True, timeout=120)
            if deep_proc.stdout:
                print(deep_proc.stdout.strip())
            if deep_proc.stderr:
                print(deep_proc.stderr.strip())
            print(f"deep_rc={deep_proc.returncode}")

            parsed = extract_json_objects(deep_proc.stdout or "")
            deep_status = ""
            for row in parsed:
                st = str(row.get("status", "")).strip().lower()
                if st in {"returned", "capped", "fault", "missing_symbol", "success"}:
                    deep_status = "returned" if st == "success" else st
                    break

            run_deep = bool(deep_status)
            if not run_deep:
                continue
            summary["deep_probed"] += 1
            if deep_status == "returned":
                summary["deep_returned"] += 1
            elif deep_status == "capped":
                summary["deep_capped"] += 1
            elif deep_status == "fault":
                summary["deep_fault"] += 1

    print(json.dumps({"probe_summary": summary}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
