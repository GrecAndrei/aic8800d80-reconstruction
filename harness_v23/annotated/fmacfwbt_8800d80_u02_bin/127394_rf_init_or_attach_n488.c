// v23 annotated: rf_init_or_attach_n488 @ 0x127394
// Original: 127394_rf_init_or_attach_n488.c
// Primary struct: <unclustered>
//
// rf_init_or_attach_n488 @ 0x127394, size 266 bytes
// Doc: rf_init_or_attach_n488 [rf]: Initialize/attach RF subsystem reading MMIO regs at 0x40501000 and table 0x190c30
// rf_init_or_attach_n488 [rf]: Initialize/attach RF subsystem reading MMIO regs at 0x40501000 and table 0x190c30
int __fastcall rf_init_or_attach_n488(int result)
{
  _BYTE *v1; // r5
  __int64 v2; // r6
  int v3; // r4
  char v4; // r3
  int v5; // r4
  int v6; // r9
  int v7; // r10
  int v8; // r7
  int v9; // r3
  int v10; // r11
  int v11; // r1
  int v12; // r0

  v1 = off_1274A8;
  LODWORD(v2) = result;
  HIDWORD(v2) = *((_DWORD *)off_1274A0 + 4) + *(_DWORD *)(result + 20);
  if ( result != dword_1274A4 || (*((_BYTE *)off_1274A8 + 88) & 4) != 0 )
  {
    if ( *((_DWORD *)off_1274A8 + 10) != result )
    {
      result = sub_10186C();
      HIDWORD(v2) += 4000 + result;
    }
    v3 = (unsigned __int8)v1[91];
    v4 = v1[88];
    *((_QWORD *)v1 + 10) = v2;
    if ( v3 )
    {
      v1[88] = v4 | 0x40;
    }
    else
    {
      v1[88] = v4 & 0xBF;
      fmacfwbt_init_load();
      result = rf_chan_table_lookup_n938(SHIDWORD(v2), 0, 0);
      v5 = *((_DWORD *)v1 + 4);
      if ( v5 )
      {
        v6 = dword_1274BC;
        v7 = dword_1274C0;
        v8 = dword_1274AC - HIDWORD(v2);
        while ( 1 )
        {
          v10 = *(_DWORD *)(v5 + 4);
          result = v10 - sub_10186C();
          if ( result + v8 >= 0 )
            break;
          v11 = *(_DWORD *)(v5 + 4);
          v12 = v6 + 1320 * *(unsigned __int8 *)(v5 + 8);
          v9 = 102400;
          if ( *(_BYTE *)(v12 + 106) )
          {
            if ( *(_BYTE *)(v12 + 106) == 2 )
              v9 = *(unsigned __int16 *)(v12 + 222) << 10;
            result = bt_rf_calibrate_or_setup(v12, v11 + v9, 0);
            v5 = *((_DWORD *)v1 + 4);
            if ( !v5 )
              break;
          }
          else
          {
            result = bt_rf_calibrate_or_setup(v12, v11 + *(_DWORD *)(v7 + 696 * *(unsigned __int8 *)(v12 + 116) + 8), 0);
            v5 = *((_DWORD *)v1 + 4);
            if ( !v5 )
              break;
          }
        }
      }
      if ( *((_DWORD *)v1 + 11) )
      {
        if ( **(__int16 **)off_1274B0 < 0 && (v1[88] & 0xC) == 0 )
          return sub_12F694(dword_1274B8, dword_1274B4, 1698);
      }
      else
      {
        return sub_1272F0(v2);
      }
    }
  }
  else
  {
    *((_BYTE *)off_1274A8 + 88) &= ~0x40u;
  }
  return result;
}

