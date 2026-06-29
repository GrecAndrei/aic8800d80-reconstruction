// sub_113918 @ 0x113918, size 264 bytes
int  sub_113918(int a1)
{
  void *v1; // r5
  uint32_t *v2; // r1
  int *v3; // r2
  uint32_t *v4; // r3
  uint16_t *v5; // r6
  int *v6; // r0
  uint32_t *v7; // r2
  uint32_t *v8; // r3
  uint32_t *v9; // r4
  uint8_t *v10; // r3
  int v11; // r5
  int v12; // r0
  int v13; // r1
  uint32_t *v14; // r6
  int *v15; // r2
  uint8_t *v16; // r4
  int v17; // r1
  uint8_t *v18; // r5
  bool v19; // cc
  char v20; // r0
  int v21; // r3
  void *v22; // r2
  int v23; // r0
  int v25; // r0

  v1 = off_113A20;
  v2 = off_113A28;
  v3 = *(int **)(*(uint32_t *)off_113A20 + 16);
  v4 = off_113A2C;
  *(uint32_t *)off_113A24 = v3;
  *v2 = v3 + 16;
  v5 = off_113A30;
  v4[2] = a1;
  *v4 = 0;
  v4[1] = 0;
  v4[4] = 0;
  v4[5] = 0;
  v4[3] = 0;
  v5[6] = 0;
  memset_thunk(v3, 0, 0x140u);
  v6 = *(int **)(*(uint32_t *)v1 + 20);
  v7 = off_113A38;
  v8 = off_113A3C;
  *(uint32_t *)off_113A34 = v6;
  *v7 = v6 + 2;
  *v8 = v6 + 4;
  v8[1] = v6 + 6;
  v8[2] = v6 + 8;
  v8[3] = v6 + 10;
  v9 = off_113A40;
  v8[4] = v6 + 12;
  *v9 = v6 + 14;
  memset_thunk(v6, 0, 0xCB8u);
  if ( **(__int16 **)off_113A44 < 0 && *(uint32_t *)(*(uint32_t *)v1 + 24) <= 0xCB7u )
    sub_12F694(dword_113A78, dword_113A74, 758);
  v10 = off_113A48;
  v11 = *((unsigned __int16 *)off_113A48 + 164);
  v12 = *((unsigned __int16 *)off_113A48 + 154);
  v13 = dword_113A50;
  v14 = off_113A54;
  *(uint32_t *)off_113A58 = *((unsigned __int16 *)off_113A48 + 153) - *(uint32_t *)off_113A4C - 4;
  v15 = (int *)off_113A5C;
  v16 = off_113A60;
  v17 = v13 * v11;
  v18 = off_113A64;
  *v14 = v12 - 4;
  v19 = v17 <= (int)v15;
  if ( v17 > (int)v15 )
    v17 = (int)off_113A68;
  else
    v15 = (int *)off_113A68;
  *v18 = v10[320];
  v20 = v10[321];
  v21 = (unsigned __int8)v10[368];
  *v16 = v20;
  if ( v19 )
    *v15 = v17;
  else
    *(uint32_t *)v17 = v15;
  if ( v21 )
  {
    v22 = off_113A6C;
    v23 = dword_113A70;
    *(uint8_t *)off_113A6C = v21;
    sub_12ECB0(v23, v21, v22);
  }
  else
  {
    v25 = dword_113A70;
    *(uint8_t *)off_113A6C = 10;
    sub_12ECB0(v25, 10, v15);
  }
  return 1;
}

