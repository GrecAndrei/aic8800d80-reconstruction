// fwstruct annotate: 12f7a4_rf_bt_state_check_n0a4.c
// rf_bt_state_check_n0a4 @ 0x12f7a4, size 82 bytes
// Doc: rf_bt_state_check_n0a4 [bt]: Check current BT state against expected value 3
// rf_bt_state_check_n0a4 [bt]: Check current BT state against expected value 3
void __fastcall rf_bt_state_check_n0a4(int a1)
{
  int v2; // r0
  int v3; // r5
  _DWORD *v4; // r4

  if ( **(_BYTE **)off_12F7F8 == 3 )
  {
    v2 = sub_10CAA8();
    v3 = v2;
    if ( v2 )
    {
      *(_DWORD *)(a1 + 24) = 49374;
      sub_14380C(v2, a1, 28);
      v4 = off_12F7FC;
      while ( !*(_DWORD *)off_12F7FC )
        ;
      list_push_tail(*(_DWORD *)off_12F800 + 540, (_DWORD *)(v3 - 4));
      *v4 = 1;
      sub_10CAFC();
    }
    else
    {
      sub_12ECB0(dword_12F804);
    }
  }
}

