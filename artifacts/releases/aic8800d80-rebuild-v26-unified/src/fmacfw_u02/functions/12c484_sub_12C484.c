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

extern uint32_t off_12C4C4;

// sub_12C484 @ 0x12c484, size 64 bytes
int  sub_12C484(char a1)
{
  int result; // r0
  unsigned int *v2; // r2
  uint8_t v3[7]; // [sp+7h] [bp-Dh] BYREF
  uint8_t v4; // [sp+Eh] [bp-6h] BYREF
  uint8_t v5[5]; // [sp+Fh] [bp-5h] BYREF

  v3[0] = a1;
  result = sub_101B00((int)v3, &v4, v5);
  v2 = (unsigned int *)off_12C4C4;
  *(uint32_t *)off_12C4C4 = *(uint32_t *)off_12C4C4 & 0xFFFF00FF | (v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | v5[0];
  return result;
}

