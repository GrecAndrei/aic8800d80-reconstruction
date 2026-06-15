// v23 annotated: sub_1372A8 @ 0x1372a8
// Original: 1372a8_sub_1372A8.c
// Primary struct: <unclustered>
//
// sub_1372A8 @ 0x1372a8, size 48 bytes
int sub_1372A8()
{
  _BYTE *v0; // r2
  char v1; // r3
  unsigned int v2; // r1

  v0 = off_1372D8;
  v1 = *((_BYTE *)off_1372D8 + 3851);
  if ( !v1 )
  {
    v2 = *((unsigned __int16 *)off_1372D8 + 2);
    if ( v2 >= 7 )
      v2 = 7;
    *(_DWORD *)off_1372DC = *(_DWORD *)off_1372DC & 0xFFFFFE3F | (v2 << 6);
  }
  v0[3851] = v1 + 1;
  sub_1383E0();
  return 0;
}

