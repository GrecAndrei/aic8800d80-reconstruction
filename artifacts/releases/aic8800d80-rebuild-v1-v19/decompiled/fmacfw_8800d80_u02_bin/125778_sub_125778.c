// sub_125778 @ 0x125778, size 254 bytes
int *__fastcall sub_125778(int a1)
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
  int v20; // r1

  v1 = dword_125880;
  v2 = dword_12589C;
  sub_118A6C(
    a1 + 116,
    dword_125878 + 620 * *(unsigned __int8 *)(a1 + 107),
    (_DWORD *)(dword_12587C + 80 * *(unsigned __int8 *)(a1 + 107)),
    (int *)(dword_125884 + (*(unsigned __int8 *)(a1 + 107) << 6)));
  v4 = *(unsigned __int8 *)(a1 + 107);
  v5 = dword_125888;
  v6 = dword_1258A0;
  v7 = dword_12588C;
  *(_WORD *)(a1 + 218) = 6;
  v8 = (_BYTE *)(v5 + 8 * v4);
  *(_WORD *)(a1 + 228) = 255;
  *(_BYTE *)(a1 + 227) = 0;
  *(_WORD *)(a1 + 220) = 0;
  *(_BYTE *)(a1 + 230) = 0;
  *v8 = 5;
  v8[1] = 4;
  v8[2] = *(_BYTE *)(a1 + 227);
  v8[4] = 0;
  v8[5] = 0;
  v8[3] = 1;
  v9 = 5 * v4;
  v10 = (int *)(v7 + 252 * v4);
  v11 = (_DWORD *)(v6 + 40 * v4);
  v12 = v1 + 20 * v4;
  v11[8] = (char *)v10 + *(unsigned __int8 *)(a1 + 229);
  v11[3] = v8 + 5;
  v11[4] = 0;
  *(_DWORD *)(v6 + 8 * v9) = v2;
  v11[2] = v8;
  v11[1] = v12;
  v11[6] = v12;
  v11[5] = v2;
  result = memset_thunk(v10, 0, 0xFCu);
  v14 = (int *)(v1 + 4 * v9);
  *v14 = v2;
  v14[1] = 0;
  v14[4] = 0;
  if ( *(_BYTE *)(a1 + 1224) )
  {
    v15 = *(unsigned __int8 *)(a1 + 107);
    result = (int *)dword_125890;
    v16 = 19 * v15;
    v15 *= 5;
    v17 = dword_125894 + 2 * v16;
    v18 = (_DWORD *)(dword_125890 + 4 * v15);
    v18[1] = 0;
    v18[2] = v17;
    result[v15] = v2;
    v18[4] = 0;
  }
  v19 = *(_DWORD **)(a1 + 192);
  v20 = dword_125898;
  v19[11] = 0;
  v19[17] = 0;
  v19[6] = 0;
  *(_DWORD *)(a1 + 204) = v20;
  *(_DWORD *)(a1 + 208) = a1;
  return result;
}

