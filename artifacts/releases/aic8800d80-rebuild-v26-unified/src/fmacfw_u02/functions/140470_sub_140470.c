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

extern uint32_t off_1404A4;
extern uint32_t dword_1404AC;
extern uint32_t dword_1404A8;

// sub_140470 @ 0x140470, size 50 bytes
int sub_140470()
{
  if ( sub_12CE88(0xBu) == 4 )
  {
    sub_1414E0();
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_1404A4 < 0 )
      sub_12F49C(dword_1404AC, dword_1404A8, 129);
    return 0;
  }
}

