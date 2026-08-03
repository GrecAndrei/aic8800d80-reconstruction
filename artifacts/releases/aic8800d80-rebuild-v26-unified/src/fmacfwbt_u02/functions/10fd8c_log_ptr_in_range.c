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

extern uint32_t off_10FDBC;
extern uint32_t off_10FDC0;

// log_ptr_in_range @ 0x10fd8c, size 46 bytes
// Doc: log_ptr_in_range [util]: Validate pointer is within log buffer range
// log_ptr_in_range [util]: Validate pointer is within log buffer range
BOOL  log_ptr_in_range(unsigned int a1)
{
  if ( *(uint32_t *)off_10FDBC <= a1 && a1 <= *(uint32_t *)off_10FDBC + *((uint32_t *)off_10FDBC + 1) )
    return 1;
  if ( a1 < *(uint32_t *)off_10FDC0 )
    return 0;
  return a1 <= *(uint32_t *)off_10FDC0 + *((uint32_t *)off_10FDC0 + 1);
}

