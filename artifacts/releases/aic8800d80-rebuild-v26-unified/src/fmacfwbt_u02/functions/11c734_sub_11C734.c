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

extern uint32_t off_11C74C;

// sub_11C734 @ 0x11c734, size 24 bytes
void  sub_11C734(int a1)
{
  uint8_t *v1; // r4

  v1 = off_11C74C;
  *(uint8_t *)off_11C74C = 1;
  sub_11F03C(a1);
  *v1 = 0;
  sub_11BE18();
}

