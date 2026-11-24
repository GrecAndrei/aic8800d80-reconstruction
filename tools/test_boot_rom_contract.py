#!/usr/bin/env python3
"""Virtual boot-ROM contract tests."""
import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import aic8800d80_emulator as emu


class BootRomContract(unittest.TestCase):
    def test_vector_slots_have_distinct_contract_entries(self):
        plat = emu.Aic8800D80Platform(emu.resolve_image("fmacfw_8800d80_h_u02"))
        values = [struct.unpack("<I", plat.mu.mem_read(slot, 4))[0] for slot in emu.BOOT_CALLBACK_SLOTS]
        self.assertEqual(len(set(values)), len(emu.BOOT_CALLBACK_SLOTS))
        for slot in emu.BOOT_CALLBACK_SLOTS:
            self.assertEqual(struct.unpack("<I", plat.mu.mem_read(slot, 4))[0], emu.BOOT_ROM_ENTRY[slot] | 1)

    def test_read_hook_returns_modeled_register_value(self):
        plat = emu.Aic8800D80Platform(emu.resolve_image("fmacfw_8800d80_h_u02"))
        plat.rom_regs[0x70001030] = 0x12345678
        plat.mu.reg_write(emu.UC_ARM_REG_R0, 0x70001030)
        term, stats = plat.run(0x10EC2C + emu.HW_OFFSET, 2000,
                               sp=plat.ivt()["stack_pointer"], assert_stops=True)
        self.assertEqual(term, "returned")
        self.assertEqual(plat.mu.reg_read(emu.UC_ARM_REG_R0), 0x12345678)
        self.assertEqual(stats["rom_calls"][0]["slot"], "0x1b0")

    def test_block_read_copies_external_config_bytes(self):
        plat = emu.Aic8800D80Platform(emu.resolve_image("lmacfw_rf_8800d80_u02"))
        dst = 0x20002000
        plat.mu.reg_write(emu.UC_ARM_REG_R0, emu.BOOT_CONFIG_BASE + 0x2000)
        plat.mu.reg_write(emu.UC_ARM_REG_R1, 8)
        plat.mu.reg_write(emu.UC_ARM_REG_R2, dst)
        term, stats = plat.run(0x1142D8 + emu.HW_OFFSET, 2000,
                               sp=plat.ivt()["stack_pointer"], assert_stops=True)
        self.assertEqual(term, "returned")
        self.assertEqual(bytes(plat.mu.mem_read(dst, 8)), b"CALI\0\0\0\0")
        self.assertEqual(stats["rom_calls"][0]["copied"], 8)

    def test_write_and_masked_write_hooks_update_register_file(self):
        plat = emu.Aic8800D80Platform(emu.resolve_image("fmacfw_8800d80_h_u02"))
        for reg, val in zip((emu.UC_ARM_REG_R0, emu.UC_ARM_REG_R1, emu.UC_ARM_REG_R2),
                            (0x70001030, 0x55AA0000, 0)):
            plat.mu.reg_write(reg, val)
        term, _ = plat.run(0x10EC34 + emu.HW_OFFSET, 2000,
                           sp=plat.ivt()["stack_pointer"], assert_stops=True)
        self.assertEqual(term, "returned")
        self.assertEqual(plat.rom_regs[0x70001030], 0x55AA0000)

        plat = emu.Aic8800D80Platform(emu.resolve_image("fmacfw_8800d80_h_u02"))
        plat.rom_regs[0x70001030] = 0x12340000
        for reg, val in zip((emu.UC_ARM_REG_R0, emu.UC_ARM_REG_R1, emu.UC_ARM_REG_R2),
                            (0x70001030, 0x3C, 0xFF)):
            plat.mu.reg_write(reg, val)
        term, stats = plat.run(0x10EC3C + emu.HW_OFFSET, 2000,
                               sp=plat.ivt()["stack_pointer"], assert_stops=True)
        self.assertEqual(term, "returned")
        self.assertEqual(plat.rom_regs[0x70001030], 0x1234003C)
        self.assertEqual(stats["rom_calls"][0]["stored"], "0x1234003c")

    def test_command_dispatcher_uses_explicit_profile(self):
        plat = emu.Aic8800D80Platform(
            emu.resolve_image("fmacfw_8800d80_h_u02"),
            boot_rom_profile={"commands": {27: 0xA1C8800D}},
        )
        term, stats = plat.run(0x114A6C + emu.HW_OFFSET, 2000,
                               sp=plat.ivt()["stack_pointer"], assert_stops=True)
        self.assertEqual(term, "returned")
        self.assertEqual(plat.mu.reg_read(emu.UC_ARM_REG_R0), 0xA1C8800D)
        self.assertEqual(stats["rom_calls"][0]["command"], 27)


if __name__ == "__main__":
    unittest.main()
