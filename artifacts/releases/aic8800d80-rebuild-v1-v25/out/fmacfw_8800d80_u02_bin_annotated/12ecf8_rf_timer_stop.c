// fwstruct annotate: 12ecf8_rf_timer_stop.c
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

