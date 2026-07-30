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

extern uint32_t dword_122D78;

// sub_122D5C @ 0x122d5c, size 28 bytes
// Doc: sub_1222D5C [ipc]: Copy/forward message payload via memory helper
// sub_1222D5C [ipc]: Copy/forward message payload via memory helper
int  sub_122D5C(int a1, int a2, int a3, int a4)
{
  int v6; // r3

  sub_14380C(dword_122D78, a2, 69);
  message_dispatch_n84(120, a4, a3, v6);
  return 0;
}

