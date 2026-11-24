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


extern uint32_t dword_135A60;
extern uint32_t dword_135A64;
extern uint32_t off_135A68;

// sub_135924 @ 0x135924, size 316 bytes
void  sub_135924(int a1)
{
  int v1; // r4
  int v2; // r2
  int v3; // r3
  int v5; // r2
  int v6; // r6
  int16_t v7; // r8
  uint32_t *v8; // r0
  int v9; // r7
  int16_t v10; // r3
  uint16_t *v11; // r12
  int v12; // r3
  int16_t v13; // r1
  int v14; // r2
  int v15; // r0
  int16_t v16; // r6
  int v17; // r4
  uint16_t *v18; // r4
  int v19; // r3
  char *v20; // r2
  int v21; // r1
  int64_t v22; // r2
  int v23; // [sp+4h] [bp-10h] BYREF
  int v24; // [sp+8h] [bp-Ch]
  int16_t v25; // [sp+Ch] [bp-8h]

  v1 = dword_135A60 + 1320 * *(uint8_t *)(a1 + 8);
  v2 = *(uint8_t *)(v1 + 108);
  v23 = 0;
  v24 = 0;
  v25 = 0;
  if ( v2 )
  {
    if ( !*(uint8_t *)(v1 + 106) )
    {
      v3 = *(uint8_t *)(a1 + 7);
      if ( v3 != 255 )
      {
        v5 = *(uint8_t *)(v1 + 116);
        if ( v5 == v3 )
        {
          v6 = dword_135A64 + 696 * v5;
          if ( *(uint8_t *)(v6 + 52) == 2 && !*(uint8_t *)(a1 + 13) )
          {
            v7 = *(uint16_t *)(a1 + 14);
            v8 = sub_119084(*(uint8_t *)(a1 + 6) != 0, 512);
            v9 = (int)v8;
            if ( v8 )
            {
              v10 = *(uint16_t *)(a1 + 4);
              LOBYTE(v23) = *(uint8_t *)(a1 + 6);
              LOWORD(v24) = v10;
              HIWORD(v23) = v10;
              sub_12C760(v1, v8, &v23);
              v11 = off_135A68;
              v12 = *(uint32_t *)(v9 + 72);
              v13 = *((uint16_t *)off_135A68 + 254);
              v14 = v6 + 38;
              *(uint32_t *)(v12 + 112) = *(uint32_t *)(v6 + 38);
              *(uint8_t *)(v12 + 108) = -48;
              *(uint16_t *)(v12 + 116) = *(uint16_t *)(v6 + 42);
              ++v13;
              v15 = *(uint32_t *)(v1 + 100);
              v16 = *(uint16_t *)(v1 + 104);
              v17 = *(uint32_t *)v14;
              *(uint32_t *)(v12 + 118) = v15;
              LOWORD(v15) = *(uint16_t *)(v14 + 4);
              *(uint8_t *)(v12 + 109) = 0;
              *(uint8_t *)(v12 + 110) = 0;
              *(uint8_t *)(v12 + 111) = 0;
              *(uint16_t *)(v12 + 122) = v16;
              *(uint32_t *)(v12 + 124) = v17;
              *(uint16_t *)(v12 + 128) = v15;
              v11[254] = v13;
              *(uint16_t *)(v12 + 130) = 16 * v13;
              *(uint8_t *)(v9 + 28) = *(uint8_t *)(a1 + 8);
              *(uint8_t *)(v9 + 29) = *(uint8_t *)(a1 + 7);
              v18 = (uint16_t *)(v12 + 108);
              *(uint8_t *)(v9 + 51) = 0;
              *(uint8_t *)(v9 + 53) = 0;
              sub_13C734(v9, 208, 8);
              sub_13B13C(v9, v18, 24);
              v19 = *(uint8_t *)(v9 + 51) + 24;
              v20 = (char *)v18 + v19;
              *((uint8_t *)v18 + v19) = 8;
              v20[1] = 1;
              v21 = *(uint32_t *)(v9 + 76);
              *((uint16_t *)v20 + 1) = v7;
              HIDWORD(v22) = v19 + *(uint8_t *)(v9 + 53) + 4;
              LODWORD(v22) = *(uint32_t *)(v21 + 28) - 1 + HIDWORD(v22);
              HIDWORD(v22) += 4;
              *(uint64_t *)(v21 + 32) = v22;
              sub_1190B4(v9, 5);
            }
          }
        }
      }
    }
  }
}
