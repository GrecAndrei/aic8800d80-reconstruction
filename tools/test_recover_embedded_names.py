#!/usr/bin/env python3
"""Unit test for recover_embedded_names (synthetic image, no firmware needed)."""
import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import recover_embedded_names as ren


def build_image():
    data = bytearray(0x200)
    strings = {0x100: b"phy_set_channel\0", 0x120: b"shared_name\0",
               0x140: b"Not An Identifier\0", 0x160: b"mdm_init\0",
               0x170: b"dma_push\0"}
    for off, s in strings.items():
        data[off:off + len(s)] = s
    hw = ren.HARDWARE_BASE
    # fn A @0x00: one name, hardware-base pointer in its literal pool
    data[0x0C:0x10] = struct.pack("<I", hw + 0x100)
    # fn B @0x20 and fn C @0x40 both reference shared_name -> ambiguous
    data[0x2C:0x30] = struct.pack("<I", hw + 0x120)
    data[0x4C:0x50] = struct.pack("<I", hw + 0x120)
    # fn D @0x60 references two names -> ambiguous
    data[0x68:0x6C] = struct.pack("<I", hw + 0x160)
    data[0x6C:0x70] = struct.pack("<I", hw + 0x170)
    # fn E @0x80 points at a non-identifier string -> ignored
    data[0x8C:0x90] = struct.pack("<I", hw + 0x140)
    return bytes(data)


class RecoverTest(unittest.TestCase):
    def test_recover(self):
        base = ren.ANALYSIS_BASE
        starts = [base + x for x in (0x00, 0x20, 0x40, 0x60, 0x80)]
        accepted, ambiguous = ren.recover(build_image(), starts)
        self.assertEqual(accepted, {base: "phy_set_channel"})
        self.assertEqual(ambiguous, {
            base + 0x20: ["shared_name"],
            base + 0x40: ["shared_name"],
            base + 0x60: ["dma_push", "mdm_init"],
        })

    def test_identifier_strings_need_nul(self):
        self.assertEqual(ren.identifier_strings(b"\0abc_def\0xx_yy!"), [(1, "abc_def")])


if __name__ == "__main__":
    unittest.main()
