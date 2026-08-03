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

extern uint32_t dword_11C3E4;

// sub_11C3B8 @ 0x11c3b8, size 44 bytes
int  sub_11C3B8(int result, int a2)
{
  int v2; // r2
  int v3; // r3

  v2 = dword_11C3E4;
  v3 = dword_11C3E4 + 28 * a2;
  if ( *(uint32_t *)(v3 + 24) )
  {
    if ( *(uint8_t *)(v3 + 46) )
      *(uint32_t *)(v3 + 36) = result;
    *(uint8_t *)(v2 + 28 * a2 + 45) = 1;
  }
  return result;
}

