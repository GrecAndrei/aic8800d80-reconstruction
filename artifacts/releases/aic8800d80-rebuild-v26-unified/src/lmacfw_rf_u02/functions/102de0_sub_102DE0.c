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

extern uint32_t off_102DFC;
extern uint32_t off_102E00;

// sub_102DE0 @ 0x102de0, size 26 bytes
BOOL sub_102DE0()
{
  BOOL result; // r0

  result = (*(uint32_t *)off_102DFC >> 27) & 1;
  if ( (*(uint32_t *)off_102DFC & 0x8000000) != 0 )
    return (*(uint32_t *)off_102E00 & 0x400) == 0;
  return result;
}

