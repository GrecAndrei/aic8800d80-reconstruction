// rf_timer_toggle @ 0x12f060, size 90 bytes
// Doc: rf_timer_toggle [rf]: Toggle RF timer state
// rf_timer_toggle [rf]: Toggle RF timer state
int rf_timer_toggle()
{
  _BYTE *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = off_12F0BC;
  v1 = event_queue_push(1070, 1);
  v2 = (char)*(_DWORD *)(v0 + 0x4);
  if ( v2 == 1 )
  {
    rf_timer_toggle_start();
    timer_set_relative(1070, 1, dword_12F0C0);
    *(_DWORD *)(v0 + 0x4) = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      rf_timer_toggle_update(v1);
      timer_set_relative(1070, 1, 1000 * *((_DWORD *)off_12F0C4 + 91));
      *(_DWORD *)(v0 + 0x4) = 1;
    }
    return 0;
  }
}

