// log_printf @ 0x10da6c, size 28 bytes
int log_printf(int a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, a1);
  return hci_cmd_init(a1, (int)varg_r1);
}

