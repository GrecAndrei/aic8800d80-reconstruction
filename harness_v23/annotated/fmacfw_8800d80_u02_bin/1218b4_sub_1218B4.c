// v23 annotated: sub_1218B4 @ 0x1218b4
// Original: 1218b4_sub_1218B4.c
// Primary struct: <unclustered>
//
// sub_1218B4 @ 0x1218b4, size 90 bytes
unsigned int sub_1218B4()
{
  __int16 **v0; // r0
  int v1; // r3
  int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  _DWORD *v5; // r2

  v0 = (__int16 **)off_121914;
  v1 = dword_121918;
  *(_DWORD *)off_121910 &= ~2u;
  v2 = (int *)off_12191C;
  v3 = **v0;
  *(_DWORD *)off_12191C = v1;
  if ( v3 < 0 && *(_DWORD *)off_121930 << 28 )
  {
    sub_12F49C(dword_121938, dword_121934, 472);
    v1 = *v2;
  }
  *(_DWORD *)off_121920 = v1 | v2[1];
  result = mmio_reg_bit_modify(0);
  v5 = off_121928;
  *(_DWORD *)off_121924 = dword_12192C;
  *v5 &= 0xFFFBFFFE;
  return result;
}

