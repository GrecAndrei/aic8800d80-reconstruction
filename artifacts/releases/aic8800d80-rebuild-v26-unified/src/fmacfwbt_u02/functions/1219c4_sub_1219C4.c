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

extern uint32_t off_1219E4;

// sub_1219C4 @ 0x1219c4, size 32 bytes
int sub_1219C4()
{
  sub_12D374(0x2000000);
  *((uint32_t *)off_1219E4 + 1) &= ~4u;
  return rf_bus_mark_n_3b7(0);
}

