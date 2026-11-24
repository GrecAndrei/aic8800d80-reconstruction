// sub_1077F8 @ 0x1077f8, size 92 bytes
int sub_1077F8()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r3
  int result; // r0
  _DWORD *v3; // r2
  int v4; // r3

  v0 = off_107854;
  crypto_hw_clear_regs();
  *v0 &= ~1u;
  delay_us(1);
  v1 = off_107858;
  *(_DWORD *)off_107858 &= 0xCFFFFFFF;
  *v1 |= 0x40000000u;
  result = delay_us(1);
  v3 = off_10785C;
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (unsigned __int16)(v4 - 1);
    while ( v4 );
  }
  *(_DWORD *)off_107854 &= ~1u;
  return result;
}

