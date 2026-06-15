// sub_1253D0 @ 0x1253d0, size 186 bytes
int __fastcall sub_1253D0(int a1, int a2)
{
  _DWORD *v3; // r5
  int v4; // r1
  int v5; // r3
  int v6; // r8
  int v7; // r7
  int v8; // r11
  int v9; // r6
  int v10; // r10
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r0
  int v16; // r6
  int v17; // r11
  __int64 v18; // r2
  int v19; // r7
  _DWORD *v20; // r1
  int result; // r0

  v3 = *(_DWORD **)(a1 + 192);
  v4 = *(unsigned __int16 *)(a2 + 4);
  v5 = *(unsigned __int8 *)(a2 + 8);
  v6 = v3[7];
  v7 = *(unsigned __int16 *)(a2 + 6);
  v8 = *(unsigned __int8 *)(a1 + 107);
  v9 = dword_12548C;
  v10 = v4 - v5;
  *(_WORD *)(a1 + 216) = v4 - v5;
  sub_132E78();
  v12 = *(unsigned __int16 *)(a2 + 6);
  v13 = dword_125490;
  v14 = v3[7] + v12 - 1;
  v3[8] = v14;
  v15 = *(_DWORD *)(a1 + 72);
  v16 = v9 + 8 * v8;
  v17 = v13 + 20 * v8;
  LODWORD(v18) = v14 + *(unsigned __int8 *)(a2 + 8) + 1;
  HIDWORD(v18) = ~v12 + v10 + v18;
  *(_QWORD *)(v17 + 8) = v18;
  v19 = v7 + 3;
  *(_DWORD *)(v17 + 16) = 0;
  if ( v15 )
  {
    v20 = off_125494;
    if ( !*(_BYTE *)(a1 + 1224) && !*(_BYTE *)(v15 + 4) )
      v20 = off_1254A4;
  }
  else
  {
    v20 = off_125494;
  }
  result = dword_12549C;
  v20[9] = (unsigned __int16)(*(_WORD *)off_125498 << 8) | (unsigned __int8)*(_DWORD *)off_125498;
  v3[11] = 0;
  v3[12] = v20;
  v3[17] = result;
  v3[6] = dword_1254A0 + 40 * *(unsigned __int8 *)(a1 + 107);
  *(_BYTE *)(a1 + 226) = 1;
  *(_BYTE *)(v16 + 3) = *(_BYTE *)(v6 + v19);
  return result;
}

