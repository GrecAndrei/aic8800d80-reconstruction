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

// get_acl_flag @ 0x12abc8, size 22 bytes
int  get_acl_flag(int result)
{
  if ( *(uint8_t *)(result + 1224) )
  {
    if ( *(uint8_t *)(result + 108) )
      *(uint32_t *)(result + 4) |= 0x40u;
  }
  return result;
}

