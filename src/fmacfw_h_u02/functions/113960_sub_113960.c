// init_bt_stack @ 0x113960, size 18 bytes
int init_bt_stack()
{
  int v0; // r1
  int v1; // r2

  bt_wait_ready(dword_113974);
  alloc_tx_event(dword_113978, v0, v1);
  return 1;
}

