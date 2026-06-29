// fwstruct annotate: 107860_sub_107860.c
// sub_107860 @ 0x107860, size 104 bytes
int sub_107860()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r2
  int result; // r0
  _DWORD *v3; // r2
  int v4; // r3

  v0 = off_1078C8;
  crypto_hw_clear_regs();
  *v0 &= ~1u;
  delay_us(1);
  v1 = off_1078CC;
  *(_DWORD *)off_1078CC = *(_DWORD *)off_1078CC & 0xCFFFFFFF | 0x10000000;
  *v1 |= 0x40000000u;
  result = delay_us(1);
  v3 = off_1078D0;
  *v0 |= 1u;
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (unsigned __int16)(v4 - 1);
    while ( v4 );
  }
  *(_DWORD *)off_1078C8 &= ~1u;
  return result;
}

