// sub_12D934 @ 0x12d934, size 120 bytes
float __fastcall sub_12D934(float a1)
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
  _DWORD *(_DWORD *)(v27 + 0x40); // [sp+0h] [bp-80h]
  _DWORD *(_DWORD *)(v28 + 0x40); // [sp+40h] [bp-40h]

  v1 = *(_DWORD *)(dword_12D9AC + 260);
  v2 = *(_DWORD *)(dword_12D9AC + 264);
  v3 = *(_DWORD *)(dword_12D9AC + 268);
  *(_DWORD *)(v27 + 0x0) = *(_DWORD *)(dword_12D9AC + 256);
  *(_DWORD *)(v27 + 0x4) = v1;
  *(_DWORD *)(v27 + 0x8) = v2;
  *(_DWORD *)(v27 + 0xc) = v3;
  v4 = *(_DWORD *)(dword_12D9AC + 276);
  v5 = *(_DWORD *)(dword_12D9AC + 280);
  v6 = *(_DWORD *)(dword_12D9AC + 284);
  *(_DWORD *)(v27 + 0x10) = *(_DWORD *)(dword_12D9AC + 272);
  *(_DWORD *)(v27 + 0x14) = v4;
  *(_DWORD *)(v27 + 0x18) = v5;
  *(_DWORD *)(v27 + 0x1c) = v6;
  v7 = *(_DWORD *)(dword_12D9AC + 292);
  v8 = *(_DWORD *)(dword_12D9AC + 296);
  v9 = *(_DWORD *)(dword_12D9AC + 300);
  *(_DWORD *)(v27 + 0x20) = *(_DWORD *)(dword_12D9AC + 288);
  *(_DWORD *)(v27 + 0x24) = v7;
  *(_DWORD *)(v27 + 0x28) = v8;
  *(_DWORD *)(v27 + 0x2c) = v9;
  v10 = *(_DWORD *)(dword_12D9AC + 308);
  v11 = *(_DWORD *)(dword_12D9AC + 312);
  v12 = *(_DWORD *)(dword_12D9AC + 316);
  *(_DWORD *)(v27 + 0x30) = *(_DWORD *)(dword_12D9AC + 304);
  *(_DWORD *)(v27 + 0x34) = v10;
  *(_DWORD *)(v27 + 0x38) = v11;
  *(_DWORD *)(v27 + 0x3c) = v12;
  v13 = *(_DWORD *)(dword_12D9AC + 324);
  v14 = *(_DWORD *)(dword_12D9AC + 328);
  v15 = *(_DWORD *)(dword_12D9AC + 332);
  *(_DWORD *)(v28 + 0x0) = *(_DWORD *)(dword_12D9AC + 320);
  *(_DWORD *)(v28 + 0x4) = v13;
  *(_DWORD *)(v28 + 0x8) = v14;
  *(_DWORD *)(v28 + 0xc) = v15;
  v16 = *(_DWORD *)(dword_12D9AC + 340);
  v17 = *(_DWORD *)(dword_12D9AC + 344);
  v18 = *(_DWORD *)(dword_12D9AC + 348);
  *(_DWORD *)(v28 + 0x10) = *(_DWORD *)(dword_12D9AC + 336);
  *(_DWORD *)(v28 + 0x14) = v16;
  *(_DWORD *)(v28 + 0x18) = v17;
  *(_DWORD *)(v28 + 0x1c) = v18;
  v19 = *(_DWORD *)(dword_12D9AC + 356);
  v20 = *(_DWORD *)(dword_12D9AC + 360);
  v21 = *(_DWORD *)(dword_12D9AC + 364);
  *(_DWORD *)(v28 + 0x20) = *(_DWORD *)(dword_12D9AC + 352);
  *(_DWORD *)(v28 + 0x24) = v19;
  *(_DWORD *)(v28 + 0x28) = v20;
  *(_DWORD *)(v28 + 0x2c) = v21;
  v22 = *(_DWORD *)(dword_12D9AC + 372);
  v23 = *(_DWORD *)(dword_12D9AC + 376);
  v24 = *(_DWORD *)(dword_12D9AC + 380);
  *(_DWORD *)(v28 + 0x30) = *(_DWORD *)(dword_12D9AC + 368);
  *(_DWORD *)(v28 + 0x34) = v22;
  *(_DWORD *)(v28 + 0x38) = v23;
  *(_DWORD *)(v28 + 0x3c) = v24;
  v25 = COERCE_FLOAT(v28[(LODWORD(a1) >> 20) & 0xF] + (LODWORD(a1) >> 1)) * *(float *)&v27[(LODWORD(a1) >> 20) & 0xF];
  return (float)((float)(a1 / v25) + v25) * 0.5;
}

