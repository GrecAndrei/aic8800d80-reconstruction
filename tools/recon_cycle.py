#!/usr/bin/env python3
"""Run one dynamic reconstruction-learning cycle.

Cycle steps:
1. Probe top queue targets with smoke_learn_loop.py and record outcomes
2. Re-run fwextract to ingest latest outcomes and produce updated learning signals
3. Emit a compact cycle report JSON for dashboarding / trend checks
"""

from __future__ import annotations

import argparse
import json
import subprocess
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path


def run(cmd: list[str], cwd: Path) -> subprocess.CompletedProcess[str]:
    return subprocess.run(cmd, cwd=cwd, text=True, capture_output=True)


def load_json(path: Path, default):
    if not path.is_file():
        return default
    try:
        return json.loads(path.read_text(encoding="utf-8", errors="ignore"))
    except json.JSONDecodeError:
        return default


def append_jsonl(path: Path, row: dict) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a", encoding="utf-8") as f:
        f.write(json.dumps(row, sort_keys=True) + "\n")


def write_json(path: Path, row: dict) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(row, indent=2) + "\n", encoding="utf-8")


def read_last_jsonl(path: Path) -> dict:
    if not path.is_file():
        return {}
    last = ""
    with path.open("r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            if line.strip():
                last = line
    if not last:
        return {}
    try:
        return json.loads(last)
    except json.JSONDecodeError:
        return {}


def read_jsonl_rows(path: Path) -> list[dict]:
    if not path.is_file():
        return []
    out: list[dict] = []
    with path.open("r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            try:
                row = json.loads(line)
            except json.JSONDecodeError:
                continue
            if isinstance(row, dict):
                out.append(row)
    return out


def count_jsonl_rows(path: Path) -> int:
    if not path.is_file():
        return 0
    count = 0
    with path.open("r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            if line.strip():
                count += 1
    return count


def percent(numer: int, denom: int) -> float:
    if denom <= 0:
        return 0.0
    return 100.0 * float(numer) / float(denom)


def plateau_streak(history_rows: list[dict], threshold: int) -> int:
    streak = 0
    for row in reversed(history_rows):
        if not isinstance(row, dict):
            break
        delta = int(row.get("delta_learning_smoke_success_count", 0))
        if delta <= threshold:
            streak += 1
            continue
        break
    return streak


def first_existing_path(candidates: list[Path]) -> Path | None:
    for path in candidates:
        if path.is_file():
            return path
    return None


def collect_ida_evidence(root: Path, run_root: Path) -> dict:
    pseudo_path = first_existing_path(
        [
            root / "extraction_out" / "ida_export_pseudo" / "pseudocode_hints.jsonl",
            run_root / "ida_export_pseudo" / "pseudocode_hints.jsonl",
        ]
    )
    cfg_path = first_existing_path(
        [
            root / "extraction_out" / "ida_export_cfg" / "cfg_hints.jsonl",
            run_root / "ida_export_cfg" / "cfg_hints.jsonl",
        ]
    )
    return {
        "cfg_hint_rows": count_jsonl_rows(cfg_path) if cfg_path else 0,
        "pseudocode_hint_rows": count_jsonl_rows(pseudo_path) if pseudo_path else 0,
        "cfg_hint_path": str(cfg_path) if cfg_path else "",
        "pseudocode_hint_path": str(pseudo_path) if pseudo_path else "",
    }


def collect_descriptor_evidence(run_root: Path) -> dict:
    analysis_dir = run_root / "analysis"
    summary = load_json(analysis_dir / "descriptor_summary.json", {})
    motif_memory = load_json(analysis_dir / "motif_recipe_memory.json", [])
    top_motifs: list[dict] = []
    if isinstance(motif_memory, list):
        sorted_rows = sorted(
            [row for row in motif_memory if isinstance(row, dict)],
            key=lambda row: (
                -float(row.get("avg_confidence", 0.0)),
                -float(row.get("success_rate", 0.0)),
                str(row.get("family", "")),
            ),
        )
        top_motifs = sorted_rows[:4]
    return {
        "summary": summary if isinstance(summary, dict) else {},
        "top_motifs": top_motifs,
        "descriptor_count": int(summary.get("descriptor_count", 0)) if isinstance(summary, dict) else 0,
        "motif_backed_count": int(summary.get("motif_backed_count", 0)) if isinstance(summary, dict) else 0,
    }


def build_action_policy_memory(experience_rows: list[dict]) -> dict:
    buckets: dict[str, dict] = {}
    for row in experience_rows:
        if not isinstance(row, dict):
            continue
        action = row.get("controller_primary_action")
        if not isinstance(action, dict):
            continue
        name = str(action.get("name", "")).strip().lower()
        mode = str(action.get("mode", "")).strip().lower()
        if not name:
            continue
        key = f"{name}|{mode}"
        bucket = buckets.setdefault(
            key,
            {
                "name": name,
                "mode": mode,
                "count": 0,
                "sum_delta": 0.0,
                "sum_return_rate": 0.0,
                "sum_nontrivial_rate": 0.0,
                "sum_deep_return_rate": 0.0,
                "sum_cap_rate": 0.0,
            },
        )
        probe = row.get("probe_summary") if isinstance(row.get("probe_summary"), dict) else {}
        probed = max(1, int(probe.get("probed", 0)))
        bucket["count"] += 1
        bucket["sum_delta"] += float(row.get("delta_learning_smoke_success_count", 0))
        bucket["sum_return_rate"] += percent(int(probe.get("returned", 0)), probed)
        bucket["sum_nontrivial_rate"] += percent(int(probe.get("nontrivial_return", 0)), probed)
        bucket["sum_deep_return_rate"] += percent(int(probe.get("deep_returned", 0)), max(1, int(probe.get("deep_probed", 0))))
        bucket["sum_cap_rate"] += percent(int(probe.get("capped", 0)), probed)

    stats: dict[str, dict] = {}
    for key, bucket in buckets.items():
        count = max(1, int(bucket["count"]))
        stats[key] = {
            "name": bucket["name"],
            "mode": bucket["mode"],
            "count": count,
            "avg_delta_learning_smoke_success": round(bucket["sum_delta"] / count, 3),
            "avg_return_rate": round(bucket["sum_return_rate"] / count, 3),
            "avg_nontrivial_rate": round(bucket["sum_nontrivial_rate"] / count, 3),
            "avg_deep_return_rate": round(bucket["sum_deep_return_rate"] / count, 3),
            "avg_cap_rate": round(bucket["sum_cap_rate"] / count, 3),
        }
    return stats


def apply_policy_memory(action_rows: list[dict], policy_memory: dict) -> None:
    for row in action_rows:
        key = f"{str(row.get('name', '')).strip().lower()}|{str(row.get('mode', '')).strip().lower()}"
        stats = policy_memory.get(key)
        if not isinstance(stats, dict):
            continue
        count = int(stats.get("count", 0))
        if count <= 0:
            continue
        delta = float(stats.get("avg_delta_learning_smoke_success", 0.0))
        return_rate = float(stats.get("avg_return_rate", 0.0))
        nontrivial_rate = float(stats.get("avg_nontrivial_rate", 0.0))
        deep_rate = float(stats.get("avg_deep_return_rate", 0.0))
        cap_rate = float(stats.get("avg_cap_rate", 0.0))
        confidence = min(1.0, count / 5.0)
        adjustment = confidence * (
            delta * 1.25 +
            return_rate / 35.0 +
            nontrivial_rate / 25.0 +
            deep_rate / 30.0 -
            cap_rate / 45.0
        )
        row["score"] = round(float(row.get("score", 0.0)) + adjustment, 3)
        row["policy_memory"] = {
            "count": count,
            "avg_delta_learning_smoke_success": round(delta, 3),
            "avg_return_rate": round(return_rate, 3),
            "avg_nontrivial_rate": round(nontrivial_rate, 3),
            "avg_deep_return_rate": round(deep_rate, 3),
            "avg_cap_rate": round(cap_rate, 3),
            "score_adjustment": round(adjustment, 3),
        }


def choose_recommended_mode(action_rows: list[dict], probe: dict) -> tuple[str, dict]:
    mode_scores: dict[str, float] = {}
    mode_reasons: dict[str, list[str]] = {}
    capped_rate = percent(int(probe.get("capped", 0)), max(1, int(probe.get("probed", 0))))
    returned_rate = percent(int(probe.get("returned", 0)), max(1, int(probe.get("probed", 0))))
    selected_count = int(probe.get("selected_count", 0))
    candidate_count = int(probe.get("candidate_count", 0))
    probed_count = int(probe.get("probed", 0))
    for row in action_rows:
        mode = str(row.get("mode", "")).strip().lower()
        if not mode:
            continue
        score = float(row.get("score", 0.0))
        mode_scores[mode] = max(score, mode_scores.get(mode, -1e9))
        mode_reasons.setdefault(mode, []).append(str(row.get("name", "")))
        memory = row.get("policy_memory") if isinstance(row.get("policy_memory"), dict) else {}
        if mode == "synthesize" and memory:
            avg_delta = float(memory.get("avg_delta_learning_smoke_success", 0.0))
            avg_cap = float(memory.get("avg_cap_rate", 0.0))
            if avg_delta <= 0.0 and avg_cap >= 75.0:
                mode_scores[mode] -= 2.0
        if mode == "deepen" and capped_rate >= 85.0 and returned_rate <= 10.0:
            mode_scores[mode] += 2.5
        if mode == "deepen" and int(probe.get("deep_returned", 0)) > 0:
            mode_scores[mode] += 1.0
        if mode == "deepen" and (selected_count == 0 or probed_count == 0):
            mode_scores[mode] -= 5.0
        if mode == "validate" and selected_count == 0:
            mode_scores[mode] += 4.0
        if mode == "explore" and candidate_count == 0:
            mode_scores[mode] -= 3.0
        if mode == "synthesize" and selected_count == 0 and candidate_count == 0:
            mode_scores[mode] -= 2.5
    if not mode_scores:
        return "synthesize", {"reason": "no_mode_candidates"}
    best_mode = sorted(mode_scores.items(), key=lambda item: (-item[1], item[0]))[0][0]
    return best_mode, {
        "mode_scores": {k: round(v, 3) for k, v in sorted(mode_scores.items())},
        "mode_reason_actions": {k: v for k, v in sorted(mode_reasons.items())},
        "capped_rate": round(capped_rate, 3),
        "returned_rate": round(returned_rate, 3),
    }


def recommend_controller_actions(report: dict, history_rows: list[dict], ida_evidence: dict, descriptor_evidence: dict, embedder_enabled: bool, policy_memory: dict) -> dict:
    summary = report.get("summary", {}) if isinstance(report.get("summary"), dict) else {}
    probe = report.get("probe_summary", {}) if isinstance(report.get("probe_summary"), dict) else {}
    descriptor_summary = descriptor_evidence.get("summary", {}) if isinstance(descriptor_evidence.get("summary"), dict) else {}
    top_motifs = descriptor_evidence.get("top_motifs", []) if isinstance(descriptor_evidence.get("top_motifs"), list) else []
    probed = max(1, int(probe.get("probed", 0)))
    capped = int(probe.get("capped", 0))
    returned = int(probe.get("returned", 0))
    nontrivial = int(probe.get("nontrivial_return", 0))
    mmio_touch = int(probe.get("mmio_touch_probes", 0))
    distinct_images = int(probe.get("selected_distinct_images", 0))
    deep_returned = int(probe.get("deep_returned", 0))
    candidate_count = int(probe.get("candidate_count", 0))
    selected_count = int(probe.get("selected_count", 0))
    plateau = plateau_streak(history_rows, 0)

    action_rows: list[dict] = []

    def add_action(name: str, mode: str, score: float, *reasons: str, overrides: dict | None = None) -> None:
        clean = [r for r in reasons if r]
        action_rows.append(
            {
                "name": name,
                "mode": mode,
                "score": round(score, 3),
                "reasons": clean,
                "overrides": overrides or {},
            }
        )

    if ida_evidence.get("cfg_hint_rows", 0) == 0 or ida_evidence.get("pseudocode_hint_rows", 0) == 0:
        add_action(
            "refresh_ida_exports",
            "explore",
            10.0,
            f"IDA evidence incomplete: cfg={ida_evidence.get('cfg_hint_rows', 0)} pseudo={ida_evidence.get('pseudocode_hint_rows', 0)}",
            "refresh grounded facts before further synthesis",
            overrides={"refresh_ida": True},
        )
    if not embedder_enabled or not bool(probe.get("embedder_active", False)):
        add_action(
            "enable_embedder_guidance",
            "explore",
            9.0,
            "embedder model absent or inactive in probe selection",
            "restore IDA-facts plus embedder-priors operation",
            overrides={"require_embedder": True},
        )

    capped_rate = percent(capped, probed)
    returned_rate = percent(returned, probed)
    nontrivial_rate = percent(nontrivial, probed)
    mmio_rate = percent(mmio_touch, probed)

    deepen_score = 8.0 + capped_rate / 25.0
    if capped_rate >= 85.0 and returned == 0:
        deepen_score += 3.0
    if capped_rate >= 70.0:
        add_action(
            "deepen_probe_and_raise_evidence",
            "deepen",
            deepen_score,
            f"cap-hit rate {capped_rate:.1f}% is dominating returns",
            f"returned rate only {returned_rate:.1f}%",
            overrides={"suggested_max_insns_multiplier": 2, "prefer_deep_on_capped": True},
        )
    if nontrivial > 0 or deep_returned > 0:
        add_action(
            "propagate_recipe_to_neighbors",
            "synthesize",
            7.0 + percent(nontrivial + deep_returned, probed) / 20.0,
            f"nontrivial/deep-return evidence available ({nontrivial} nontrivial, {deep_returned} deep)",
            "apply successful motif families to embedding-near neighbors",
            overrides={"propagate_neighbors": True},
        )
    if report.get("delta_learning_smoke_success_count", 0) <= 0:
        motif_score = 6.0 + float(max(0, plateau - 1))
        if capped_rate >= 85.0 and returned == 0:
            motif_score -= 3.5
        add_action(
            "synthesize_new_motif_family",
            "synthesize",
            motif_score,
            f"learning plateau streak={plateau + 1}",
            "current queue traversal is not increasing learned smoke returns",
            overrides={"prefer_new_motifs": True},
        )
    if candidate_count == 0 or selected_count == 0:
        empty_score = 9.5 + float(max(0, plateau))
        if candidate_count == 0:
            empty_score += 2.0
        add_action(
            "retask_empty_frontier",
            "validate",
            empty_score,
            f"frontier is empty or unselectable (candidates={candidate_count}, selected={selected_count})",
            f"plateau streak={plateau + 1} suggests generic probing is exhausted",
            overrides={"retask_frontier": True, "skip_auto_impl": True},
        )
    if distinct_images < 2 and candidate_count > probed:
        add_action(
            "rebalance_frontier_diversity",
            "explore",
            5.5,
            f"selected image diversity is low ({distinct_images}) with remaining candidates available",
            "shift budget toward under-covered images/clusters",
            overrides={"prefer_image_diversity": True},
        )
    if mmio_rate < 20.0 and capped_rate >= 50.0:
        add_action(
            "validate_mmio_state_model",
            "validate",
            5.0,
            f"mmio-touch rate {mmio_rate:.1f}% is low while capped rate is {capped_rate:.1f}%",
            "likely harness or peripheral-state mismatch rather than true behavior",
            overrides={"review_mmio_state": True},
        )
    if int(descriptor_summary.get("motif_backed_count", 0)) > 0:
        motif_rows = [row for row in top_motifs if isinstance(row, dict)]
        if motif_rows:
            best = motif_rows[0]
            family = str(best.get("family", "")).strip()
            avg_conf = float(best.get("avg_confidence", 0.0))
            success_rate = float(best.get("success_rate", 0.0))
            if family and avg_conf >= 0.65:
                add_action(
                    "apply_descriptor_motif_memory",
                    "synthesize",
                    6.5 + avg_conf * 2.0 + success_rate / 40.0,
                    f"descriptor motif memory identifies reusable family {family}",
                    f"family confidence {avg_conf:.2f} success_rate {success_rate:.1f}%",
                    overrides={"prefer_descriptor_motifs": True, "motif_family": family},
                )
    phenotype_counts = descriptor_summary.get("phenotype_counts", {}) if isinstance(descriptor_summary.get("phenotype_counts"), dict) else {}
    motif_family_counts = descriptor_summary.get("motif_family_counts", {}) if isinstance(descriptor_summary.get("motif_family_counts"), dict) else {}
    capped_mmio = int(phenotype_counts.get("capped_mmio_wait", 0))
    shallow_wrappers = int(phenotype_counts.get("shallow_wrapper", 0))
    register_commit = int(motif_family_counts.get("register_commit", 0))
    bounded_poll = int(motif_family_counts.get("bounded_poll", 0))
    if capped_mmio > 0:
        add_action(
            "prioritize_mmio_wait_family",
            "synthesize",
            5.0 + min(6.0, capped_mmio * 0.4),
            f"descriptor layer sees {capped_mmio} capped MMIO wait functions",
            "promote bounded wait and MMIO-transfer motif recovery",
            overrides={"prefer_mmio_wait_family": True},
        )
    if register_commit > 0:
        add_action(
            "specialize_register_commit_family",
            "synthesize",
            6.5 + min(8.0, register_commit * 0.02),
            f"descriptor motif memory tracks {register_commit} register_commit functions",
            "prefer transfer-backed register-commit emitters over generic queue walking",
            overrides={"prefer_register_commit_family": True},
        )
    if bounded_poll > 0 and capped_mmio > 0:
        add_action(
            "specialize_bounded_poll_family",
            "synthesize",
            6.0 + min(5.0, bounded_poll * 0.15),
            f"bounded_poll motifs={bounded_poll} with capped_mmio_wait phenotype count={capped_mmio}",
            "promote explicit MMIO wait-loop emitters before generic synthesis",
            overrides={"prefer_bounded_poll_family": True},
        )
    if shallow_wrappers > 0:
        add_action(
            "unwrap_shallow_dispatchers",
            "synthesize",
            4.5 + min(5.0, shallow_wrappers * 0.3),
            f"descriptor layer sees {shallow_wrappers} shallow wrapper functions",
            "promote dispatcher/queue/state-machine motif routing ahead of generic synthesis",
            overrides={"prefer_wrapper_breaking": True},
        )

    if not action_rows:
        add_action(
            "continue_balanced_cycle",
            "synthesize",
            1.0,
            "no dominant failure mode detected",
            overrides={"keep_current_policy": True},
        )

    apply_policy_memory(action_rows, policy_memory)
    action_rows.sort(key=lambda row: (-float(row.get("score", 0.0)), str(row.get("name", ""))))
    primary = action_rows[0]
    recommended_mode, mode_decision = choose_recommended_mode(action_rows, probe)
    return {
        "schema_version": "0.1.0",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "tag": report.get("tag", ""),
        "primary_action": primary,
        "recommended_actions": action_rows,
        "recommended_mode": recommended_mode,
        "mode_decision": mode_decision,
        "ida_evidence": ida_evidence,
        "descriptor_evidence": descriptor_evidence,
        "embedder": {
            "model_enabled": embedder_enabled,
            "probe_embedder_active": bool(probe.get("embedder_active", False)),
        },
        "frontier_metrics": {
            "candidate_count": candidate_count,
            "selected_distinct_images": distinct_images,
            "completion_pct": summary.get("completion_pct", 0.0),
            "semantic_completion_pct": summary.get("semantic_completion_pct", 0.0),
        },
        "policy_memory": policy_memory,
    }


def build_experience_record(report: dict, controller_state: dict, queue_source: str) -> dict:
    probe = report.get("probe_summary", {}) if isinstance(report.get("probe_summary"), dict) else {}
    return {
        "schema_version": "0.1.0",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "tag": report.get("tag", ""),
        "queue_source": queue_source,
        "probe_summary": probe,
        "learning_smoke_success_count": int(report.get("learning_smoke_success_count", 0)),
        "delta_learning_smoke_success_count": int(report.get("delta_learning_smoke_success_count", 0)),
        "learning_reason_counts": report.get("learning_reason_counts", {}),
        "controller_primary_action": controller_state.get("primary_action", {}),
        "controller_recommended_mode": controller_state.get("recommended_mode", "synthesize"),
        "ida_evidence": controller_state.get("ida_evidence", {}),
        "descriptor_evidence": controller_state.get("descriptor_evidence", {}),
    }


def compact_cycle_summary(report: dict, controller_state: dict) -> dict:
    probe = report.get("probe_summary", {}) if isinstance(report.get("probe_summary"), dict) else {}
    return {
        "tag": report.get("tag", ""),
        "learning_smoke_success_count": int(report.get("learning_smoke_success_count", 0)),
        "delta_learning_smoke_success_count": int(report.get("delta_learning_smoke_success_count", 0)),
        "probe_summary": {
            "candidate_count": int(probe.get("candidate_count", 0)),
            "probed": int(probe.get("probed", 0)),
            "returned": int(probe.get("returned", 0)),
            "capped": int(probe.get("capped", 0)),
            "selected_count": int(probe.get("selected_count", 0)),
            "nontrivial_return": int(probe.get("nontrivial_return", 0)),
            "deep_returned": int(probe.get("deep_returned", 0)),
            "mmio_touch_probes": int(probe.get("mmio_touch_probes", 0)),
            "selected_distinct_images": int(probe.get("selected_distinct_images", 0)),
        },
        "ida_evidence": controller_state.get("ida_evidence", {}),
        "descriptor_evidence": controller_state.get("descriptor_evidence", {}),
        "controller_primary_action": controller_state.get("primary_action", {}),
    }


def emit_failure(label: str, proc: subprocess.CompletedProcess[str]) -> None:
    payload = {
        "stage": label,
        "returncode": proc.returncode,
    }
    stderr = proc.stderr.strip()
    stdout = proc.stdout.strip()
    if stderr:
        payload["stderr_tail"] = stderr.splitlines()[-20:]
    elif stdout:
        payload["stdout_tail"] = stdout.splitlines()[-20:]
    print(json.dumps(payload, indent=2))


def recommend_fault_seeds(outcomes_path: Path, top_n: int) -> list[str]:
    if top_n <= 0:
        return []
    counts: Counter[str] = Counter()
    for row in read_jsonl_rows(outcomes_path):
        status = str(row.get("status", "")).strip().lower()
        if status not in {"fault", "error", "failed"}:
            continue
        fault_addr = str(row.get("fault_address", "")).strip().lower()
        if not fault_addr:
            continue
        if not fault_addr.startswith("0x"):
            fault_addr = "0x" + fault_addr
        try:
            _ = int(fault_addr, 16)
        except ValueError:
            continue
        counts[fault_addr] += 1
    ranked = sorted(counts.items(), key=lambda kv: (-kv[1], kv[0]))
    return [f"{addr}=0" for addr, _ in ranked[:top_n]]


def parse_probe_summary(stdout: str) -> dict:
    summary: dict = {}
    for line in stdout.splitlines():
        line = line.strip()
        if not line.startswith("{"):
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError:
            continue
        if isinstance(row, dict) and "probe_summary" in row and isinstance(row["probe_summary"], dict):
            summary = row["probe_summary"]
    return summary


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--root", type=Path, default=Path("."), help="repo root")
    ap.add_argument("--run-root", type=Path, default=Path("extraction_out/reconstruction/mega7"), help="reconstruction run root")
    ap.add_argument("--primary-source", type=Path, required=True, help="primary C source used by smoke loop")
    ap.add_argument("--source-glob", action="append", default=[], help="additional source glob(s)")
    ap.add_argument("--limit", type=int, default=10, help="number of queue targets to probe this cycle")
    ap.add_argument("--max-insns", type=int, default=120, help="max instructions per probe")
    ap.add_argument("--min-success-insns", type=int, default=8, help="treat success below this instruction count as shallow")
    ap.add_argument("--shallow-cooldown", type=int, default=3, help="skip targets with repeated shallow-success outcomes")
    ap.add_argument("--seed", action="append", default=["0x40000000=0"], help="default seed ADDR=VALUE")
    ap.add_argument("--tag", default="", help="run tag for this cycle")
    ap.add_argument("--missing-cooldown", type=int, default=3, help="skip targets with repeated missing_symbol outcomes")
    ap.add_argument("--retry-fault-once", action="store_true", help="retry faulted probes once with learned fault seed")
    ap.add_argument("--retry-shallow-success", action="store_true", help="retry shallow successes once with higher instruction budget")
    ap.add_argument("--shallow-retry-max-insns", type=int, default=512, help="max instructions for shallow-success retry")
    ap.add_argument("--retry-capped-once", action="store_true", help="retry capped probes once with higher instruction budget")
    ap.add_argument("--capped-retry-max-insns", type=int, default=1024, help="max instructions for capped retry")
    ap.add_argument("--recent-window-min", type=int, default=30, help="skip functions attempted within this many minutes")
    ap.add_argument("--prefer-non-cycle-queue", action="store_true", help="prefer latest non-cycle queue over cycle queue")
    ap.add_argument("--auto-seed-top", type=int, default=8, help="auto-append top recurring fault-address seeds from historical outcomes")
    ap.add_argument("--embedder-model", default="", help="Path to GGUF embedding model for behavioral classification")
    ap.add_argument("--verbose", action="store_true", help="emit underlying command stdout/stderr instead of compact summaries")
    args = ap.parse_args()

    root = args.root.resolve()
    run_root = (root / args.run_root).resolve()
    outcomes = run_root / "smoke_observations.jsonl"
    runs_dir = run_root / "runs"
    runs_dir.mkdir(parents=True, exist_ok=True)

    if args.tag.strip():
        tag = args.tag.strip()
    else:
        tag = "cycle_" + datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ")

    candidates = list((runs_dir).glob("*/mining_queue_top300.jsonl"))
    if not candidates:
        raise SystemExit("no mining_queue_top300.jsonl found under run root")
    candidates.sort(key=lambda p: p.stat().st_mtime)
    latest_queue = candidates[-1]
    if args.prefer_non_cycle_queue:
        non_cycle = [p for p in candidates if "cycle" not in p.parent.name.lower()]
        if non_cycle:
            latest_queue = non_cycle[-1]

    auto_seeds = recommend_fault_seeds(outcomes, args.auto_seed_top)
    merged_seeds: list[str] = []
    seen_seeds: set[str] = set()
    for seed in list(args.seed) + auto_seeds:
        key = seed.strip().lower()
        if not key or key in seen_seeds:
            continue
        seen_seeds.add(key)
        merged_seeds.append(seed)

    smoke_cmd = [
        "python3",
        "tools/smoke_learn_loop.py",
        "--source",
        str(args.primary_source),
        "--queue",
        str(latest_queue),
        "--outcomes",
        str(outcomes),
        "--readme",
        "README.md",
        "--limit",
        str(args.limit),
        "--max-insns",
        str(args.max_insns),
        "--min-success-insns",
        str(args.min_success_insns),
        "--shallow-cooldown",
        str(args.shallow_cooldown),
        "--shallow-retry-max-insns",
        str(args.shallow_retry_max_insns),
        "--missing-cooldown",
        str(args.missing_cooldown),
        "--recent-window-min",
        str(args.recent_window_min),
    ]
    if args.retry_fault_once:
        smoke_cmd.append("--retry-fault-once")
    if args.retry_shallow_success:
        smoke_cmd.append("--retry-shallow-success")
    if args.retry_capped_once:
        smoke_cmd.append("--retry-capped-once")
    smoke_cmd.extend(["--capped-retry-max-insns", str(args.capped_retry_max_insns)])
    for g in args.source_glob:
        smoke_cmd.extend(["--source-glob", g])
    for s in merged_seeds:
        smoke_cmd.extend(["--seed", s])
    if args.embedder_model:
        smoke_cmd.extend(["--embedder-model", str(args.embedder_model)])

    smoke = run(smoke_cmd, root)
    if args.verbose and smoke.stdout:
        print(smoke.stdout)
    if smoke.returncode != 0:
        emit_failure("smoke_learn_loop", smoke)
        return smoke.returncode
    probe_summary = parse_probe_summary(smoke.stdout)

    extract_cmd = [
        "go",
        "run",
        "./cmd/fwextract",
        "-root",
        ".",
        "-out",
        str(args.run_root),
        "-run-tag",
        tag,
    ]
    ex = run(extract_cmd, root)
    if args.verbose and ex.stdout:
        print(ex.stdout)
    if ex.returncode != 0:
        emit_failure("fwextract", ex)
        return ex.returncode

    run_dir = run_root / "runs" / tag
    summary = load_json(run_dir / "summary.json", {})
    learning = load_json(run_dir / "learning_signals.json", {})
    by_function = learning.get("by_function", {}) if isinstance(learning, dict) else {}
    by_prefix = learning.get("by_prefix", {}) if isinstance(learning, dict) else {}

    reason_counts: dict[str, int] = {}
    for row in by_function.values():
        if not isinstance(row, dict):
            continue
        reason = str(row.get("reason", "unknown"))
        reason_counts[reason] = reason_counts.get(reason, 0) + 1

    report = {
        "schema_version": "0.1.0",
        "tag": tag,
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "queue_source": str(latest_queue),
        "summary": summary,
        "learning_by_function_count": len(by_function),
        "learning_by_prefix_count": len(by_prefix),
        "learning_reason_counts": reason_counts,
        "learning_smoke_success_count": int(
            reason_counts.get("learned_smoke_returned", 0)
            + reason_counts.get("learned_smoke_success", 0)
        ),
        "learning_smoke_returned_count": int(reason_counts.get("learned_smoke_returned", 0)),
        "learning_smoke_capped_count": int(reason_counts.get("learned_smoke_capped", 0)),
        "outcomes_path": str(outcomes),
        "probe_summary": probe_summary,
        "recommended_seeds": auto_seeds,
        "effective_seeds": merged_seeds,
    }
    history_path = run_root / "cycle_history.jsonl"
    prev = read_last_jsonl(history_path)
    prev_func = int(prev.get("learning_by_function_count", 0)) if isinstance(prev, dict) else 0
    prev_prefix = int(prev.get("learning_by_prefix_count", 0)) if isinstance(prev, dict) else 0
    prev_success = 0
    if isinstance(prev, dict):
        if "learning_smoke_success_count" in prev:
            prev_success = int(prev.get("learning_smoke_success_count", 0))
        else:
            prev_reasons = prev.get("learning_reason_counts", {})
            if isinstance(prev_reasons, dict):
                prev_success = int(
                    prev_reasons.get("learned_smoke_returned", 0)
                    + prev_reasons.get("learned_smoke_success", 0)
                )
    report["delta_learning_by_function_count"] = len(by_function) - prev_func
    report["delta_learning_by_prefix_count"] = len(by_prefix) - prev_prefix
    report["delta_learning_smoke_success_count"] = int(report["learning_smoke_success_count"]) - prev_success
    ida_evidence = collect_ida_evidence(root, run_root)
    descriptor_evidence = collect_descriptor_evidence(run_root)
    policy_memory = build_action_policy_memory(read_jsonl_rows(run_root / "controller_experience.jsonl"))
    controller_state = recommend_controller_actions(report, read_jsonl_rows(history_path), ida_evidence, descriptor_evidence, bool(args.embedder_model), policy_memory)
    report["ida_evidence"] = ida_evidence
    report["descriptor_evidence"] = descriptor_evidence
    report["controller_primary_action"] = controller_state.get("primary_action", {})
    report["controller_recommended_mode"] = controller_state.get("recommended_mode", "synthesize")
    report_path = run_dir / "cycle_report.json"
    write_json(report_path, report)
    write_json(run_dir / "controller_state.json", controller_state)
    write_json(run_root / "controller_state.json", controller_state)
    append_jsonl(history_path, report)
    append_jsonl(run_root / "controller_experience.jsonl", build_experience_record(report, controller_state, str(latest_queue)))
    print(json.dumps(compact_cycle_summary(report, controller_state), indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
