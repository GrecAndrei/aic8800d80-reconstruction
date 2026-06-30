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

extern uint32_t dword_128CE4;
extern uint32_t dword_128CE8;
extern uint32_t off_128CEC;

// sub_128CA0 @ 0x128ca0, size 64 bytes
int  sub_128CA0(int a1, int a2)
{
  int result; // r0
  uint16_t *v5; // r2
  char v6; // r3

  feature_guard_check(2, dword_128CE4);
  result = sub_128B2C(a1, a2, dword_128CE8);
  if ( result )
  {
    v5 = (uint16_t *)off_128CEC;
    if ( !*((uint8_t *)off_128CEC + 8) || (v6 = *((uint8_t *)off_128CEC + 8) - 1, (*((uint8_t *)off_128CEC + 8) = v6) == 0) )
    {
      *(uint8_t *)v5 = 1;
      return sub_12CA10(50, v5[1], 0);
    }
  }
  return result;
}

