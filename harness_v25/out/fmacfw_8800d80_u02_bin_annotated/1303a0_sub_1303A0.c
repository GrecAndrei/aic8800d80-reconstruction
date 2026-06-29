// fwstruct annotate: 1303a0_sub_1303A0.c
// sub_1303A0 @ 0x1303a0, size 118 bytes
int sub_1303A0()
{
  unsigned __int8 *v0; // r4
  int v1; // r4
  int v2; // r0
  int v4; // [sp+14h] [bp-4h]

  v0 = (unsigned __int8 *)off_130418;
  msg_parse(
    dword_13041C,
    *(char *)off_130418,
    *((char *)off_130418 + 1),
    *((char *)off_130418 + 2),
    *((char *)off_130418 + 3));
  msg_parse(dword_130420, v0[4], v0[5], v0[6]);
  msg_parse(dword_130424, (char)v0[8], (char)v0[9], (char)v0[10], (char)v0[11], (char)v0[12], (char)v0[13]);
  v1 = *((unsigned __int8 *)off_130428 + 363);
  v4 = *((_DWORD *)off_130428 + 91);
  v2 = message_dispatch_c8b4(1070, 1);
  return msg_parse(dword_13042C, v1, v4, v2);
}

