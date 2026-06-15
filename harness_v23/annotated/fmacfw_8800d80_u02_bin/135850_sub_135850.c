// v23 annotated: sub_135850 @ 0x135850
// Original: 135850_sub_135850.c
// Primary struct: <unclustered>
//
// sub_135850 @ 0x135850, size 200 bytes
// Doc: sub_1235850 [scan]: Reads shared scan/state structure and dispatches action
// sub_1235850 [scan]: Reads shared scan/state structure and dispatches action
int __fastcall sub_135850(unsigned int a1)
{
  int v1; // r8
  int v2; // r7
  int v3; // r5
  _BYTE *v5; // r0
  _DWORD *v6; // r3
  int v7; // r1
  int *v8; // r2
  int v9; // r4
  int *v10; // r1
  int v11; // lr
  int v12; // r12
  int v13; // r0
  int v14; // r5
  int v15; // r0

  v1 = *((_DWORD *)off_13591C + 4);
  v2 = dword_135920;
  v3 = *(unsigned __int8 *)(v1 + 61);
  if ( **(__int16 **)off_135918 < 0 && *(int *)(dword_135920 + 1320 * v3 + 472) >= 0 )
    sub_12F46C(dword_13592C, dword_135928, 1398);
  v5 = (_BYTE *)sub_12C92C(6150, 13, 6, 0x2Cu);
  *v5 = *(_BYTE *)(v1 + 61);
  v6 = v5 + 1;
  v7 = v2 + 1320 * v3;
  v8 = (int *)(v7 + 374);
  v9 = (int)v5;
  v10 = (int *)(v7 + 406);
  do
  {
    v11 = *v8;
    v12 = v8[1];
    v13 = v8[2];
    v6[3] = v8[3];
    v8 += 4;
    *v6 = v11;
    v6[1] = v12;
    v6[2] = v13;
    v6 += 4;
  }
  while ( v8 != v10 );
  *(_BYTE *)v6 = *(_BYTE *)v8;
  v14 = v2 + 1320 * v3;
  v15 = *(_DWORD *)(v14 + 368);
  *(_WORD *)(v9 + 38) = *(_WORD *)(v14 + 372);
  *(_DWORD *)(v9 + 34) = v15;
  *(_DWORD *)(v9 + 40) = bswap32(a1);
  sub_12CD34(6u, 6);
  timer_set_relative(6154, 6, dword_135924);
  return sdio_buffer_prepare_n_4e8(v9);
}

