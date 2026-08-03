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

extern uint32_t off_13387C;
extern uint32_t dword_133884;
extern uint32_t dword_133880;

// sub_133820 @ 0x133820, size 90 bytes
int sub_133820()
{
  int v0; // r0

  if ( **(int16_t **)off_13387C < 0 && sub_12CD48(6u) != 4 && sub_12CD48(6u) && sub_12CD48(6u) != 10 )
    sub_12F32C(dword_133884, dword_133880, 636);
  v0 = sub_12CD48(6u);
  if ( v0 != 4 )
  {
    v0 = sub_12CD48(6u);
    if ( v0 != 10 )
      return 0;
  }
  sub_13467C(v0);
  return 0;
}

