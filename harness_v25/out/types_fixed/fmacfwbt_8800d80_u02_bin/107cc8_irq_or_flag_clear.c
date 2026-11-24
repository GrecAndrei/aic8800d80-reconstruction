// irq_or_flag_clear @ 0x107cc8, size 104 bytes
// Doc: irq_or_flag_clear [util]: Clears bit 0 in a flag register and invokes a callback.
// irq_or_flag_clear [util]: Clears bit 0 in a flag register and invokes a callback.
int irq_or_flag_clear()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r2
  int result; // r0
  _DWORD *v3; // r2
  int v4; // r3

  v0 = off_107D30;
  sub_107370();
  *v0 &= ~1u;
  delay_us(1);
  v1 = off_107D34;
  *(_DWORD *)off_107D34 = *(_DWORD *)off_107D34 & 0xCFFFFFFF | 0x10000000;
  *v1 |= 0x40000000u;
  result = delay_us(1);
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

