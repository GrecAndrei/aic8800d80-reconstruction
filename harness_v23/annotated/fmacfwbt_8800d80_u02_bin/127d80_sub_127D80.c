// v23 annotated: sub_127D80 @ 0x127d80
// Original: 127d80_sub_127D80.c
// Primary struct: <unclustered>
//
// sub_127D80 @ 0x127d80, size 446 bytes
int __fastcall sub_127D80(unsigned __int8 *a1, int a2)
{
  _BYTE *v2; // r7
  int v5; // r5
  unsigned int v6; // r3
  _DWORD *v7; // r8
  char v8; // r3
  _BYTE *v10; // r8
  char v11; // r3
  int v12; // r0
  _BYTE *v13; // r2
  __int16 v14; // r1
  unsigned int v15; // r1
  int v16; // r2
  int v17; // r0
  int v18; // r0

  v2 = off_127F40;
  feature_guard_sdio(8, dword_127F44);
  v5 = *a1;
  if ( *a1 )
  {
    if ( v5 == 1 )
    {
      if ( (unsigned __int8)v2[136] == 255 )
        return 0;
      v6 = (unsigned __int8)v2[128];
      v7 = off_127F54;
      if ( v6 > 3 )
      {
        if ( v6 == 4 )
        {
          timestamp_remove_058((int)off_127F54 + 64);
          v12 = v7[8];
          v7[18] = 0;
          sub_12788C(v12);
        }
      }
      else if ( v6 > 1 )
      {
        v13 = *((_BYTE **)off_127F54 + 11);
        *((_BYTE *)off_127F54 + 88) &= ~4u;
        if ( v13 )
        {
          if ( v13 == v2 + 112 && (_BYTE *)v7[20] == v13 )
          {
            timestamp_remove_058((int)(v7 + 16));
            v7[18] = 0;
          }
          v7[11] = 0;
        }
        phy_init_or_register_n_e(dword_127F48);
      }
      else if ( v6 == 1 )
      {
        *((_BYTE *)off_127F54 + 88) &= 0xFAu;
        phy_init_or_register_n_e((int)(v2 + 112));
      }
      v8 = *((_BYTE *)v7 + 88);
      v2[136] = -1;
      if ( (v8 & 0x12) != 0x10 )
        return 0;
      v18 = dword_127F50;
      *((_BYTE *)v7 + 88) = v8 & 0xEF;
      v5 = 0;
      timestamp_remove_058(v18);
      return v5;
    }
    return 1;
  }
  if ( (unsigned __int8)v2[136] != 255 || v2[128] == 4 || msg_get_value(4) == 1 )
  {
    v10 = off_127F54;
    v11 = *((_BYTE *)off_127F54 + 88);
    if ( (v11 & 0x20) == 0 )
      return 1;
  }
  else
  {
    v10 = off_127F54;
    if ( !*((_BYTE *)off_127F54 + 91) )
    {
      v11 = *((_BYTE *)off_127F54 + 88);
      goto LABEL_25;
    }
    v11 = *((_BYTE *)off_127F54 + 88);
    if ( (v11 & 0x20) == 0 )
    {
LABEL_25:
      v2[136] = 4;
      v2[116] = a1[2];
      v2[117] = a1[3];
      v14 = *((_WORD *)a1 + 3);
      *((_WORD *)v2 + 59) = *((_WORD *)a1 + 2);
      *((_WORD *)v2 + 61) = *((_WORD *)a1 + 4);
      *((_WORD *)v2 + 60) = v14;
      v2[124] = a1[16];
      v2[128] = 1;
      v2[125] = 0;
      v15 = *((_DWORD *)a1 + 3);
      *((_WORD *)v2 + 63) = a2;
      v16 = 1000 * v15;
      if ( v15 > 0x23 )
        v16 -= 35000;
      *((_DWORD *)v2 + 33) = v16;
      v2[138] = a1[1];
      if ( a2 )
      {
        v10[88] = v11 | 1;
        sub_127568();
      }
      else
      {
        v17 = dword_127F48;
        v10[88] = v11 | 4;
        rf_init_or_attach_n488(v17);
      }
      *(_DWORD *)off_127F4C |= 4u;
      return v5;
    }
  }
  v10[88] = v11 & 0xDF;
  return 1;
}

