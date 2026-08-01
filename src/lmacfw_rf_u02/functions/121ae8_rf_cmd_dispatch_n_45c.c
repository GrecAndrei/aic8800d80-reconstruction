// return_0_tail @ 0x121ae8, size 6 bytes
// Doc: return_0_tail [rf]: Dispatch incoming RF commands to handlers
// return_0_tail [rf]: Dispatch incoming RF commands to handlers
int return_0_tail()
{
  return handle_interrupt_save(0);
}

