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
  sub_12E948(dword_1302E0, *(_DWORD *)(v0 + 0x10), *(_DWORD *)(v0 + 0x14), *(_DWORD *)(v0 + 0x18));
  sub_12E948(dword_1302E4, (char)*(_DWORD *)(v0 + 0x20), (char)*(_DWORD *)(v0 + 0x24), (char)*(_DWORD *)(v0 + 0x28), (char)*(_DWORD *)(v0 + 0x2c), (char)*(_DWORD *)(v0 + 0x30), (char)*(_DWORD *)(v0 + 0x34));
  v1 = *((unsigned __int8 *)off_1302E8 + 363);
  v4 = *((_DWORD *)off_1302E8 + 91);
  v2 = sub_12C774(1070, 1);
  return sub_12E948(dword_1302EC, v1, v4, v2);
}

