// fwstruct annotate: 128aac_sub_128AAC.c
// sub_128AAC @ 0x128aac, size 530 bytes
int __fastcall sub_128AAC(int a1, int a2)
{
  __int16 **v2; // r10
  int v3; // r8
  int v4; // r7
  int v7; // r6
  int v8; // r9
  int v9; // r1
  _BYTE *v10; // r11
  int v11; // r3
  int v12; // r2
  _BYTE *v13; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r2
  int result; // r0
  int v18; // r3
  char v19; // r0
  __int16 *v20; // r3
  unsigned int v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r1

  v2 = (__int16 **)off_128CF0;
  v3 = dword_128CCC;
  v4 = dword_128CC0;
  v7 = dword_128CCC + 28 * a2;
  if ( **(__int16 **)off_128CF0 >= 0
    || *(_DWORD *)(dword_128CC0 + 1320 * a1 + 72) && (sub_12F694(dword_128CD8, dword_128CD4, 3061), **v2 >= 0) )
  {
    v8 = 8 * a2;
  }
  else
  {
    v8 = 8 * a2;
    if ( *(unsigned __int8 *)(v3 + 28 * a2 + 24) == 255 )
      sub_12F694(dword_128CDC, dword_128CD4, 3062);
  }
  v9 = v3 + 4 * (v8 - a2);
  v10 = off_128CF4;
  v11 = v4 + 1320 * a1;
  v12 = (unsigned __int8)(*(_BYTE *)(v9 + 25) + 1);
  *(_BYTE *)(v9 + 25) = v12;
  *(_DWORD *)(v11 + 72) = v7;
  *(_BYTE *)(v11 + 85) = 0;
  if ( v12 == 1 )
  {
    v19 = v10[90];
    *(_BYTE *)(v9 + 16) = 1;
    v20 = *v2;
    v21 = (unsigned __int8)(v19 + 1);
    v10[90] = v21;
    if ( *v20 < 0 && v21 > 2 )
    {
      sub_12F694(dword_128CE4, dword_128CD4, 3082);
      v21 = (unsigned __int8)v10[90];
    }
    if ( v21 == 2 )
    {
      bt_xtal_init_check(dword_128CEC);
      v23 = dword_128CC0;
      v24 = dword_128CC0 + 5280;
      do
      {
        *(_BYTE *)(v23 + 85) &= ~1u;
        v23 += 1320;
      }
      while ( v24 != v23 );
    }
    list_push_tail(dword_128CE0);
    if ( (v10[88] & 0xC) != 0 )
    {
      v22 = *((_DWORD *)v10 + 8);
      if ( **v2 < 0 && !v22 )
      {
        sub_12F694(dword_128CE8, dword_128CD4, 3097);
        v22 = 0;
      }
      *(_DWORD *)(v22 + 8) = v7;
    }
    else if ( *((_DWORD *)v10 + 11) )
    {
      *((_DWORD *)v10 + 11) = v7;
    }
    else
    {
      sub_1272F0(v7);
    }
  }
  feature_guard_sdio(256, dword_128CC4);
  v13 = (_BYTE *)(v4 + 1320 * a1);
  v14 = (unsigned __int8)v13[1224];
  v13[86] = -1;
  if ( v14 && *(_BYTE *)(dword_128CC8 + 140 * (unsigned __int8)v13[1225] + 112) == 1 )
  {
    v13[85] |= 0x10u;
  }
  else
  {
    v15 = dword_128CCC;
    while ( 1 )
    {
      if ( *(unsigned __int8 *)(v15 + 24) != 255 )
      {
        v16 = *(unsigned __int8 *)(v15 + 27);
        if ( v16 != 255 )
          break;
      }
      v15 += 28;
      if ( dword_128CCC + 84 == v15 )
        goto LABEL_10;
    }
    if ( *(_DWORD *)(v4 + 1320 * v16 + 72) != v7 )
      *(_BYTE *)(v4 + 1320 * a1 + 85) |= 0x10u;
  }
LABEL_10:
  result = sub_12876C(v7);
  v18 = *((unsigned __int8 *)off_128CD0 + 16);
  if ( v18 != a1 && v18 != 255 )
    return fw_state_lookup_n_528(a2);
  return result;
}

