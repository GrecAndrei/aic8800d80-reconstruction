// log_printf @ 0x10dc24, size 28 bytes
int log_printf(int a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, a1);
  return prepare_debug_buffer(a1, (int)varg_r1);
}

