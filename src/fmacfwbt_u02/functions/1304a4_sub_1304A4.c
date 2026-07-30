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

extern uint32_t off_1304D8;
extern uint32_t off_1304DC;

// sub_1304A4 @ 0x1304a4, size 50 bytes
void sub_1304A4()
{
  uint32_t *v0; // r4
  unsigned int u8; // r0

  v0 = off_1304D8;
  while ( (*v0 & 1) == 0 )
  {
    if ( (*v0 & 0xF) == 4 )
    {
      u8 = mmio_read_u8();
      if ( sub_130234(u8) > 0 )
      {
        if ( *(uint8_t *)off_1304DC )
          sub_13038C();
        return;
      }
    }
  }
}

