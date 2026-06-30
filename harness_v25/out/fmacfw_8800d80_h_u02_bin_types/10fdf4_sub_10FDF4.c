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

extern uint32_t off_10FE24;
extern uint32_t off_10FE28;

// sub_10FDF4 @ 0x10fdf4, size 46 bytes
BOOL  sub_10FDF4(unsigned int a1)
{
  if ( *(uint32_t *)off_10FE24 <= a1 && a1 <= *(uint32_t *)off_10FE24 + *((uint32_t *)off_10FE24 + 1) )
    return 1;
  if ( a1 < *(uint32_t *)off_10FE28 )
    return 0;
  return a1 <= *(uint32_t *)off_10FE28 + *((uint32_t *)off_10FE28 + 1);
}

