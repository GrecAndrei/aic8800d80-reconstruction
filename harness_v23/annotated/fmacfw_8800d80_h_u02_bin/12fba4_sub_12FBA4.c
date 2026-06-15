// v23 annotated: sub_12FBA4 @ 0x12fba4
// Original: 12fba4_sub_12FBA4.c
// Primary struct: <unclustered>
//
// sub_12FBA4 @ 0x12fba4, size 362 bytes
int __fastcall sub_12FBA4(int a1, int a2)
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

  if ( sub_143D00(*(_DWORD *)(a2 + 4)) != 12 || sub_143D00(*(_DWORD *)(a2 + 8)) != 12 )
    return -2;
  v3 = *(unsigned __int8 **)(a2 + 4);
  sub_143630(v26, v3 + 8, 4);
  v3[8] = 0;
  v27 = 0;
  v4 = sub_12F818(v3, nullptr, 0x10u);
  v5 = sub_12F818(v26, nullptr, 0x10u);
  v6 = *(unsigned __int8 **)(a2 + 8);
  v7 = v5;
  sub_143630(v26, v6 + 8, 4);
  v6[8] = 0;
  v27 = 0;
  v8 = sub_12F818(v6, nullptr, 0x10u);
  LOWORD(v6) = sub_12F818(v26, nullptr, 0x10u);
  sub_12E948(dword_12FD10);
  v9 = off_12FD18;
  v10 = off_12FD1C;
  v11 = off_12FD44;
  v12 = off_12FD48;
  v13 = off_12FD20;
  *(_DWORD *)off_12FD14 = 512;
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
  *(v10 - 457698) = dword_12FD24;
  v14 = off_12FD4C;
  v15 = off_12FD50;
  v16 = off_12FD2C;
  v13[37597] = dword_12FD28;
  v17 = off_12FD54;
  v18 = (unsigned int *)off_12FD30;
  *v14 = -1;
  *v15 = -1;
  *v16 = -1;
  *v17 = -1;
  *v18 = bswap32(v4);
  v18 += 4;
  *(_DWORD *)off_12FD34 = __rev16(v7);
  v19 = bswap32(v8);
  *v18 = v19;
  v20 = (char *)off_12FD38;
  *(_DWORD *)off_12FD38 = __rev16((unsigned __int16)v6);
  *(v18 - 380) = v19;
  v21 = (int *)off_12FD58;
  v22 = dword_12FD5C;
  v23 = dword_12FD60;
  *(_DWORD *)off_12FD3C = __rev16((unsigned __int16)v6);
  *(_DWORD *)&v20[-148] = 7;
  *(_DWORD *)&v20[-148] = v23;
  v24 = dword_12FD40;
  *v21 = v22;
  sub_12E948(v24, v4, v7, v8, (unsigned __int16)v6);
  return 0;
}

