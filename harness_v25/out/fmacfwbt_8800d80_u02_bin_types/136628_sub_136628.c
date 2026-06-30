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

extern uint32_t dword_13667C;
extern uint32_t dword_136680;

// sub_136628 @ 0x136628, size 84 bytes
int  sub_136628(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int v7; // r4

  feature_guard_sdio(256, dword_13667C);
  v7 = dword_136680 + 1320 * *a2;
  if ( *(uint8_t *)(v7 + 106) == 2 && *(uint8_t *)(v7 + 108) )
  {
    if ( msg_get_value(7u) )
    {
      return 2;
    }
    else
    {
      patch_apply_n_2ac(v7);
      return 0;
    }
  }
  else
  {
    message_dispatch_n84(7171, a4, a3);
    return 0;
  }
}

