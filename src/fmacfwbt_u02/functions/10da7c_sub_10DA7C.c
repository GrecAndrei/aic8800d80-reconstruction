// printf_wrapper @ 0x10da7c, size 28 bytes
int printf_wrapper(int a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, a1);
  return debug_printf(a1, (int)varg_r1);
}

