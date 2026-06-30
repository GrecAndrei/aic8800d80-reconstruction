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

extern uint32_t dword_128F08;
extern uint32_t dword_128F0C;
extern uint32_t off_128F10;

// sub_128EC4 @ 0x128ec4, size 64 bytes
int  sub_128EC4(int a1, int a2, int a3, int a4)
{
  int result; // r0
  uint16_t *v7; // r2
  char v8; // r3

  feature_guard_sdio(2, dword_128F08);
  result = sub_128D50(a1, a2, dword_128F0C);
  if ( result )
  {
    v7 = (uint16_t *)off_128F10;
    if ( !*((uint8_t *)off_128F10 + 8) || (v8 = *((uint8_t *)off_128F10 + 8) - 1, (*((uint8_t *)off_128F10 + 8) = v8) == 0) )
    {
      *(uint8_t *)v7 = 1;
      return message_dispatch_n84(50, v7[1], 0, a4);
    }
  }
  return result;
}

