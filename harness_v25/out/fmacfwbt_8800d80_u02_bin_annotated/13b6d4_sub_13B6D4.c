// fwstruct annotate: 13b6d4_sub_13B6D4.c
// sub_13B6D4 @ 0x13b6d4, size 50 bytes
// Doc: sub_123B6D4 [bt]: Helper in BT firmware, dispatches based on return value
// sub_123B6D4 [bt]: Helper in BT firmware, dispatches based on return value
int __fastcall sub_13B6D4(int a1, int a2, unsigned int a3)
{
  if ( msg_get_value(a3) == 2 )
  {
    rx_entry_lookup(a3 >> 8);
    list_push_tail(dword_13B70C, (_DWORD *)(dword_13B708 + 32 * (a3 >> 8)));
    rf_bus_mark_n_3b7(a3, 0);
  }
  return 0;
}

