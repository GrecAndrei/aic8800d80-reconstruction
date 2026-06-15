// sub_1222CC @ 0x1222cc, size 362 bytes
int __fastcall sub_1222CC(int a1, int a2)
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

  if ( sub_1288C0(*(_DWORD *)(a2 + 4)) != 12 || sub_1288C0(*(_DWORD *)(a2 + 8)) != 12 )
    return -2;
  v3 = *(unsigned __int8 **)(a2 + 4);
  sub_1282E8(v26, v3 + 8, 4);
  v3[8] = 0;
  v27 = 0;
  v4 = sub_121E3C(v3, nullptr, 0x10u);
  v5 = sub_121E3C(v26, nullptr, 0x10u);
  v6 = *(unsigned __int8 **)(a2 + 8);
  v7 = v5;
  sub_1282E8(v26, v6 + 8, 4);
  v6[8] = 0;
  v27 = 0;
  v8 = sub_121E3C(v6, nullptr, 0x10u);
  LOWORD(v6) = sub_121E3C(v26, nullptr, 0x10u);
  sub_11F504(dword_122438);
  v9 = off_122440;
  v10 = off_122444;
  v11 = off_12246C;
  v12 = off_122470;
  v13 = off_122448;
  *(_DWORD *)off_12243C = 512;
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
  *(v10 - 457698) = dword_12244C;
  v14 = off_122474;
  v15 = off_122478;
  v16 = off_122454;
  v13[37597] = dword_122450;
  v17 = off_12247C;
  v18 = (unsigned int *)off_122458;
  *v14 = -1;
  *v15 = -1;
  *v16 = -1;
  *v17 = -1;
  *v18 = bswap32(v4);
  v18 += 4;
  *(_DWORD *)off_12245C = __rev16(v7);
  v19 = bswap32(v8);
  *v18 = v19;
  v20 = (char *)off_122460;
  *(_DWORD *)off_122460 = __rev16((unsigned __int16)v6);
  *(v18 - 380) = v19;
  v21 = (int *)off_122480;
  v22 = dword_122484;
  v23 = dword_122488;
  *(_DWORD *)off_122464 = __rev16((unsigned __int16)v6);
  *(_DWORD *)&v20[-148] = 7;
  *(_DWORD *)&v20[-148] = v23;
  v24 = dword_122468;
  *v21 = v22;
  sub_11F504(v24, v4, v7, v8, (unsigned __int16)v6);
  return 0;
}

