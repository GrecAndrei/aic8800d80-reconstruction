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

extern uint32_t off_10D3F0;
extern uint32_t off_10D3F8;
extern uint32_t dword_10D400;
extern uint32_t dword_10D3FC;
extern uint32_t off_10D3F4;

// sub_10D3AC @ 0x10d3ac, size 66 bytes
int  sub_10D3AC(int result)
{
  if ( result == 1 )
  {
    *(uint32_t *)off_10D3F0 = 0x40000;
  }
  else if ( result == 2 )
  {
    *(uint32_t *)off_10D3F0 = 0x80000;
  }
  else if ( **(int16_t **)off_10D3F8 < 0 )
  {
    result = sub_12F46C(dword_10D400, dword_10D3FC, 2118);
  }
  *((uint32_t *)off_10D3F4 + 1) |= 0x400000u;
  return result;
}

