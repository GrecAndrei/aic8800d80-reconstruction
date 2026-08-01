// rf_store_cal_byte @ 0x12529c, size 18 bytes
int rf_store_cal_byte()
{
  dispatch_event_handler(dword_1252B4, *(char *)off_1252B0);
  return 0;
}

