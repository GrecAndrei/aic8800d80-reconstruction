// sub_1306CC @ 0x1306cc, size 62 bytes
unsigned int sub_1306CC()
{
  int v0; // s15
  int v1; // r3

  v0 = (int)COERCE_FLOAT(rf_hw_timer_read());
  sub_12ECB0(dword_13070C, v0);
  v1 = (char)v0 - *((char *)off_130710 + 3);
  if ( v1 < 0 )
    v1 = *((char *)off_130710 + 3) - (char)v0;
  if ( v1 > 4 )
  {
    *((_BYTE *)off_130710 + 3) = v0;
    sub_13064C((char)v0);
  }
  return rf_level_step_04e0();
}

