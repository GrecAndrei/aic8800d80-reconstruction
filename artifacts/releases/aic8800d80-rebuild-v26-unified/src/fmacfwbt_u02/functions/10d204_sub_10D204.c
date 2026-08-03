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

extern uint32_t off_10D248;
extern uint32_t off_10D250;
extern uint32_t dword_10D258;
extern uint32_t dword_10D254;
extern uint32_t off_10D24C;

// sub_10D204 @ 0x10d204, size 66 bytes
int  sub_10D204(int result)
{
  if ( result == 1 )
  {
    *(uint32_t *)off_10D248 = 0x40000;
  }
  else if ( result == 2 )
  {
    *(uint32_t *)off_10D248 = 0x80000;
  }
  else if ( **(int16_t **)off_10D250 < 0 )
  {
    result = sub_12F694(dword_10D258, dword_10D254, 2118);
  }
  *((uint32_t *)off_10D24C + 1) |= 0x400000u;
  return result;
}

