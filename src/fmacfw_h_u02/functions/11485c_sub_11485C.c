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

extern uint32_t dword_1148F8;

// packet_prepare_b @ 0x11485c, size 156 bytes
int  packet_prepare_b(int a1, int a2)
{
  int v3; // r1
  int v4; // r2
  int v5; // r7
  unsigned int v6; // r4
  int v7; // r0
  int v8; // r2
  int result; // r0
  unsigned int v10; // r4
  int v11; // zf
  int v12; // r3
  unsigned int v13; // r4
  unsigned int v14; // r5
  uint8_t *v15; // r4
  int v16; // [sp+4h] [bp-18h]
  int v17; // [sp+8h] [bp-14h]
  uint32_t v18[4]; // [sp+Ch] [bp-10h] BYREF

  v3 = *(uint32_t *)(dword_1148F8 + 4);
  v4 = *(uint32_t *)(dword_1148F8 + 8);
  v18[0] = *(uint32_t *)dword_1148F8;
  v18[1] = v3;
  v18[2] = v4;
  v5 = v18[a1];
  v16 = MEMORY[0x1FC](v5);
  v6 = v16;
  v7 = MEMORY[0x1FC](v5 + 1);
  v8 = 0;
  v17 = v7;
  result = 0;
  while ( 1 )
  {
    v12 = v6 >> (8 * (v8 & 3));
    v14 = (uint8_t)v12;
    v10 = (uint8_t)v12 >> 4;
    if ( (v12 & 0xF0) == 0 )
    {
      v12 = 1 << (4 * v8);
      if ( !v14 )
      {
        result |= 2 << (4 * v8);
        v15 = (uint8_t *)(a2 + v8);
        goto LABEL_8;
      }
      result |= v12;
      v10 = v14;
    }
    v11 = (v10 & 1) == 0;
    if ( (v10 & 1) != 0 )
      LOBYTE(v12) = -1;
    v13 = v10 >> 1;
    if ( v11 )
      LOBYTE(v12) = 1;
    LOBYTE(v14) = v13 * v12;
    v15 = (uint8_t *)(a2 + v8);
LABEL_8:
    ++v8;
    *v15 = v14;
    if ( v8 == 6 )
      return result;
    v6 = *(uint32_t *)((char *)&v18[-2] + (v8 & 0xFFFFFFFC));
  }
}

