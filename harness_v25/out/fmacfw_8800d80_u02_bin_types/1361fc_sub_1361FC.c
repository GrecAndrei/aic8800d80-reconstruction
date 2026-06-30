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

extern uint32_t off_136230;
extern uint32_t dword_136238;
extern uint32_t dword_136234;

// sub_1361FC @ 0x1361fc, size 52 bytes
int  sub_1361FC(int a1)
{
  int v2; // r0

  if ( **(int16_t **)off_136230 >= 0 || (a1 = sub_12CE88(7u), a1 == 3) )
  {
    sub_136820(a1);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_136238, dword_136234, 415);
    sub_136820(v2);
    return 0;
  }
}

