#!/usr/bin/env python3
"""Unit tests for tools/fidelity_meter.py."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import fidelity_meter as fm


class SerializedRelocationTests(unittest.TestCase):
    def _uart_seq(self, payload: bytes):
        return [["0x40032000", hex(b)] for b in payload]

    def test_proven_serialized_function_pointer_relocation(self):
        orig = self._uart_seq(b", func 0x132a0d unknown\r\n")
        recon = self._uart_seq(b", func 0x818f15 unknown\r\n")
        old = fm.is_equivalent_serialized_code_ptr
        seen = []
        try:
            def proof(o, r, image, elf):
                seen.append((o, r))
                return (o, r) == (0x132A0D, 0x818F15)
            fm.is_equivalent_serialized_code_ptr = proof
            self.assertTrue(fm.equivalent_ordered_mmio_with_reloc(orig, recon, b"", {}))
        finally:
            fm.is_equivalent_serialized_code_ptr = old
        self.assertEqual(seen, [(0x132A0D, 0x818F15)])

    def test_unproven_or_textual_uart_differences_are_not_normalized(self):
        orig = self._uart_seq(b", func 0x132a0d unknown\r\n")
        recon = self._uart_seq(b", func 0x818f15 unknown\r\n")
        old = fm.is_equivalent_serialized_code_ptr
        try:
            fm.is_equivalent_serialized_code_ptr = lambda *args: False
            self.assertFalse(fm.equivalent_ordered_mmio_with_reloc(orig, recon, b"", {}))
        finally:
            fm.is_equivalent_serialized_code_ptr = old

        recon_text = self._uart_seq(b", func 0x132a0d unknowx\r\n")
        self.assertFalse(fm.equivalent_ordered_mmio_with_reloc(orig, recon_text, b"", {}))

    def test_real_lmac_return_site_and_entry_proofs(self):
        import linked_recon_run as lrr
        image = "lmacfw_rf_8800d80_u02"
        elf_path = lrr.FULL_LINK / image / f"{image}.full.elf"
        firmware = fm.REPO / "inputs" / "firmware" / f"{image}.bin"
        if not elf_path.is_file() or not firmware.is_file():
            self.skipTest("linked lmac fixture not built")
        elf = fm.load_elf_info(elf_path, image=image)
        orig_image = firmware.read_bytes()
        # USB-style callback diagnostic: exact function-entry relocation.
        self.assertTrue(fm.is_equivalent_serialized_code_ptr(0x132A0D, 0x818F15, orig_image, elf))
        # Exception dump LR: same enclosing analysis function, both BL
        # fallthroughs, and equivalent immediate call targets.
        self.assertTrue(fm.is_equivalent_serialized_code_ptr(0x133967, 0x82F495, orig_image, elf))
        # Adjacent non-equivalent values must not be accepted merely because
        # they are hexadecimal code-shaped words.
        self.assertFalse(fm.is_equivalent_serialized_code_ptr(0x133967, 0x82F497, orig_image, elf))


class ClosedLoopProofTests(unittest.TestCase):
    def test_countdown_loop_is_not_terminal_proof(self):
        # subs r0,#1; bne start — a finite register countdown must never be
        # promoted to non-returning equivalence merely because it is a loop.
        blob = bytes.fromhex("0138fdd1")
        self.assertIsNone(fm.closed_loop_proof(blob, 0x1000, 0x1002))

    def test_real_assert_allocation_loops_are_terminal_proof(self):
        import linked_recon_run as lrr
        image = "fmacfw_8800d80_u02"
        elf_path = lrr.FULL_LINK / image / f"{image}.full.elf"
        firmware = fm.REPO / "inputs" / "firmware" / f"{image}.bin"
        if not elf_path.is_file() or not firmware.is_file():
            self.skipTest("linked fmac fixture not built")
        elf = fm.load_elf_info(elf_path, image=image)
        orig = firmware.read_bytes()
        # Original shared assert helper: cmp/bne closed loop.
        self.assertEqual(fm.closed_loop_proof(orig, 0x120000, 0x14F48A)["load_count"], 0)
        # Reconstructed inlined allocation-failure path: fixed-address RAM
        # load + cmp/bne. The fixed base is not rewritten and the loaded value
        # is never used as a pointer, so the value is invariant in the closed
        # machine model.
        self.assertEqual(fm.closed_loop_proof(elf["blob"], elf["base"], 0x8126EA)["load_count"], 1)
        self.assertTrue(fm.terminal_closed_loop_proof(orig, elf, 0x14F48A, 0x8126EA, [], []))
        # A peripheral read inside either loop would make the proof unsound
        # because the MMIO model may be autonomous.
        self.assertFalse(
            fm.terminal_closed_loop_proof(orig, elf, 0x14F48A, 0x8126EA, [], ["0x8126e6"])
        )


class MachineInputDomainScanTests(unittest.TestCase):
    def scan(self, image, key):
        return fm.machine_deref_params(str(fm.REPO / "inputs" / "firmware" / f"{image}.bin"), key)

    def test_cfg_scan_skips_literal_pool_bytes(self):
        # process_debug_char's inline literal pool decodes as spurious stores
        # when swept linearly. Direct control flow never reaches those bytes,
        # so the fault-character scalar input is not a machine memory base.
        self.assertEqual(self.scan("fmacfw_8800d80_h_u02", 0x115250), frozenset())

    def test_libc_pointer_scans_remain_precise(self):
        self.assertEqual(self.scan("fmacfw_8800d80_h_u02", 0x100200), frozenset({0}))  # memset
        self.assertEqual(self.scan("fmacfw_8800d80_h_u02", 0x143630), frozenset({0, 1}))  # memcpy

    def test_machine_contract_hits_used_by_invalid_input_classification(self):
        img = "lmacfw_rf_8800d80_u02"
        path = str(fm.REPO / "inputs" / "firmware" / f"{img}.bin")
        self.assertEqual(fm.machine_deref_params(path, 0x11F594), frozenset({0}))
        self.assertEqual(fm.machine_index_params(path, 0x11F594), frozenset({1, 2}))
        fmac = str(fm.REPO / "inputs" / "firmware" / "fmacfw_8800d80_h_u02.bin")
        self.assertEqual(fm.machine_deref_params(fmac, 0x141C0C), frozenset({0}))
        self.assertEqual(fm.machine_index_params(fmac, 0x141C0C), frozenset({1}))
        # bsscfg_index strength-reduces 28*a2 to shifted rsb/add addressing
        # and uses a later prologue MLA for 1320*a1. Both forms are machine
        # scalar/index evidence, so large pointer-shaped probe values are not
        # valid inputs merely because they are mapped memory.
        self.assertEqual(fm.machine_index_params(fmac, 0x128748), frozenset({0, 1}))


class ValidInputProbeTests(unittest.TestCase):
    def test_rf_mem_read_machine_valid_input_exactly_matches(self):
        """Deep valid-input evidence for the rf_mem_read truth-lane target.

        The machine entry checks count != 0 and width in {1,2,4}, aligns and
        dereferences r0 as the memory base, and multiplies count by width.
        r0=SRAM_NODE_A (4-aligned seeded RAM), r1=4, r2=4, r3=0 is therefore
        inside the machine-proven input domain, unlike the corpus stress rows
        that pass a wild base or a pointer-shaped count.
        """
        import aic8800d80_emulator as emu
        import composed_source
        import corpus_sweep as cs
        import linked_recon_run as lrr
        import prototype_infer
        from unicorn.arm_const import UC_ARM_REG_R0

        image = "lmacfw_rf_8800d80_u02"
        elf_path = lrr.FULL_LINK / image / f"{image}.full.elf"
        firmware = fm.REPO / "inputs" / "firmware" / f"{image}.bin"
        if not elf_path.is_file() or not firmware.is_file():
            self.skipTest("linked lmac fixture not built")
        key = 0x11F594
        args = (fm.SRAM_NODE_A, 4, 4, 0)
        img_path = emu.resolve_image(image)
        model = emu.load_mmio_model()
        bootstate = cs.capture_bootstate(image, 300000)
        elf = fm.load_elf_info(elf_path, image=image)
        short = lrr.SHORT[image]
        parsed = fm.parse_composed_functions(composed_source.load_composed_text(short))
        meta = parsed[key]

        def run_one(recon: bool):
            plat = emu.Aic8800D80Platform(img_path, mmio_model=model)
            plat.counter_by_reads = lrr.COUNTER_TICKS_PER_READ
            plat._free_entries = ()
            if recon:
                plat._map_rwx(lrr.LINK_BASE, lrr.LINK_SPAN)
                plat.mu.mem_write(lrr.LINK_BASE, elf["blob"])
                plat.function_table = elf["funcs"]
                fm.relocate_image_function_pointers(plat, elf, emu.load_function_table(image))
            else:
                plat.function_table = emu.load_function_table(short)
            cs.apply_bootstate(
                plat.mu,
                fm.relocate_bootstate_for_recon(bootstate, elf) if recon else bootstate,
            )
            fm.seed_sram_pointers(plat.mu)
            fm._set_args(plat.mu, args)
            sp = plat.ivt()["stack_pointer"]
            if recon:
                saved = emu.CHIP_BASE
                emu.CHIP_BASE, plat.image = lrr.LINK_BASE, elf["blob"]
                try:
                    term, _stats = plat.run(elf["by_name"][meta["marker"]], 100000, sp=sp, assert_stops=True)
                finally:
                    emu.CHIP_BASE = saved
            else:
                term, _stats = plat.run(key + emu.HW_OFFSET, 100000, sp=sp, assert_stops=True)
            fp = lrr.fingerprint(plat.traffic)
            return term, fp, int(plat.mu.reg_read(UC_ARM_REG_R0)) & 0xFFFFFFFF

        oterm, ofp, or0 = run_one(False)
        rterm, rfp, rr0 = run_one(True)
        self.assertEqual((oterm, rterm), ("returned", "returned"))
        self.assertEqual(len(ofp["periph_write_sequence"]), 47)
        self.assertEqual(ofp["periph_write_sequence"], rfp["periph_write_sequence"])
        self.assertEqual(or0, rr0)
        uart = bytes(
            int(v, 16) & 0xFF for a, v in ofp["periph_write_sequence"]
            if int(a, 16) == 0x40032000
        )
        self.assertEqual(uart, b"20002200: 00000000 00000000 00000003 00000001\r\n")


class StaticScannerTests(unittest.TestCase):
    def test_splits_params_and_varargs(self):
        self.assertEqual(fm._split_params(""), (None, False))
        self.assertEqual(fm._split_params("void"), (0, False))
        self.assertEqual(fm._split_params("int a, const char *b"), (2, False))
        self.assertEqual(fm._split_params("int (*cb)(int, int), int n"), (2, False))
        self.assertEqual(fm._split_params("const char *fmt, ..."), (1, True))

    def test_counts_balanced_call_args(self):
        s = "foo(a + bar(1, 2), \"x,y\", ')', (b, c))"
        idx = s.index("(")
        self.assertEqual(fm._count_call_args(s, idx), (4, len(s) - 1))
        self.assertEqual(fm._count_call_args("g()", 1), (0, 2))

    def test_detects_under_arity_cast_call(self):
        src = (
            "// foo @ 0x100100\n"
            "int foo(int a1, int a2, int a3) {\n"
            "  return a1 + a2 + a3;\n"
            "}\n"
            "// bar @ 0x100120\n"
            "void bar(int x) {\n"
            "  ((int (*)())foo)(x);\n"
            "}\n"
        )
        funcs = fm.parse_composed_functions(src)
        self.assertFalse(funcs[0x100100]["is_void"])
        self.assertTrue(funcs[0x100120]["is_void"])
        self.assertEqual(funcs[0x100100]["param_count"], 3)

        body = funcs[0x100120]["body"]
        m = fm.CAST_CALL_PREFIX_RE.search(body)
        self.assertIsNotNone(m)
        self.assertEqual(m.group(1), "foo")
        passed, _ = fm._count_call_args(body, m.end() - 1)
        self.assertEqual(passed, 1)

    def test_parses_fn_pointer_params_and_libmatch_markers(self):
        src = (
            "// rf_check_rssi @ 0x119f10\n"
            "int rf_check_rssi(int a1, void ( **a2)(int), unsigned int a3) {\n"
            "  return a1;\n"
            "}\n"
            "// double_subtract @ 0x1272b0\n"
            "/* libmatch: 634 bytes identical to __aeabi_dsub (libgcc.a:_arm_addsubdf3.o); the library routine is linked */\n"
        )
        funcs = fm.parse_composed_functions(src)
        self.assertIn(0x119F10, funcs)
        self.assertIn(0x1272B0, funcs)
        self.assertTrue(funcs[0x119F10]["has_c_body"])
        self.assertEqual(funcs[0x119F10]["param_count"], 3)
        self.assertFalse(funcs[0x1272B0]["has_c_body"])
        self.assertTrue(funcs[0x1272B0]["libmatch_linked"])
        self.assertFalse(funcs[0x1272B0]["libmatch_dropped"])
        self.assertEqual(funcs[0x1272B0]["libmatch_target"], "__aeabi_dsub")
        meta = fm.build_func_meta(funcs, {})
        self.assertEqual(meta[0x1272B0]["libmatch_target"], "__aeabi_dsub")
        self.assertTrue(meta[0x1272B0]["libmatch_linked"])


class RamAndVerdictTests(unittest.TestCase):
    def _mk(self, term="returned", r0=0, mmio=(), ram=None, elf=None, stack_lo=0x19FE00):
        return {
            "termination": term,
            "r0": r0,
            "periph_write_sequence": list(mmio),
            "ram_bytes": dict(ram or {}),
            "elf_bytes": dict(elf or {}),
            "stack_lo": stack_lo,
            "sp_init": 0x1A0000,
        }

    def test_stack_frames_ignored_while_globals_compared(self):
        # Stack frame slot 0x19FE80 differs between orig and recon (stack_lo=0x19FE00),
        # while global write 0x182B60 matches.
        orig = self._mk(ram={0x19FE80: 0xAA, 0x182B60: 0x11}, stack_lo=0x19FF00)
        recon = self._mk(ram={0x19FE80: 0x55, 0x182B60: 0x11}, stack_lo=0x19FE00)
        v_ok = fm.evaluate_vector_pair(orig, recon, is_void=False)
        self.assertEqual(v_ok["status"], "MATCH")
        self.assertTrue(v_ok["ram_match"])
        self.assertTrue(v_ok["exercised"])

        # Global mismatch must fail even when MMIO matches.
        recon_bad = self._mk(ram={0x182B60: 0x22}, stack_lo=0x19FE00)
        v = fm.evaluate_vector_pair(orig, recon_bad, is_void=False)
        self.assertEqual(v["status"], "DIFFER")
        self.assertEqual(v["reason"], "ram_differ")
        self.assertTrue(v["mmio_match"])
        self.assertFalse(v["ram_match"])

    def test_void_ignores_r0_while_nonvoid_checks_r0(self):
        orig = self._mk(r0=0x1234)
        recon = self._mk(r0=0x5678)
        v_void = fm.evaluate_vector_pair(orig, recon, is_void=True)
        self.assertEqual(v_void["status"], "MATCH")
        self.assertFalse(v_void["exercised"])

        v_nonvoid = fm.evaluate_vector_pair(orig, recon, is_void=False)
        self.assertEqual(v_nonvoid["status"], "DIFFER")
        self.assertEqual(v_nonvoid["reason"], "r0_differ")
        self.assertTrue(v_nonvoid["mmio_match"])

    def test_non_trivial_r0_counts_as_exercised(self):
        orig = self._mk(r0=1)
        recon = self._mk(r0=1)
        v = fm.evaluate_vector_pair(orig, recon, is_void=False)
        self.assertEqual(v["status"], "MATCH")
        self.assertTrue(v["exercised"])

    def test_nonreturn_ordered_write_prefix_is_partial_evidence(self):
        # Both sides capped: a non-empty exact prefix is comparable partial
        # evidence, distinct from both a full MATCH and neutral NOT_RUN.
        v = fm.evaluate_outcomes(
            "capped", 0, [["0x40032000", "1"], ["0x40032000", "2"]],
            "capped", 0, [["0x40032000", "1"]], None, [], True, False, False, None,
            is_void=False,
        )
        self.assertEqual(v["status"], "PREFIX_MATCH")
        self.assertEqual(v["reason"], "nonreturn_write_prefix")
        self.assertTrue(v["exercised"])
        self.assertEqual(v["shared_write_prefix"], 1)

        # A mismatch at the same ordinal position remains a genuine difference.
        v = fm.evaluate_outcomes(
            "capped", 0, [["0x40032000", "1"]],
            "capped", 0, [["0x40032000", "2"]], None, [], True, False, False, None,
            is_void=False,
        )
        self.assertEqual(v["status"], "DIFFER")
        self.assertEqual(v["reason"], "mmio_differ")

        # Empty/non-empty asymmetry is timing-inconclusive, not evidence.
        v = fm.evaluate_outcomes(
            "capped", 0, [["0x40032000", "1"]],
            "capped", 0, [], None, [], True, False, False, None,
            is_void=False,
        )
        self.assertEqual(v["status"], "NOT_RUN")
        self.assertEqual(v["reason"], "nonreturn_inconclusive")

        # If the reconstruction returned, missing original writes cannot be
        # excused as cap timing.
        v = fm.evaluate_outcomes(
            "capped", 0, [["0x40032000", "1"]],
            "returned", 0, [], None, [], True, False, False, None,
            is_void=False,
        )
        self.assertEqual(v["status"], "DIFFER")

    def test_machine_nullsub_excludes_r0_without_counting_as_exercised(self):
        v = fm.evaluate_outcomes(
            "returned", 0x1234, [], "returned", 0, [], None, [], True, False, False, None,
            is_void=False, is_void_ub=True, r0_exclude=True,
        )
        self.assertEqual(v["status"], "MATCH")
        self.assertFalse(v["exercised"])

    def test_64bit_results_compare_and_exercise_high_word(self):
        v = fm.evaluate_outcomes(
            "returned", 1, [], "returned", 1, [], None, [], True, False, False, None,
            is_void=False, orig_r1=0x12345678, recon_r1=0x12345678, return_width=64,
        )
        self.assertEqual(v["status"], "MATCH")
        self.assertTrue(v["exercised"])

        v = fm.evaluate_outcomes(
            "returned", 1, [], "returned", 1, [], None, [], True, False, False, None,
            is_void=False, orig_r1=0x12345678, recon_r1=0, return_width=64,
        )
        self.assertEqual(v["status"], "DIFFER")
        self.assertEqual(v["reason"], "r1_differ")
        self.assertFalse(v["r1_match"])

        # The same r1 difference is irrelevant to a 32-bit result contract.
        v = fm.evaluate_outcomes(
            "returned", 1, [], "returned", 1, [], None, [], True, False, False, None,
            is_void=False, orig_r1=0x12345678, recon_r1=0, return_width=32,
        )
        self.assertEqual(v["status"], "MATCH")

    def test_abi_return_widths(self):
        self.assertEqual(fm.abi_return_width("uint64_t"), 64)
        self.assertEqual(fm.abi_return_width("volatile uint64_t *"), 32)
        self.assertEqual(fm.abi_return_width(None, "__aeabi_dmul"), 64)
        self.assertEqual(fm.abi_return_width(None, "__aeabi_d2uiz"), 32)

    def test_exact_peripheral_reads_are_evidence_not_a_pass_criterion(self):
        reads = [["0x40500010", "0x1"]]
        v = fm.evaluate_outcomes(
            "returned", 0, [], "returned", 0, [], None, [], True, False, False, None,
            is_void=False, orig_mmio_reads=reads, recon_mmio_reads=reads,
        )
        self.assertEqual(v["status"], "MATCH")
        self.assertTrue(v["read_evidence"])
        self.assertTrue(v["exercised"])

        # Unequal polling frequency does not fail the row, but also cannot be
        # counted as exercised evidence.
        v = fm.evaluate_outcomes(
            "returned", 0, [], "returned", 0, [], None, [], True, False, False, None,
            is_void=False, orig_mmio_reads=reads, recon_mmio_reads=reads + reads,
        )
        self.assertEqual(v["status"], "MATCH")
        self.assertFalse(v["read_evidence"])
        self.assertFalse(v["exercised"])

    def test_narrow_abi_vector_arguments_are_normalized(self):
        self.assertEqual(
            fm.normalize_abi_args((0xFFFFFFFF, 0xFFFFFF80, 0x12345678, 0), ["uint8_t a1", "int8_t a2"]),
            (0xFF, 0xFFFFFF80, 0x12345678, 0),
        )
        self.assertEqual(fm._split_params("void"), (0, False))
        self.assertEqual(fm._split_params(""), (None, False))


    def test_void_ub_detection_and_reason_split(self):
        src = (
            "// rf_phy_irq @ 0x10d44c\n"
            "int rf_phy_irq() {\n"
            "  int result; // r0\n"
            "  return result;\n"
            "}\n"
            "// real_ret @ 0x10d480\n"
            "int real_ret(int x) {\n"
            "  return x + 1;\n"
            "}\n"
        )
        funcs = fm.parse_composed_functions(src)
        self.assertTrue(funcs[0x10D44C]["is_void_ub"])
        self.assertFalse(funcs[0x10D480]["is_void_ub"])
        v_ub = fm.evaluate_outcomes(
            "returned", 1, [], "returned", 0, [], None, [], True, False, False, None,
            is_void=False, is_void_ub=True,
        )
        self.assertEqual(v_ub["reason"], "r0_void_ub")
        v_real = fm.evaluate_outcomes(
            "returned", 1, [], "returned", 0, [], None, [], True, False, False, None,
            is_void=False, is_void_ub=False,
        )
        self.assertEqual(v_real["reason"], "r0_differ")


        self.assertEqual(v_real["reason"], "r0_differ")

    def test_interior_libmatch_fragments_are_structural_not_never_comparable(self):
        def row(libdrop=False):
            return {
                "image": "fmacfw_h_u02", "address": "0x1000", "function": "x",
                "machine_class": "unknown", "libmatch_dropped": libdrop,
                "vectors": {v: {"status": "NOT_RUN", "reason": "not_in_linked_image"}
                            for v in fm.DEFAULT_VECTORS},
            }
        out = fm.summarize_rows([row(True), row(False)], fm.DEFAULT_VECTORS)
        self.assertEqual(out["aggregate"]["interior_libmatch_fragment"], 1)
        self.assertEqual(out["aggregate"]["never_comparable"], 1)
        self.assertIn("interior_fragment_parent_coverage", out)
        self.assertIn("prefix_nonreturn_classification", out)

    def test_softfp_nan_vector_is_default_and_quiet_nan_shaped(self):
        self.assertIn("boot_double_nan", fm.DEFAULT_VECTORS)
        cfg = fm.ALL_VECTORS["boot_double_nan"]
        self.assertEqual(cfg["args"], (0, 0x7FF80000, 0, 0x3FF80000))
        self.assertTrue(cfg["bootstate"])
        self.assertFalse(cfg["sram_seed"])

    def test_prefix_nonreturn_reason_taxonomy_is_explicit(self):
        def prefix_row(reason):
            return {
                "image": "fmacfw_h_u02", "address": "0x2000", "function": "x",
                "machine_class": "unknown", "libmatch_dropped": False,
                "vectors": {v: {"status": "PREFIX_MATCH", "reason": reason, "exercised": True}
                            for v in fm.DEFAULT_VECTORS},
            }
        out = fm.summarize_rows([prefix_row("nonreturn_exact_write_sequence")], fm.DEFAULT_VECTORS)
        cls = out["prefix_nonreturn_classification"]
        self.assertEqual(cls["row_reason_shapes"], {"nonreturn_exact_write_sequence": 1})
        self.assertEqual(cls["vector_reasons"]["nonreturn_exact_write_sequence"], len(fm.DEFAULT_VECTORS))
        self.assertIn("future writes unproven", cls["legend"]["nonreturn_exact_write_sequence"])

    def test_relocated_cstr_and_fn_ptr_match(self):
        orig_img = b"\x00" * 0x100 + b"adjust xtal_cap: tgt=0x%x\n\x00"
        blob = b"\x00" * 0x200 + b"adjust xtal_cap: tgt=0x%x\n\x00"
        elf_info = {
            "base": 0x800000,
            "blob": blob,
            "mem_end": 0x810000,
            "orig_fn_by_hw_addr": {0x120040: "isr_a"},
            "recon_fn_by_addr": {0x800080: "isr_a", 0x8000C0: "isr_b"},
            "rodata_range": (0x800100, 0x800300),
        }
        orig_str = 0x120100
        recon_str = 0x800200
        self.assertTrue(fm.is_equivalent_reloc_ptr(orig_str, recon_str, orig_img, elf_info))
        self.assertTrue(fm.is_equivalent_reloc_ptr(0x120041, 0x800081, orig_img, elf_info))
        self.assertFalse(fm.is_equivalent_reloc_ptr(0x120041, 0x8000C1, orig_img, elf_info))

        res = fm.evaluate_outcomes(
            "returned", orig_str, [], "returned", recon_str, [],
            None, [], True, False, False, None,
            is_void=False, is_void_ub=False, orig_image=orig_img, elf_info=elf_info,
        )
        self.assertEqual(res["status"], "MATCH")
        self.assertEqual(res["reason"], "reloc_ptr_match")

    def test_bootstate_function_pointer_relocation_is_exact(self):
        bs = {
            0x2000: (4, 0x132A0D),
            0x2004: (4, 0xDEADBEEF),
            0x2008: (2, 0x132A),
        }
        elf = {"recon_analysis_by_addr": {0x831000: 0x112A0C}}
        out = fm.relocate_bootstate_for_recon(bs, elf)
        self.assertEqual(out[0x2000], (4, 0x831001))
        self.assertEqual(out[0x2004], (4, 0xDEADBEEF))
        self.assertEqual(out[0x2008], (2, 0x132A))


if __name__ == "__main__":
    unittest.main()
