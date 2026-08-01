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

extern uint32_t dword_129528;
extern uint32_t off_129520;
extern uint32_t off_12952C;
extern uint32_t off_129530;
extern uint32_t off_129538;
extern uint32_t off_12953C;
extern uint32_t off_129540;
extern uint32_t off_129534;

// wlc_mmio_clock_enable @ 0x1294c8, size 86 bytes
int wlc_mmio_clock_enable()
{
  int v0; // r1
  uint32_t *v1; // r0
  uint32_t *v2; // r1
  uint32_t *v3; // r5
  uint32_t *v4; // r2

  v0 = dword_129528;
  *(uint32_t *)off_129520 |= 0x2000000u;
  check_status_bits(2, v0);
  if ( !*((uint8_t *)off_12952C + 18) )
    *(uint32_t *)off_129530 &= ~1u;
  v1 = off_129538;
  v2 = off_129530;
  v3 = off_12953C;
  v4 = off_129540;
  *(uint32_t *)off_129534 &= ~0x10000u;
  *v1 &= ~0x40000000u;
  *v2 &= ~0x10000000u;
  *v3 = 0;
  *v4 &= ~1u;
  return 0;
}

