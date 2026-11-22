#!/usr/bin/env python3
"""Tests for the mechanical source rules: volatile_pointees, libmatch, deref_two_d, callsite_targets."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import callsite_targets
import libmatch
import periph_symbols
import volatile_pointees
from convert_decompiled_to_functions import convert_to_c99, deref_two_d


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

    def test_tracked_matches_are_current_and_applied(self):
        meta = libmatch.load_meta()
        self.assertEqual(libmatch.scan(), meta)
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


class PeriphSymbols(unittest.TestCase):
    def test_address_of_a_peripheral_named_symbol_is_the_address(self):
        src = ("((volatile uint32_t *)(uintptr_t)&dword_40504080)[result] &= 0xFFFFFFF0;\n"
               "x = (uintptr_t)&dword_12C2CC; y = dword_40504080;\n")
        out, n = periph_symbols.absolute(src)
        self.assertEqual(n, 1)
        self.assertIn("((volatile uint32_t *)(uintptr_t)0x40504080u)[result]", out)
        self.assertIn("x = (uintptr_t)&dword_12C2CC; y = dword_40504080;", out)
        self.assertEqual(periph_symbols.absolute(out), (out, 0))

    def test_tracked_sources_are_at_the_fixed_point(self):
        for img in periph_symbols.IMAGES:
            text = (periph_symbols.REPO / "src" / img / "main.c").read_text(errors="replace")
            self.assertEqual(periph_symbols.absolute(text)[1], 0)


if __name__ == "__main__":
    unittest.main()
