// sub_113670 @ 0x113670, size 124 bytes
// Doc: rf_stream_start2_n460 [rf]: Start RF stream variant 2 with argument
// rf_stream_start2_n460 [rf]: Start RF stream variant 2 with argument
int sub_113670()
{
  void *v0; // r7
  int result; // r0
  _WORD *v2; // r9
  _WORD *v3; // r6
  int v4; // r8
  int v5; // r11
  __int16 **v6; // r10
  unsigned __int16 v7; // r5
  unsigned int v8; // r1
  int v9; // r2

  v0 = rf_stream_start2_n4a0;
  result = bt_xtal_init_check(rf_stream_start2_n4a4);
  if ( *(_WORD *)(*(_DWORD *)v0 + 8) )
  {
    v2 = rf_stream_start2_3700;
    v3 = rf_stream_start2_n4a8;
    v4 = dword_113704;
    v5 = rf_stream_start2_n4bc;
    v6 = (__int16 **)rf_stream_cmd_dispatch;
    v7 = 0;
    do
    {
      if ( !log_pool_alloc2(v4, (unsigned __int16)(v2[153] - 4)) )
      {
        sub_12ECB0(v5, v7, v9);
        if ( **v6 < 0 )
          sub_12F694(rf_stream_start2_n4b0, rf_stream_start2_n4ac, 495);
      }
      result = list_push_tail(rf_stream_start2_n4a4);
      v8 = *(unsigned __int16 *)(*(_DWORD *)v0 + 8);
      ++v7;
      ++*v3;
    }
    while ( v8 > v7 );
  }
  return result;
}

