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

extern uint32_t off_1202D4;

// check_hw_counters @ 0x1202b4, size 30 bytes
int check_hw_counters()
{
  int result; // r0

  if ( *((uint8_t *)off_1202D4 + 18) + *((uint8_t *)off_1202D4 + 17) != 1 )
    return 0;
  result = *((uint32_t *)off_1202D4 + 2);
  if ( *(uint8_t *)(result + 106) )
    return 0;
  return result;
}

