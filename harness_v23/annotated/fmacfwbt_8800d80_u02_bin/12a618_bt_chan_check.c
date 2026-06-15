// v23 annotated: bt_chan_check @ 0x12a618
// Original: 12a618_bt_chan_check.c
// Primary struct: <unclustered>
//
// bt_chan_check @ 0x12a618, size 106 bytes
// Doc: bt_chan_check [bt]: Check BT channel/status byte (offset 0x18) against 0x7F
// bt_chan_check [bt]: Check BT channel/status byte (offset 0x18) against 0x7F
int __fastcall bt_chan_check(int result, _BYTE *a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r6
  int v6; // r5
  int v7; // [sp+4h] [bp-4h]

  if ( a2[24] == 127 && !a2[29] && (unsigned __int8)a2[31] == 221 && a2[36] == 9 )
  {
    v4 = (int)(a2 + 37);
    if ( a2[37] == 12 )
    {
      v5 = *(unsigned __int8 *)(result + 1225);
      v6 = result;
      if ( **(__int16 **)off_12A684 < 0 )
      {
        if ( *(_BYTE *)(result + 106) )
        {
          v7 = a4;
          sub_12F694(dword_12A68C, dword_12A688, 64);
          a4 = v7;
        }
      }
      return sub_129FAC(v5, v4, *(_DWORD *)(v6 + 132) + a4);
    }
  }
  return result;
}

