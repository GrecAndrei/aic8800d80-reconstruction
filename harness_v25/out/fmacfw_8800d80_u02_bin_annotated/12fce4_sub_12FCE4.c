// fwstruct annotate: 12fce4_sub_12FCE4.c
// sub_12FCE4 @ 0x12fce4, size 362 bytes
int __fastcall sub_12FCE4(int a1, int a2)
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

  if ( sub_143E40(*(_DWORD *)(a2 + 4)) != 12 || sub_143E40(*(_DWORD *)(a2 + 8)) != 12 )
    return -2;
  v3 = *(unsigned __int8 **)(a2 + 4);
  sub_143770(v26, v3 + 8, 4);
  v3[8] = 0;
  v27 = 0;
  v4 = sub_12F958(v3, nullptr, 0x10u);
  v5 = sub_12F958(v26, nullptr, 0x10u);
  v6 = *(unsigned __int8 **)(a2 + 8);
  v7 = v5;
  sub_143770(v26, v6 + 8, 4);
  v6[8] = 0;
  v27 = 0;
  v8 = sub_12F958(v6, nullptr, 0x10u);
  LOWORD(v6) = sub_12F958(v26, nullptr, 0x10u);
  msg_parse(dword_12FE50);
  v9 = off_12FE58;
  v10 = off_12FE5C;
  v11 = off_12FE84;
  v12 = off_12FE88;
  v13 = off_12FE60;
  *(_DWORD *)off_12FE54 = 512;
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
  *(v10 - 457698) = dword_12FE64;
  v14 = off_12FE8C;
  v15 = off_12FE90;
  v16 = off_12FE6C;
  v13[37597] = dword_12FE68;
  v17 = off_12FE94;
  v18 = (unsigned int *)off_12FE70;
  *v14 = -1;
  *v15 = -1;
  *v16 = -1;
  *v17 = -1;
  *v18 = bswap32(v4);
  v18 += 4;
  *(_DWORD *)off_12FE74 = __rev16(v7);
  v19 = bswap32(v8);
  *v18 = v19;
  v20 = (char *)off_12FE78;
  *(_DWORD *)off_12FE78 = __rev16((unsigned __int16)v6);
  *(v18 - 380) = v19;
  v21 = (int *)off_12FE98;
  v22 = dword_12FE9C;
  v23 = dword_12FEA0;
  *(_DWORD *)off_12FE7C = __rev16((unsigned __int16)v6);
  *(_DWORD *)&v20[-148] = 7;
  *(_DWORD *)&v20[-148] = v23;
  v24 = dword_12FE80;
  *v21 = v22;
  msg_parse(v24, v4, v7, v8, (unsigned __int16)v6);
  return 0;
}

