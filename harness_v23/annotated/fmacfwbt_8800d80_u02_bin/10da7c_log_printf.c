// v23 annotated: log_printf @ 0x10da7c
// Original: 10da7c_log_printf.c
// Primary struct: <unclustered>
//
// log_printf @ 0x10da7c, size 28 bytes
// Doc: log_printf [util]: Variadic log printf forwarding to core formatter
// log_printf [util]: Variadic log printf forwarding to core formatter
int log_printf(int a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, a1);
  return sdio_transfer(a1, (int)varg_r1);
}

