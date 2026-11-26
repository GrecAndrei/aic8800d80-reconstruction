#!/usr/bin/env python3
"""Umbrella-expansion tests for the post-demonolith composed source."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import composed_source


class ComposedSource(unittest.TestCase):
    def test_module_function_markers_are_visible_in_the_logical_monolith(self):
        umbrella = (composed_source.REPO / "src" / "lmacfw_rf_u02" / "main.c").read_text(errors="replace")
        logical = composed_source.load_composed_text("lmacfw_rf_u02")
        self.assertIn('#include "modules/', umbrella)
        self.assertNotIn("// rf_config_load @ 0x126764", umbrella)
        self.assertIn("// rf_config_load @ 0x126764", logical)
        self.assertIn("// osal_int_exit @ 0x1149fc", logical)

    def test_modules_are_expanded_in_umbrella_include_order(self):
        logical = composed_source.load_composed_text("lmacfw_rf_u02")
        first = logical.index("// start @ 0x1001a8")
        rf_config = logical.index("// rf_config_load @ 0x126764")
        self.assertLess(first, rf_config)


if __name__ == "__main__":
    unittest.main()
