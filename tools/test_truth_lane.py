import unittest
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
from linked_recon_run import (corpus_outcome, differing_write_registers, first_difference,
                               linked_verdict, summarize_corpus)
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

    def test_linked_verdict_compares_the_whole_write_sequence(self):
        def fp(writes, term="returned", reads=(), left=()):
            seq = [["read", a] for a in reads] + [["write", a] for a, _ in writes]
            return {"termination": term, "left_reconstruction_at": list(left),
                    "periph_write_addrs": sorted({a for a, _ in writes}),
                    "periph_write_sequence": [list(w) for w in writes], "periph_sequence": seq}

        w = [("0x40342248", "0x4000000"), ("0x40342400", "0xffd879")]
        other_value = [("0x40342248", "0x4000000"), ("0x40342400", "0x0")]
        for orig, recon, expected in [
            (fp(w), fp(w), ("PASS", "identical_peripheral_sequence")),
            (fp(w, reads=["0x40342248"]), fp(w), ("PASS", "identical_peripheral_write_sequence")),
            (fp(w), fp(other_value), ("FAIL", "same_write_registers_different_sequence")),
            (fp(w), fp(w[:1]), ("FAIL", "peripheral_writes_differ")),
            (fp(w), fp([], term="capped"), ("FAIL", "linked_run_did_not_return")),
            (fp(w), fp(w, left=["0x120100"]), ("REVIEW", "linked_run_left_reconstruction")),
            (fp(w, term="capped"), fp(w), ("REVIEW", "original_did_not_return")),
            (fp(w), {"termination": "no_symbol"}, ("REVIEW", "target_not_in_linked_image")),
        ]:
            with self.subTest(expected=expected):
                self.assertEqual(linked_verdict(orig, recon), expected)
        self.assertEqual(differing_write_registers(fp(w), fp(other_value)), ["0x40342400"])
        self.assertEqual(differing_write_registers(fp(w), fp(w)), [])

    def test_corpus_outcome_counts_only_comparable_runs(self):
        def fp(writes, term="returned", stopped_in=None):
            return {"termination": term, "stopped_in": stopped_in, "left_reconstruction_at": [],
                    "periph_write_addrs": sorted({a for a, _ in writes}),
                    "periph_write_sequence": [list(w) for w in writes],
                    "periph_sequence": [["write", a] for a, _ in writes]}

        def outcome(orig, recon, writer=None):
            verdict = linked_verdict(orig, recon)[0]
            return corpus_outcome(orig, recon, verdict, first_difference(orig, recon), writer)

        w = [("0x40342248", "0x1"), ("0x40032000", "0x25")]
        text = [("0x40342248", "0x1"), ("0x40032000", "0x64")]
        reg = [("0x40342248", "0x0"), ("0x40032000", "0x25")]
        self.assertEqual(first_difference(fp(w), fp(text)),
                         {"index": 1, "orig": ["0x40032000", "0x25"], "recon": ["0x40032000", "0x64"]})
        self.assertIsNone(first_difference(fp(w), fp(w)))
        rows = [
            (outcome(fp(w), fp(w)), ("MATCH", "identical_peripheral_writes")),
            (outcome(fp(w), fp(text)), ("DIFFER", "console_text")),
            (outcome(fp(w), fp(w[:1])), ("DIFFER", "console_text")),
            (outcome(fp(w), fp(reg), "rf_init"), ("DIFFER", "register_write_in:rf_init")),
            (outcome(fp(w), fp([], "capped", "strlen")), ("DIFFER", "no_return_in:strlen")),
            # no comparison exists: neither counts as a match or a difference
            (outcome(fp(w, "capped"), fp([], "capped", "x")),
             ("NOT_RUN", "original_does_not_return_standalone")),
            (outcome(fp(w, "capped"), fp(w)), ("NOT_RUN", "original_does_not_return_standalone")),
            (outcome(fp(w), {"termination": "no_symbol"}), ("NOT_RUN", "not_in_linked_image")),
            # the firmware's assert trap ends a run like a return does
            (outcome(fp(w, "asserted"), fp(w, "asserted")),
             ("MATCH", "identical_peripheral_writes_up_to_assert_trap")),
            (outcome(fp(w, "asserted"), fp(reg, "asserted"), "rf_init"),
             ("DIFFER", "register_write_in:rf_init")),
            (outcome(fp(w, "asserted"), fp(w)), ("DIFFER", "assert_trap_only_in_original")),
            (outcome(fp(w), fp(w, "asserted")), ("DIFFER", "assert_trap_only_in_reconstruction")),
        ]
        for got, expected in rows:
            with self.subTest(expected=expected):
                self.assertEqual(got, expected)
        summary = summarize_corpus([{"image": "i", "outcome": o, "group": g} for (o, g), _ in rows])
        self.assertEqual(summary["outcomes"], {"DIFFER": 7, "MATCH": 2, "NOT_RUN": 3})
        self.assertEqual(list(summary["groups"]["DIFFER"].items())[0], ("console_text", 2))


if __name__ == "__main__":
    unittest.main()
