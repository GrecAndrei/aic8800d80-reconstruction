// v23 annotated: rf_timer_toggle_start @ 0x130370
// Original: 130370_rf_timer_toggle_start.c
// Primary struct: <unclustered>
//
// rf_timer_toggle_start @ 0x130370, size 4 bytes
// Doc: rf_timer_toggle_start [rf]: Toggles and starts an RF timer
// rf_timer_toggle_start [rf]: Toggles and starts an RF timer
// attributes: thunk
int rf_timer_toggle_start()
{
  return rf_cmd_send_1();
}

