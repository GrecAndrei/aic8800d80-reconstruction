// sub_11EACC @ 0x11eacc, size 120 bytes
float __fastcall sub_11EACC(float a1)
{
  int v1; // r1
  int v2; // r2
  int v3; // r3
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  float v25; // s15
  _DWORD v27[16]; // [sp+0h] [bp-80h]
  _DWORD v28[16]; // [sp+40h] [bp-40h]

  v1 = *(_DWORD *)(dword_11EB44 + 260);
  v2 = *(_DWORD *)(dword_11EB44 + 264);
  v3 = *(_DWORD *)(dword_11EB44 + 268);
  v27[0] = *(_DWORD *)(dword_11EB44 + 256);
  v27[1] = v1;
  v27[2] = v2;
  v27[3] = v3;
  v4 = *(_DWORD *)(dword_11EB44 + 276);
  v5 = *(_DWORD *)(dword_11EB44 + 280);
  v6 = *(_DWORD *)(dword_11EB44 + 284);
  v27[4] = *(_DWORD *)(dword_11EB44 + 272);
  v27[5] = v4;
  v27[6] = v5;
  v27[7] = v6;
  v7 = *(_DWORD *)(dword_11EB44 + 292);
  v8 = *(_DWORD *)(dword_11EB44 + 296);
  v9 = *(_DWORD *)(dword_11EB44 + 300);
  v27[8] = *(_DWORD *)(dword_11EB44 + 288);
  v27[9] = v7;
  v27[10] = v8;
  v27[11] = v9;
  v10 = *(_DWORD *)(dword_11EB44 + 308);
  v11 = *(_DWORD *)(dword_11EB44 + 312);
  v12 = *(_DWORD *)(dword_11EB44 + 316);
  v27[12] = *(_DWORD *)(dword_11EB44 + 304);
  v27[13] = v10;
  v27[14] = v11;
  v27[15] = v12;
  v13 = *(_DWORD *)(dword_11EB44 + 324);
  v14 = *(_DWORD *)(dword_11EB44 + 328);
  v15 = *(_DWORD *)(dword_11EB44 + 332);
  v28[0] = *(_DWORD *)(dword_11EB44 + 320);
  v28[1] = v13;
  v28[2] = v14;
  v28[3] = v15;
  v16 = *(_DWORD *)(dword_11EB44 + 340);
  v17 = *(_DWORD *)(dword_11EB44 + 344);
  v18 = *(_DWORD *)(dword_11EB44 + 348);
  v28[4] = *(_DWORD *)(dword_11EB44 + 336);
  v28[5] = v16;
  v28[6] = v17;
  v28[7] = v18;
  v19 = *(_DWORD *)(dword_11EB44 + 356);
  v20 = *(_DWORD *)(dword_11EB44 + 360);
  v21 = *(_DWORD *)(dword_11EB44 + 364);
  v28[8] = *(_DWORD *)(dword_11EB44 + 352);
  v28[9] = v19;
  v28[10] = v20;
  v28[11] = v21;
  v22 = *(_DWORD *)(dword_11EB44 + 372);
  v23 = *(_DWORD *)(dword_11EB44 + 376);
  v24 = *(_DWORD *)(dword_11EB44 + 380);
  v28[12] = *(_DWORD *)(dword_11EB44 + 368);
  v28[13] = v22;
  v28[14] = v23;
  v28[15] = v24;
  v25 = COERCE_FLOAT(v28[(LODWORD(a1) >> 20) & 0xF] + (LODWORD(a1) >> 1)) * *(float *)&v27[(LODWORD(a1) >> 20) & 0xF];
  return (float)((float)(a1 / v25) + v25) * 0.5;
}

