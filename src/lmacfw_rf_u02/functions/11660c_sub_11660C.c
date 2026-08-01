// log_and_disable_irq @ 0x11660c, size 22 bytes
int log_and_disable_irq()
{
  check_kernel_state(dword_116624);
  return set_busy_flag_alt(0x200000);
}

