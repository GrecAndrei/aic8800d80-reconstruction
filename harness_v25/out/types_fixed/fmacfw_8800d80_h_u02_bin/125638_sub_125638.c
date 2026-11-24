// sub_125638 @ 0x125638, size 254 bytes
int *__fastcall sub_125638(int a1)
{
  int v1; // r7
  int v2; // r9
  int v4; // r3
  int v5; // r1
  int v6; // r12
  int v7; // r0
  _BYTE *v8; // r2
  int v9; // r8
  int *v10; // r0
  _DWORD *v11; // r6
  int v12; // r3
  int *result; // r0
  int *v14; // r3
  int v15; // r3
  int v16; // r2
  int v17; // r1
  _DWORD *v18; // r2
  _DWORD *v19; // r3
  void *v20; // r1

  v1 = dword_125740;
  v2 = dword_12575C;
  sub_11892C(
    a1 + 116,
    dword_125738 + 620 * *(unsigned __int8 *)(a1 + 107),
    (_DWORD *)(dword_12573C + 80 * *(unsigned __int8 *)(a1 + 107)),
    (int *)(dword_125744 + (*(unsigned __int8 *)(a1 + 107) << 6)));
  v4 = *(unsigned __int8 *)(a1 + 107);
  v5 = dword_125748;
  v6 = dword_125760;
  v7 = dword_12574C;
  *(_WORD *)(a1 + 218) = 6;
  v8 = (_BYTE *)(v5 + 8 * v4);
  *(_WORD *)(a1 + 228) = 255;
  *(_BYTE *)(a1 + 227) = 0;
  *(_WORD *)(a1 + 220) = 0;
  *(_BYTE *)(a1 + 230) = 0;
  *v8 = 5;
  *(_DWORD *)(v8 + 0x4) = 4;
  *(_DWORD *)(v8 + 0x8) = *(_BYTE *)(a1 + 227);
  *(_DWORD *)(v8 + 0x10) = 0;
  *(_DWORD *)(v8 + 0x14) = 0;
  *(_DWORD *)(v8 + 0xc) = 1;
  v9 = 5 * v4;
  v10 = (int *)(v7 + 252 * v4);
  v11 = (_DWORD *)(v6 + 40 * v4);
  v12 = v1 + 20 * v4;
  *(_DWORD *)(v11 + 0x20) = (char *)v10 + *(unsigned __int8 *)(a1 + 229);
  *(_DWORD *)(v11 + 0xc) = v8 + 5;
  *(_DWORD *)(v11 + 0x10) = 0;
  *(_DWORD *)(v6 + 8 * v9) = v2;
  *(_DWORD *)(v11 + 0x8) = v8;
  *(_DWORD *)(v11 + 0x4) = v12;
  *(_DWORD *)(v11 + 0x18) = v12;
  *(_DWORD *)(v11 + 0x14) = v2;
  result = sub_100200(v10, 0, 0xFCu);
  v14 = (int *)(v1 + 4 * v9);
  *v14 = v2;
  *(_DWORD *)(v14 + 0x4) = 0;
  *(_DWORD *)(v14 + 0x10) = 0;
  if ( *(_BYTE *)(a1 + 1224) )
  {
    v15 = *(unsigned __int8 *)(a1 + 107);
    result = (int *)dword_125750;
    v16 = 19 * v15;
    v15 *= 5;
    v17 = dword_125754 + 2 * v16;
    v18 = (_DWORD *)(dword_125750 + 4 * v15);
    *(_DWORD *)(v18 + 0x4) = 0;
    *(_DWORD *)(v18 + 0x8) = v17;
    result[v15] = v2;
    *(_DWORD *)(v18 + 0x10) = 0;
  }
  v19 = *(_DWORD **)(a1 + 192);
  v20 = off_125758;
  *(_DWORD *)(v19 + 0x2c) = 0;
  *(_DWORD *)(v19 + 0x44) = 0;
  *(_DWORD *)(v19 + 0x18) = 0;
  *(_DWORD *)(a1 + 204) = v20;
  *(_DWORD *)(a1 + 208) = a1;
  return result;
}

