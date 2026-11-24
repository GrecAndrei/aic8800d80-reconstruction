// sub_113374 @ 0x113374, size 264 bytes
int __fastcall sub_113374(int a1)
{
  void *v1; // r5
  _DWORD *v2; // r1
  int *v3; // r2
  _DWORD *v4; // r3
  _WORD *v5; // r6
  int *v6; // r0
  _DWORD *v7; // r2
  _DWORD *v8; // r3
  _DWORD *v9; // r4
  _BYTE *v10; // r3
  int v11; // r5
  int v12; // r0
  int v13; // r1
  _DWORD *v14; // r6
  int *v15; // r2
  _BYTE *v16; // r4
  int v17; // r1
  _BYTE *v18; // r5
  bool v19; // cc
  char v20; // r0
  int v21; // r3
  int v22; // r0

  v1 = off_11347C;
  v2 = off_113484;
  v3 = *(int **)(*(_DWORD *)off_11347C + 16);
  v4 = off_113488;
  *(_DWORD *)off_113480 = v3;
  *v2 = v3 + 16;
  v5 = off_11348C;
  *(_DWORD *)(v4 + 0x8) = a1;
  *v4 = 0;
  *(_DWORD *)(v4 + 0x4) = 0;
  *(_DWORD *)(v4 + 0x10) = 0;
  *(_DWORD *)(v4 + 0x14) = 0;
  *(_DWORD *)(v4 + 0xc) = 0;
  *(_DWORD *)(v5 + 0x18) = 0;
  sub_100200(v3, 0, 0x140u);
  v6 = *(int **)(*(_DWORD *)v1 + 20);
  v7 = off_113494;
  v8 = off_113498;
  *(_DWORD *)off_113490 = v6;
  *v7 = v6 + 2;
  *v8 = v6 + 4;
  *(_DWORD *)(v8 + 0x4) = v6 + 6;
  *(_DWORD *)(v8 + 0x8) = v6 + 8;
  *(_DWORD *)(v8 + 0xc) = v6 + 10;
  v9 = off_11349C;
  *(_DWORD *)(v8 + 0x10) = v6 + 12;
  *v9 = v6 + 14;
  sub_100200(v6, 0, 0xCB8u);
  if ( **(__int16 **)off_1134A0 < 0 && *(_DWORD *)(*(_DWORD *)v1 + 24) <= 0xCB7u )
    rf_cmd_send_n264(dword_1134D4, dword_1134D0, 758);
  v10 = off_1134A4;
  v11 = *((unsigned __int16 *)off_1134A4 + 164);
  v12 = *((unsigned __int16 *)off_1134A4 + 154);
  v13 = dword_1134AC;
  v14 = off_1134B0;
  *(_DWORD *)off_1134B4 = *((unsigned __int16 *)off_1134A4 + 153) - *(_DWORD *)off_1134A8 - 4;
  v15 = (int *)off_1134B8;
  v16 = off_1134BC;
  v17 = v13 * v11;
  v18 = off_1134C0;
  *v14 = v12 - 4;
  v19 = v17 <= (int)v15;
  if ( v17 > (int)v15 )
    v17 = (int)off_1134C4;
  else
    v15 = (int *)off_1134C4;
  *v18 = *(_DWORD *)(v10 + 0x500);
  v20 = *(_DWORD *)(v10 + 0x504);
  v21 = (unsigned __int8)*(_DWORD *)(v10 + 0x5c0);
  *v16 = v20;
  if ( v19 )
    *v15 = v17;
  else
    *(_DWORD *)v17 = v15;
  v22 = dword_1134CC;
  if ( v21 )
  {
    *(_BYTE *)off_1134C8 = v21;
    msg_parse(v22, v21);
  }
  else
  {
    *(_BYTE *)off_1134C8 = 10;
    msg_parse(v22, 10);
  }
  return 1;
}

