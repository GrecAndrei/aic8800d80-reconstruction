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

extern uint32_t off_12B6F4;
extern uint32_t dword_12B6F8;
extern uint32_t off_12B700;
extern uint32_t off_12B704;
extern uint32_t dword_12B6FC;

// sub_12B5BC @ 0x12b5bc, size 312 bytes
// Doc: sub_122B5BC [rf]: Read RF status bytes and dispatch to message handler
// sub_122B5BC [rf]: Read RF status bytes and dispatch to message handler
void sub_12B5BC()
{
  int v0; // r5
  char *v1; // r6
  int v2; // r7
  int v3; // r0
  int v4; // r0
  char *v5; // r2
  int v6; // r1
  uint16_t *v7; // lr
  int v8; // r3
  int16_t v9; // r4
  int *v10; // r9
  int v11; // r12
  int16_t v12; // r10
  int v13; // r0
  int v14; // r0
  int16_t v15; // r10
  int v16; // r0
  int v17; // r3
  char v18; // t1
  int v19; // r2
  int v20; // r3
  int v21; // [sp+0h] [bp-Ch]
  int v22; // [sp+4h] [bp-8h]

  v0 = *(uint32_t *)off_12B6F4;
  v22 = *((uint8_t *)off_12B6F4 + 10);
  if ( *(uint8_t *)(*(uint32_t *)off_12B6F4 + 368) )
  {
    v21 = dword_12B6F8 + 1320 * *(uint8_t *)(*(uint32_t *)off_12B6F4 + 366);
    v1 = (char *)(v0 + 253);
    v2 = 0;
    do
    {
      if ( *(uint8_t *)(v21 + 1224) || *(uint8_t *)(v0 + 6 * v22 + 2) )
      {
        v3 = 1;
      }
      else
      {
        v3 = *(uint8_t *)(v0 + 369);
        if ( *(uint8_t *)(v0 + 369) )
          v3 = 1;
      }
      v4 = sub_119084(v3, *(uint16_t *)(v0 + 364) + (uint8_t)*(v1 - 1) + 26);
      v5 = v1;
      v6 = v4;
      if ( !v4 )
        break;
      v7 = off_12B700;
      v8 = *(uint32_t *)(v4 + 72);
      v9 = *((uint16_t *)off_12B700 + 254);
      v10 = (int *)off_12B704;
      v11 = *(uint32_t *)(v4 + 76);
      v12 = *((uint16_t *)off_12B704 + 2);
      *(uint32_t *)(v8 + 118) = *(uint32_t *)(v21 + 100);
      v13 = *v10;
      LOWORD(v10) = *(uint16_t *)(v21 + 104);
      *(uint32_t *)(v8 + 112) = v13;
      ++v9;
      v14 = *(uint32_t *)(v0 + 352);
      *(uint16_t *)(v8 + 116) = v12;
      v15 = *(uint16_t *)(v0 + 356);
      *(uint16_t *)(v8 + 122) = (uint16_t)v10;
      *(uint32_t *)(v8 + 124) = v14;
      *(uint8_t *)(v8 + 108) = 64;
      *(uint16_t *)(v8 + 128) = v15;
      *(uint8_t *)(v8 + 109) = 0;
      *(uint8_t *)(v8 + 110) = 0;
      *(uint8_t *)(v8 + 111) = 0;
      v7[254] = v9;
      *(uint8_t *)(v8 + 132) = 0;
      *(uint8_t *)(v8 + 133) = *(v1 - 1);
      v16 = (uint8_t)*(v1 - 1);
      *(uint16_t *)(v8 + 130) = 16 * v9;
      if ( v16 )
      {
        v17 = v8 + 133;
        do
        {
          v18 = *v5++;
          *(uint8_t *)++v17 = v18;
        }
        while ( v5 != &v1[v16] );
      }
      v19 = *(uint16_t *)(v0 + 364);
      v20 = *(uint32_t *)(v11 + 32);
      *(uint32_t *)(v11 + 24) = dword_12B6FC;
      *(uint32_t *)(v11 + 32) = v20 - v19;
      *(uint32_t *)(v6 + 88) = 0;
      *(uint32_t *)(v6 + 92) = 0;
      *(uint8_t *)(v6 + 28) = *(uint8_t *)(v0 + 366);
      *(uint8_t *)(v6 + 29) = -1;
      sub_1190B4(v6, 5);
      ++v2;
      v1 += 33;
    }
    while ( *(uint8_t *)(v0 + 368) > v2 );
  }
}

