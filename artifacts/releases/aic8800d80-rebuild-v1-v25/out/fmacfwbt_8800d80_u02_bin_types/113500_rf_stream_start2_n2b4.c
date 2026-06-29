// rf_stream_start2_n2b4 @ 0x113500, size 14 bytes
// Doc: rf_stream_start2_n2b4 [rf]: Looks up RF stream handler by stream id and starts it.
// rf_stream_start2_n2b4 [rf]: Looks up RF stream handler by stream id and starts it.
int  rf_stream_start2_n2b4(unsigned int a1)
{
  if ( a1 > 7 )
    return 0;
  else
    return *(uint32_t *)(rf_stream_start2_n2c4 + 4 * a1);
}

