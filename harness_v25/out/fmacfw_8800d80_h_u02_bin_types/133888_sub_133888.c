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

extern uint32_t off_1338BC;
extern uint32_t dword_1338C4;
extern uint32_t dword_1338C0;

// sub_133888 @ 0x133888, size 52 bytes
int  sub_133888(int a1)
{
  int v2; // r0

  if ( **(int16_t **)off_1338BC >= 0 || (a1 = sub_12CD48(6u), a1 == 4) )
  {
    sub_13467C(a1);
    return 0;
  }
  else
  {
    v2 = sub_12F32C(dword_1338C4, dword_1338C0, 670);
    sub_13467C(v2);
    return 0;
  }
}

