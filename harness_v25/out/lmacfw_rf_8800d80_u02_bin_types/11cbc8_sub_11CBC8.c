// sub_11CBC8 @ 0x11cbc8, size 304 bytes
// Doc: sub_121CBC8 [mmio]: Read PHY status fields from shared state
// sub_121CBC8 [mmio]: Read PHY status fields from shared state
void sub_11CBC8()
{
  int v0; // r5
  int v1; // r8
  char *v2; // r6
  int v3; // r7
  int v4; // r0
  int v5; // r0
  char *v6; // r2
  int v7; // r1
  uint16_t *v8; // lr
  int v9; // r3
  __int16 v10; // r4
  int *v11; // r9
  int v12; // r12
  __int16 v13; // r10
  int v14; // r0
  int v15; // r0
  __int16 v16; // r10
  int v17; // r0
  int v18; // r3
  char v19; // t1
  int v20; // r2
  int v21; // r3
  int v22; // [sp+0h] [bp-Ch]
  int v23; // [sp+4h] [bp-8h]

  v0 = *(uint32_t *)off_11CCF8;
  v22 = *((unsigned __int8 *)off_11CCF8 + 10);
  if ( *(uint8_t *)(*(uint32_t *)off_11CCF8 + 368) )
  {
    v1 = dword_11CCFC + 224 * *(unsigned __int8 *)(*(uint32_t *)off_11CCF8 + 366) + 88;
    v2 = (char *)(v0 + 253);
    v3 = 0;
    v23 = 2 * *((unsigned __int8 *)off_11CCF8 + 10);
    do
    {
      if ( *(uint8_t *)(v0 + 2 * (v23 + v22) + 2) )
      {
        v4 = 1;
      }
      else
      {
        v4 = *(unsigned __int8 *)(v0 + 369);
        if ( *(uint8_t *)(v0 + 369) )
          v4 = 1;
      }
      v5 = rf_alloc_or_init(v4, *(unsigned __int16 *)(v0 + 364) + (unsigned __int8)*(v2 - 1) + 26);
      v6 = v2;
      v7 = v5;
      if ( !v5 )
        break;
      v8 = off_11CD04;
      v9 = *(uint32_t *)(v5 + 28);
      v10 = *((uint16_t *)off_11CD04 + 70);
      v11 = (int *)off_11CD08;
      v12 = *(uint32_t *)(v5 + 32);
      v13 = *((uint16_t *)off_11CD08 + 2);
      *(uint32_t *)(v9 + 114) = *(uint32_t *)v1;
      v14 = *v11;
      LOWORD(v11) = *(uint16_t *)(v1 + 4);
      *(uint32_t *)(v9 + 108) = v14;
      ++v10;
      v15 = *(uint32_t *)(v0 + 352);
      *(uint16_t *)(v9 + 112) = v13;
      v16 = *(uint16_t *)(v0 + 356);
      *(uint16_t *)(v9 + 118) = (uint16_t)v11;
      *(uint32_t *)(v9 + 120) = v15;
      *(uint8_t *)(v9 + 104) = 64;
      *(uint16_t *)(v9 + 124) = v16;
      *(uint8_t *)(v9 + 105) = 0;
      *(uint8_t *)(v9 + 106) = 0;
      *(uint8_t *)(v9 + 107) = 0;
      v8[70] = v10;
      *(uint8_t *)(v9 + 128) = 0;
      *(uint8_t *)(v9 + 129) = *(v2 - 1);
      v17 = (unsigned __int8)*(v2 - 1);
      *(uint16_t *)(v9 + 126) = 16 * v10;
      if ( v17 )
      {
        v18 = v9 + 129;
        do
        {
          v19 = *v6++;
          *(uint8_t *)++v18 = v19;
        }
        while ( v6 != &v2[v17] );
      }
      v20 = *(unsigned __int16 *)(v0 + 364);
      v21 = *(uint32_t *)(v12 + 28);
      *(uint32_t *)(v12 + 20) = dword_11CD00;
      *(uint32_t *)(v12 + 28) = v21 - v20;
      *(uint32_t *)(v7 + 44) = 0;
      *(uint32_t *)(v7 + 48) = 0;
      *(uint8_t *)(v7 + 15) = *(uint8_t *)(v0 + 366);
      *(uint8_t *)(v7 + 16) = -1;
      sub_1165B0(v7, 5);
      ++v3;
      v2 += 33;
    }
    while ( *(unsigned __int8 *)(v0 + 368) > v3 );
  }
}

