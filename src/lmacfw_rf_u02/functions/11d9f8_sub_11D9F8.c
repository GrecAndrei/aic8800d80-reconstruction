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

extern uint32_t off_11DA38;

// util_byte_to_hex @ 0x11d9f8, size 64 bytes
int  util_byte_to_hex(char a1)
{
  int result; // r0
  unsigned int *v2; // r2
  uint8_t v3[7]; // [sp+7h] [bp-Dh] BYREF
  uint8_t v4; // [sp+Eh] [bp-6h] BYREF
  uint8_t v5[5]; // [sp+Fh] [bp-5h] BYREF

  v3[0] = a1;
  result = rf_get_status((int)v3, &v4, v5);
  v2 = (unsigned int *)off_11DA38;
  *(uint32_t *)off_11DA38 = *(uint32_t *)off_11DA38 & 0xFFFF00FF | (v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | v5[0];
  return result;
}

