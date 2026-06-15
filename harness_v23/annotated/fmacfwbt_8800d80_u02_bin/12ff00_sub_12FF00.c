// v23 annotated: sub_12FF00 @ 0x12ff00
// Original: 12ff00_sub_12FF00.c
// Primary struct: <unclustered>
//
// sub_12FF00 @ 0x12ff00, size 362 bytes
int __fastcall sub_12FF00(int a1, int a2)
{
  unsigned __int8 *v3; // r6
  unsigned int v4; // r6
  unsigned __int16 v5; // r0
  unsigned __int8 *v6; // r5
  unsigned __int16 v7; // r7
  unsigned int v8; // r8
  _DWORD *v9; // r0
  _DWORD *v10; // r1
  _DWORD *v11; // r12
  _DWORD *v12; // lr
  _DWORD *v13; // r3
  _DWORD *v14; // r9
  _DWORD *v15; // lr
  _DWORD *v16; // r0
  _DWORD *v17; // r12
  unsigned int *v18; // r1
  unsigned int v19; // r3
  char *v20; // r0
  int *v21; // r12
  int v22; // lr
  int v23; // r9
  int v24; // r0
  unsigned __int8 v26[4]; // [sp+8h] [bp-Ch] BYREF
  char v27; // [sp+Ch] [bp-8h]

  if ( sub_143F00(*(_DWORD *)(a2 + 4)) != 12 || sub_143F00(*(_DWORD *)(a2 + 8)) != 12 )
    return -2;
  v3 = *(unsigned __int8 **)(a2 + 4);
  sub_14380C(v26, v3 + 8, 4);
  v3[8] = 0;
  v27 = 0;
  v4 = sub_12FB74(v3, nullptr, 0x10u);
  v5 = sub_12FB74(v26, nullptr, 0x10u);
  v6 = *(unsigned __int8 **)(a2 + 8);
  v7 = v5;
  sub_14380C(v26, v6 + 8, 4);
  v6[8] = 0;
  v27 = 0;
  v8 = sub_12FB74(v6, nullptr, 0x10u);
  LOWORD(v6) = sub_12FB74(v26, nullptr, 0x10u);
  sub_12ECB0(dword_13006C);
  v9 = off_130074;
  v10 = off_130078;
  v11 = off_1300A0;
  v12 = off_1300A4;
  v13 = off_13007C;
  *(_DWORD *)off_130070 = 512;
  *v12 = 7;
  *v9 = 7;
  *v10 = 7;
  *v11 = 7;
  *v13 = 7;
  v9[4] = 7;
  v13 -= 495296;
  v10[4] = 7;
  v11[4] = 7;
  *v13 = 9816;
  *(v9 - 457703) = 50529027;
  *(v10 - 457698) = dword_130080;
  v14 = off_1300A8;
  v15 = off_1300AC;
  v16 = off_130088;
  v13[37597] = dword_130084;
  v17 = off_1300B0;
  v18 = (unsigned int *)off_13008C;
  *v14 = -1;
  *v15 = -1;
  *v16 = -1;
  *v17 = -1;
  *v18 = bswap32(v4);
  v18 += 4;
  *(_DWORD *)off_130090 = __rev16(v7);
  v19 = bswap32(v8);
  *v18 = v19;
  v20 = (char *)off_130094;
  *(_DWORD *)off_130094 = __rev16((unsigned __int16)v6);
  *(v18 - 380) = v19;
  v21 = (int *)off_1300B4;
  v22 = dword_1300B8;
  v23 = dword_1300BC;
  *(_DWORD *)off_130098 = __rev16((unsigned __int16)v6);
  *(_DWORD *)&v20[-148] = 7;
  *(_DWORD *)&v20[-148] = v23;
  v24 = dword_13009C;
  *v21 = v22;
  sub_12ECB0(v24, v4, v7, v8, (unsigned __int16)v6);
  return 0;
}

