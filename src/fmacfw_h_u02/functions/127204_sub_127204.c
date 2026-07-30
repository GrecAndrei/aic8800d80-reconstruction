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

extern uint32_t off_127234;
extern uint32_t off_127238;

// sub_127204 @ 0x127204, size 48 bytes
int sub_127204()
{
  void *v0; // r2
  int v1; // r0
  int result; // r0

  v0 = off_127234;
  if ( (*((uint8_t *)off_127234 + 88) & 0x10) == 0 )
  {
    v1 = *((uint8_t *)off_127234 + 90);
    *((uint8_t *)off_127234 + 88) |= 0x10u;
    if ( v1 )
      return sub_124BFC((int)v0 + 48, *((uint32_t *)off_127238 + 4) + 30000);
    else
      return sub_127160();
  }
  return result;
}

