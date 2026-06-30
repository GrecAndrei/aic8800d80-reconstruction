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

extern uint32_t off_133814;
extern uint32_t dword_13381C;
extern uint32_t dword_133818;

// sub_1337E0 @ 0x1337e0, size 52 bytes
int  sub_1337E0(int a1)
{
  int v2; // r0

  if ( **(int16_t **)off_133814 >= 0 || (a1 = sub_12CD48(6u), a1 == 10) )
  {
    sub_13467C(a1);
    return 0;
  }
  else
  {
    v2 = sub_12F32C(dword_13381C, dword_133818, 871);
    sub_13467C(v2);
    return 0;
  }
}

