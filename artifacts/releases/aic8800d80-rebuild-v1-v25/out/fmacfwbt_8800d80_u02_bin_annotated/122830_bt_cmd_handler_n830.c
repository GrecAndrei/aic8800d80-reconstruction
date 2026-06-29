// fwstruct annotate: 122830_bt_cmd_handler_n830.c
// bt_cmd_handler_n830 @ 0x122830, size 392 bytes
// Doc: bt_cmd_handler_n830 [bt]: Handle BT command message in fmacfwbt with parameter parsing
// bt_cmd_handler_n830 [bt]: Handle BT command message in fmacfwbt with parameter parsing
int __fastcall bt_cmd_handler_n830(int a1, int a2, int a3, int *a4)
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
  v9 = sub_12DD88(v6 + 36, (unsigned __int16)(v5 - 36));
  if ( !v9 )
    goto LABEL_7;
  v10 = *(unsigned __int8 *)(v9 + 2);
  v11 = *((unsigned __int8 *)off_1229B8 + 36);
  if ( !*((_BYTE *)off_1229B8 + 36) )
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
    sub_122810(*(_BYTE *)(v7 + 107), 1);
    *(_WORD *)(v7 + 146) = 0;
    *(_BYTE *)(v7 + 148) = 0;
  }
  v12 = off_1229BC;
  *(_BYTE *)(v7 + 141) = 1;
  if ( dword_1229C0 - v12[4] + *(_DWORD *)(v7 + 120) < 0 && !sub_1194CC(*(unsigned __int8 *)(v7 + 116), 0, 0) )
    *(_DWORD *)(v7 + 120) = *((_DWORD *)off_1229BC + 4);
  v23 = *(char *)(v4 + 45);
  sub_101968();
  v13 = v23;
  if ( *((_BYTE *)off_1229C4 + 17) == 1 )
  {
    sub_122528((_DWORD *)v7, v23);
    v13 = v23;
  }
  sub_122358((_BYTE *)v7, v13);
  v14 = sub_12D71C(v6 + 32, 4, 0);
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
        v14 = sub_12D71C(v20, (unsigned __int8)v16[1], v14);
      v18 = (unsigned __int16)(v18 + -2 - v19);
      v16 = &v20[v19];
    }
    while ( v18 > 1 );
    v7 = v17;
    a4 = v15;
    v4 = v24;
  }
  *(_DWORD *)(v7 + 124) = v14;
  sub_120B78(v6, v5, v4, v7, a3, *a4);
  result = msg_get_value(4);
  if ( result != 1 )
    return *(_DWORD *)(v7 + 124) != v25;
  return result;
}

