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


extern uint32_t off_129520;
extern uint32_t off_12952C;
extern uint32_t off_129530;
extern uint32_t off_129534;
extern uint32_t off_129538;
extern uint32_t off_12953C;
extern uint32_t off_129540;

// wlc_mmio_clock_enable @ 0x1294c8, size 86 bytes
int wlc_mmio_clock_enable()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r1
  uint32_t *v2; // r5
  uint32_t *v3; // r2

  *(uint32_t *)off_129520 |= 0x2000000u;
  check_status_bits(2, "%s\r\n", aPsUpmExit);
  if ( !*((uint8_t *)off_12952C + 18) )
    *(uint32_t *)off_129530 &= ~1u;
  v0 = off_129538;
  v1 = off_129530;
  v2 = off_12953C;
  v3 = off_129540;
  *(uint32_t *)off_129534 &= ~0x10000u;
  *v0 &= ~0x40000000u;
  *v1 &= ~0x10000000u;
  *v2 = 0;
  *v3 &= ~1u;
  return 0;
}
