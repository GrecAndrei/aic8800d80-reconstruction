// v23 annotated: sub_107CC8 @ 0x107cc8
// Original: 107cc8_sub_107CC8.c
// Primary struct: <unclustered>
//
// sub_107CC8 @ 0x107cc8, size 104 bytes
int sub_107CC8()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r2
  int result; // r0
  _DWORD *v3; // r2
  int v4; // r3

  v0 = off_107D30;
  sub_107370();
  *v0 &= ~1u;
  sub_100644(1);
  v1 = off_107D34;
  *(_DWORD *)off_107D34 = *(_DWORD *)off_107D34 & 0xCFFFFFFF | 0x10000000;
  *v1 |= 0x40000000u;
  result = sub_100644(1);
  v3 = off_107D38;
  *v0 |= 1u;
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (unsigned __int16)(v4 - 1);
    while ( v4 );
  }
  *(_DWORD *)off_107D30 &= ~1u;
  return result;
}

