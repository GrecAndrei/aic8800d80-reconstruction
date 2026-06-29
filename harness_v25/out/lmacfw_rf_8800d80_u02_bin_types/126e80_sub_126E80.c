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
  sub_11F504(dword_126F00, v0[4], v0[5], v0[6]);
  sub_11F504(dword_126F04, (char)v0[8], (char)v0[9], (char)v0[10], (char)v0[11], (char)v0[12], (char)v0[13]);
  v1 = *((unsigned __int8 *)off_126F08 + 363);
  v4 = *((uint32_t *)off_126F08 + 91);
  v2 = sub_11DDCC(1070, 1);
  return sub_11F504(dword_126F0C, v1, v4, v2);
}

