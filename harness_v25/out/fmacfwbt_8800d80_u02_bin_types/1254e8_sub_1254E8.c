// sub_1254E8 @ 0x1254e8, size 566 bytes
// Doc: sub_12254E8 [util]: Helper processing function on 3-byte struct input
// sub_12254E8 [util]: Helper processing function on 3-byte struct input
int  sub_1254E8(unsigned __int16 *a1)
{
  unsigned int v1; // r2
  int v2; // r3
  int v5; // r0
  unsigned int v6; // r1
  int v7; // r2
  char v8; // r7
  uint8_t *v9; // r6
  char v10; // r12
  int v11; // r5
  int v12; // lr
  int v13; // r2
  unsigned int v14; // r12
  int v15; // r7
  int v16; // r0
  unsigned int v17; // r8
  int v18; // lr
  __int16 v19; // r2
  int v20; // r1
  __int16 v21; // r2
  int v22; // lr
  int v23; // r12
  int v24; // r7
  int v25; // r7
  int v26; // r2
  int v27; // r7
  __int16 v28; // r1
  __int16 v29; // r1
  unsigned __int8 v30; // r8
  int v31; // r2
  int v32; // r7
  int v33; // r7
  uint8_t *v34; // r12
  int v35; // r2
  char v36; // r1
  int v37; // r2

  v1 = *a1;
  v2 = *((unsigned __int8 *)a1 + 3);
  if ( *a1 )
  {
    v5 = dword_125724 + 252 * v2;
    v6 = (unsigned __int8)(v1 >> 3);
    v7 = 1 << (v1 & 7);
    v8 = *(uint8_t *)(v6 + v5);
    v9 = (uint8_t *)(v6 + v5);
    v10 = v7;
    v11 = dword_125728 + 8 * v2;
    if ( *((uint8_t *)a1 + 2) )
    {
      if ( ((unsigned __int8)v7 & *(uint8_t *)(v6 + v5)) == 0 )
      {
        v12 = dword_125720;
        v13 = dword_125720 + 1320 * v2;
        *v9 = v10 | v8;
        v14 = *(unsigned __int8 *)(v13 + 228);
        ++*(uint16_t *)(v13 + 220);
        v15 = dword_12572C;
        if ( v14 > v6 )
        {
          *(uint32_t *)(dword_12572C + 40 * v2 + 28) = v5 + (v6 & 0xFE);
          *(uint8_t *)(v13 + 228) = v6 & 0xFE;
        }
        v16 = v12 + 1320 * v2;
        v17 = *(unsigned __int8 *)(v16 + 229);
        if ( v17 < v6 )
        {
          *(uint8_t *)(v16 + 229) = v6;
          LOWORD(v17) = v6;
          *(uint32_t *)(v15 + 40 * v2 + 32) = v9;
        }
        v18 = v12 + 1320 * v2;
        v19 = *(unsigned __int8 *)(v18 + 228);
        *(uint8_t *)(v11 + 4) = v19;
        v20 = v15 + 40 * v2;
        v21 = 6 - v19 + v17;
        v2 = v20 + 20;
        *(uint32_t *)(v20 + 12) = v11 + 4;
        *(uint32_t *)(v20 + 4) = v20 + 20;
        *(uint16_t *)(v18 + 218) = v21;
        *(uint8_t *)(v11 + 1) = v21 - 2;
      }
    }
    else if ( ((unsigned __int8)v7 & *(uint8_t *)(v6 + v5)) != 0 )
    {
      v22 = dword_125720;
      v23 = dword_125720 + 1320 * v2;
      *v9 = v8 & ~(uint8_t)v7;
      v24 = (unsigned __int16)(*(uint16_t *)(v23 + 220) - 1);
      *(uint16_t *)(v23 + 220) = v24;
      if ( v24 )
      {
        v25 = *(unsigned __int8 *)(v23 + 228);
        if ( v25 == (v6 & 0xFE) )
        {
          while ( 1 )
          {
            if ( v25 == 251 )
            {
              v31 = 250;
              LOBYTE(v32) = -6;
              goto LABEL_22;
            }
            v30 = v25 + 1;
            if ( *(uint8_t *)(v25 + v5) )
              break;
            v25 = v30;
            *(uint8_t *)(v23 + 228) = v30;
          }
          v32 = v25 & 0xFE;
          v31 = v32;
LABEL_22:
          *(uint32_t *)(dword_12572C + 40 * v2 + 28) = v31 + v5;
          *(uint8_t *)(v22 + 1320 * v2 + 228) = v32;
        }
        v26 = v22 + 1320 * v2;
        v27 = *(unsigned __int8 *)(v26 + 229);
        if ( v27 == v6 )
        {
          while ( 1 )
          {
            if ( !v6 )
            {
              LOWORD(v27) = 0;
              goto LABEL_28;
            }
            v33 = (unsigned __int8)*v9;
            v34 = v9;
            v6 = (unsigned __int8)(v6 - 1);
            --v9;
            if ( v33 )
              break;
            *(uint8_t *)(v26 + 229) = v6;
          }
          v5 = (int)v34;
          LOWORD(v27) = *(unsigned __int8 *)(v22 + 1320 * v2 + 229);
LABEL_28:
          *(uint32_t *)(dword_12572C + 40 * v2 + 32) = v5;
        }
        v2 = v22 + 1320 * v2;
        v28 = *(unsigned __int8 *)(v2 + 228);
        *(uint8_t *)(v11 + 4) = v28;
        v29 = 6 - v28 + v27;
        *(uint16_t *)(v2 + 218) = v29;
        *(uint8_t *)(v11 + 1) = v29 - 2;
      }
      else
      {
        *(uint16_t *)(v23 + 218) = 6;
        *(uint16_t *)(v22 + 1320 * v2 + 228) = 255;
        v35 = dword_12572C;
        v36 = *(uint8_t *)(v23 + 218);
        *(uint8_t *)(v11 + 4) = 0;
        v2 = v35 + 40 * v2;
        *(uint32_t *)(v2 + 12) = v11 + 5;
        *(uint8_t *)(v11 + 1) = v36 - 2;
        v37 = dword_125730 + 20 * *((unsigned __int8 *)a1 + 3);
        *(uint32_t *)(v2 + 32) = v5 + *(unsigned __int8 *)(v23 + 229);
        *(uint32_t *)(v2 + 4) = v37;
      }
    }
  }
  else
  {
    v2 = dword_125720 + 1320 * v2;
    if ( *((uint8_t *)a1 + 2) )
      *(uint8_t *)(v2 + 230) = 1;
    else
      *(uint8_t *)(v2 + 230) = 0;
  }
  message_dispatch_n84(66, *(a1 - 2), 0, v2);
  return j_buffer_pool_get(a1 - 6);
}

