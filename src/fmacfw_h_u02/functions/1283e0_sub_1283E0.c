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

extern uint32_t off_128404;

// cfm_call_ops @ 0x1283e0, size 34 bytes
BOOL  cfm_call_ops(int a1)
{
  BOOL result; // r0

  result = cfm_ops_get2(a1);
  if ( result )
    return !*((uint32_t *)off_128404 + 11) || *(uint8_t *)(*((uint32_t *)off_128404 + 10) + 16) == 6;
  return result;
}

