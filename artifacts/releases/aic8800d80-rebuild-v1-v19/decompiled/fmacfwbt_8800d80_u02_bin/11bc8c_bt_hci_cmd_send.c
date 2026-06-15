// bt_hci_cmd_send @ 0x11bc8c, size 382 bytes
// Doc: bt_hci_cmd_send [bt]: Send HCI command to BT controller
// bt_hci_cmd_send [bt]: Send HCI command to BT controller
int __fastcall bt_hci_cmd_send(int a1)
{
  _DWORD *v1; // r5
  int v2; // r6
  int v4; // r3
  void *v5; // r7
  int v6; // r2
  int v7; // r8
  _DWORD *v8; // r4
  __int64 v9; // r0
  _DWORD *v10; // r2
  _DWORD *v11; // r2
  unsigned int v12; // r3
  int v13; // r3
  _WORD *v14; // r7
  void *v15; // r7
  char v16; // r3
  int v17; // r1
  int v18; // r2
  int v19; // r2
  int v20; // r3
  _DWORD *v22; // [sp+4h] [bp-4h] BYREF

  v1 = off_11BE0C;
  v2 = *((unsigned __int8 *)off_11BE0C + 190);
  v22 = nullptr;
  patch_sub_1217374(v2);
  sub_11AD40(*((unsigned __int8 *)v1 + 190));
  if ( !a1 )
    goto LABEL_24;
  v4 = *(_DWORD *)(a1 + 36);
  if ( (v4 & 0x200000) != 0 )
  {
    v5 = off_11BE10;
    v6 = *(_DWORD *)(a1 + 68);
    if ( *(_BYTE *)(*(_DWORD *)off_11BE10 + 1) )
    {
      v7 = *(_DWORD *)(v6 + 88);
    }
    else if ( (v4 & 0x380000) == 0x280000 || (*(_WORD *)(v6 + 8) & 0x400) != 0 )
    {
      v7 = *(_DWORD *)(v6 + 20);
    }
    else
    {
      v7 = *(_DWORD *)(v6 + 88);
      *(_DWORD *)(v6 + 88) = *(_WORD *)(v6 + 8) & 0x400;
    }
    LODWORD(v9) = rf_cmd_process_n_4c5(a1, (int)&v22);
    v8 = v22;
    HIDWORD(v9) = *(unsigned __int8 *)(*(_DWORD *)v5 + 1);
    if ( v22 )
    {
      if ( !*(_BYTE *)(*(_DWORD *)v5 + 1) && (v22[14] & 0x200000) != 0 )
      {
        *(_DWORD *)(v9 + 4) = v7;
        v1[7 * v2 + 9] = v9;
        goto LABEL_11;
      }
      v22[1] = v7;
    }
    if ( (_DWORD)v9 )
      goto LABEL_21;
LABEL_25:
    v18 = dword_11BE14;
    LODWORD(v9) = 84 * v2;
    *(_DWORD *)(dword_11BE14 + 84 * v2) = 0;
    v1[7 * v2 + 9] = 0;
    v19 = v18 + 84 * v2;
    if ( !HIDWORD(v9) )
    {
      *(_DWORD *)(v19 + 4) = 0;
      *(_DWORD *)(v19 + 8) = 0;
    }
    return v9;
  }
  if ( (*(_WORD *)(a1 + 82) & 4) == 0 )
  {
LABEL_24:
    HIDWORD(v9) = *(unsigned __int8 *)(*(_DWORD *)off_11BE10 + 1);
    goto LABEL_25;
  }
  v11 = *(_DWORD **)(a1 + 76);
  v12 = *(_DWORD *)(*(_DWORD *)(a1 + 44) + 60);
  LODWORD(v9) = v11 + 3;
  if ( (*(_WORD *)(a1 + 30) & 0x2000) != 0 )
    v13 = (v12 >> 4) & 1;
  else
    v13 = (v12 >> 3) & 1;
  v22 = v11 + 3;
  if ( v13 || (v14 = (_WORD *)v11[7], (*v14 & 0x8000) == 0) )
  {
    v8 = v11 + 3;
    HIDWORD(v9) = *(unsigned __int8 *)(*(_DWORD *)off_11BE10 + 1);
  }
  else
  {
    *v14 &= ~0x8000u;
    v15 = off_11BE10;
    v16 = *(_BYTE *)(a1 + 50) - 4;
    *(_BYTE *)(a1 + 51) -= 4;
    *(_BYTE *)(a1 + 50) = v16;
    v17 = v11[9];
    v11[8] -= 4;
    v11[9] = v17 - 4;
    HIDWORD(v9) = *(unsigned __int8 *)(*(_DWORD *)v15 + 1);
    v8 = v11 + 3;
  }
LABEL_21:
  v1[7 * v2 + 9] = v9;
  if ( !HIDWORD(v9) )
  {
LABEL_11:
    if ( (v8[14] & 0x200000) != 0 )
    {
      if ( !*(_DWORD *)(v9 + 4) )
      {
        v20 = dword_11BE14 + 84 * v2;
        HIDWORD(v9) = 1;
        *(_QWORD *)(v20 + 4) = v9;
        *(_DWORD *)v20 = v8;
      }
    }
    else if ( !v8[1] )
    {
      v10 = (_DWORD *)(dword_11BE14 + 84 * v2);
      v10[1] = 0;
      v10[2] = 0;
      *v10 = v8;
      LODWORD(v9) = 84 * v2;
    }
    return v9;
  }
  if ( !v8[1] )
  {
    *(_DWORD *)(dword_11BE14 + 84 * v2) = v8;
    LODWORD(v9) = 84 * v2;
  }
  return v9;
}

