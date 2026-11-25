#!/usr/bin/env python3
"""Regression tests for the linked-ELF provenance guard.

The dynamic fidelity infrastructure silently produced a false mismatch once
because it executed a stale/wrong-base runtime ELF. mtimes cannot prove
freshness (make reproduce rewrites main.c at the compose fixed point), so the
guard is content-hash based: full_link writes a stamp next to the ELF and the
check recomputes the fingerprint of the whole derivation chain.
"""
import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parent))

import linked_recon_run as lrr
import link_freshness as lf


class ElfFreshness(unittest.TestCase):
    def _tree(self, tmp: Path) -> Path:
        elf = tmp / "full_link_run" / "fmacfw_8800d80_h_u02" / "x.full.elf"
        elf.parent.mkdir(parents=True)
        elf.write_bytes(b"\x7fELF")
        (tmp / "src" / "fmacfw_h_u02").mkdir(parents=True)
        (tmp / "src" / "fmacfw_h_u02" / "main.c").write_text("// composed\n")
        (tmp / "src" / "include").mkdir(parents=True)
        (tmp / "src" / "Makefile").write_text("# makefile\n")
        return elf

    def _check(self, tmp: Path, elf: Path):
        with mock.patch.object(lf, "REPO", tmp):
            lrr.check_elf_freshness(elf)

    def test_unstamped_elf_is_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            tmp = Path(td)
            elf = self._tree(tmp)
            with self.assertRaises(SystemExit) as cm:
                self._check(tmp, elf)
            self.assertIn("unstamped", str(cm.exception))
            self.assertIn("--text-base 0x800000", str(cm.exception))

    def test_wrong_base_elf_is_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            tmp = Path(td)
            elf = self._tree(tmp)
            with mock.patch.object(lf, "REPO", tmp):
                lf.write_stamp(elf, elf.parent.name, 0x100000)
            with self.assertRaises(SystemExit) as cm:
                self._check(tmp, elf)
            self.assertIn("wrong-base", str(cm.exception))

    def test_fingerprint_mismatch_is_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            tmp = Path(td)
            elf = self._tree(tmp)
            with mock.patch.object(lf, "REPO", tmp):
                lf.write_stamp(elf, elf.parent.name, lrr.LINK_BASE)
                # inputs change after the stamp was written
                (tmp / "src" / "fmacfw_h_u02" / "main.c").write_text("// edited\n")
            with self.assertRaises(SystemExit) as cm:
                self._check(tmp, elf)
            self.assertIn("stale linked reconstruction", str(cm.exception))

    def test_matching_stamp_passes(self):
        with tempfile.TemporaryDirectory() as td:
            tmp = Path(td)
            elf = self._tree(tmp)
            with mock.patch.object(lf, "REPO", tmp):
                lf.write_stamp(elf, elf.parent.name, lrr.LINK_BASE)
            self._check(tmp, elf)

    def test_tracked_runtime_elves_are_currently_fresh(self):
        elves = sorted(lrr.FULL_LINK.glob("*/*.full.elf"))
        if not elves:
            self.skipTest("no runtime ELFs built")
        for elf in elves:
            lrr.check_elf_freshness(elf)


if __name__ == "__main__":
    unittest.main()
