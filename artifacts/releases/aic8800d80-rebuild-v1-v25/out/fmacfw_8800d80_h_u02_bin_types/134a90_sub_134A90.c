// sub_134A90 @ 0x134a90, size 428 bytes
uint32_t *sub_134A90()
{
  int v0; // r10
  int v1; // r5
  uint8_t *v2; // r9
  int v3; // r7
  int v4; // r4
  int v5; // r6
  int v6; // r11
  uint8_t *v7; // r8
  int v8; // r0
  void *v9; // r3
  int v10; // r0
  int v11; // r3
  int v12; // r0
  int v13; // r6
  int v14; // r6
  int v15; // r7
  int *v16; // r10
  int v17; // r0
  int v18; // t1
  int v19; // r0
  int *v21; // r6
  int v22; // [sp+0h] [bp-Ch]

  v0 = dword_134C48;
  v1 = *((uint32_t *)off_134C3C + 4);
  v22 = *(unsigned __int8 *)(v1 + 61);
  v2 = (uint8_t *)sub_12C7EC(5145, 5, 6, 2u);
  v3 = sub_12C7EC(24, 0, 6, 8u);
  v4 = 1320 * v22;
  v5 = sub_12C7EC(22, 0, 6, 8u);
  v6 = sub_12C7EC(20, 0, 6, 4u);
  v7 = (uint8_t *)sub_12C7EC(5143, 5, 6, 2u);
  sub_1342AC();
  *v2 = 1;
  v2[1] = *(uint8_t *)(v1 + 61);
  sub_12D108((int)off_134C3C + 24, (uint32_t *)v2 - 3);
  v8 = *(uint32_t *)(v0 + 1320 * v22 + 368);
  *(uint16_t *)(v3 + 4) = *(uint16_t *)(v0 + 1320 * v22 + 372);
  v9 = off_134C3C;
  *(uint32_t *)v3 = v8;
  *(uint8_t *)(v3 + 6) = *(uint8_t *)(v1 + 61);
  sub_12D108((int)v9 + 24, (uint32_t *)(v3 - 12));
  *(uint8_t *)(v5 + 5) = *(uint8_t *)(v0 + 1320 * v22 + 412);
  v10 = sub_132654((unsigned __int8 *)(1320 * v22 + 424 + v0), 1);
  v11 = *(unsigned __int8 *)(v5 + 5);
  *(uint32_t *)v5 = v10;
  *(uint8_t *)(v5 + 4) = *(uint8_t *)(v1 + 61);
  if ( !v11 )
  {
    if ( (v10 & 1) != 0 )
    {
      *((uint32_t *)off_134C40 + 5) = 1024;
    }
    else if ( (v10 & 0x10) != 0 )
    {
      *((uint32_t *)off_134C40 + 5) = 4;
    }
  }
  sub_12D108(dword_134C44, (uint32_t *)(v5 - 12));
  v12 = dword_134C44;
  v13 = v0 + 1320 * v22;
  *(uint16_t *)v6 = *(uint16_t *)(v13 + 422);
  *(uint8_t *)(v6 + 2) = *(uint8_t *)(v1 + 61);
  sub_12D108(v12, (uint32_t *)(v6 - 12));
  if ( (*(uint32_t *)(v13 + 472) & 8) != 0 )
  {
    v21 = (int *)sub_12C7EC(113, 0, 6, 4u);
    *v21 = sub_132744(v0 + v4 + 248);
    sub_12D108(dword_134C44, v21 - 3);
  }
  v14 = 0;
  v15 = dword_134C44;
  v16 = (int *)(v0 + v4 + 440);
  do
  {
    v17 = sub_12C7EC(26, 0, 6, 8u);
    v18 = *v16++;
    *(uint32_t *)v17 = v18;
    *(uint8_t *)(v17 + 5) = v14;
    *(uint8_t *)(v17 + 6) = *(uint8_t *)(v1 + 61);
    *(uint8_t *)(v17 + 4) = 0;
    ++v14;
    sub_12D108(v15, (uint32_t *)(v17 - 12));
  }
  while ( v14 != 4 );
  *v7 = 1;
  v19 = dword_134C44;
  v7[1] = *(uint8_t *)(v1 + 61);
  sub_12D108(v19, (uint32_t *)v7 - 3);
  sub_13467C();
  return sub_12CBF4(6u, 4);
}

