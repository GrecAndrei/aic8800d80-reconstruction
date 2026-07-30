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

extern uint32_t off_11F71C;
extern uint32_t off_11F720;

// sub_11F6F0 @ 0x11f6f0, size 44 bytes
void sub_11F6F0()
{
  uint8_t *v0; // r3
  unsigned int v1; // r2

  v0 = *((uint8_t **)off_11F71C + 2);
  if ( !v0[106] && v0[108] && v0[117] )
  {
    v1 = (uint8_t)v0[118];
    if ( v1 <= 8 )
      *(uint32_t *)off_11F720 = ((1 << v1) - 1) << 8;
  }
}

