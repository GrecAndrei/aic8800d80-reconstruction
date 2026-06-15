// rf_level_dump @ 0x126e80, size 118 bytes
// Doc: rf_level_apply_nd8 [rf]: Apply RF power/level parameters from struct fields
// rf_level_apply_nd8 [rf]: Apply RF power/level parameters from struct fields
int rf_level_dump()
{
  unsigned __int8 *v0; // r4
  int v1; // r4
  int v2; // r0
  int v4; // [sp+14h] [bp-4h]

  v0 = (unsigned __int8 *)rf_level_apply_n120;
  msg_parse(
    rf_level_apply_n124,
    *(char *)rf_level_apply_n120,
    *((char *)rf_level_apply_n120 + 1),
    *((char *)rf_level_apply_n120 + 2),
    *((char *)rf_level_apply_n120 + 3));
  msg_parse(dword_126F00, v0[4], v0[5], v0[6]);
  msg_parse(dword_126F04, (char)v0[8], (char)v0[9], (char)v0[10], (char)v0[11], (char)v0[12], (char)v0[13]);
  v1 = *((unsigned __int8 *)off_126F08 + 363);
  v4 = *((_DWORD *)off_126F08 + 91);
  v2 = sub_11DDCC(1070, 1);
  return msg_parse(dword_126F0C, v1, v4, v2);
}

