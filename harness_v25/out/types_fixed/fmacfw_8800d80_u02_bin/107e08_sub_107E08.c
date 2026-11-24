// sub_107E08 @ 0x107e08, size 92 bytes
int sub_107E08()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r3
  int result; // r0
  _DWORD *v3; // r2
  int v4; // r3

  v0 = off_107E64;
  crypto_engine_clear_sram_regs();
  *v0 &= ~1u;
  delay_us_0644(1);
  v1 = off_107E68;
  *(_DWORD *)off_107E68 &= 0xCFFFFFFF;
  *v1 |= 0x40000000u;
  result = delay_us_0644(1);
  v3 = off_107E6C;
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (unsigned __int16)(v4 - 1);
    while ( v4 );
  }
  *(_DWORD *)off_107E64 &= ~1u;
  return result;
}

