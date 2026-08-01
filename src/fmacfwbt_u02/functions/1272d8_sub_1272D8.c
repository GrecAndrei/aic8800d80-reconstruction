// check_irq_handler @ 0x1272d8, size 22 bytes
int check_irq_handler()
{
  int v0; // r0
  int result; // r0

  v0 = mac_cmd_send();
  result = timer_tick_handler(v0);
  if ( !result )
    return tx_ready_check();
  return result;
}

