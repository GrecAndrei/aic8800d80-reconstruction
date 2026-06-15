// v23 annotated: rf_hw_timer_read @ 0x10dea0
// Original: 10dea0_rf_hw_timer_read.c
// Primary struct: <unclustered>
//
// rf_hw_timer_read @ 0x10dea0, size 72 bytes
// Doc: rf_hw_timer_read [rf]: Read RF hardware timer from 0x4010d000
// rf_hw_timer_read [rf]: Read RF hardware timer from 0x4010d000
int rf_hw_timer_read()
{
  _DWORD *v0; // r3
  __int64 v1; // r0
  __int64 v2; // r0
  __int64 v3; // r0
  int v4; // r0

  while ( *((_DWORD *)off_10DF00 + 7) != 1 )
    ;
  v0 = off_10DF00;
  *((_DWORD *)off_10DF00 + 7) = 1;
  v1 = sub_142A50(v0[4]);
  v2 = sub_142B44(v1, HIDWORD(v1), dword_10DEE8, dword_10DEEC);
  v3 = sub_142D98(v2, HIDWORD(v2), dword_10DEF0, dword_10DEF4);
  v4 = sub_1427D4(v3, HIDWORD(v3), dword_10DEF8, dword_10DEFC);
  return sub_143108(v4);
}

