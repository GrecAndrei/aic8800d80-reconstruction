// v23 annotated: sub_113814 @ 0x113814
// Original: 113814_sub_113814.c
// Primary struct: <unclustered>
//
// sub_113814 @ 0x113814, size 124 bytes
// Doc: rf_stream_start_n4c8 [rf]: Starts RF stream by enabling engine and reading control structure
// rf_stream_start_n4c8 [rf]: Starts RF stream by enabling engine and reading control structure
int sub_113814()
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

  v0 = off_113890;
  result = sub_12D240(dword_113894);
  if ( *(_WORD *)(*(_DWORD *)v0 + 8) )
  {
    v2 = off_1138A4;
    v3 = off_113898;
    v4 = dword_1138A8;
    v5 = rf_stream_start2_n4bc_38ac;
    v6 = (__int16 **)rf_cmd_queue_next_38b0;
    v7 = 0;
    do
    {
      if ( !sub_10FB28(v4, (unsigned __int16)(v2[153] - 4)) )
      {
        msg_parse(v5, v7, v9);
        if ( **v6 < 0 )
          sub_12F46C(rf_msg_process_body_n_3a8, dword_11389C, 495);
      }
      result = list_push_tail(dword_113894);
      v8 = *(unsigned __int16 *)(*(_DWORD *)v0 + 8);
      ++v7;
      ++*v3;
    }
    while ( v8 > v7 );
  }
  return result;
}

