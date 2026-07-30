# Repo Reorganization Plan

Drafted after surveying the tree on 2026-06-30. Covers four goals: harness
sprawl, root binaries, IDA wrapper overlap, and stale docs/junk.

**Status:** draft, awaiting user approval. No moves executed.

---

## Current state (the mess)

```
11 harness_v* dirs (Jun 13-15, 2 days):
  v15-v17           production layers (kept)
  v18_oracle/       EMPTY stub (never populated)
  v19               production layer (Hex-Rays)
  v20-v24           coherent struct-recovery pipeline
                      v20 access patterns → v21 cross-ref → v22 more names
                      → v23 annotated C → v24 cross-binary map
  v25/              EMPTY README, but out/ has 21 untracked .json artifacts

6 root-level binaries (3-9 MB each):
  fwapplysynth fwcompose fwcycle fwfinalize fwharden fwimplsynth fwstruct
  - all stale v15-era prebuilts (cmd/ has 14-byte stub cmd subdirs)
  - cmd/fwstruct/ is real source (9 .go files) for the root fwstruct
  - tools/local-bin/ has 3 newer versions of fwcompose/fwcompact/fwimplsynth

2 AGENTS docs:
  agents.md   lowercase, old workflow guide (165 lines, smoke-cycle focused)
  AGENTS.md   uppercase, current pipeline guide (v15-v19)

IDA wrapper sprawl (6 analysis/ dirs):
  analysis/ida_export_wrapper/      <-- duplicates extraction_out/ida_export/
  analysis/ida_export_wrapper_auto/
  analysis/ida_export_wrapper_db/
  analysis/ida_export_cfg_wrapper/  <-- duplicates extraction_out/ida_export_cfg/
  analysis/ida_headless/            <-- duplicates harness_v19/idb/
  analysis/ida/                     <-- IDB scratch + autosave junk
  analysis/recon_ida_wrapper{,2}/   <-- more wrappers

extraction_out/   15 GB total, mostly gitignored
  - mega7/ (6.1G), reconstruction/ (5.2G), runs/ (2.9G), reconstruction_small/ (634M)
  - dashboard/ (8.7M), ida_export_*/ (small)
  - dashboard.nohup.log (4 KB) - looks stale
internal/         has 11 sub-packages, 4 empty stubs (annotate/diff/ivt/
                  and one more), but the real internal/reconstruct/ +
                  internal/decompile/ + internal/structs/ are live
```

---

## Goal 1: Flatten harness_v* sprawl

### A. Delete empty stubs
```
rmdir harness_v18_oracle/                          # empty since creation
rm -rf harness_v25/                                # empty + only untracked output
```

### B. Promote v18_oracle intent — it was meant to be a layer, not a stub
v18's real source lives in `harness_v17/disasm_to_asm.py` (per AGENTS.md:
"see `harness_v17/disasm_to_asm.py` for v18"). So `v18_oracle/` was an
exploration that got abandoned. **Action:** drop it (already empty).

### C. Group v20-v24 as one pipeline family
Each has scripts/, SUMMARY.json, README.md and a distinct role. Rather
than renaming, mark them as a **family** in docs/REPO_LAYOUT.md:

```
harness_v20/   struct discovery (access patterns)
harness_v21/   struct cross-reference
harness_v22/   expanded struct names
harness_v23/   annotated v19 C + field invariants
harness_v24/   cross-binary function map
```

Each one is the input to the next. This is fine as-is, no rename. Just
need to:
- Add cross-links in each README ("Builds on v19, feeds v21")
- Add a top-level `harness_v20_v24/README.md` (NEW) describing the
  struct-recovery family

### D. v25 verdict
`harness_v25/out/` has 21 untracked .json files (callgraph, clusters,
funcs, magic, initpath, structs_summary per binary + 1 diff). No source,
no README. This is in-flight work. **Action:**
- Either: name it (e.g., rename to `harness_v26_callgraph/`, add a
  README + scripts dir, then commit the json output)
- Or: drop it entirely (the 21 json files can be regenerated from cmd/fwstruct/)

Recommend option 2 (drop) — v25 has no source code to regenerate it,
but the same outputs exist in `cmd/fwstruct/` and would reappear under
a v26 run that *is* scripted.

---

## Goal 2: Root binary cleanup

### A. Move `cmd/fwstruct/` source to a tracked location
```
git add cmd/fwstruct/   # 9 .go files, currently untracked
```

### B. Decide what to do with the 6 root binaries
Each root binary (fwapplysynth, fwcycle, etc.) has a 14-byte stub in
`cmd/` that's the *intended* source. Three options:

| Option | What it means | Cost |
|--------|---------------|------|
| **Keep + regitignore** | Already gitignored via `/fw*` rule. Leave alone. | 0 |
| **Move to bin/** | `mkdir bin/ && git mv fw* bin/`; standard Go convention. | Small ref to README |
| **Delete** | They're stale v15 builds. Recompile from cmd/ when needed. | Safe (gitignored) |

Recommend **Move to bin/** — it's the Go idiom, frees the root, and
preserves the artifacts in case someone wants to diff old vs new builds.

### C. tools/local-bin/ duplicates
Three binaries there (`fwcompact`, `fwcompose`, `fwimplsynth`) are
**different builds** (different md5, different sizes) than the root
versions. They're newer (May 22-23 vs Jun 7-15). **Action:**
- Move them into `bin/` alongside the others, OR
- Delete them if `cmd/fwcompact/`, `cmd/fwcompose/`, `cmd/fwimplsynth/`
  can regenerate them from source

Recommend: keep newer ones in `bin/`, delete older root duplicates.
But: check first whether any cmd/*.go source actually exists for the
three tools/local-bin builds (some cmd/ dirs are 14-byte stubs only).

---

## Goal 3: IDA wrapper consolidation

The 6 `analysis/` subdirs are 5+ duplicate IDA wrappers. Plan:

```
analysis/
├── ida/                          # KEEP: IDB scratch + autosave (gitignored via *.i64)
├── ida_headless/                 # KEEP: legacy headless log (1 KB text)
├── ida_export_wrapper/           # DELETE: dup of extraction_out/ida_export/
├── ida_export_wrapper_auto/      # DELETE: empty wrapper
├── ida_export_wrapper_db/        # DELETE: empty wrapper
├── ida_export_cfg_wrapper/       # DELETE: dup of extraction_out/ida_export_cfg/
├── recon_ida_wrapper/            # KEEP if scripts present, else delete
└── recon_ida_wrapper2/           # KEEP if scripts present, else delete
```

Need to verify whether `recon_ida_wrapper*` have real scripts before
deciding. (Inspect first.)

---

## Goal 4: Trim stale files & docs

### A. Rename lowercase `agents.md` to make its purpose clear
- `agents.md` is the OLD workflow guide (smoke-loop, fwextract focus)
- `AGENTS.md` is the NEW pipeline guide (harness v15-v19, IDA setup)
- **Action:** rename `agents.md` → `agents_workflow.md` (lowercase
  preserved to mark historical). Add a pointer in AGENTS.md saying
  "for the older workflow guide, see agents_workflow.md".

Actually on reflection — the old guide is **about** the v15-v18 era
work, and the new guide is about the v19+ era. Both are useful as
historical record. Cleanest fix:
- Keep both
- Rename `agents.md` → `WORKFLOW_LEGACY.md` (uppercase, descriptive)
- Add a one-line breadcrumb at top of AGENTS.md

### B. Remove empty `internal/` stubs
```
internal/annotate/   empty
internal/diff/       empty
internal/ivt/        empty
```
rmdir each (after confirming truly empty with `ls -la`).

### C. Clear `tmp/opencode/` session scratch
- `tmp/` is gitignored, so not a git issue
- But it's 378 MB on disk; ask user if safe to wipe

### D. Tighten .gitignore
Current rules are decent. Gaps I noticed:
- `harness_v21/out/`, `harness_v22/out/`, `harness_v23/out/` not in
  gitignore (these don't exist, but if regenerated they should be)
- `harness_v25/` not mentioned at all
- `cmd/fwstruct/` untracked but should be tracked
- Internal scratch like `internal/structs/cache` not covered

Add:
```
# v20-v24 generated outputs (regenerate from scripts)
harness_v20/access_patterns/
harness_v20/structs/
harness_v21/field_map/
harness_v22/field_map/
harness_v22/structs/
harness_v23/annotated/
harness_v23/FIELD_INVARIANTS.json
harness_v24/*.json
```

### E. extraction_out/ size (15 GB)
Already gitignored. But worth a one-time prune of the largest dirs:
- `mega7/` (6.1G) — what is this? Inspect before any prune
- `reconstruction/` (5.2G), `runs/` (2.9G) — recon artifacts, may be
  re-runnable

**Don't prune yet** — need user confirmation on what to keep vs
discard. Add to "ask user" list.

---

## Execution order (after approval)

1. **Inspect** `analysis/recon_ida_wrapper*/` for real scripts → decide keep/delete
2. **Inspect** `extraction_out/mega7/` and `reconstruction/` first 2 files → confirm re-runnable
3. **Verify** `cmd/fwcompact/`, `cmd/fwcompose/`, `cmd/fwimplsynth/` have .go sources
4. **git add cmd/fwstruct/** (8 untracked .go files → track)
5. **`git mv agents.md docs/WORKFLOW_LEGACY.md`** (track historical doc)
6. **`rmdir harness_v18_oracle/`** + **`rm -rf harness_v25/`**
7. **`rmdir internal/annotate internal/diff internal/ivt`** (after empty confirm)
8. **`mkdir bin/ && git mv fw* bin/`** (root binaries)
9. **Decide** `tools/local-bin/fw*` per-binary: move to bin/ or delete
10. **`rm -rf analysis/ida_export_wrapper{,_auto,_db}/ analysis/ida_export_cfg_wrapper/`**
    (after confirming dup with extraction_out/)
11. **Delete** stale `extraction_out/dashboard.nohup.log` (4 KB, old)
12. **Update** `docs/REPO_LAYOUT.md` to reflect new layout
13. **Update** `.gitignore` with new rules
14. **Add** `harness_v20_v24/README.md` family overview
15. **Commit** in 4 logical chunks:
    - `chore: track cmd/fwstruct source + move historical agents.md`
    - `chore: drop empty harness_v18_oracle + harness_v25 stubs`
    - `chore: consolidate root binaries into bin/`
    - `chore: prune duplicate IDA wrappers + tighten .gitignore`

---

## Decisions (2026-06-30)

| # | Decision |
|---|----------|
| 1 | `harness_v18_oracle/` + `harness_v25/` — **SKIP** for now, leave alone |
| 2 | Root binaries — move all 6 to `bin/` |
| 3 | `tools/local-bin/fw*` (3 newer) — consolidate into `bin/` |
| 4 | `agents.md` → `docs/WORKFLOW_LEGACY.md` + breadcrumb in AGENTS.md |
| 5 | `analysis/ida_export_wrapper{,_auto,_db}/` + `ida_export_cfg_wrapper/` — DELETE |
| 6 | `extraction_out/` — leave alone (gitignored, possibly irreplaceable) |
| 7 | `tmp/opencode/` — leave (gitignored) |

---

## Final execution order

1. **Verify** `cmd/fwcompact/`, `cmd/fwcompose/`, `cmd/fwimplsynth/` have .go sources
2. **git add cmd/fwstruct/** (track 8 untracked .go files)
3. **`git mv agents.md docs/WORKFLOW_LEGACY.md`** (track historical doc)
4. Add one-line breadcrumb at top of `AGENTS.md`
5. **`rmdir internal/annotate internal/diff internal/ivt`** (empty stubs)
6. **`mkdir bin/`** + **`git mv fwapplysynth fwcompose fwcycle fwfinalize fwharden fwimplsynth fwstruct bin/`**
7. **`mv tools/local-bin/fwcompact tools/local-bin/fwcompose tools/local-bin/fwimplsynth bin/`**
   (then re-verify with `ls bin/`)
8. **`rm -rf analysis/ida_export_wrapper analysis/ida_export_wrapper_auto analysis/ida_export_wrapper_db analysis/ida_export_cfg_wrapper`**
9. **`rmdir extraction_out/dashboard.nohup.log`** (4 KB stale file)
10. **Update** `docs/REPO_LAYOUT.md` — add `bin/` row, drop deleted wrappers, mark `agents.md` rename
11. **Update** `.gitignore` — add `bin/` coverage, v20-v24 generated output dirs
12. **Add** `harness_v20_v24/README.md` family overview (links v20→v24)
13. **Commit** in 4 logical chunks:
    - `chore: track cmd/fwstruct source + rename historical agents.md`
    - `chore: consolidate root + tools/local-bin binaries into bin/`
    - `chore: prune duplicate IDA export wrappers`
    - `docs: update REPO_LAYOUT, add v20-v24 family overview, tighten .gitignore`

**Total moves:** ~25 file ops + 4 commits. Estimated disk delta: -30 MB (root), +30 MB in bin/.

---

## Pre-flight checks (must pass before executing)

- [x] `cmd/fwcompact/`, `cmd/fwcompose/`, `cmd/fwimplsynth/` each contain real `.go` source
      (not 14-byte stubs) — **PASS**: 2.7K, 20K, 263K main.go respectively
- [x] `analysis/recon_ida_wrapper{,2}/` are NOT duplicates — they hold 663 MB
      `recon_union.jsonl` per dir. **KEEP**, do not touch.
- [x] No CI/scripts reference `fwapplysynth` at root — **2 call sites found:**
      - `tools/overnight_behavioral.sh:78` uses absolute `/tmp/opencode/fwapplysynth`
      - `tools/score_truth_lane.py:31` uses `REPO / "fwimplsynth"`
      Both must be updated to `bin/fwapplysynth` / `bin/fwimplsynth`.
- [x] `docs/REPO_LAYOUT.md` references the lowercase `agents.md` (need to update)

## Updated execution order (post pre-flight)

1. **`git add cmd/fwstruct/`** (track 9 untracked .go files)
2. **`git mv agents.md docs/WORKFLOW_LEGACY.md`** + breadcrumb at top of AGENTS.md
3. **`rmdir internal/annotate internal/diff internal/ivt`** (empty stubs)
4. **`mkdir bin/`** + **`git mv fwapplysynth fwcompose fwcycle fwfinalize fwharden fwimplsynth fwstruct bin/`**
5. **`mv tools/local-bin/fwcompact tools/local-bin/fwcompose tools/local-bin/fwimplsynth bin/`**
6. **Fix broken paths:**
   - `tools/overnight_behavioral.sh:78` — `/tmp/opencode/fwapplysynth` → `/tmp/opencode/bin/fwapplysynth`
     (or rewrite as `go run ./cmd/fwapplysynth` for portability)
   - `tools/score_truth_lane.py:31` — `REPO / "fwimplsynth"` → `REPO / "bin" / "fwimplsynth"`
7. **`rm -rf analysis/ida_export_wrapper analysis/ida_export_wrapper_auto analysis/ida_export_wrapper_db analysis/ida_export_cfg_wrapper`**
8. **`rm extraction_out/dashboard.nohup.log`** (4 KB stale file)
9. **Update** `docs/REPO_LAYOUT.md` — add `bin/`, drop deleted wrappers, mark `agents.md` rename
10. **Update** `.gitignore` — add v20-v24 generated output dirs (defensive)
11. **Add** `harness_v20_v24/README.md` family overview
12. **Commit** in 4 chunks (see below)

## 4 commits

1. `chore: track cmd/fwstruct source + move historical agents.md to docs/WORKFLOW_LEGACY.md`
2. `chore: consolidate root + tools/local-bin binaries into bin/`
3. `chore: fix root-binary path references in tools/`
4. `chore: prune duplicate IDA export wrappers + tighten .gitignore`

(Original "docs commit" split into two because path-fix is in tools, not docs.)

---

**Awaiting final go-ahead from user.**