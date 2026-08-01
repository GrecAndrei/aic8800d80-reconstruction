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

extern uint32_t off_13880C;
extern uint32_t dword_138810;
extern uint32_t dword_138814;

// rf_validate_rate @ 0x1386a8, size 354 bytes
int  rf_validate_rate(int a1, int16_t a2)
{
  uint8_t *v2; // r2
  int v3; // r4
  int v4; // r3
  int v5; // r1
  int v6; // r5
  int result; // r0
  int v8; // r3
  char v9; // r1
  int v10; // r6
  int v11; // r8
  int v12; // r3
  int v13; // t1
  char v14; // r1
  int v15; // r4
  int16_t v16; // r3
  int v17; // r12
  char v18; // r4
  int v19; // r3

  v2 = off_13880C;
  v3 = *((uint8_t *)off_13880C + 8);
  v4 = (a2 & 0x7C) - 4;
  v5 = a2 & 0x400;
  v6 = a1 + v3;
  switch ( v4 )
  {
    case 0:
      *((uint8_t *)off_13880C + 8) = v3 + 4;
      result = 1;
      break;
    case 4:
      *((uint8_t *)off_13880C + 8) = v3 + 8;
      v16 = *(uint16_t *)(a1 + v3);
      v17 = *(uint16_t *)(v6 + 6);
      v18 = v2[48];
      *((uint32_t *)v2 + 4) = (uint16_t)(v16 << 8)
                          | *(uint8_t *)(v6 + 2)
                          | (*(uint16_t *)(v6 + 4) << 16);
      *((uint32_t *)v2 + 5) = v17;
      v2[48] = v18 | 3;
      if ( v5 )
        v19 = 1320 * (uint8_t)v2[10] + 480 + 120 * (*(uint16_t *)(v6 + 2) >> 14) + dword_138810;
      else
        v19 = dword_138814 + 696 * (uint8_t)v2[9];
      *((uint32_t *)v2 + 8) = v19;
      result = 1;
      break;
    case 8:
    case 12:
    case 16:
    case 20:
      if ( v5 )
        v8 = 1320 * *((uint8_t *)off_13880C + 10)
           + 480
           + 120 * (*(uint16_t *)(v6 + 2) >> 14)
           + dword_138810;
      else
        v8 = dword_138814 + 696 * *((uint8_t *)off_13880C + 9);
      *((uint8_t *)off_13880C + 8) = v3 + 8;
      v9 = v2[48];
      v10 = *(uint16_t *)(a1 + v3);
      v11 = *(uint16_t *)(v6 + 4);
      *((uint32_t *)v2 + 8) = v8;
      *((uint32_t *)v2 + 5) = *(uint16_t *)(v6 + 6);
      v2[48] = v9 | 2;
      *((uint32_t *)v2 + 4) = v10 | (v11 << 16);
      result = 1;
      break;
    case 24:
      if ( v5 )
        v12 = 1320 * *((uint8_t *)off_13880C + 10)
            + 480
            + 120 * (*(uint16_t *)(v6 + 2) >> 14)
            + dword_138810;
      else
        v12 = dword_138814 + 696 * *((uint8_t *)off_13880C + 9);
      *((uint8_t *)off_13880C + 8) = v3 + 18;
      v13 = *(uint32_t *)(v6 + 2);
      v14 = v2[48];
      v15 = *(uint32_t *)(v6 + 6);
      *((uint32_t *)v2 + 8) = v12;
      v2[48] = v14 | 2;
      *((uint32_t *)v2 + 4) = v13;
      *((uint32_t *)v2 + 5) = v15;
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

