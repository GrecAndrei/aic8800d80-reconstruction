// fwstruct annotate: 1225fc_sub_1225FC.c
// sub_1225FC @ 0x1225fc, size 392 bytes
int __fastcall sub_1225FC(int a1, int a2, int a3, int *a4)
{
  int v4; // r7
  int v5; // r11
  int v6; // r9
  int v7; // r4
  int v9; // r0
  int v10; // r2
  int v11; // r3
  _DWORD *v12; // r3
  int v13; // r1
  int v14; // r0
  int *v15; // r7
  _BYTE *v16; // r1
  int v17; // r8
  unsigned int v18; // r4
  int v19; // r5
  _BYTE *v20; // r10
  int result; // r0
  int v23; // [sp+10h] [bp-Ch]
  int v24; // [sp+10h] [bp-Ch]
  int v25; // [sp+14h] [bp-8h]

  v4 = a1;
  v5 = *(unsigned __int16 *)(a1 + 28);
  v6 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8);
  v7 = a2;
  v25 = *(_DWORD *)(a2 + 124);
  v9 = sub_12DB60(v6 + 36, (unsigned __int16)(v5 - 36));
  if ( !v9 )
    goto LABEL_7;
  v10 = *(unsigned __int8 *)(v9 + 2);
  v11 = *((unsigned __int8 *)off_122784 + 36);
  if ( !*((_BYTE *)off_122784 + 36) )
  {
    if ( (unsigned int)(v10 - 1) <= 0xD )
    {
      if ( v10 == 14 )
        v11 = 2484;
      else
        v11 = 5 * v10 + 2407;
    }
LABEL_6:
    if ( *(unsigned __int16 *)(v7 + 414) != v11 )
      goto LABEL_8;
    goto LABEL_7;
  }
  if ( v11 == 1 && (unsigned __int8)(v10 - 1) <= 0xB0u )
  {
    v11 = 5 * v10 + 5000;
    goto LABEL_6;
  }
  if ( !*(_WORD *)(v7 + 414) )
LABEL_7:
    *(_BYTE *)(v7 + 128) = 0;
LABEL_8:
  if ( *(_BYTE *)(v7 + 147) )
  {
    tx_send_msg_n25dc(*(_BYTE *)(v7 + 107), 1);
    *(_WORD *)(v7 + 146) = 0;
    *(_BYTE *)(v7 + 148) = 0;
  }
  v12 = off_122788;
  *(_BYTE *)(v7 + 141) = 1;
  if ( dword_12278C - v12[4] + *(_DWORD *)(v7 + 120) < 0 && !sub_11908C(*(unsigned __int8 *)(v7 + 116), 0, 0) )
    *(_DWORD *)(v7 + 120) = *((_DWORD *)off_122788 + 4);
  v23 = *(char *)(v4 + 45);
  sub_101AEC();
  v13 = v23;
  if ( *((_BYTE *)off_122790 + 17) == 1 )
  {
    sub_1222F4((_DWORD *)v7, v23);
    v13 = v23;
  }
  sub_122124((_BYTE *)v7, v13);
  v14 = sub_12D4F4(v6 + 32, 4, 0);
  *a4 = 0;
  if ( (unsigned __int16)(v5 - 36) > 1u )
  {
    v24 = v4;
    v15 = a4;
    v16 = (_BYTE *)(v6 + 36);
    v17 = v7;
    v18 = (unsigned __int16)(v5 - 36);
    do
    {
      v19 = (unsigned __int8)v16[1];
      v20 = v16 + 2;
      if ( v19 + 1 >= (int)v18 )
        break;
      if ( *v16 == 5 )
        *v15 = (int)v16;
      else
        v14 = sub_12D4F4(v20, (unsigned __int8)v16[1], v14);
      v18 = (unsigned __int16)(v18 + -2 - v19);
      v16 = &v20[v19];
    }
    while ( v18 > 1 );
    v7 = v17;
    a4 = v15;
    v4 = v24;
  }
  *(_DWORD *)(v7 + 124) = v14;
  sub_120840(v6, v5, v4, v7, a3, *a4);
  result = msg_get_value(4);
  if ( result != 1 )
    return *(_DWORD *)(v7 + 124) != v25;
  return result;
}

