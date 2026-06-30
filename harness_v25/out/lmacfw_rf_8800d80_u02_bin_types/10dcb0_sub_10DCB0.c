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

extern uint32_t dword_10DCE0;
extern uint32_t off_10DCE4;

// sub_10DCB0 @ 0x10dcb0, size 48 bytes
int sub_10DCB0()
{
  int result; // r0
  uint32_t *v1; // r3

  result = sub_10EFB4(dword_10DCE0, 0x2000, 15360);
  v1 = off_10DCE4;
  *((uint32_t *)off_10DCE4 + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}

