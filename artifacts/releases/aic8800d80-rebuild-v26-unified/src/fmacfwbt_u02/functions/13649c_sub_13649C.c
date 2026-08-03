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

extern uint32_t off_1364F8;
extern uint32_t dword_136500;
extern uint32_t dword_1364FC;

// sub_13649C @ 0x13649c, size 90 bytes
int sub_13649C()
{
  int v0; // r0

  if ( **(int16_t **)off_1364F8 < 0 && sub_12D0B0(7u) != 1 && sub_12D0B0(7u) && sub_12D0B0(7u) != 3 )
    sub_12F694(dword_136500, dword_1364FC, 274);
  v0 = sub_12D0B0(7u);
  if ( v0 != 1 )
  {
    v0 = sub_12D0B0(7u);
    if ( v0 != 3 )
      return 0;
  }
  sub_13697C(v0);
  return 0;
}

