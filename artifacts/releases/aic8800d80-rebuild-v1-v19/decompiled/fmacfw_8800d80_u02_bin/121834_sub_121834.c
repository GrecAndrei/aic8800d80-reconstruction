// sub_121834 @ 0x121834, size 84 bytes
unsigned int sub_121834()
{
  __int16 **v0; // r0
  int v1; // r3
  int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  int v5; // r1
  _DWORD *v6; // r2

  v0 = (__int16 **)off_12188C;
  v1 = dword_121890;
  *(_DWORD *)off_121888 |= 2u;
  v2 = (int *)off_121894;
  v3 = **v0;
  *(_DWORD *)off_121894 = v1;
  if ( v3 < 0 && *(_DWORD *)off_1218A8 << 28 )
  {
    sub_12F49C(dword_1218B0, dword_1218AC, 472);
    v1 = *v2;
  }
  *(_DWORD *)off_121898 = v1 | v2[1];
  result = mmio_reg_bit_modify(0);
  v5 = dword_1218A0;
  v6 = off_1218A4;
  *(_DWORD *)off_12189C = dword_1218A0;
  *v6 |= v5;
  return result;
}

