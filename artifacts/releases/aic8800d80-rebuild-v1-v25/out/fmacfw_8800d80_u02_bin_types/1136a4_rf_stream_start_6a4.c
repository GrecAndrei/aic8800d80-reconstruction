// rf_stream_start_6a4 @ 0x1136a4, size 14 bytes
// Doc: rf_stream_start_6a4 [rf]: start RF data stream
// rf_stream_start_6a4 [rf]: start RF data stream
int  rf_stream_start_6a4(unsigned int a1)
{
  if ( a1 > 7 )
    return 0;
  else
    return *(uint32_t *)(rf_stream_start_6b4 + 4 * a1);
}

