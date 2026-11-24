// sub_1166CC @ 0x1166cc, size 340 bytes
int __fastcall sub_1166CC(int a1, int a2, int a3)
{
  int v3; // r10
  int v4; // r11
  int v6; // r5
  int v8; // r3
  int v10; // r0
  int v11; // r4
  int v12; // r5
  int v13; // r3
  int v14; // r2
  __int16 v15; // r1
  int v16; // r0
  __int16 v17; // r5
  int v18; // r0
  __int16 v19; // r5
  char v20; // r2
  int v22; // r1
  int v23; // r0
  __int16 v24; // r2
  int v25; // r0

  v3 = dword_116830;
  v4 = dword_116834;
  v6 = *(unsigned __int8 *)(dword_116830 + 152 * a1 + 32);
  v8 = *(_DWORD *)(dword_116834 + 224 * v6 + 72);
  if ( !v8 )
  {
    if ( **(__int16 **)off_116820 >= 0 )
    {
LABEL_9:
      v11 = rf_alloc_or_init(1, 24);
      if ( !v11 )
        return 1;
      goto LABEL_4;
    }
LABEL_8:
    rf_cmd_send_n264(dword_11682C, dword_116828, 520);
    goto LABEL_9;
  }
  v10 = *(unsigned __int8 *)(v8 + 4);
  if ( **(__int16 **)off_116820 < 0 && v10 == 2 )
    goto LABEL_8;
  v11 = rf_alloc_or_init(v10 != 0, 24);
  if ( !v11 )
    return 1;
LABEL_4:
  v12 = v4 + 224 * v6;
  sub_11DA78(v12, v11);
  v13 = *(_DWORD *)(v11 + 28);
  if ( *(_BYTE *)(v12 + 94) == 2 )
  {
    v22 = v3 + 152 * a1;
    *(_DWORD *)(v13 + 108) = *(_DWORD *)(v22 + 36);
    LOWORD(v22) = *(_WORD *)(v22 + 40);
    v23 = *(_DWORD *)(v12 + 88);
    *(_BYTE *)(v13 + 105) = 2;
    *(_DWORD *)(v13 + 114) = v23;
    v24 = *(_WORD *)(v12 + 92);
    v25 = *(_DWORD *)(v12 + 88);
    *(_WORD *)(v13 + 112) = v22;
    *(_WORD *)(v13 + 118) = *(_WORD *)(v12 + 92);
    *(_BYTE *)(v13 + 106) = 0;
    *(_BYTE *)(v13 + 107) = 0;
    *(_BYTE *)(v13 + 104) = 72;
    *(_DWORD *)(v13 + 120) = v25;
    *(_WORD *)(v13 + 124) = v24;
  }
  else
  {
    v14 = v3 + 152 * a1;
    v15 = *(_WORD *)(v12 + 92);
    *(_DWORD *)(v13 + 108) = *(_DWORD *)(v14 + 36);
    v16 = *(_DWORD *)(v12 + 88);
    v17 = *(_WORD *)(v14 + 40);
    *(_DWORD *)(v13 + 114) = v16;
    v18 = *(_DWORD *)(v14 + 36);
    *(_WORD *)(v13 + 112) = v17;
    *(_WORD *)(v13 + 118) = v15;
    *(_DWORD *)(v13 + 120) = v18;
    *(_WORD *)(v13 + 124) = v17;
    *(_BYTE *)(v13 + 106) = 0;
    *(_BYTE *)(v13 + 107) = 0;
    *(_BYTE *)(v13 + 104) = 72;
    *(_BYTE *)(v13 + 105) = 1;
  }
  v19 = *((_WORD *)off_116824 + 70) + 1;
  *((_WORD *)off_116824 + 70) = v19;
  v20 = *(_BYTE *)(v3 + 152 * a1 + 32);
  *(_WORD *)(v13 + 126) = 16 * v19;
  *(_DWORD *)(v11 + 44) = a2;
  *(_DWORD *)(v11 + 48) = a3;
  *(_BYTE *)(v11 + 15) = v20;
  *(_BYTE *)(v11 + 16) = a1;
  sub_1165B0(v11, 5);
  return 0;
}

