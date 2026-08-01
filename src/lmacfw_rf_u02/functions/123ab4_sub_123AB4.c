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

extern uint32_t off_123B28;
extern uint32_t off_123B2C;

// build_hci_event @ 0x123ab4, size 114 bytes
int  build_hci_event(int a1)
{
  uint64_t v2; // r0
  uint16_t *v3; // r2
  int16_t v4; // r3
  int16_t v5; // r1
  int v6; // r0
  int16_t v7; // r7
  int v9; // [sp+0h] [bp-24h] BYREF
  int16_t v10; // [sp+4h] [bp-20h]
  int v11; // [sp+8h] [bp-1Ch] BYREF
  int16_t v12; // [sp+Ch] [bp-18h]
  int v13; // [sp+10h] [bp-14h] BYREF
  int16_t v14; // [sp+14h] [bp-10h]
  int v15; // [sp+18h] [bp-Ch] BYREF
  int16_t v16; // [sp+1Ch] [bp-8h]

  v2 = *((uint64_t *)off_123B28 + 1);
  v10 = *((uint32_t *)off_123B28 + 3);
  v9 = v2;
  HIDWORD(v2) = *((uint32_t *)off_123B28 + 1);
  v11 = *(uint32_t *)off_123B28;
  v12 = WORD2(v2);
  memcpy_large(&v13, &v9, 6);
  memcpy_large(&v15, &v11, 6);
  v3 = off_123B2C;
  v4 = *((uint16_t *)off_123B2C + 70);
  *(uint32_t *)(a1 + 4) = v15;
  v5 = v16;
  *(uint32_t *)(a1 + 10) = v13;
  ++v4;
  v6 = v15;
  v7 = v14;
  *(uint16_t *)(a1 + 8) = v5;
  *(uint16_t *)(a1 + 20) = v5;
  *(uint8_t *)a1 = 8;
  *(uint32_t *)(a1 + 16) = v6;
  *(uint16_t *)(a1 + 14) = v7;
  *(uint8_t *)(a1 + 3) = 0;
  *(uint8_t *)(a1 + 1) = 1;
  *(uint8_t *)(a1 + 2) = 1;
  v3[70] = v4;
  *(uint16_t *)(a1 + 22) = 16 * v4;
  return 24;
}

