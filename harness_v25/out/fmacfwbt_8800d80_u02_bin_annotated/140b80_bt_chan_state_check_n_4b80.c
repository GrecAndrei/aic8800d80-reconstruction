// fwstruct annotate: 140b80_bt_chan_state_check_n_4b80.c
// bt_chan_state_check_n_4b80 @ 0x140b80, size 130 bytes
// Doc: bt_chan_state_check_n_4b80 [bt]: Check BT channel state byte against expected value 3
// bt_chan_state_check_n_4b80 [bt]: Check BT channel state byte against expected value 3
int __fastcall bt_chan_state_check_n_4b80(int result, int a2)
{
  int v2; // r6
  unsigned int v3; // r4
  int v4; // r7
  int v5; // r3
  int v7; // r0
  int v8; // r4

  v2 = dword_140C04;
  v3 = *(unsigned __int8 *)(dword_140C04 + 6489);
  if ( v3 <= 3 && *(unsigned __int8 *)(dword_140C04 + 6488) <= 0x1Fu )
  {
    v4 = result;
    v5 = *(_DWORD *)(dword_140C08 + 1320 * v3 + 72);
    v7 = v5 ? *(unsigned __int8 *)(v5 + 4) : *((unsigned __int8 *)off_140C10 + 36);
    result = sub_119084(v7 != 0, 512);
    v8 = result;
    if ( result )
    {
      *(_BYTE *)(result + 28) = *(_BYTE *)(v2 + 6489);
      *(_BYTE *)(result + 29) = *(_BYTE *)(v2 + 6488);
      *(_BYTE *)(result + 51) = 0;
      *(_BYTE *)(result + 53) = 0;
      if ( !a2 )
      {
        *(_DWORD *)(result + 88) = dword_140C0C;
        *(_DWORD *)(result + 92) = result;
      }
      sub_1405DC(result, 1, a2, v4);
      return sub_1190B4(v8, 3);
    }
  }
  return result;
}

