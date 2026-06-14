"""Build ELF wrapper around a raw ARM Thumb binary so IDA loads it as ARM.

The AIC8800D80 firmware binaries are raw bytes that load at 0x100000 in
the SoC. To get IDA to:
  - load them as ARM (not x86 metapc),
  - default to 32-bit (not 64-bit AArch64),
  - start at 0x100000 (not 0x0),
  - treat the segment as Thumb code,
we wrap each in a minimal ARM ELF.

Output: harness_v19/elf/<image>.elf
"""
import struct
import sys
from pathlib import Path

LOAD_ADDR = 0x100000


def make_arm_elf(bin_path: Path, elf_path: Path, load_addr: int = LOAD_ADDR) -> None:
    bin_data = bin_path.read_bytes()
    bin_size = len(bin_data)
    ehdr_size = 52
    phdr_size = 32
    text_offset = ehdr_size + phdr_size

    elf = b''
    # e_ident
    elf += b'\x7fELF'   # magic
    elf += b'\x01'       # 32-bit
    elf += b'\x01'       # little-endian
    elf += b'\x01'       # ELF version
    elf += b'\x00'       # OS ABI
    elf += b'\x00' * 8   # padding
    # e_type = 2 (executable)
    elf += struct.pack('<H', 2)
    # e_machine = 0x28 (ARM)
    elf += struct.pack('<H', 0x28)
    # e_version
    elf += struct.pack('<I', 1)
    # e_entry (Thumb bit set so Thumb mode for entry)
    elf += struct.pack('<I', load_addr + 0x100 + 1)
    # e_phoff
    elf += struct.pack('<I', ehdr_size)
    # e_shoff (no section headers)
    elf += struct.pack('<I', 0)
    # e_flags (ARM flags, EABI5)
    elf += struct.pack('<I', 0x5000200)
    # e_ehsize
    elf += struct.pack('<H', ehdr_size)
    # e_phentsize
    elf += struct.pack('<H', phdr_size)
    # e_phnum
    elf += struct.pack('<H', 1)
    # e_shentsize
    elf += struct.pack('<H', 0)
    # e_shnum
    elf += struct.pack('<H', 0)
    # e_shstrndx
    elf += struct.pack('<H', 0)

    # Program header (LOAD)
    elf += struct.pack('<I', 1)            # p_type = LOAD
    elf += struct.pack('<I', text_offset)  # p_offset
    elf += struct.pack('<I', load_addr)    # p_vaddr
    elf += struct.pack('<I', load_addr)    # p_paddr
    elf += struct.pack('<I', bin_size)     # p_filesz
    elf += struct.pack('<I', bin_size)     # p_memsz
    elf += struct.pack('<I', 5)            # p_flags = R|X
    elf += struct.pack('<I', 0x1000)       # p_align

    elf += bin_data
    elf_path.write_bytes(elf)
    print(f"Created {elf_path}: {len(elf)} bytes, load 0x{load_addr:x}, code {bin_size} bytes")


def main():
    images = [
        'fmacfw_8800d80_h_u02',
        'fmacfw_8800d80_u02',
        'fmacfwbt_8800d80_u02',
        'lmacfw_rf_8800d80_u02',
    ]
    src_dir = Path('inputs/firmware')
    dst_dir = Path('harness_v19/elf')
    dst_dir.mkdir(parents=True, exist_ok=True)
    for name in images:
        src = src_dir / f'{name}.bin'
        if not src.exists():
            print(f"WARN: missing {src}")
            continue
        dst = dst_dir / f'{name}.elf'
        make_arm_elf(src, dst)


if __name__ == '__main__':
    main()
