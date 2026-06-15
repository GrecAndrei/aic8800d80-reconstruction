// v23 annotated: sub_107C60 @ 0x107c60
// Original: 107c60_sub_107C60.c
// Primary struct: <unclustered>
//
// sub_107C60 @ 0x107c60, size 92 bytes
// Doc: sub_1207C60 [util]: Clear low bit of 0x403420c8 register and trigger callback
// sub_1207C60 [util]: Clear low bit of 0x403420c8 register and trigger callback
int sub_107C60()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r3
  int result; // r0
  _DWORD *v3; // r2
  int v4; // r3

  v0 = off_107CBC;
  sub_107370();
  *v0 &= ~1u;
  delay_us(1);
  v1 = off_107CC0;
  *(_DWORD *)off_107CC0 &= 0xCFFFFFFF;
  *v1 |= 0x40000000u;
  result = delay_us(1);
  v3 = off_107CC4;
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (unsigned __int16)(v4 - 1);
    while ( v4 );
  }
  *(_DWORD *)off_107CBC &= ~1u;
  return result;
}

