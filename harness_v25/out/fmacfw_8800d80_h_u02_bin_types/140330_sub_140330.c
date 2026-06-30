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

extern uint32_t off_140364;
extern uint32_t dword_14036C;
extern uint32_t dword_140368;

// sub_140330 @ 0x140330, size 50 bytes
int sub_140330()
{
  if ( sub_12CD48(0xBu) == 4 )
  {
    sub_1413A0();
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_140364 < 0 )
      sub_12F35C(dword_14036C, dword_140368, 129);
    return 0;
  }
}

