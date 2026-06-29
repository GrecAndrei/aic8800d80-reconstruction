// fwstruct annotate: 130370_rf_timer_toggle_start.c
// rf_timer_toggle_start @ 0x130370, size 62 bytes
unsigned int rf_timer_toggle_start()
{
  int v0; // s15
  int v1; // r3

  v0 = (int)COERCE_FLOAT(sub_10DF08());
  sub_12E948(dword_1303B0, v0);
  v1 = (char)v0 - *((char *)off_1303B4 + 3);
  if ( v1 < 0 )
    v1 = *((char *)off_1303B4 + 3) - (char)v0;
  if ( v1 > 4 )
  {
    *((_BYTE *)off_1303B4 + 3) = v0;
    sub_1302F0((char)v0);
  }
  return sub_130184();
}

