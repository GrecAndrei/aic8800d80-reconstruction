// sub_12D70C @ 0x12d70c, size 120 bytes
float  sub_12D70C(float a1)
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
  uint32_t v27[16]; // [sp+0h] [bp-80h]
  uint32_t v28[16]; // [sp+40h] [bp-40h]

  v1 = *(uint32_t *)(dword_12D784 + 260);
  v2 = *(uint32_t *)(dword_12D784 + 264);
  v3 = *(uint32_t *)(dword_12D784 + 268);
  v27[0] = *(uint32_t *)(dword_12D784 + 256);
  v27[1] = v1;
  v27[2] = v2;
  v27[3] = v3;
  v4 = *(uint32_t *)(dword_12D784 + 276);
  v5 = *(uint32_t *)(dword_12D784 + 280);
  v6 = *(uint32_t *)(dword_12D784 + 284);
  v27[4] = *(uint32_t *)(dword_12D784 + 272);
  v27[5] = v4;
  v27[6] = v5;
  v27[7] = v6;
  v7 = *(uint32_t *)(dword_12D784 + 292);
  v8 = *(uint32_t *)(dword_12D784 + 296);
  v9 = *(uint32_t *)(dword_12D784 + 300);
  v27[8] = *(uint32_t *)(dword_12D784 + 288);
  v27[9] = v7;
  v27[10] = v8;
  v27[11] = v9;
  v10 = *(uint32_t *)(dword_12D784 + 308);
  v11 = *(uint32_t *)(dword_12D784 + 312);
  v12 = *(uint32_t *)(dword_12D784 + 316);
  v27[12] = *(uint32_t *)(dword_12D784 + 304);
  v27[13] = v10;
  v27[14] = v11;
  v27[15] = v12;
  v13 = *(uint32_t *)(dword_12D784 + 324);
  v14 = *(uint32_t *)(dword_12D784 + 328);
  v15 = *(uint32_t *)(dword_12D784 + 332);
  v28[0] = *(uint32_t *)(dword_12D784 + 320);
  v28[1] = v13;
  v28[2] = v14;
  v28[3] = v15;
  v16 = *(uint32_t *)(dword_12D784 + 340);
  v17 = *(uint32_t *)(dword_12D784 + 344);
  v18 = *(uint32_t *)(dword_12D784 + 348);
  v28[4] = *(uint32_t *)(dword_12D784 + 336);
  v28[5] = v16;
  v28[6] = v17;
  v28[7] = v18;
  v19 = *(uint32_t *)(dword_12D784 + 356);
  v20 = *(uint32_t *)(dword_12D784 + 360);
  v21 = *(uint32_t *)(dword_12D784 + 364);
  v28[8] = *(uint32_t *)(dword_12D784 + 352);
  v28[9] = v19;
  v28[10] = v20;
  v28[11] = v21;
  v22 = *(uint32_t *)(dword_12D784 + 372);
  v23 = *(uint32_t *)(dword_12D784 + 376);
  v24 = *(uint32_t *)(dword_12D784 + 380);
  v28[12] = *(uint32_t *)(dword_12D784 + 368);
  v28[13] = v22;
  v28[14] = v23;
  v28[15] = v24;
  v25 = COERCE_FLOAT(v28[(LODWORD(a1) >> 20) & 0xF] + (LODWORD(a1) >> 1)) * *(float *)&v27[(LODWORD(a1) >> 20) & 0xF];
  return (float)((float)(a1 / v25) + v25) * 0.5;
}

