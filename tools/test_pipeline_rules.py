#!/usr/bin/env python3
"""Tests for the mechanical source rules: volatile_pointees, libmatch, deref_two_d, callsite_targets."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import absolute_memory
import arm_shifts
import asm_returns
import call_cast_returns
import double_args
import dword_compares
import float_bits
import float_compares
import heal_composed
import stack_frames
import callsite_targets
import libmatch
import periph_symbols
import post_compose
import signed_halfwords
import signed_muls
import volatile_pointees
from convert_decompiled_to_functions import convert_to_c99, deref_two_d


class AbsoluteMemory(unittest.TestCase):
    def test_constant_memory_accesses_become_absolute_memd_lvalues(self):
        src = ('  v0 = (MEMORY[0x100000] & 1) == 0;\n'
               '  MEMORY[0] = (int)(uintptr_t)(v5);\n'
               '  return ((int (*)())MEMORY[0x1FC])(27);\n')
        out, n, unsupported = absolute_memory.rewrite(src)
        self.assertEqual((n, unsupported), (3, []))
        self.assertIn('MEMD(0x100000)', out)
        self.assertIn('MEMD(0) =', out)
        self.assertIn('((int (*)())MEMD(0x1FC))(27)', out)
        self.assertNotIn('MEMORY[', out)
        self.assertEqual(absolute_memory.rewrite(out), (out, 0, []))

    def test_decimal_and_nonconstant_subscripts(self):
        out, n, unsupported = absolute_memory.rewrite('x = MEMORY[508]; y = MEMORY[i]; z = MEMD(508);')
        self.assertEqual(n, 2)
        self.assertEqual(unsupported, ['i'])
        self.assertIn('x = MEMD(0x1FC);', out)
        self.assertIn('z = MEMD(0x1FC);', out)
        self.assertIn('MEMORY[i]', out)

    def test_comments_and_strings_are_not_rewritten(self):
        src = '// MEMORY[0x1FC]\ns = "MEMORY[0]"; x = MEMORY[ 0x1fc ];\n'
        out, n, unsupported = absolute_memory.rewrite(src)
        self.assertEqual((n, unsupported), (1, []))
        self.assertIn('// MEMORY[0x1FC]', out)
        self.assertIn('"MEMORY[0]"', out)
        self.assertIn('x = MEMD(0x1FC);', out)


class VolatilePointees(unittest.TestCase):
    def test_qualifies_scalar_pointees_once(self):
        src = "  uint32_t *v0;\n  x = *((_BYTE *)p + 1);\n"
        out, n = volatile_pointees.qualify(src)
        self.assertEqual(n, 2)
        self.assertIn("volatile uint32_t *v0", out)
        self.assertIn("(volatile _BYTE *)p", out)
        self.assertEqual(volatile_pointees.qualify(out), (out, 0))

    def test_leaves_comments_strings_and_struct_pointers(self):
        src = '// uint32_t *a\n  s = "char *b";\n  struct foo *c;\n  /* int *d */\n'
        self.assertEqual(volatile_pointees.qualify(src), (src, 0))


class DerefTwoD(unittest.TestCase):
    def test_bare_subscript_is_a_byte_load(self):
        out = convert_to_c99("v42 = off_11F4A0[0][v40 >> 4];")
        self.assertEqual(out, "v42 = *((uint8_t *)(uintptr_t)off_11F4A0[0] + (v40 >> 4));")

    def test_lobyte_hibyte_use_the_element_width(self):
        self.assertEqual(convert_to_c99("v = HIBYTE(off_11EF28[v13][0]);"),
                         "v = *((uint8_t *)(uintptr_t)off_11EF28[v13] + (3));")
        self.assertEqual(convert_to_c99("v = LOBYTE(off_11EF28[v13][1]);"),
                         "v = *((uint8_t *)(uintptr_t)off_11EF28[v13] + (4));")

    def test_unknown_width_is_an_error(self):
        with self.assertRaises(SystemExit):
            convert_to_c99("v = HIBYTE(off_12345678[i][0]);")

    def test_composed_form_and_idempotence(self):
        src = ("v42 = (int)(uintptr_t)(((volatile uint8_t *)(uintptr_t)"
               "((volatile uint32_t *)(uintptr_t)&off_11F4A0)[0] + (v40 & 0xF)));")
        out, n = deref_two_d(src)
        self.assertEqual(n, 1)
        self.assertEqual(out, "v42 = *((volatile uint8_t *)(uintptr_t)"
                              "((volatile uint32_t *)(uintptr_t)&off_11F4A0)[0] + (v40 & 0xF));")
        self.assertEqual(deref_two_d(out), (out, 0))


class LibMatch(unittest.TestCase):
    ROWS = [{"address": "0x143f00", "size": 220, "symbol": "strlen",
             "lib": "libc.a", "member": "libc_a-strlen.o"}]
    SRC = ("unsigned int memmove_5(unsigned int a1);\n"
           "int keep(int a);\n"
           "/* --- function bodies --- */\n"
           "// keep @ 0x100000\nint keep(int a) {\n  return memmove_5(a);\n}\n\n\n"
           "// memmove_5 @ 0x143f00\nunsigned int memmove_5(unsigned int a1) {\n"
           "  while ( !HIDWORD(0) )\n    ;\n}\n\n\n")

    def test_binds_declaration_and_drops_body(self):
        out, done = libmatch.bind(self.SRC, self.ROWS)
        self.assertEqual([d["name"] for d in done], ["memmove_5"])
        self.assertIn('unsigned int memmove_5(unsigned int a1) __asm__("__libmatch_strlen");', out)
        self.assertNotIn("HIDWORD", out)
        self.assertIn("return memmove_5(a);", out)
        self.assertIn("// memmove_5 @ 0x143f00\n/* libmatch: 220 bytes identical to strlen", out)

    def test_idempotent(self):
        out, _ = libmatch.bind(self.SRC, self.ROWS)
        self.assertEqual(libmatch.bind(out, self.ROWS), (out, []))

    def test_drops_unreferenced_interior_fragment_but_keeps_called_or_recursive(self):
        src = (
            "unsigned int memmove_5(unsigned int a1);\n"
            "int keep(int a);\n"
            "int frag_dead(int a);\n"
            "int frag_called(int a);\n"
            "int frag_rec(int a);\n"
            "/* --- function bodies --- */\n"
            "// keep @ 0x100000\nint keep(int a) {\n  return memmove_5(a) + frag_called(a);\n}\n\n\n"
            "// memmove_5 @ 0x143f00\nunsigned int memmove_5(unsigned int a1) {\n  return frag_dead(a1);\n}\n\n\n"
            "// frag_dead @ 0x143f20\nint frag_dead(int a) {\n  JUMPOUT(0x143f00);\n}\n\n\n"
            "// frag_called @ 0x143f40\nint frag_called(int a) {\n  return a + 1;\n}\n\n\n"
            "// frag_rec @ 0x143f60\nint frag_rec(int a) {\n  return a ? frag_rec(a - 1) : 0;\n}\n\n\n"
        )
        out, done = libmatch.bind(src, self.ROWS)
        self.assertEqual([(d["name"], d["symbol"]) for d in done],
                         [("memmove_5", "strlen"), ("frag_dead", "strlen+interior")])
        self.assertIn("/* libmatch: interior fragment of strlen @ 0x143f00", out)
        self.assertNotIn("JUMPOUT(0x143f00)", out)
        self.assertIn("// frag_called @ 0x143f40\nint frag_called(int a) {", out)
        self.assertIn("// frag_rec @ 0x143f60\nint frag_rec(int a) {", out)
        self.assertEqual(libmatch.bind(out, self.ROWS), (out, []))

    def test_tracked_matches_are_current_and_applied(self):
        meta = libmatch.load_meta()
        self.assertEqual(libmatch.scan(), meta)
        h_by_sym = {r["symbol"]: r["address"] for r in meta["images"]["fmacfw_8800d80_h_u02"]}
        self.assertEqual(h_by_sym["__aeabi_dcmpeq"], "0x142e38")
        self.assertEqual(h_by_sym["__aeabi_fcmpeq"], "0x143270")
        for img, short in libmatch.IMAGES.items():
            text = (libmatch.REPO / "src" / short / "main.c").read_text()
            self.assertEqual(libmatch.bind(text, meta["images"][img])[1], [])
            self.assertEqual(volatile_pointees.qualify(text)[1], 0)
            self.assertEqual(deref_two_d(text)[1], 0)


class CallsiteTargets(unittest.TestCase):
    # 0x100000: bl 0x100010; bx lr    0x100008: bx lr    0x100010: bx lr
    BLOB = bytes.fromhex("00f006f8" "7047" "0000" "7047" "0000" "0000" "0000" "7047" "0000")
    SRC = ("int foo(int a1);\nint foo_1(int a1);\nvoid foo_2();\nint caller(int a1);\n"
           "/* --- function bodies --- */\n"
           "// caller @ 0x100000\nint caller(int a1) {\n  return foo(a1) + foo (a1);\n}\n\n"
           "// foo @ 0x100008\nint foo(int a1) {\n  return a1;\n}\n\n"
           "// foo_1 @ 0x100010\nint foo_1(int a1) {\n  return a1;\n}\n")

    def test_rebinds_to_the_binary_target(self):
        out, done, left = callsite_targets.rebind(self.SRC, self.BLOB)
        self.assertEqual(done, [("caller", "foo", "foo_1")])
        self.assertEqual(left, [])
        self.assertIn("return foo_1(a1) + foo_1 (a1);", out)
        self.assertIn("// foo @ 0x100008\nint foo(int a1) {", out)
        self.assertEqual(callsite_targets.rebind(out, self.BLOB), (out, [], []))

    def test_leaves_a_call_the_binary_confirms(self):
        blob = bytes.fromhex("00f002f8") + self.BLOB[4:]      # bl 0x100008
        self.assertEqual(callsite_targets.rebind(self.SRC, blob), (self.SRC, [], []))

    def test_leaves_a_call_the_target_prototype_does_not_fit(self):
        src = self.SRC.replace("int foo_1(int a1)", "int foo_1(int a1, int a2)")
        out, done, left = callsite_targets.rebind(src, self.BLOB)
        self.assertEqual((out, done), (src, []))
        self.assertEqual(left, [("caller", "foo", "foo_1")])

    def test_before_heal_rebinds_without_the_prototype(self):
        src = self.SRC.replace("int foo_1(int a1)", "int foo_1(int a1, int a2)")
        out, done, left = callsite_targets.rebind(src, self.BLOB, fit=False)
        self.assertEqual((done, left), ([("caller", "foo", "foo_1")], []))
        self.assertIn("return foo_1(a1) + foo_1 (a1);", out)

    def test_two_family_members_in_a_straight_line_body_bind_in_call_order(self):
        # 0x100000: bl 0x100010; b 0x100008
        blob = bytes.fromhex("00f006f8" "00f000b8") + self.BLOB[8:]
        src = self.SRC.replace("return foo(a1) + foo (a1);", "foo(a1);\n  return foo(a1);")
        out, done, left = callsite_targets.rebind(src, blob)
        self.assertEqual((done, left), ([("caller", "foo", "foo_1/foo")], []))
        self.assertIn("foo_1(a1);\n  return foo(a1);", out)
        self.assertEqual(callsite_targets.rebind(out, blob), (out, [], []))
        branchy = src.replace("foo(a1);\n", "if ( a1 ) foo(a1);\n")
        self.assertEqual(callsite_targets.rebind(branchy, blob), (branchy, [], []))

    def test_family_is_the_dedupe_suffix_only(self):
        self.assertTrue(callsite_targets.same_family("ke_msg_send", "ke_msg_send_2"))
        self.assertTrue(callsite_targets.same_family("memmove_2_1", "memmove_2"))
        self.assertTrue(callsite_targets.same_family("irq_lock_1", "irq_lock_3"))
        self.assertFalse(callsite_targets.same_family("ke_msg_send", "ke_msg_alloc"))
        self.assertFalse(callsite_targets.same_family("foo", "foo"))

    def test_call_arities(self):
        self.assertEqual(callsite_targets.call_arities("f(a, g(b, c), (int)d[1, 2]); f(); x = f;", "f"),
                         [3, 0])

    def test_tracked_sources_are_at_the_fixed_point(self):
        for short, long in callsite_targets.IMAGES.items():
            fw = callsite_targets.REPO / "inputs" / "firmware" / f"{long}.bin"
            if not fw.is_file():
                self.skipTest("firmware images are not in the tree")
            text = (callsite_targets.REPO / "src" / short / "main.c").read_text(errors="replace")
            self.assertEqual(callsite_targets.rebind(text, fw.read_bytes())[1], [])
            self.assertEqual(callsite_targets.entry_labels(text, fw.read_bytes())[1], [])


class EntryLabels(unittest.TestCase):
    # 0x100000: bl 0x10000c    0x100004: bx lr    0x100008: literal word
    # 0x10000c: push {r4, lr}; pop {r4, pc}
    BLOB = bytes.fromhex("00f004f8" "7047" "0000" "a4221900" "10b5" "10bd")
    SRC = ("#define loc_10000C 0x10000c  /* code label address */\n"
           "// caller @ 0x100000\nint caller(int a1) {\n"
           "  return ((int ( *)(int))loc_10000C)(a1) + loc_10000C;\n}\n\n"
           "// alloc @ 0x100008\nint alloc(int a1) {\n  return a1;\n}\n")

    def test_a_label_the_binary_calls_instead_of_the_start_is_the_entry(self):
        out, done = callsite_targets.entry_labels(self.SRC, self.BLOB)
        self.assertEqual(done, [("loc_10000C", "alloc")])
        self.assertIn("return ((int ( *)(int))alloc)(a1) + loc_10000C;", out)
        self.assertIn("#define loc_10000C 0x10000c", out)
        self.assertEqual(callsite_targets.entry_labels(out, self.BLOB), (out, []))

    def test_a_second_entry_point_is_left_alone(self):
        # 0x100004 becomes bl 0x100008: the function start is called too
        blob = self.BLOB[:4] + bytes.fromhex("00f000f8") + self.BLOB[8:]
        self.assertEqual(callsite_targets.entry_labels(self.SRC, blob), (self.SRC, []))

    def test_a_label_that_is_not_a_prologue_or_too_far_in_is_left_alone(self):
        blob = self.BLOB[:12] + bytes.fromhex("7047" "0000")     # bx lr at the label
        self.assertEqual(callsite_targets.entry_labels(self.SRC, blob), (self.SRC, []))
        src = self.SRC.replace("// alloc @ 0x100008", "// alloc @ 0x0fffe8")
        src = src.replace("// caller @ 0x100000", "// caller @ 0x0fffe0")
        self.assertEqual(callsite_targets.entry_labels(src, self.BLOB), (src, []))


class AsmReturns(unittest.TestCase):
    ANN = ("// sub_1 @ 0x1\nvoid __fastcall sub_1(int a1)\n{\n  if ( !a1 )\nLABEL_1:\n"
           "    __asm { POP.W           {R4-R11,PC} }\n  g();\n  goto LABEL_1;\n}\n")
    BODY = "\nvoid f(int a1) {\n  if ( !a1 )\nLABEL_1:\n    \n  g();\n  goto LABEL_1;\n}\n\n"

    def test_the_stripped_epilogue_is_a_return(self):
        out, done, left = asm_returns.restore(self.BODY, self.ANN)
        self.assertEqual((done, left), (1, 0))
        self.assertIn("  if ( !a1 )\nLABEL_1:\n    return;\n  g();", out)
        self.assertTrue(out.endswith("}\n\n"))
        self.assertEqual(asm_returns.restore(out, self.ANN), (out, 0, 0))

    def test_a_function_with_the_r0_variable_returns_it(self):
        body = self.BODY.replace("void f(int a1)", "int f(int result, int a1)").replace("    \n", "{ }\n")
        out, done, left = asm_returns.restore(body, self.ANN)
        self.assertEqual((done, left), (1, 0))
        self.assertIn("LABEL_1:\n    return result;\n", out)

    def test_an_unknown_return_value_is_left(self):
        body = self.BODY.replace("void f(int a1)", "int f(int a1)")
        self.assertEqual(asm_returns.restore(body, self.ANN), (body, 0, 1))

    def test_other_asm_and_filled_lines_are_left(self):
        ann = self.ANN.replace("POP.W           {R4-R11,PC}", "UADD8.W         R5, R2, R12")
        self.assertEqual(asm_returns.restore(self.BODY, ann), (self.BODY, 0, 0))
        body = self.BODY.replace("    \n", "    h();\n")
        self.assertEqual(asm_returns.restore(body, self.ANN), (body, 0, 0))

    def test_tracked_sources_are_at_the_fixed_point(self):
        for short, image in asm_returns.IMAGES.items():
            text = (asm_returns.REPO / "src" / short / "main.c").read_text(errors="replace")
            ann = asm_returns.REPO / "harness_v25" / "out" / f"{image}_bin_annotated"
            self.assertEqual(asm_returns.restore_image(text, ann)[1], [])


class CallCastReturns(unittest.TestCase):
    SRC = ("// dmul @ 0x100000\nuint64_t dmul(uint64_t a1) {\n  return a1;\n}\n\n"
           "// f @ 0x100010\nint f(int a1) {\n  return a1;\n}\n\n"
           "// g @ 0x100020\nint g() {\n  uint64_t v1;\n"
           "  v1 = ((int (*)())dmul)(1, 2);\n  v1 = ((int ( *)(int))dmul)(3);\n"
           "  return ((int (*)())f)(1, 2);\n}\n")

    def test_a_cast_over_a_64_bit_callee_keeps_its_return_type(self):
        out, n = call_cast_returns.widen(self.SRC)
        self.assertEqual(n, 2)
        self.assertIn("v1 = ((uint64_t (*)())dmul)(1, 2);", out)
        self.assertIn("v1 = ((uint64_t ( *)(int))dmul)(3);", out)
        self.assertIn("return ((int (*)())f)(1, 2);", out)
        self.assertEqual(call_cast_returns.widen(out), (out, 0))

    def test_rtabi_helpers_return_64_bits_by_name_or_through_a_libmatch_binding(self):
        src = ('int dmul_1(uint64_t a1, int a2) __asm__("__libmatch___aeabi_dmul");\n'
               'int cmp_1(uint64_t a1) __asm__("__libmatch___aeabi_dcmpeq");\n'
               "// g @ 0x100020\nint g() {\n  uint64_t v1;\n"
               "  v1 = ((int (*)())__aeabi_f2d)(1);\n  v1 = ((int (*)())dmul_1)(1, 2, 3, 4);\n"
               "  return ((int (*)())cmp_1)(1, 2) + ((int (*)())__aeabi_dcmpeq)(1, 2);\n}\n")
        out, n = call_cast_returns.widen(src)
        self.assertEqual(n, 3)
        self.assertIn('uint64_t dmul_1(uint64_t a1, int a2) __asm__', out)
        self.assertIn('int cmp_1(uint64_t a1) __asm__', out)
        self.assertIn("((uint64_t (*)())__aeabi_f2d)(1)", out)
        self.assertIn("((uint64_t (*)())dmul_1)(1, 2, 3, 4)", out)
        self.assertIn("((int (*)())cmp_1)(1, 2) + ((int (*)())__aeabi_dcmpeq)(1, 2)", out)
        self.assertEqual(call_cast_returns.widen(out), (out, 0))

    def test_tracked_sources_are_at_the_fixed_point(self):
        for img in call_cast_returns.IMAGES:
            text = (call_cast_returns.REPO / "src" / img / "main.c").read_text(errors="replace")
            self.assertEqual(call_cast_returns.widen(text)[1], 0)


class StackFrames(unittest.TestCase):
    SRC = ("// f @ 0x100000\nint f(int a1) {\n  int v1; // r0\n"
           "  int v3; // [sp+0h] [bp-10h]\n  uint8_t v4[4]; // [sp+8h] [bp-8h] BYREF\n"
           "  char v5; // [sp+Ch] [bp-4h] BYREF\n\n"
           "  v3 = a1;\n  v1 = *((volatile uint32_t *)&v4[0] - 2);\n  return v1 + (&v5 - (char *)v4);\n}\n")

    def test_stack_locals_keep_their_printed_offsets(self):
        out, n = stack_frames.apply(self.SRC)
        self.assertEqual(n, 1)
        self.assertIn("struct __attribute__((packed)) { int v3; // [sp+0h]", out)
        self.assertIn("  char _pad1[4]; uint8_t v4[4]; // [sp+8h]", out)
        self.assertIn("  char v5; // [sp+Ch]", out)
        self.assertIn("  } _frame;\n  _frame.v3 = a1;", out)
        self.assertIn("&_frame.v4[0] - 2", out)
        self.assertIn("int v1; // r0", out)
        self.assertEqual(out.count("\n"), self.SRC.count("\n"))
        self.assertEqual(stack_frames.apply(out), (out, 0))

    def test_a_frame_without_an_address_taken_local_or_with_unknown_sizes_is_left_alone(self):
        plain = self.SRC.replace(" BYREF", "")
        self.assertEqual(stack_frames.apply(plain), (plain, 0))
        odd = self.SRC.replace("int v3;", "struct_x v3;")
        self.assertEqual(stack_frames.apply(odd), (odd, 0))
        overlap = self.SRC.replace("[sp+Ch]", "[sp+9h]")
        self.assertEqual(stack_frames.apply(overlap), (overlap, 0))

    def test_same_offset_spill_slots_become_anonymous_union(self):
        src = ("// g @ 0x100000\nint g(int a1) {\n"
               "  int v1; // [sp+0h] [bp-Ch]\n"
               "  unsigned int v2; // [sp+0h] [bp-Ch]\n"
               "  int v3; // [sp+4h] [bp-8h] BYREF\n"
               "  int v4; // [sp+8h] [bp-4h]\n\n"
               "  v1 = a1; v2 = v1 + 1; return (&v3)[1] + v4;\n}\n")
        out, n = stack_frames.apply(src)
        self.assertEqual(n, 1)
        self.assertIn("struct __attribute__((packed)) { union { int v1;", out)
        self.assertIn("unsigned int v2; }; // [sp+0h]", out)
        self.assertIn("_frame.v1 = a1; _frame.v2 = _frame.v1 + 1;", out)
        self.assertEqual(out.count("\n"), src.count("\n"))
        self.assertEqual(stack_frames.apply(out), (out, 0))

    def test_bp_plus_zero_locals_stay_in_frame(self):
        src = ("// h @ 0x100000\nint h(int a1) {\n"
               "  int v34; // [sp+3Ch] [bp-4h]\n"
               "  uint64_t vars0[2]; // [sp+40h] [bp+0h] BYREF\n\n"
               "  v34 = a1; return *((volatile uint32_t *)&vars0[0] - 1);\n}\n")
        out, n = stack_frames.apply(src)
        self.assertEqual(n, 1)
        self.assertIn("_frame.vars0[0]", out)
        self.assertIn("  } _frame;\n  _frame.v34 = a1;", out)
        self.assertEqual(stack_frames.apply(out), (out, 0))

    def test_tracked_sources_are_at_the_fixed_point(self):
        for img in stack_frames.IMAGES:
            text = (stack_frames.REPO / "src" / img / "main.c").read_text(errors="replace")
            self.assertEqual(stack_frames.apply(text)[1], 0)


class DoubleArgs(unittest.TestCase):
    SRC = ('uint64_t ddiv(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4) __asm__("__libmatch___aeabi_ddiv");\n'
           'unsigned int d2f(unsigned int a1, int a2) __asm__("__libmatch___aeabi_d2f");\n'
           "// f @ 0x100000\nint f(int a1) {\n  int v1; // r0\n  int v2; // r0\n  uint64_t v3; // r0\n  int v4; // r0\n\n"
           "  v1 = ddiv(a1, 0, 1, 2);\n  v2 = a1;\n  v3 = ddiv(a1, 0, 1, 2);\n  v4 = ddiv(a1, 0, 1, 2);\n"
           "  g(v4);\n"
           "  return ((int (*)())d2f)(v1) + ((int (*)())d2f)(v2) + ((int (*)())d2f)(v3) + ((int (*)())d2f)(v4);\n}\n")

    def test_a_double_reaches_the_helper_with_both_words(self):
        out, n = double_args.apply(self.SRC)
        self.assertEqual(n, 2)
        self.assertIn("  uint64_t v1; // r0\n  int v2; // r0\n  uint64_t v3; // r0\n  int v4; // r0\n", out)
        self.assertIn("return ((int (*)(uint64_t))d2f)(v1) + ((int (*)())d2f)(v2) + "
                      "((int (*)(uint64_t))d2f)(v3) + ((int (*)())d2f)(v4);", out)
        self.assertEqual(double_args.apply(out), (out, 0))

    def test_tracked_sources_are_at_the_fixed_point(self):
        for img in double_args.IMAGES:
            text = (double_args.REPO / "src" / img / "main.c").read_text(errors="replace")
            self.assertEqual(double_args.apply(text)[1], 0)


class DwordCompares(unittest.TestCase):
    SRC = ("// f @ 0x100000\nint f(int a1, unsigned int a2) {\n  int v4; // r3\n  unsigned int v5; // r2\n\n"
           "  if ( *(volatile uint32_t *)a1 < v4 && v5 <= 49 )\n    return 1;\n"
           "  if ( v4 >= *(volatile uint32_t *)(a1 + 4 * (v5 + 1)) || *(volatile uint32_t *)(a1 + 8) > a2 )\n    return 2;\n"
           "  if ( *(volatile uint32_t *)(a1 + 8) > v5 || *(volatile uint32_t *)(a1 + 8) > 1u )\n    return 3;\n"
           "  return *(volatile uint32_t *)(a1 + 16) - v4 >= a1;\n}\n")

    def test_a_load_compared_with_a_signed_local_is_a_signed_compare(self):
        out, n = dword_compares.apply(self.SRC)
        self.assertEqual(n, 2)
        self.assertIn("if ( (int)*(volatile uint32_t *)a1 < v4 && v5 <= 49 )", out)
        self.assertIn("if ( v4 >= (int)*(volatile uint32_t *)(a1 + 4 * (v5 + 1)) || *(volatile uint32_t *)(a1 + 8) > a2 )", out)
        self.assertIn("if ( *(volatile uint32_t *)(a1 + 8) > v5 || *(volatile uint32_t *)(a1 + 8) > 1u )", out)
        self.assertIn("return *(volatile uint32_t *)(a1 + 16) - v4 >= a1;", out)
        self.assertEqual(dword_compares.apply(out), (out, 0))

    def test_tracked_sources_are_at_the_fixed_point(self):
        for img in dword_compares.IMAGES:
            text = (dword_compares.REPO / "src" / img / "main.c").read_text(errors="replace")
            self.assertEqual(dword_compares.apply(text)[1], 0)


class FloatBits(unittest.TestCase):
    SRC = ("// f @ 0x100000\nint f(int a1) {\n  float v5; // r0\n  int v6; // r0\n  float v7; // r0\n\n"
           "  v5 = ((int (*)(uint64_t))d2f)(a1);\n  v6 = ((int (*)(uint64_t))d2f)(a1);\n  v7 = v5 * 2.0;\n"
           "  return f2d(LODWORD(v5)) + f2d(LODWORD(v6)) + g(v7);\n}\n"
           "// h @ 0x100010\nint h(int v5) {\n  return LODWORD(v5);\n}\n")

    def test_a_float_local_carries_the_helper_result_as_bits(self):
        out, n = float_bits.apply(self.SRC)
        self.assertEqual(n, 2)
        self.assertIn("  v5 = COERCE_FLOAT(((int (*)(uint64_t))d2f)(a1));\n  v6 = ((int (*)(uint64_t))d2f)(a1);\n  v7 = v5 * 2.0;\n", out)
        self.assertIn("return f2d(COERCE_UNSIGNED_INT(v5)) + f2d(LODWORD(v6)) + g(v7);", out)
        self.assertIn("int h(int v5) {\n  return LODWORD(v5);", out)
        self.assertEqual(float_bits.apply(out), (out, 0))

    def test_tracked_sources_are_at_the_fixed_point(self):
        for img in float_bits.IMAGES:
            text = (float_bits.REPO / "src" / img / "main.c").read_text(errors="replace")
            self.assertEqual(float_bits.apply(text)[1], 0)


class PeriphSymbols(unittest.TestCase):
    def test_address_of_a_peripheral_named_symbol_is_the_address(self):
        src = ("((volatile uint32_t *)(uintptr_t)&dword_40504080)[result] &= 0xFFFFFFF0;\n"
               "x = (uintptr_t)&dword_12C2CC; y = dword_40504080;\n")
        out, n = periph_symbols.absolute(src)
        self.assertEqual(n, 1)
        self.assertIn("((volatile uint32_t *)(uintptr_t)0x40504080u)[result]", out)
        self.assertIn("x = (uintptr_t)&dword_12C2CC; y = dword_40504080;", out)
        self.assertEqual(periph_symbols.absolute(out), (out, 0))

    def test_convert_to_c99_rewrites_scalar_peripheral_mmio(self):
        out = convert_to_c99("v0 = dword_40501010;\nunk_40501008 = 4;\ndword_40021000[i] = 1;")
        self.assertIn("(*(volatile uint32_t *)0x40501010u)", out)
        self.assertIn("(*(volatile uint32_t *)0x40501008u) = 4;", out)
        self.assertIn("dword_40021000[i] = 1;", out)

    def test_convert_to_c99_rewrites_ptr_to_array_and_msr_msp(self):
        out = convert_to_c99("v0 = (*off_1142E0)[0];\n__asm { MSR.W MSP, R0 }\nreturn fmt_fn(fmt, (unsigned int *)varg_r1);")
        self.assertIn("((uint32_t *)(uintptr_t)off_1142E0)[0]", out)
        self.assertIn('__asm volatile("msr msp, %0" : : "r"(_R0) : "memory");', out)
        self.assertIn("(unsigned int *)(*(void **)&(varg_r1))", out)

    def test_convert_to_c99_normalizes_hwbase_aicfn(self):
        out = convert_to_c99("aicfn_1334f0_end(a, b, c);\naicfn_12f2c8_end(1);")
        self.assertEqual(out, "sub_1334F0(a, b, c);\nsub_12F2C8(1);")

    def test_tracked_sources_are_at_the_fixed_point(self):
        for img in periph_symbols.IMAGES:
            text = (periph_symbols.REPO / "src" / img / "main.c").read_text(errors="replace")
            self.assertEqual(periph_symbols.absolute(text)[1], 0)


class HealSubscript(unittest.TestCase):
    def test_off_nonzero_subscript_derefs_pointer_not_literal_pool(self):
        msg = "error: subscripted value is neither array nor pointer"
        line, ok = heal_composed.heal_line("  v8 = off_11B6B4[10];\n", msg)
        self.assertTrue(ok)
        self.assertEqual(line, "  v8 = ((uint32_t *)(uintptr_t)off_11B6B4)[10];\n")
        line0, ok0 = heal_composed.heal_line("  v9 = off_11F4A0[0];\n", msg)
        self.assertTrue(ok0)
        self.assertEqual(line0, "  v9 = ((uint32_t *)(uintptr_t)&off_11F4A0)[0];\n")

    def test_unary_deref_handles_cast_prefix_and_binary_mul(self):
        msg = "invalid type argument of unary '*' (have 'uint32_t')"
        line, ok = heal_composed.heal_line("  v1 = (uint8_t)*off_123474;\n", msg)
        self.assertTrue(ok)
        self.assertEqual(line, "  v1 = (uint8_t)*(uint8_t *)(uintptr_t)(off_123474);\n")
        line2, ok2 = heal_composed.heal_line("  v2 = x*2 + *off_123474;\n", msg)
        self.assertTrue(ok2)
        self.assertEqual(line2, "  v2 = x*2 + *(uint32_t *)(uintptr_t)(off_123474);\n")


class ArmShifts(unittest.TestCase):
    def test_masks_mod256_exponent_shifts_once(self):
        src = ("v6 = 0xFFFFFFFF >> ((HIDWORD(a1) >> 20) - 19);\n"
               "v3 = (0x80000 >> ((HIDWORD(a1) >> 20) + 1));\n")
        out, n = arm_shifts.apply(src)
        self.assertEqual(n, 2)
        self.assertIn("0xFFFFFFFF >> (((HIDWORD(a1) >> 20) - 19) & 0xFF)", out)
        self.assertIn("0x80000 >> (((HIDWORD(a1) >> 20) + 1) & 0xFF)", out)
        self.assertEqual(arm_shifts.apply(out), (out, 0))

    def test_tracked_sources_are_at_the_fixed_point(self):
        for img in arm_shifts.IMAGES:
            text = (arm_shifts.REPO / "src" / img / "main.c").read_text(errors="replace")
            self.assertEqual(arm_shifts.apply(text)[1], 0)


class FloatCompares(unittest.TestCase):
    def test_rewrites_float_loop_exit_lt_to_negated_ge_once(self):
        src = (
            "// mem_swap_fields @ 0x1051d0\n"
            "int mem_swap_fields(int a1, float a2) {\n"
            "  float v9; // s14\n"
            "  int v8;\n"
            "  while ( 1 ) {\n"
            "    if ( v9 < a2 )\n"
            "      break;\n"
            "    if ( v8 < a1 )\n"
            "      goto LABEL_6;\n"
            "  }\n"
            "LABEL_6:\n"
            "  return 0;\n"
            "}\n"
        )
        out, n = float_compares.apply(src)
        self.assertEqual(n, 1)
        self.assertIn("if ( !(v9 >= a2) )\n      break;", out)
        self.assertIn("if ( v8 < a1 )", out)
        self.assertEqual(float_compares.apply(out), (out, 0))

    def test_tracked_sources_are_at_the_fixed_point(self):
        for img in float_compares.IMAGES:
            text = (float_compares.REPO / "src" / img / "main.c").read_text(errors="replace")
            self.assertEqual(float_compares.apply(text)[1], 0)


class SignedMuls(unittest.TestCase):
    def test_restores_smull_casts_but_leaves_umull_alone(self):
        src = (
            "v1 = ((uint64_t)(dword_1038D4 * (uint64_t)(4 * (v36 - 35))) >> 32);\n"
            "v2 = ((uint64_t)(dword_1076D4 * (uint64_t)*(volatile int *)(a1 + 4)) >> 32);\n"
            "v3 = (v9 & 0x7FFFFF) * (uint64_t)(int)_frame.v11[(v9 >> 18) & 0x1F];\n"
            "u1 = (unsigned int)dword_10C5B0 * (uint64_t)*(volatile unsigned int *)off_10C5AC;\n"
        )
        out, n = signed_muls.apply(src)
        self.assertEqual(n, 3)
        self.assertIn("(int32_t)dword_1038D4 * (int64_t)(int32_t)(4 * (v36 - 35))", out)
        self.assertIn("(int32_t)dword_1076D4 * (int64_t)(int32_t)(*(volatile int *)(a1 + 4))", out)
        self.assertIn("(int64_t)(int32_t)(v9 & 0x7FFFFF) * (int64_t)(int32_t)(_frame.v11[(v9 >> 18) & 0x1F])", out)
        self.assertIn("(unsigned int)dword_10C5B0 * (uint64_t)", out)
        self.assertEqual(signed_muls.apply(out), (out, 0))

    def test_tracked_sources_are_at_the_fixed_point(self):
        for img in signed_muls.IMAGES:
            text = (signed_muls.REPO / "src" / img / "main.c").read_text(errors="replace")
            self.assertEqual(signed_muls.apply(text)[1], 0)


class SignedHalfwords(unittest.TestCase):
    def test_restores_signed_int16_locals_casts_and_double_deref(self):
        bt = (
            "int sub_10E6FC(void) {\n"
            "  int16_t *v8;\n"
            "  int16_t **v99;\n"
            "  v8 = (int16_t *)off_10E8A4;\n"
            "  v99 = (int16_t **)off_100428;\n"
            "  if ( **(int16_t **)off_111614 < 0 )\n"
            "    return (int16_t)(v1 - v2);\n"
            "  return (uint16_t)v3;\n"
            "}\n"
        )
        mc = (
            "{\n"
            "  volatile uint16_t *v8;\n"
            "  volatile uint16_t **v21;\n"
            "  volatile int16_t **v1;\n"
            "  v8 = (volatile uint16_t *)off_10E8A4;\n"
            "  v21 = (volatile uint16_t **)off_100428;\n"
            "  v1 = (volatile uint16_t **)off_12CCC4;\n"
            "  if ( **(volatile uint16_t **)off_111614 < 0 )\n"
            "    return (uint16_t)(v1 - v2);\n"
            "  return (uint16_t)v3;\n"
            "}\n"
        )
        out, n = signed_halfwords.apply_function(mc, bt)
        self.assertGreaterEqual(n, 6)
        self.assertIn("volatile int16_t *v8;", out)
        self.assertIn("volatile int16_t **v21;", out)
        self.assertIn("(volatile int16_t **)off_12CCC4", out)
        self.assertIn("(volatile int16_t *)off_10E8A4", out)
        self.assertIn("**(volatile int16_t **)off_111614 < 0", out)
        self.assertIn("(int16_t)(v1 - v2)", out)
        self.assertIn("(uint16_t)v3", out)
        self.assertEqual(signed_halfwords.apply_function(out, bt), (out, 0))

    def test_tracked_sources_are_at_the_fixed_point(self):
        for short, img in signed_halfwords.IMAGES.items():
            text = (signed_halfwords.REPO / "src" / short / "main.c").read_text(errors="replace")
            tdir = signed_halfwords.REPO / "harness_v25" / "out" / f"{img}_bin_types"
            self.assertEqual(signed_halfwords.apply_image(text, tdir)[1], 0)


class PostCompose(unittest.TestCase):
    RULES = {"callsite_targets.py", "periph_symbols.py", "asm_returns.py",
             "call_cast_returns.py", "double_args.py", "float_bits.py",
             "stack_frames.py", "dword_compares.py", "arm_shifts.py",
             "float_compares.py", "signed_muls.py", "signed_halfwords.py",
             "heal_two_d_subscript.py", "libmatch.py", "volatile_pointees.py",
             "heal_composed.py", "absolute_memory.py"}

    def test_the_chain_runs_every_rule_and_rebinds_before_heal(self):
        steps = [(s, a) for s, a, _ in post_compose.STEPS]
        self.assertEqual({s for s, _ in steps}, self.RULES)
        self.assertLess(steps.index(("callsite_targets.py", ["--before-heal"])),
                        steps.index(("heal_composed.py", [])))
        self.assertLess(steps.index(("libmatch.py", ["scan"])),
                        steps.index(("libmatch.py", ["apply"])))
        for s in self.RULES:
            self.assertTrue((post_compose.TOOLS / s).exists(), s)


if __name__ == "__main__":
    unittest.main()
