#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t dword_125500;
extern uint32_t dword_125504;
extern uint32_t dword_1254FC;
extern uint32_t dword_125508;
extern uint32_t dword_12550C;

// rf_parse_descriptor_n3f8 @ 0x1252c4, size 566 bytes
// Doc: rf_parse_descriptor_n3f8 [rf]: Parses a 4-byte RF descriptor header (length/type fields)
// rf_parse_descriptor_n3f8 [rf]: Parses a 4-byte RF descriptor header (length/type fields)
int  rf_parse_descriptor_n3f8(uint16_t *a1)
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
  int16_t v19; // r2
  int v20; // r1
  int16_t v21; // r2
  int v22; // lr
  int v23; // r12
  int v24; // r7
  int v25; // r7
  int v26; // r2
  int v27; // r7
  int v28; // r3
  int16_t v29; // r1
  int16_t v30; // r1
  uint8_t v31; // r8
  int v32; // r2
  int v33; // r7
  int v34; // r7
  uint8_t *v35; // r12
  int v36; // r2
  char v37; // r1
  uint32_t *v38; // r3
  int v39; // r2

  v1 = *a1;
  v2 = *((uint8_t *)a1 + 3);
  if ( *a1 )
  {
    v5 = dword_125500 + 252 * v2;
    v6 = (uint8_t)(v1 >> 3);
    v7 = 1 << (v1 & 7);
    v8 = *(uint8_t *)(v6 + v5);
    v9 = (uint8_t *)(v6 + v5);
    v10 = v7;
    v11 = dword_125504 + 8 * v2;
    if ( *((uint8_t *)a1 + 2) )
    {
      if ( ((uint8_t)v7 & *(uint8_t *)(v6 + v5)) == 0 )
      {
        v12 = dword_1254FC;
        v13 = dword_1254FC + 1320 * v2;
        *v9 = v10 | v8;
        v14 = *(uint8_t *)(v13 + 228);
        ++*(uint16_t *)(v13 + 220);
        v15 = dword_125508;
        if ( v14 > v6 )
        {
          *(uint32_t *)(dword_125508 + 40 * v2 + 28) = v5 + (v6 & 0xFE);
          *(uint8_t *)(v13 + 228) = v6 & 0xFE;
        }
        v16 = v12 + 1320 * v2;
        v17 = *(uint8_t *)(v16 + 229);
        if ( v17 < v6 )
        {
          *(uint8_t *)(v16 + 229) = v6;
          LOWORD(v17) = v6;
          *(uint32_t *)(v15 + 40 * v2 + 32) = v9;
        }
        v18 = v12 + 1320 * v2;
        v19 = *(uint8_t *)(v18 + 228);
        *(uint8_t *)(v11 + 4) = v19;
        v20 = v15 + 40 * v2;
        v21 = 6 - v19 + v17;
        *(uint32_t *)(v20 + 12) = v11 + 4;
        *(uint32_t *)(v20 + 4) = v20 + 20;
        *(uint16_t *)(v18 + 218) = v21;
        *(uint8_t *)(v11 + 1) = v21 - 2;
      }
    }
    else if ( ((uint8_t)v7 & *(uint8_t *)(v6 + v5)) != 0 )
    {
      v22 = dword_1254FC;
      v23 = dword_1254FC + 1320 * v2;
      *v9 = v8 & ~(uint8_t)v7;
      v24 = (uint16_t)(*(uint16_t *)(v23 + 220) - 1);
      *(uint16_t *)(v23 + 220) = v24;
      if ( v24 )
      {
        v25 = *(uint8_t *)(v23 + 228);
        if ( v25 == (v6 & 0xFE) )
        {
          while ( 1 )
          {
            if ( v25 == 251 )
            {
              v32 = 250;
              LOBYTE(v33) = -6;
              goto LABEL_22;
            }
            v31 = v25 + 1;
            if ( *(uint8_t *)(v25 + v5) )
              break;
            v25 = v31;
            *(uint8_t *)(v23 + 228) = v31;
          }
          v33 = v25 & 0xFE;
          v32 = v33;
LABEL_22:
          *(uint32_t *)(dword_125508 + 40 * v2 + 28) = v32 + v5;
          *(uint8_t *)(v22 + 1320 * v2 + 228) = v33;
        }
        v26 = v22 + 1320 * v2;
        v27 = *(uint8_t *)(v26 + 229);
        if ( v27 == v6 )
        {
          while ( 1 )
          {
            if ( !v6 )
            {
              LOWORD(v27) = 0;
              goto LABEL_28;
            }
            v34 = (uint8_t)*v9;
            v35 = v9;
            v6 = (uint8_t)(v6 - 1);
            --v9;
            if ( v34 )
              break;
            *(uint8_t *)(v26 + 229) = v6;
          }
          v5 = (int)v35;
          LOWORD(v27) = *(uint8_t *)(v22 + 1320 * v2 + 229);
LABEL_28:
          *(uint32_t *)(dword_125508 + 40 * v2 + 32) = v5;
        }
        v28 = v22 + 1320 * v2;
        v29 = *(uint8_t *)(v28 + 228);
        *(uint8_t *)(v11 + 4) = v29;
        v30 = 6 - v29 + v27;
        *(uint16_t *)(v28 + 218) = v30;
        *(uint8_t *)(v11 + 1) = v30 - 2;
      }
      else
      {
        *(uint16_t *)(v23 + 218) = 6;
        *(uint16_t *)(v22 + 1320 * v2 + 228) = 255;
        v36 = dword_125508;
        v37 = *(uint8_t *)(v23 + 218);
        *(uint8_t *)(v11 + 4) = 0;
        v38 = (uint32_t *)(v36 + 40 * v2);
        v38[3] = v11 + 5;
        *(uint8_t *)(v11 + 1) = v37 - 2;
        v39 = dword_12550C + 20 * *((uint8_t *)a1 + 3);
        v38[8] = v5 + *(uint8_t *)(v23 + 229);
        v38[1] = v39;
      }
    }
  }
  else if ( *((uint8_t *)a1 + 2) )
  {
    *(uint8_t *)(dword_1254FC + 1320 * v2 + 230) = 1;
  }
  else
  {
    *(uint8_t *)(dword_1254FC + 1320 * v2 + 230) = 0;
  }
  sub_12CA10(66, *(a1 - 2), 0);
  return sub_12CA38(a1 - 6);
}

