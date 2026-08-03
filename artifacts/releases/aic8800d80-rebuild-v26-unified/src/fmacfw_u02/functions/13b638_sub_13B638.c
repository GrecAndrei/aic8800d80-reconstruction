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

extern uint32_t dword_13B670;
extern uint32_t dword_13B66C;

// sub_13B638 @ 0x13b638, size 50 bytes
// Doc: sub_123B638 [unknown]: Unknown utility/helper function at 0x13b638
// sub_123B638 [unknown]: Unknown utility/helper function at 0x13b638
int  sub_13B638(int a1, int a2, unsigned int a3)
{
  if ( msg_get_value(a3) == 2 )
  {
    sub_13BA24(a3 >> 8);
    list_push_tail(dword_13B670, (uint32_t *)(dword_13B66C + 32 * (a3 >> 8)));
    sub_12CD34(a3, 0);
  }
  return 0;
}

