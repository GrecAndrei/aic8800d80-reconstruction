// sub_126E80 @ 0x126e80, size 118 bytes
// Doc: rf_level_apply_nc6 [rf]: Apply 9 signed RF level/IQ compensation values from a level table to chain 6 via rf_reg_write helper.
// rf_level_apply_nc6 [rf]: Apply 9 signed RF level/IQ compensation values from a level table to chain 6 via rf_reg_write helper.
int sub_126E80()
{
  unsigned __int8 *v0; // r4
  int v1; // r4
  int v2; // r0
  int v4; // [sp+14h] [bp-4h]

  v0 = (unsigned __int8 *)off_126EF8;
  sub_11F504(
    dword_126EFC,
    *(char *)off_126EF8,
    *((char *)off_126EF8 + 1),
    *((char *)off_126EF8 + 2),
    *((char *)off_126EF8 + 3));
  sub_11F504(dword_126F00, *(_DWORD *)(v0 + 0x10), *(_DWORD *)(v0 + 0x14), *(_DWORD *)(v0 + 0x18));
  sub_11F504(dword_126F04, (char)*(_DWORD *)(v0 + 0x20), (char)*(_DWORD *)(v0 + 0x24), (char)*(_DWORD *)(v0 + 0x28), (char)*(_DWORD *)(v0 + 0x2c), (char)*(_DWORD *)(v0 + 0x30), (char)*(_DWORD *)(v0 + 0x34));
  v1 = *((unsigned __int8 *)off_126F08 + 363);
  v4 = *((_DWORD *)off_126F08 + 91);
  v2 = sub_11DDCC(1070, 1);
  return sub_11F504(dword_126F0C, v1, v4, v2);
}

