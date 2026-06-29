// fwstruct annotate: 1304b0_rf_timer_toggle_update.c
// rf_timer_toggle_update @ 0x1304b0, size 62 bytes
// Doc: rf_timer_toggle_update [rf]: Update RF timer toggle value via float-to-int conversion
// rf_timer_toggle_update [rf]: Update RF timer toggle value via float-to-int conversion
unsigned int rf_timer_toggle_update()
{
  int v0; // s15
  int v1; // r3

  v0 = (int)COERCE_FLOAT(rf_hw_timer_read());
  msg_parse(dword_1304F0, v0);
  v1 = (char)v0 - *((char *)off_1304F4 + 3);
  if ( v1 < 0 )
    v1 = *((char *)off_1304F4 + 3) - (char)v0;
  if ( v1 > 4 )
  {
    *((_BYTE *)off_1304F4 + 3) = v0;
    rf_level_compute((char)v0);
  }
  return rf_level_step_02c4();
}

