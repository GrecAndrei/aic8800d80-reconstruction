import unittest
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
from truth_lane_smoke import smoke_verdict
from unicorn_smoke import can_autopage, is_mmio_addr


class TruthLaneTest(unittest.TestCase):
    def test_autopaging_is_not_peripheral_evidence(self):
        for addr in (0, 0x100000, 0x20000100, 0x21000000):
            with self.subTest(addr=hex(addr)):
                self.assertTrue(can_autopage(addr))
                self.assertFalse(is_mmio_addr(addr))
        for addr in (0x40000000, 0x5fffffff, 0xe0000000, 0xe00fffff):
            with self.subTest(addr=hex(addr)):
                self.assertTrue(can_autopage(addr))
                self.assertTrue(is_mmio_addr(addr))
        self.assertFalse(can_autopage(0x60000000))

    def test_verdict_requires_successful_execution_and_peripheral_write(self):
        for status, rc, writes, real, expected in [
            ("returned", 0, 1, True, "PASS"),
            ("returned", 0, 0, True, "REVIEW"),
            ("returned", 0, 1, False, "REVIEW"),
            ("capped", 4, 1, True, "REVIEW"),
            ("fault", 2, 1, True, "FAIL"),
            ("missing_symbol", 3, 0, True, "FAIL"),
            ("returned", 1, 1, True, "FAIL"),
        ]:
            with self.subTest(status=status, rc=rc, writes=writes, real=real):
                self.assertEqual(smoke_verdict(status, rc, writes, real), expected)
