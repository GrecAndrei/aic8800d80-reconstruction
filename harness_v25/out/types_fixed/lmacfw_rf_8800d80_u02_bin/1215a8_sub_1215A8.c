// sub_1215A8 @ 0x1215a8, size 90 bytes
int sub_1215A8()
{
  _BYTE *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = off_121604;
  v1 = event_queue_push(1070, 1);
  v2 = (char)*(_DWORD *)(v0 + 0x4);
  if ( v2 == 1 )
  {
    rf_level_apply_n78();
    timer_set_relative(1070, 1, dword_121608);
    *(_DWORD *)(v0 + 0x4) = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      rf_level_apply_n1b8(v1);
      timer_set_relative(1070, 1, 1000 * *((_DWORD *)off_12160C + 91));
      *(_DWORD *)(v0 + 0x4) = 1;
    }
    return 0;
  }
}

