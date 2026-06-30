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

extern uint32_t dword_13B6D0;
extern uint32_t dword_13B6CC;
extern uint32_t dword_13B6C8;

// sub_13B69C @ 0x13b69c, size 42 bytes
int  sub_13B69C(int a1, int a2, unsigned int a3)
{
  int v4; // r0

  if ( msg_get_value(a3) == 1 )
  {
    if ( a3 < 0x1000 )
      v4 = dword_13B6D0;
    else
      v4 = dword_13B6CC;
    list_push_tail(v4, (uint32_t *)(dword_13B6C8 + 32 * (a3 >> 8)));
  }
  return 0;
}

