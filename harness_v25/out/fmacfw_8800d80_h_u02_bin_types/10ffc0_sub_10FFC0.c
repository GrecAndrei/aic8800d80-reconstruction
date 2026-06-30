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

extern uint32_t off_11003C;
extern uint32_t off_110044;
extern uint32_t off_110040;
extern uint32_t dword_110048;

// sub_10FFC0 @ 0x10ffc0, size 122 bytes
int sub_10FFC0()
{
  void *v0; // r4
  int v1; // r3
  uint32_t *v2; // r0
  int16_t v3; // r2
  int16_t v4; // r1
  uint64_t v5; // kr00_8
  uint16_t v7[2]; // [sp+4h] [bp-14h] BYREF
  uint16_t v8[8]; // [sp+8h] [bp-10h] BYREF

  v0 = off_11003C;
  v1 = *(uint32_t *)off_11003C;
  v2 = off_110044;
  v3 = *((uint16_t *)off_110040 + 153);
  v4 = *((uint16_t *)off_110040 + 154) - 4;
  v7[1] = *(uint16_t *)(*(uint32_t *)off_11003C + 2);
  v8[1] = *(uint16_t *)(v1 + 4);
  v8[5] = *(uint16_t *)(v1 + 6);
  v8[7] = *(uint16_t *)(v1 + 8);
  v5 = *(uint64_t *)(v1 + 20);
  *(uint32_t *)off_110044 = v5;
  v2[3] = dword_110048;
  v2[1] = HIDWORD(v5);
  *((uint8_t *)v2 + 8) = 1;
  v8[2] = v4;
  v8[6] = v3 - 4;
  v7[0] = 12;
  v8[4] = 1596;
  v8[0] = 124;
  v8[3] = 0;
  sub_10F7E4(v2, (int)v7, 0x20u);
  return sub_10FE2C((int)v8, *(uint32_t *)(*(uint32_t *)v0 + 28), *(uint32_t *)(*(uint32_t *)v0 + 32));
}

