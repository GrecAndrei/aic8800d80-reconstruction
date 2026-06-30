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

extern uint32_t off_140500;
extern uint32_t dword_140508;
extern uint32_t dword_140504;

// sub_1404CC @ 0x1404cc, size 50 bytes
int sub_1404CC()
{
  if ( sub_12D0B0(0xBu) == 1 )
  {
    sub_141688();
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_140500 < 0 )
      sub_12F6C4(dword_140508, dword_140504, 157);
    return 0;
  }
}

