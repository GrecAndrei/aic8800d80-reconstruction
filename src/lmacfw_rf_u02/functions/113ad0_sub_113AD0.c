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

extern uint32_t off_113B28;
extern uint32_t off_113B2C;

// mmio_write32 @ 0x113ad0, size 88 bytes
int  mmio_write32(unsigned int a1, int a2)
{
  uint32_t *v4; // r3

  get_bandgap_trim(1);
  while ( !*(uint32_t *)off_113B28 )
    ;
  if ( a1 <= 0x1F )
  {
    v4 = off_113B2C;
    *((uint32_t *)off_113B2C + 16) = 1;
    v4[19] = 34816;
    v4[21] = 629;
    __dsb(0xFu);
    v4[a1 + 512] = a2;
    v4[16] = 0;
    v4[19] = 0;
    v4[21] &= ~4u;
  }
  *(uint32_t *)off_113B28 = 1;
  return get_bandgap_trim(0);
}

