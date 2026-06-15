// v23 annotated: rf_mailbox_post_n44 @ 0x11b1a4
// Original: 11b1a4_rf_mailbox_post_n44.c
// Primary struct: <unclustered>
//
// rf_mailbox_post_n44 @ 0x11b1a4, size 256 bytes
// Doc: rf_mailbox_post_n44 [ipc]: Post message into RF mailbox peripheral
// rf_mailbox_post_n44 [ipc]: Post message into RF mailbox peripheral
int __fastcall rf_mailbox_post_n44(int result)
{
  _BYTE *v1; // r4
  int v2; // r5
  int v3; // r6
  int v4; // r7
  char v5; // r3
  int v6; // r9
  int v7; // r7
  int v8; // r8
  int v9; // r6
  int v10; // r10
  int v11; // r0
  int v12; // r3

  v1 = off_11B2AC;
  v2 = result;
  v3 = *((_DWORD *)off_11B2A4 + 4) + *(_DWORD *)(result + 20);
  if ( result != dword_11B2A8 || (*((_BYTE *)off_11B2AC + 88) & 4) != 0 )
  {
    if ( *((_DWORD *)off_11B2AC + 10) != result )
    {
      result = sub_101A20();
      v3 += 4000 + result;
    }
    v4 = (unsigned __int8)v1[91];
    v5 = v1[88];
    *((_DWORD *)v1 + 20) = v2;
    *((_DWORD *)v1 + 21) = v3;
    if ( v4 )
    {
      v1[88] = v5 | 0x40;
    }
    else
    {
      v1[88] = v5 & 0xBF;
      rf_init_or_query();
      result = rf_xosc_setup(v3, 0, 0);
      v6 = *((_DWORD *)v1 + 4);
      if ( v6 )
      {
        v7 = dword_11B2B4;
        v8 = dword_11B2C4;
        v9 = dword_11B2B0 - v3;
        do
        {
          v10 = *(_DWORD *)(v6 + 4);
          result = v10 - sub_101A20();
          if ( result + v9 >= 0 )
            break;
          v11 = v7 + 224 * *(unsigned __int8 *)(v6 + 8);
          v12 = 102400;
          if ( !*(_BYTE *)(v11 + 94) )
            v12 = *(_DWORD *)(v8 + 152 * *(unsigned __int8 *)(v11 + 102) + 8);
          result = rf_cal_or_init_handler(v11, *(_DWORD *)(v6 + 4) + v12, 0);
          v6 = *((_DWORD *)v1 + 4);
        }
        while ( v6 );
      }
      if ( *((_DWORD *)v1 + 11) )
      {
        if ( **(__int16 **)off_11B2B8 < 0 && (v1[88] & 0xC) == 0 )
          return rf_cmd_send_n264(dword_11B2C0, dword_11B2BC, 1698);
      }
      else
      {
        return sub_11ADD0(v2);
      }
    }
  }
  else
  {
    *((_BYTE *)off_11B2AC + 88) &= ~0x40u;
  }
  return result;
}

