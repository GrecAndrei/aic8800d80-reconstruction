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

extern uint32_t off_10CC3C;
extern uint32_t off_10CC40;
extern uint32_t off_10CC44;
extern uint32_t dword_10CC4C;
extern uint32_t dword_10CC48;

// fmac_tx_dispatch @ 0x10cbe4, size 86 bytes
// Doc: fmac_tx_dispatch [tx]: FMAC transmit path dispatcher
// fmac_tx_dispatch [tx]: FMAC transmit path dispatcher
int fmac_tx_dispatch()
{
  uint32_t *v0; // r4
  int v1; // r0
  int v2; // r3
  int v4; // r3

  v0 = off_10CC3C;
  while ( !*(uint32_t *)off_10CC3C )
    ;
  if ( *(uint32_t *)(*(uint32_t *)off_10CC40 + 612) )
  {
    v1 = rf_bus_mark_n100_d2d0(*(uint32_t *)off_10CC40 + 612);
    v2 = **(int16_t **)off_10CC44;
    *v0 = 1;
    if ( v2 >= 0 || v1 )
      return v1 + 20;
  }
  else
  {
    v4 = **(int16_t **)off_10CC44;
    *(uint32_t *)off_10CC3C = 1;
    if ( v4 >= 0 )
      return 20;
  }
  sub_12F46C(dword_10CC4C, dword_10CC48, 1101);
  return 20;
}

