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

extern uint32_t off_12338C;
extern uint32_t off_123390;

// sub_123358 @ 0x123358, size 50 bytes
void sub_123358()
{
  uint32_t *v0; // r4
  unsigned int v1; // r0

  v0 = off_12338C;
  while ( (*v0 & 1) == 0 )
  {
    if ( (*v0 & 0xF) == 4 )
    {
      v1 = sub_10D680();
      if ( rf_init_or_reset(v1) > 0 )
      {
        if ( *(uint8_t *)off_123390 )
          sub_123240();
        return;
      }
    }
  }
}

