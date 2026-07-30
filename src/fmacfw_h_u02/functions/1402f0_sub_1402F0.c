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

extern uint32_t off_140324;
extern uint32_t dword_14032C;
extern uint32_t dword_140328;

// sub_1402F0 @ 0x1402f0, size 50 bytes
int sub_1402F0()
{
  if ( sub_12CD48(0xBu) == 1 )
  {
    sub_1414AC();
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_140324 < 0 )
      sub_12F35C(dword_14032C, dword_140328, 157);
    return 0;
  }
}

