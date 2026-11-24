#!/usr/bin/env python3
"""Machine-grounded prototype inference golden tests."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import prototype_infer


class PrototypeInfer(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.rows = []
        for image in prototype_infer.IMAGES:
            cls.rows.extend(prototype_infer.scan_image(image))
        cls.by_key = {(r["image"], int(r["address"], 16)): r for r in cls.rows}

    def test_exact_nullsub_corpus_is_complete(self):
        rows = [r for r in self.rows if r["class"] == "exact_nullsub"]
        self.assertEqual(len(rows), 32)
        self.assertEqual({r["image"] for r in rows}, set(prototype_infer.IMAGES))
        for image in prototype_infer.IMAGES:
            self.assertEqual(sum(r["image"] == image for r in rows), 8)

    def test_j_nullsub_aliases_resolve_to_exact_nullsubs(self):
        rows = [r for r in self.rows if r["class"] == "nullsub_tail_alias"]
        self.assertEqual(len(rows), 4)
        for row in rows:
            target = self.by_key[(row["image"], int(row["target"], 16))]
            self.assertEqual(target["class"], "exact_nullsub")

    def test_normal_functions_are_not_forced_into_a_type(self):
        row = self.by_key[("fmacfw_8800d80_h_u02", 0x1001A8)]
        self.assertEqual(row["class"], "unknown")


if __name__ == "__main__":
    unittest.main()
