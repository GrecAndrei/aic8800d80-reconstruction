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

extern uint32_t dword_123B7C;

// sub_123B54 @ 0x123b54, size 40 bytes
// Doc: sub_1223B54 [unknown]: Unknown helper at 0x1223B54
// sub_1223B54 [unknown]: Unknown helper at 0x1223B54
int  sub_123B54(int a1, int a2, int a3, int a4)
{
  int v5; // r3

  list_init_or_dequeue(a2);
  feature_guard_sdio(256, dword_123B7C);
  message_dispatch_n84(108, a4, a3, v5);
  return 0;
}

