// fwstruct annotate: 130590_rf_temp_read_n590.c
// rf_temp_read_n590 @ 0x130590, size 38 bytes
// Doc: rf_temp_read_n590 [rf]: Reads signed byte from RF register and forwards value via sub_10dea0
// rf_temp_read_n590 [rf]: Reads signed byte from RF register and forwards value via sub_10dea0
int rf_temp_read_n590()
{
  if ( *((_BYTE *)off_1305B8 + 1) )
    return *((char *)off_1305B8 + 3);
  rf_hw_timer_init();
  return (int)COERCE_FLOAT(rf_hw_timer_read());
}

