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

extern uint32_t off_1233C0;
extern uint32_t off_1233BC;
extern uint32_t off_1233C4;
extern uint32_t off_1233C8;

// sub_123394 @ 0x123394, size 38 bytes
int  sub_123394(int a1)
{
  uint32_t *v1; // r1
  int v2; // r0
  int result; // r0

  v1 = off_1233C0;
  v2 = *(uint32_t *)(a1 + 4);
  ++*(uint16_t *)off_1233BC;
  result = mmio_write_40320150(v2 + *v1);
  *(uint32_t *)off_1233C4 += *(char *)off_1233C8;
  return result;
}

