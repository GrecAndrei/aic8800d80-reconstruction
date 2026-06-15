// sub_10C9A0 @ 0x10c9a0, size 182 bytes
int sub_10C9A0()
{
  int v0; // r4
  int result; // r0
  _DWORD *v2; // r2
  _BYTE *v3; // r3
  _DWORD *v4; // r2
  _DWORD *v5; // r2
  _DWORD *v6; // r2

  v0 = *(_DWORD *)off_10CA58;
  if ( (*(_DWORD *)off_10CA58 & 0x20) != 0 )
  {
    v6 = off_10CA60;
    *(_DWORD *)off_10CA78 = 32;
    *v6 = 32;
    sub_12CFC4(0x80000);
  }
  result = v0 << 27;
  if ( (v0 & 0x10) != 0 )
  {
    v5 = off_10CA60;
    *(_DWORD *)off_10CA78 = 16;
    *v5 = 16;
    result = sub_12CFC4(0x100000);
  }
  if ( (v0 & 2) != 0 )
  {
    result = sub_12CFC4(0x8000000);
    *(_DWORD *)off_10CA78 = 2;
  }
  if ( (v0 & 0x40000000) != 0 )
  {
    result = sub_11446C(1);
    *(_DWORD *)off_10CA60 = 0x40000000;
  }
  if ( v0 < 0 )
  {
    v2 = off_10CA60;
    *(_DWORD *)off_10CA5C = 0x80000000;
    *v2 = 0x80000000;
  }
  if ( (v0 & 0x20000000) == 0 )
  {
    v3 = off_10CA64;
    if ( !*(_BYTE *)off_10CA64 || !*(_DWORD *)off_10CA68 )
      return result;
LABEL_16:
    v4 = off_10CA6C;
    v3[1] = 1;
    *v4 |= 1u;
    return result;
  }
  v3 = off_10CA64;
  *(_DWORD *)off_10CA60 = 0x20000000;
  if ( *v3 )
    goto LABEL_16;
  if ( (*(_DWORD *)off_10CA70 & dword_10CA74) == 0x10000 )
    return sub_114434();
  return result;
}

