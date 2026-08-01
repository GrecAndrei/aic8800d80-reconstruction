// jump_10d02c @ 0x121a58, size 4 bytes
// Doc: jump_10d02c [rf]: Dispatch RF command from queue
// jump_10d02c [rf]: Dispatch RF command from queue
// attributes: thunk
int jump_10d02c()
{
  return rf_irq_handler();
}

