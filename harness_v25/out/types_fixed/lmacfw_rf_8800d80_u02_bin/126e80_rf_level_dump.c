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
  msg_parse(dword_126F00, *(_DWORD *)(v0 + 0x10), *(_DWORD *)(v0 + 0x14), *(_DWORD *)(v0 + 0x18));
  msg_parse(dword_126F04, (char)*(_DWORD *)(v0 + 0x20), (char)*(_DWORD *)(v0 + 0x24), (char)*(_DWORD *)(v0 + 0x28), (char)*(_DWORD *)(v0 + 0x2c), (char)*(_DWORD *)(v0 + 0x30), (char)*(_DWORD *)(v0 + 0x34));
  v1 = *((unsigned __int8 *)off_126F08 + 363);
  v4 = *((_DWORD *)off_126F08 + 91);
  v2 = sub_11DDCC(1070, 1);
  return msg_parse(dword_126F0C, v1, v4, v2);
}

