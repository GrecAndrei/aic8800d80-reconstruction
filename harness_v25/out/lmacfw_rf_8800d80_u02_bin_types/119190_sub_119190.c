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

extern uint32_t dword_1191B4;

// sub_119190 @ 0x119190, size 36 bytes
int  sub_119190(int result, int a2, int a3)
{
  int v3; // r4

  v3 = result;
  if ( (a2 & 0x800000) != 0 )
  {
    *(uint8_t *)(result + 116) = 0;
  }
  else
  {
    sub_11F74C(1024, dword_1191B4, a3, a2 << 8);
    return sub_119170(v3);
  }
  return result;
}

