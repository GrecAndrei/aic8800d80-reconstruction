// v23 annotated: sub_1371A4 @ 0x1371a4
// Original: 1371a4_sub_1371A4.c
// Primary struct: <unclustered>
//
// sub_1371A4 @ 0x1371a4, size 48 bytes
// Doc: sub_12371A4 [util]: Helper reading shared flag/state at offset 0xf0b
// sub_12371A4 [util]: Helper reading shared flag/state at offset 0xf0b
int sub_1371A4()
{
  _BYTE *v0; // r2
  char v1; // r3
  unsigned int v2; // r1

  v0 = off_1371D4;
  v1 = *((_BYTE *)off_1371D4 + 3851);
  if ( !v1 )
  {
    v2 = *((unsigned __int16 *)off_1371D4 + 2);
    if ( v2 >= 7 )
      v2 = 7;
    *(_DWORD *)off_1371D8 = *(_DWORD *)off_1371D8 & 0xFFFFFE3F | (v2 << 6);
  }
  v0[3851] = v1 + 1;
  sub_1382DC();
  return 0;
}

