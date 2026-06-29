// bt_event_handler @ 0x1267e0, size 56 bytes
// Doc: bt_event_handler [bt]: BT firmware event/task handler
// bt_event_handler [bt]: BT firmware event/task handler
int bt_event_handler()
{
  int result; // r0
  uint32_t *v1; // r4
  char *v2; // r5
  char *v3; // r4

  result = rf_bus_mark_n100_d2d0(dword_126818);
  if ( result )
  {
    v1 = off_12681C;
    timestamp_remove(dword_126820);
    v1[18] = 0;
    v2 = (char *)(v1 + 6);
    v3 = (char *)(v1 + 8);
    do
    {
      list_push_tail(v2);
      result = rf_bus_mark_n100_d2d0(v3);
    }
    while ( result );
  }
  return result;
}

