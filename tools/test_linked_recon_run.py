#!/usr/bin/env python3
"""Regression tests for the stale-linked-ELF freshness guard.

The dynamic fidelity infrastructure silently produced a false mismatch once
because it executed a stale runtime ELF linked at the wrong base. The guard
must fire whenever the ELF is older than the composed main.c it derives from.
"""
import os
import sys
import tempfile
import unittest
from pathlib import Path
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parent))

import linked_recon_run as lrr


class ElfFreshness(unittest.TestCase):
    def _tree(self, tmp: Path, elf_mtime: int, main_mtime: int | None) -> Path:
        elf = tmp / "full_link_run" / "fmacfw_8800d80_h_u02" / "x.full.elf"
        elf.parent.mkdir(parents=True)
        elf.write_bytes(b"\x7fELF")
        os.utime(elf, (elf_mtime, elf_mtime))
        if main_mtime is not None:
            main_c = tmp / "src" / "fmacfw_h_u02" / "main.c"
            main_c.parent.mkdir(parents=True)
            main_c.write_text("// composed\n")
            os.utime(main_c, (main_mtime, main_mtime))
        return elf

    def test_stale_elf_is_rejected_with_regeneration_command(self):
        with tempfile.TemporaryDirectory() as td:
            tmp = Path(td)
            elf = self._tree(tmp, elf_mtime=1000, main_mtime=2000)
            with mock.patch.object(lrr, "REPO", tmp):
                with self.assertRaises(SystemExit) as cm:
                    lrr.check_elf_freshness(elf)
            self.assertIn("stale linked reconstruction", str(cm.exception))
            self.assertIn("--text-base 0x800000", str(cm.exception))

    def test_fresh_elf_passes(self):
        with tempfile.TemporaryDirectory() as td:
            tmp = Path(td)
            elf = self._tree(tmp, elf_mtime=2000, main_mtime=1000)
            with mock.patch.object(lrr, "REPO", tmp):
                lrr.check_elf_freshness(elf)

    def test_missing_main_c_cannot_be_judged(self):
        with tempfile.TemporaryDirectory() as td:
            tmp = Path(td)
            elf = self._tree(tmp, elf_mtime=1000, main_mtime=None)
            with mock.patch.object(lrr, "REPO", tmp):
                lrr.check_elf_freshness(elf)

    def test_tracked_runtime_elves_are_currently_fresh(self):
        for elf in sorted(lrr.FULL_LINK.glob("*/*.full.elf")):
            lrr.check_elf_freshness(elf)


if __name__ == "__main__":
    unittest.main()
