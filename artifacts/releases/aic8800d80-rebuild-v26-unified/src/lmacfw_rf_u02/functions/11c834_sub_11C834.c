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

extern uint32_t dword_11C84C;

// sub_11C834 @ 0x11c834, size 24 bytes
int  sub_11C834(int a1, int a2, int a3)
{
  int result; // r0

  result = dword_11C84C + 32 * a1;
  if ( a3 )
    ++*(uint32_t *)(result + 20);
  else
    ++*(uint32_t *)(result + 16);
  return result;
}

