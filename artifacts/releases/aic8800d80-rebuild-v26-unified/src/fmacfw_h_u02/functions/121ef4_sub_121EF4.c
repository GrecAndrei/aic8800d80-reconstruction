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

extern uint32_t dword_121F18;

// sub_121EF4 @ 0x121ef4, size 36 bytes
int  sub_121EF4(int result, int a2)
{
  int v2; // r4

  v2 = result;
  if ( (a2 & 0x800000) != 0 )
  {
    *(uint8_t *)(result + 128) = 0;
  }
  else
  {
    sub_12EB90(1024, dword_121F18);
    return sub_121ED4(v2);
  }
  return result;
}

