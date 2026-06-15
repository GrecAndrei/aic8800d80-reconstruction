// v23 annotated: sub_11BBA4 @ 0x11bba4
// Original: 11bba4_sub_11BBA4.c
// Primary struct: <unclustered>
//
// sub_11BBA4 @ 0x11bba4, size 392 bytes
// Doc: sub_121BBA4 [unknown]: Init handler reading control byte from 0x1863b0+0x80 and struct fields
// sub_121BBA4 [unknown]: Init handler reading control byte from 0x1863b0+0x80 and struct fields
int __fastcall sub_11BBA4(unsigned __int8 *a1, int a2)
{
  _BYTE *v2; // r7
  int v5; // r5
  unsigned int v6; // r3
  _DWORD *v7; // r4
  char v8; // r3
  int v10; // r0
  _BYTE *v11; // r2
  __int16 v12; // r2
  unsigned int v13; // r2
  int v14; // r3
  _BYTE *v15; // r2
  int v16; // r0
  int v17; // r0

  v2 = off_11BD2C;
  sub_11F74C(8, dword_11BD30, *a1, *((_DWORD *)a1 + 3));
  v5 = *a1;
  if ( *a1 )
  {
    if ( v5 == 1 )
    {
      if ( (unsigned __int8)v2[136] == 255 )
        return 0;
      v6 = (unsigned __int8)v2[128];
      v7 = off_11BD34;
      if ( v6 > 3 )
      {
        if ( v6 == 4 )
        {
          timestamp_remove((int)off_11BD34 + 64);
          v10 = v7[8];
          v7[18] = 0;
          rf_chan_init_n4e8(v10);
        }
      }
      else if ( v6 > 1 )
      {
        v11 = *((_BYTE **)off_11BD34 + 11);
        *((_BYTE *)off_11BD34 + 88) &= ~4u;
        if ( v11 )
        {
          if ( v11 == v2 + 112 && (_BYTE *)v7[20] == v11 )
          {
            timestamp_remove((int)(v7 + 16));
            v7[18] = 0;
          }
          v7[11] = 0;
        }
        ipc_msg_send_n_d58(dword_11BD38);
      }
      else if ( v6 == 1 )
      {
        *((_BYTE *)off_11BD34 + 88) &= 0xFAu;
        ipc_msg_send_n_d58((int)(v2 + 112));
      }
      v8 = *((_BYTE *)v7 + 88);
      v2[136] = -1;
      if ( (v8 & 0x12) != 0x10 )
        return 0;
      v16 = dword_11BD40;
      *((_BYTE *)v7 + 88) = v8 & 0xEF;
      v5 = 0;
      timestamp_remove(v16);
      return v5;
    }
    return 1;
  }
  if ( (unsigned __int8)v2[136] == 255 && v2[128] != 4 )
  {
    v2[136] = 4;
    v2[116] = a1[2];
    v2[117] = a1[3];
    v12 = *((_WORD *)a1 + 3);
    *((_WORD *)v2 + 59) = *((_WORD *)a1 + 2);
    *((_WORD *)v2 + 61) = *((_WORD *)a1 + 4);
    *((_WORD *)v2 + 60) = v12;
    v2[124] = a1[16];
    v2[128] = 1;
    v2[125] = v5;
    v13 = *((_DWORD *)a1 + 3);
    *((_WORD *)v2 + 63) = a2;
    v14 = 1000 * v13;
    if ( v13 > 0x23 )
      v14 -= 35000;
    *((_DWORD *)v2 + 33) = v14;
    v15 = off_11BD34;
    v2[138] = a1[1];
    if ( a2 )
    {
      v15[88] |= 1u;
      phy_flag_check_or_set();
    }
    else
    {
      v17 = dword_11BD38;
      v15[88] |= 4u;
      rf_mailbox_post_n44(v17);
    }
    *(_DWORD *)off_11BD3C |= 4u;
    return v5;
  }
  if ( (*((_BYTE *)off_11BD34 + 88) & 0x20) == 0 )
    return 1;
  *((_BYTE *)off_11BD34 + 88) &= ~0x20u;
  return 1;
}

