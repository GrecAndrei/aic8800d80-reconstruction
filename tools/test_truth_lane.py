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
                self.assertEqual(smoke_verdict(status, rc, writes, real)[0], expected)

    def test_write_free_return_needs_matching_original_footprint(self):
        def orig(addrs=(), writes=(), callee=False, term="returned"):
            return {"termination": term, "self_periph_addrs": list(addrs),
                    "self_periph_write_addrs": list(writes), "callee_periph_write": callee}

        reg = ["0x40200900"]
        for addrs, o, expected in [
            (reg, orig(reg), ("PASS", "original_writes_no_peripheral")),
            ([], orig(), ("PASS", "original_writes_no_peripheral")),
            ([], orig(reg), ("REVIEW", "peripheral_footprint_differs")),
            (reg, orig(reg, reg), ("REVIEW", "original_body_writes_peripheral")),
            ([], orig(callee=True), ("REVIEW", "original_writes_peripheral_only_in_callees")),
            ([], orig(term="capped"), ("REVIEW", "original_body_writes_peripheral")),
            ([], None, ("REVIEW", "no_peripheral_write")),
        ]:
            with self.subTest(addrs=addrs, orig=o):
                self.assertEqual(smoke_verdict("returned", 0, 0, True, addrs, o), expected)
        self.assertEqual(smoke_verdict("returned", 0, 2, True, reg, orig(reg)),
                         ("REVIEW", "write_absent_from_original_body"))


if __name__ == "__main__":
    unittest.main()
