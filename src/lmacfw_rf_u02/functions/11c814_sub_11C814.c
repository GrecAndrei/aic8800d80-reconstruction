// init_three_entries @ 0x11c814, size 30 bytes
int *init_three_entries()
{
  tx_slot_get_busy(0);
  tx_slot_get_busy(1);
  tx_slot_get_busy(2);
  return tx_slot_get_busy(3);
}

