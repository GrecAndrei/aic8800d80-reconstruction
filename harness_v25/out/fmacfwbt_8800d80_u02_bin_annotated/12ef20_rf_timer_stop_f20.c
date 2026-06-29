// fwstruct annotate: 12ef20_rf_timer_stop_f20.c
// rf_timer_stop_f20 @ 0x12ef20, size 32 bytes
// Doc: rf_timer_stop_f20 [rf]: Stops RF timer, disables timer interrupt
// rf_timer_stop_f20 [rf]: Stops RF timer, disables timer interrupt
int rf_timer_stop_f20()
{
  sub_12ECB0(dword_12EF40);
  sub_12C964(1071, 1);
  *((_DWORD *)off_12EF44 + 20) &= ~2u;
  return 0;
}

