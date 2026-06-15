// sub_12AA04 @ 0x12aa04, size 716 bytes
unsigned __int8 *__fastcall sub_12AA04(int a1)
{
  int v1; // r9
  int v2; // r8
  int v3; // r6
  int v4; // r3
  int v6; // r10
  unsigned __int8 *v7; // r7
  int v8; // r4
  __int16 **v9; // r3
  int v10; // r1
  _DWORD *v11; // r11
  int v12; // r0
  int v13; // r12
  int v14; // r2
  unsigned int v15; // lr
  int v16; // r3
  int v17; // r6
  unsigned __int8 *result; // r0
  __int64 v19; // r0
  int v20; // r4
  int v21; // [sp+0h] [bp-Ch]
  char v22; // [sp+4h] [bp-8h]

  v1 = dword_12ACF4;
  v2 = *(unsigned __int8 *)(a1 + 17);
  v3 = *(unsigned __int8 *)(a1 + 16);
  v4 = dword_12ACF4 + 140 * v2;
  v21 = *(unsigned __int8 *)(v4 + 113);
  v6 = dword_12ACD0 + 1320 * v21;
  v7 = (unsigned __int8 *)v4;
  if ( *(_BYTE *)(v4 + 112) == 1 )
  {
    v8 = *(_DWORD *)(a1 + 12);
  }
  else
  {
    v20 = *(_DWORD *)(a1 + 44);
    if ( **(__int16 **)off_12ACD4 < 0 && *(_BYTE *)(v6 + 106) )
      sub_12F694(dword_12ACEC, dword_12ACE8, 98);
    v8 = v20 + *((_DWORD *)off_12ACDC + 4) - *(_DWORD *)off_12ACE4 - *(_DWORD *)(v6 + 132);
  }
  v9 = (__int16 **)off_12ACD4;
  v10 = dword_12ACD8;
  v11 = off_12ACDC;
  while ( 1 )
  {
    if ( v3 == 1 )
      goto LABEL_27;
    if ( v3 == 2 )
    {
      do
      {
        v17 = *(unsigned __int8 *)(a1 + 19);
        if ( v17 != 255 )
        {
          v17 = (unsigned __int8)(v17 - 1);
          *(_BYTE *)(a1 + 19) = v17;
          if ( !v17 )
          {
            if ( *(_BYTE *)(v1 + 140 * v2 + 112) == 1 )
            {
              bt_link_state_get_n2c4(v6, *(unsigned __int8 *)(a1 + 18), 0);
              v12 = (int)v7;
            }
            else
            {
              if ( *(_BYTE *)(a1 + 16) )
              {
                timestamp_remove_058(a1);
                *(_BYTE *)(a1 + 16) = 0;
              }
              v12 = (int)v7;
            }
            goto LABEL_21;
          }
        }
        v13 = v1 + 140 * v2;
        v15 = *(_DWORD *)(a1 + 28);
        v14 = *(_DWORD *)(a1 + 24);
        v16 = *(unsigned __int8 *)(v13 + 112);
        v8 += v15 - v14;
        if ( v16 == 1 )
        {
          if ( *(_BYTE *)(v13 + 132) )
          {
            v19 = *(_QWORD *)(a1 + 36);
            LODWORD(v19) = v19 + v15;
            --HIDWORD(v19);
            *(_QWORD *)(a1 + 36) = v19;
            if ( HIDWORD(v19) )
            {
              if ( v8 - *((_DWORD *)off_12ACDC + 4) - 5000 >= 0 )
              {
                v3 = 1;
                v16 = *(unsigned __int8 *)(v13 + 112);
                goto LABEL_35;
              }
            }
            else
            {
              *(_BYTE *)(a1 + 20) = v17;
              if ( v15 )
                *(_DWORD *)(a1 + 40) = 0x80000000 / v15 - 1;
              sub_125EFC(*(unsigned __int8 *)(dword_12ACD0 + 1320 * v21 + 107), 3);
              if ( v8 - *((_DWORD *)off_12ACDC + 4) - 5000 >= 0 )
              {
                v3 = 1;
                v16 = *(unsigned __int8 *)(v1 + 140 * v2 + 112);
                goto LABEL_35;
              }
LABEL_27:
              v14 = *(_DWORD *)(a1 + 24);
            }
          }
          else if ( v8 - *((_DWORD *)off_12ACDC + 4) - 5000 >= 0 )
          {
            v22 = *(_BYTE *)(v13 + 112);
            timestamp_update_4f60(a1, v8);
            *(_BYTE *)(a1 + 16) = v22;
            sub_1297BC((int)v7);
            result = sub_129A28(v7);
            if ( *(_BYTE *)(dword_12ACD0 + 1320 * v21 + 106) != 2 )
              return result;
            goto LABEL_30;
          }
        }
        else if ( v8 - *((_DWORD *)off_12ACDC + 4) - 5000 >= 0 )
        {
          v3 = 1;
          goto LABEL_35;
        }
        v8 += v14;
      }
      while ( v8 - *((_DWORD *)off_12ACDC + 4) - 5000 < 0 );
      v3 = 2;
      if ( *(_BYTE *)(v1 + 140 * v2 + 112) )
        goto LABEL_36;
LABEL_42:
      if ( **(__int16 **)off_12ACD4 < 0 && *(_BYTE *)(v6 + 106) )
        sub_12F694(dword_12ACEC, dword_12ACF0, 79);
      *(_DWORD *)(a1 + 44) = *(_DWORD *)off_12ACE4 - *((_DWORD *)off_12ACDC + 4) + *(_DWORD *)(v6 + 132) + v8;
      goto LABEL_36;
    }
    if ( **v9 < 0 )
    {
      sub_12F694(dword_12ACE0, v10, 720);
      v9 = (__int16 **)off_12ACD4;
      v10 = dword_12ACD8;
    }
    if ( v8 - v11[4] - 5000 >= 0 )
      break;
    if ( !v3 )
      goto LABEL_10;
  }
  if ( !v3 )
  {
LABEL_10:
    v12 = (int)v7;
LABEL_21:
    sub_1297BC(v12);
    return sub_129A28(v7);
  }
  v16 = *(unsigned __int8 *)(v1 + 140 * v2 + 112);
LABEL_35:
  if ( !v16 )
    goto LABEL_42;
LABEL_36:
  timestamp_update_4f60(a1, v8);
  *(_BYTE *)(a1 + 16) = v3;
  sub_1297BC((int)v7);
  result = sub_129A28(v7);
  if ( *(_BYTE *)(dword_12ACD0 + 1320 * v21 + 106) == 2 && v3 == 1 )
LABEL_30:
    *(_DWORD *)(dword_12ACD0 + 1320 * v21 + 4) |= 0x20u;
  return result;
}

