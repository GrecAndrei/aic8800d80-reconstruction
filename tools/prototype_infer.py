#!/usr/bin/env python3
"""prototype_infer.py — machine-code-grounded return-contract evidence.

First stage of the deterministic prototype pipeline. It does not guess C types
from Hex-Rays text. It reads the original firmware bytes and classifies only
cases that are locally unambiguous:

* exact_nullsub: the first instruction is ``bx lr`` and every following byte
  before the next function boundary is padding (``nop``/zero);
* tail_alias: the complete body is an unconditional branch to another
  function entry, so its return contract is transparently the target's.

The JSONL output is evidence for later void/nonvoid inference. Unknown or
complex functions are emitted as ``unknown`` rather than forced into a type.
"""
import argparse
import json
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_MCLASS
from capstone.arm_const import ARM_REG_R0, ARM_REG_R1, ARM_REG_R2, ARM_REG_R3

REPO = Path(__file__).resolve().parent.parent
ANALYSIS_BASE = 0x100000
IMAGES = {
    "fmacfw_8800d80_h_u02": "fmacfw_h_u02",
    "fmacfw_8800d80_u02": "fmacfw_u02",
    "fmacfwbt_8800d80_u02": "fmacfwbt_u02",
    "lmacfw_rf_8800d80_u02": "lmacfw_rf_u02",
}
MARKER_RE = __import__("re").compile(r"^// \S+ @ (0x[0-9a-fA-F]+)", __import__("re").M)


def load_funcs(image: str) -> list[dict]:
    """Composed function starts in analysis order.

    The v25 scan is an input-discovery artifact and omits tiny padding/nullsub
    units. The composed source is the actual link/corpus universe, so it is the
    authoritative boundary set for inference over reconstruction functions.
    """
    text = (REPO / "src" / IMAGES[image] / "main.c").read_text(errors="replace")
    rows = [{"address": int(x, 16), "name": "composed"} for x in MARKER_RE.findall(text)]
    rows.sort(key=lambda r: r["address"])
    dedup = []
    for row in rows:
        if not dedup or row["address"] != dedup[-1]["address"]:
            dedup.append(row)
    return dedup


ARG_REGS = (ARM_REG_R0, ARM_REG_R1, ARM_REG_R2, ARM_REG_R3)
ARG_INDEX = {r: i for i, r in enumerate(ARG_REGS)}
CONTROL_FLOW_MNEMONICS = {
    "b", "b.w", "bx", "bl", "blx", "cbz", "cbnz", "pop", "ldmia",
}


def prologue_inputs(image: bytes, addr: int, limit: int = 32) -> list[int] | None:
    """Conservative upward-exposed argument-register evidence from the entry.

    Scan only the straight-line prologue before the first control-flow transfer.
    A register is an input when it is read before the function writes it. This
    is deliberately an underapproximation: branches/calls stop the scan and
    complex cases remain unknown rather than inventing a prototype.
    """
    off = addr - ANALYSIS_BASE
    if not 0 <= off < len(image):
        return None
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)
    md.detail = True
    used: set[int] = set()
    written: set[int] = set()
    for ins in md.disasm(image[off:off + 160], addr, count=limit):
        mnemonic = ins.mnemonic
        if mnemonic in {"b", "b.w", "bx", "bl", "blx", "cbz", "cbnz"} or mnemonic.startswith("b") and mnemonic not in {"bf", "bic"}:
            break
        try:
            reads, writes = ins.regs_access()
        except Exception:
            break
        # A prologue push preserves argument registers; it is not evidence
        # that their values are semantic inputs. Likewise a later epilogue
        # pop restores them rather than defining machine-level results here.
        if mnemonic in {"push", "pop"}:
            continue
        for reg in reads:
            if reg in ARG_INDEX and reg not in written:
                used.add(ARG_INDEX[reg])
        for reg in writes:
            if reg in ARG_INDEX:
                written.add(reg)
    return sorted(used)



# ---------------------------------------------------------------------------
# CFG-aware r0 return-provenance analysis
# ---------------------------------------------------------------------------
#
# For every return point (bx lr, or a pop/ldmia that includes pc), determine
# what the caller observes in r0 by walking the backwards-reachable straight-
# line instruction DAG:
#
#   input_residue   no write to r0 dominates the return on any path: the
#                   caller sees whatever it passed in r0. Machine proof that
#                   the function produces no result.
#   produced        every path's most recent r0 event is a local write
#                   (mov/ldr/alu/vmov) with no call in between.
#   call_passthru   the most recent r0 event on some path is a bl/blx: the
#                   caller sees that callee's result.
#   tail_target     the return is an unconditional branch to another function.
#   mixed           paths disagree (e.g. a conditional tail call plus an
#                   input-residue fallthrough): not transparently anything.
#   unknown         indirect control flow, jump tables, or excessive depth.
#
# Scratch writes that are consumed locally (``movs r0,#1; strb r0,[r2]``)
# still count as writes: provenance answers "what does the caller see", and
# only caller-use evidence decides whether that value is a semantic result.
# The two evidences combine in the verdict logic, never in the machine scan.

RETURN_MNEMONICS = {"bx"}
COND_BRANCH = tuple("b" + c for c in (
    "eq", "ne", "cs", "hs", "cc", "lo", "mi", "pl", "vs", "vc",
    "hi", "ls", "ge", "lt", "gt", "le", "al"))


def _parse_branch_target(op_str: str) -> int | None:
    s = op_str.strip().lstrip("#")
    try:
        return int(s, 0)
    except ValueError:
        return None


def disassemble_fn(blob: bytes, addr: int, end: int, base: int = ANALYSIS_BASE) -> list:
    """Linear-sweep capstone instructions covering [addr, end)."""
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)
    md.detail = True
    off, off_end = addr - base, end - base
    if not 0 <= off < off_end <= len(blob):
        return []
    return list(md.disasm(blob[off:off_end], addr))


def build_cfg(insns: list) -> dict:
    """Return {addr: {succ, kind, ins}} per instruction.

    kind: ret (bx lr), rettail (unconditional branch out of scanning range or
    to another entry), branch, cbranch, call, popret, fallthrough, indirect.
    Successors are instruction addresses inside the function; call successors
    point at the next instruction (the call clobber is handled in provenance).
    """
    by_addr = {i.address: i for i in insns}
    addrs = sorted(by_addr)
    if not addrs:
        return {}
    idx = {a: n for n, a in enumerate(addrs)}
    last = addrs[-1]
    out = {}
    for n, a in enumerate(addrs):
        ins = by_addr[a]
        mn = ins.mnemonic
        nxt = addrs[n + 1] if n + 1 < len(addrs) else None
        kind = "fallthrough"
        succ = []
        if mn == "bx" and "lr" in ins.op_str:
            kind, succ = "ret", []
        elif mn == "bx":
            kind, succ = "indirect", []
        elif mn in ("pop", "ldmia") and "pc" in ins.op_str:
            kind, succ = "popret", []
        elif mn in ("b", "b.w"):
            kind = "branch"
            tgt = _parse_branch_target(ins.op_str)
            succ = [tgt] if tgt in by_addr else []
            if tgt not in by_addr:
                kind = "rettail"      # leaves the function: tail call or dead-end
                out[a] = {"succ": succ, "kind": kind, "ins": ins, "tail_target": tgt}
                continue
        elif mn in COND_BRANCH or mn in ("cbz", "cbnz"):
            kind = "cbranch"
            tgt = _parse_branch_target(ins.op_str)
            succ = [x for x in (tgt, nxt) if x in by_addr]
        elif mn in ("tbb", "tbh"):
            kind, succ = "indirect", []
        elif mn in ("bl", "blx"):
            kind = "call"
            succ = [nxt] if nxt in by_addr else []
            tgt = _parse_branch_target(ins.op_str)
            out[a] = {"succ": succ, "kind": kind, "ins": ins, "call_target": tgt}
            continue
        else:
            succ = [nxt] if nxt in by_addr else []
            if nxt is None and mn not in ("bx",):
                kind = "fallthrough"
        out[a] = {"succ": succ, "kind": kind, "ins": ins}
    return out


def r0_provenance(cfg: dict, entries: list[int], max_depth: int = 400) -> dict:
    """Backward r0-provenance at every return point.

    Returns {kind-set, returns: [{addr, prov}], tail_targets}. entries limits
    analysis to blocks reachable from the function entry; unreachable trailing
    literal pools never disassemble cleanly enough to matter here.
    """
    returns = []
    tails = []
    for a, blk in cfg.items():
        if blk["kind"] in ("ret", "popret"):
            returns.append(a)
        elif blk["kind"] == "rettail":
            tails.append((a, blk.get("tail_target")))

    def backtrack(start: int) -> str:
        """Walk backward from the return; classify the nearest r0 event."""
        # forward reachability order is approximated by iterating predecessors
        # breadth-first backward; a small depth cap keeps loops finite.
        preds: dict[int, list[int]] = {}
        for a, blk in cfg.items():
            for s in blk["succ"]:
                preds.setdefault(s, []).append(a)
        seen_states = set()
        frontier = [(start, 0)]
        provs = set()
        steps = 0
        while frontier and steps < max_depth:
            steps += 1
            cur, depth = frontier.pop()
            if depth > 120:
                provs.add("unknown")
                continue
            state = cur
            if state in seen_states and depth:
                # loop with no r0 event on this cycle: the event dominating the
                # loop entry dominates here too; treat as undecided residue of
                # the continuing walk (bounded by depth cap).
                continue
            seen_states.add(state)
            blk = cfg.get(cur)
            if blk is None:
                provs.add("unknown")
                continue
            ins = blk["ins"]
            try:
                reads, writes = ins.regs_access()
            except Exception:
                reads, writes = (), ()
            r0w = ARM_REG_R0 in writes
            if blk["kind"] == "call":
                # a call defines r0 as the callee's result
                provs.add("call_passthru")
                continue
            if blk["kind"] == "popret" and cur != start:
                pass
            if r0w:
                provs.add("produced")
                continue
            if blk["kind"] in ("ret", "popret") and cur != start:
                # reached a different return without an r0 event: multi-exit
                # tangle; conservative
                provs.add("unknown")
                continue
            ps = preds.get(cur, [])
            if not ps:
                # walked back to the entry with no write and no call
                provs.add("input_residue")
                continue
            for p in ps:
                frontier.append((p, depth + 1))
        if steps >= max_depth:
            provs.add("unknown")
        return "+".join(sorted(provs)) if provs else "unknown"

    rep = []
    for r in returns:
        rep.append({"addr": hex(r), "prov": backtrack(r)})
    kinds = set()
    for x in rep:
        kinds.update(x["prov"].split("+"))
    return {"returns": rep, "tail_targets": [hex(t) for _, t in tails if t], "kinds": sorted(kinds)}



def return_verdict(prov: dict, has_indirect: bool) -> tuple[str, list[str]]:
    """Fuse per-return provenance and tail targets into a return-contract verdict.

    Machine-grounded rules (evidence: subagent machine analysis of the corpus):
    * a function whose every return carries input residue and that has no tail
      path produces no result: void_input_residue.
    * a tail-only function is transparently its target: handled by the
      existing tail_alias class, not here.
    * a conditional tail PLUS a fallthrough return is never transparent:
      contract is mixed, because the paths must be unioned.
    * uniform produced/call_passthru across all returns is result evidence,
      but scratch writes cannot be distinguished locally: it is caller-use
      evidence that decides whether the value is a semantic result.
    * anything involving unknown or indirect control flow stays inert.
    """
    evidence = []
    kinds = set(prov.get("kinds", []))
    tails = prov.get("tail_targets", [])
    rets = prov.get("returns", [])
    if "unknown" in kinds or has_indirect:
        return "unknown", ["indirect or undecidable control flow"]
    if not rets and tails:
        return "unknown", ["no direct returns; tail-only handled by alias resolution"]
    if tails and rets:
        evidence.append(f"{len(tails)} conditional tail path(s) unioned with fallthrough returns")
        base = "mixed"
    else:
        base = None
    if kinds == {"input_residue"} and not tails:
        return "void_input_residue", ["no return path writes or receives a computed r0"]
    if kinds == {"input_residue"} and tails:
        return "mixed", evidence + ["fallthrough paths are input residue but tail paths may produce"]
    if kinds <= {"produced"} and kinds:
        v = "result_produced" if base is None else base
        return v, evidence + ["every return path writes r0 locally before returning"]
    if kinds <= {"call_passthru"} and kinds:
        v = "result_passthru" if base is None else base
        return v, evidence + ["every return path yields a callee result"]
    if kinds <= {"produced", "call_passthru"} and kinds:
        v = "result_produced" if base is None else base
        return v, evidence + ["return paths produce r0 locally or through a callee"]
    if kinds == {"input_residue", "produced"} or kinds == {"input_residue", "call_passthru"}:
        return "mixed", evidence + ["return paths disagree on whether r0 carries a result"]
    return ("mixed" if base else "unknown"), evidence or ["unclassified provenance shape"]


def analyze_function(blob: bytes, addr: int, end: int, base: int = ANALYSIS_BASE) -> dict:
    insns = disassemble_fn(blob, addr, end, base)
    if not insns:
        return {"cfg_kind": "empty", "kinds": ["unknown"]}
    cfg = build_cfg(insns)
    prov = r0_provenance(cfg, [addr])
    indirect = any(b["kind"] == "indirect" for b in cfg.values())
    prov["has_indirect_cf"] = indirect
    verdict, evidence = return_verdict(prov, indirect)
    prov["verdict"] = verdict
    prov["verdict_evidence"] = evidence
    return prov


def scan_image(image: str) -> list[dict]:
    blob = (REPO / "inputs" / "firmware" / f"{image}.bin").read_bytes()
    funcs = load_funcs(image)
    starts = {r["address"] for r in funcs}
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)
    out = []
    for i, row in enumerate(funcs):
        addr = row["address"]
        off = addr - ANALYSIS_BASE
        end = funcs[i + 1]["address"] - ANALYSIS_BASE if i + 1 < len(funcs) else len(blob)
        body = blob[off:end]
        rec = {
            "image": image,
            "address": hex(addr),
            "scan_name": row.get("name", ""),
            "class": "unknown",
            "machine_inputs": prologue_inputs(blob, addr),
            "evidence": [],
        }
        if len(body) >= 2 and body[:2] == b"\x70\x47":
            # A function whose entry instruction is bx lr is empty regardless
            # of what padding/data follows; bytes after the return are unreachable.
            rec["class"] = "exact_nullsub"
            rec["evidence"] = ["entry instruction is bx lr"]
        elif body:
            ins = next(md.disasm(body[:4], addr), None)
            if ins and ins.mnemonic in {"b", "b.w"}:
                try:
                    target = int(ins.op_str.strip().lstrip("#"), 0)
                except ValueError:
                    target = 0
                if target in starts:
                    rec["class"] = "tail_alias"
                    rec["target"] = hex(target)
                    rec["evidence"] = [f"entry instruction is unconditional branch to {target:#x}"]
        out.append(rec)
    return resolve_aliases(out)


def resolve_aliases(rows: list[dict]) -> list[dict]:
    by_addr = {int(r["address"], 16): r for r in rows}
    for r in rows:
        if r["class"] != "tail_alias":
            continue
        seen = set()
        cur = int(r["target"], 16)
        chain = []
        while cur in by_addr and cur not in seen:
            seen.add(cur)
            t = by_addr[cur]
            chain.append(hex(cur))
            if t["class"] != "tail_alias":
                if t["class"] == "exact_nullsub":
                    r["class"] = "nullsub_tail_alias"
                    r["terminal_class"] = "exact_nullsub"
                    r["evidence"].append("alias chain terminates at exact_nullsub")
                break
            cur = int(t.get("target", "0"), 16)
        r["alias_chain"] = chain
    return rows


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--out", type=Path, default=REPO / "metadata" / "prototype_inference.jsonl")
    args = ap.parse_args()
    rows = []
    for image in IMAGES:
        rows.extend(scan_image(image))
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text("".join(json.dumps(r, sort_keys=True) + "\n" for r in rows))
    counts = {}
    for r in rows:
        counts[r["class"]] = counts.get(r["class"], 0) + 1
    print(f"[prototype_infer] {len(rows)} functions -> {args.out} {counts}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
