// fwstruct annotate: 130260_sub_130260.c
// sub_130260 @ 0x130260, size 118 bytes
int sub_130260()
{
  unsigned __int8 *v0; // r4
  int v1; // r4
  int v2; // r0
  int v4; // [sp+14h] [bp-4h]

  v0 = (unsigned __int8 *)off_1302D8;
  sub_12E948(
    dword_1302DC,
    *(char *)off_1302D8,
    *((char *)off_1302D8 + 1),
    *((char *)off_1302D8 + 2),
    *((char *)off_1302D8 + 3));
  sub_12E948(dword_1302E0, v0[4], v0[5], v0[6]);
  sub_12E948(dword_1302E4, (char)v0[8], (char)v0[9], (char)v0[10], (char)v0[11], (char)v0[12], (char)v0[13]);
  v1 = *((unsigned __int8 *)off_1302E8 + 363);
  v4 = *((_DWORD *)off_1302E8 + 91);
  v2 = sub_12C774(1070, 1);
  return sub_12E948(dword_1302EC, v1, v4, v2);
}

