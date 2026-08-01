// debug_printf @ 0x10dae4, size 28 bytes
int debug_printf(int a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, a1);
  return stack_struct_init(a1, (int)varg_r1);
}

