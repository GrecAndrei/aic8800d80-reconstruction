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

extern uint32_t off_140540;
extern uint32_t dword_140548;
extern uint32_t dword_140544;

// sub_14050C @ 0x14050c, size 50 bytes
int sub_14050C()
{
  if ( sub_12D0B0(0xBu) == 4 )
  {
    sub_14157C();
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_140540 < 0 )
      sub_12F6C4(dword_140548, dword_140544, 129);
    return 0;
  }
}

