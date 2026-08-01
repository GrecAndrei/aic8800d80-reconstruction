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

extern uint32_t off_123AA8;
extern uint32_t dword_123AAC;
extern uint32_t off_123AB0;

// build_hci_command @ 0x123a20, size 136 bytes
int  build_hci_command(int a1)
{
  int v2; // r1
  uint64_t v3; // r0
  uint16_t *v4; // r2
  int16_t v5; // r3
  int16_t v6; // r1
  int16_t v7; // r5
  int v8; // r0
  int v10; // [sp+0h] [bp-34h] BYREF
  int16_t v11; // [sp+4h] [bp-30h]
  int v12; // [sp+8h] [bp-2Ch] BYREF
  int16_t v13; // [sp+Ch] [bp-28h]
  int v14; // [sp+10h] [bp-24h] BYREF
  int16_t v15; // [sp+14h] [bp-20h]
  int v16; // [sp+18h] [bp-1Ch] BYREF
  int16_t v17; // [sp+1Ch] [bp-18h]
  uint8_t v18[8]; // [sp+20h] [bp-14h] BYREF
  int v19; // [sp+28h] [bp-Ch] BYREF
  int16_t v20; // [sp+2Ch] [bp-8h]

  v2 = *((uint32_t *)off_123AA8 + 1);
  v10 = *(uint32_t *)off_123AA8;
  v11 = v2;
  v3 = *((uint64_t *)off_123AA8 + 1);
  v13 = *((uint32_t *)off_123AA8 + 3);
  v12 = v3;
  HIDWORD(v3) = *(uint32_t *)(dword_123AAC + 4);
  v14 = *(uint32_t *)dword_123AAC;
  v15 = WORD2(v3);
  memcpy_large(&v16, &v10, 6);
  memcpy_large(v18, &v12, 6);
  memcpy_large(&v19, &v14, 6);
  v4 = off_123AB0;
  v5 = *((uint16_t *)off_123AB0 + 70);
  *(uint32_t *)(a1 + 10) = v16;
  v6 = v20;
  v7 = v17;
  *(uint8_t *)a1 = 8;
  ++v5;
  v8 = v19;
  *(uint16_t *)(a1 + 14) = v7;
  *(uint16_t *)(a1 + 8) = v6;
  *(uint16_t *)(a1 + 20) = v6;
  *(uint32_t *)(a1 + 4) = v8;
  *(uint32_t *)(a1 + 16) = v8;
  *(uint8_t *)(a1 + 1) = 2;
  *(uint8_t *)(a1 + 2) = 1;
  *(uint8_t *)(a1 + 3) = 0;
  v4[70] = v5;
  *(uint16_t *)(a1 + 22) = 16 * v5;
  return 24;
}

