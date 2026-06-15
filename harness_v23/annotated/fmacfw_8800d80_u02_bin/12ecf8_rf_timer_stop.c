// v23 annotated: rf_timer_stop @ 0x12ecf8
// Original: 12ecf8_rf_timer_stop.c
// Primary struct: <unclustered>
//
// rf_timer_stop @ 0x12ecf8, size 32 bytes
// Doc: rf_timer_stop [rf]: Stop RF hardware timer
// rf_timer_stop [rf]: Stop RF hardware timer
int rf_timer_stop()
{
  msg_parse(dword_12ED18);
  event_queue_push(1071, 1);
  *((_DWORD *)off_12ED1C + 20) &= ~2u;
  return 0;
}

