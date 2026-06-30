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

extern uint32_t off_10FE54;
extern uint32_t off_10FE58;

// sub_10FE24 @ 0x10fe24, size 46 bytes
BOOL  sub_10FE24(unsigned int a1)
{
  if ( *(uint32_t *)off_10FE54 <= a1 && a1 <= *(uint32_t *)off_10FE54 + *((uint32_t *)off_10FE54 + 1) )
    return 1;
  if ( a1 < *(uint32_t *)off_10FE58 )
    return 0;
  return a1 <= *(uint32_t *)off_10FE58 + *((uint32_t *)off_10FE58 + 1);
}

