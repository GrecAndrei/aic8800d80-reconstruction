// sub_1305BC @ 0x1305bc, size 118 bytes
int sub_1305BC()
{
  unsigned __int8 *v0; // r4
  int v1; // r4
  int v2; // r0
  int v4; // [sp+14h] [bp-4h]

  v0 = (unsigned __int8 *)off_130634;
  sub_12ECB0(
    dword_130638,
    *(char *)off_130634,
    *((char *)off_130634 + 1),
    *((char *)off_130634 + 2),
    *((char *)off_130634 + 3));
  sub_12ECB0(dword_13063C, *(_DWORD *)(v0 + 0x10), *(_DWORD *)(v0 + 0x14), *(_DWORD *)(v0 + 0x18));
  sub_12ECB0(dword_130640, (char)*(_DWORD *)(v0 + 0x20), (char)*(_DWORD *)(v0 + 0x24), (char)*(_DWORD *)(v0 + 0x28), (char)*(_DWORD *)(v0 + 0x2c), (char)*(_DWORD *)(v0 + 0x30), (char)*(_DWORD *)(v0 + 0x34));
  v1 = *((unsigned __int8 *)off_130644 + 363);
  v4 = *((_DWORD *)off_130644 + 91);
  v2 = sub_12CADC(1070, 1);
  return sub_12ECB0(dword_130648, v1, v4, v2);
}

