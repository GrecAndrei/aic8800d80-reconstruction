// rf_stream_start2_n2b4 @ 0x113500, size 14 bytes
// Doc: rf_stream_start2_n2b4 [rf]: Looks up RF stream handler by stream id and starts it.
// rf_stream_start2_n2b4 [rf]: Looks up RF stream handler by stream id and starts it.
int __fastcall rf_stream_start2_n2b4(unsigned int a1)
{
  if ( a1 > 7 )
    return 0;
  else
    return *(_DWORD *)(rf_stream_start2_n2c4 + 4 * a1);
}

