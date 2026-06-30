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

extern uint32_t off_1080CC;
extern uint32_t off_1080C8;
extern uint32_t dword_1080D0;
extern uint32_t off_1080D4;

// sub_108090 @ 0x108090, size 56 bytes
// Doc: sub_1208090 [unknown]: Unknown utility function at 0x108090
// sub_1208090 [unknown]: Unknown utility function at 0x108090
int sub_108090()
{
  unsigned int *v0; // r5
  int v1; // r6
  int16_t v2; // r4
  int result; // r0
  uint32_t *v4; // r1

  v0 = (unsigned int *)off_1080CC;
  v1 = *(uint32_t *)off_1080CC;
  v2 = (uint16_t)*(uint32_t *)off_1080C8 >> 4;
  result = feature_guard_sdio(1, dword_1080D0);
  v4 = off_1080D4;
  *v0 = (v2 + (uint16_t)v1) & 0xFFF | *v0 & 0xFFFFF000;
  *v4 |= 0x400000u;
  return result;
}

