// fwstruct annotate: 10dc24_sub_10DC24.c
// sub_10DC24 @ 0x10dc24, size 28 bytes
int sub_10DC24(int a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, a1);
  return sdio_transfer_808(a1, (int)varg_r1);
}

