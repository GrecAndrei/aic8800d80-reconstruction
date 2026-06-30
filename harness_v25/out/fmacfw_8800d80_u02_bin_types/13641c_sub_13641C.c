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

extern uint32_t dword_136470;
extern uint32_t dword_136474;

// sub_13641C @ 0x13641c, size 84 bytes
int  sub_13641C(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int v7; // r4

  feature_guard_check(256, dword_136470);
  v7 = dword_136474 + 1320 * *a2;
  if ( *(uint8_t *)(v7 + 106) == 2 && *(uint8_t *)(v7 + 108) )
  {
    if ( msg_get_value(7u) )
    {
      return 2;
    }
    else
    {
      sub_1369CC(v7);
      return 0;
    }
  }
  else
  {
    sub_12CA10(7171, a4, a3);
    return 0;
  }
}

