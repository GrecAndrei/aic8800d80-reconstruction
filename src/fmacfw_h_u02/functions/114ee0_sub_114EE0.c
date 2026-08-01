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

extern uint32_t off_114FC8;
extern uint32_t off_114FE8;
extern uint32_t off_114FD4;
extern uint32_t dword_114FDC;
extern uint32_t off_114FE0;
extern uint32_t dword_114FE4;
extern uint32_t off_114FCC;
extern uint32_t off_114FD0;
extern uint32_t off_114FD8;

// get_phy_state @ 0x114ee0, size 230 bytes
int get_phy_state()
{
  int v0; // r4
  uint32_t *v1; // r3
  uint32_t *v2; // r2
  uint32_t *v3; // r3
  uint32_t *v4; // r3
  int v6; // r1
  int v7; // r1
  uint32_t *v8; // r2

  if ( **(uint8_t **)off_114FC8 == 2 )
  {
    if ( phy_get_status() )
      v0 = *((uint32_t *)off_114FE8 + 87);
    else
      v0 = 16;
    phy_is_calibrated();
    *((uint32_t *)off_114FD4 + 34) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    alloc_tx_event(dword_114FDC, v6, 1);
    v8 = off_114FE0;
    *((uint32_t *)off_114FE0 + 513) |= 2u;
    v8[4] |= 1u;
    while ( (v8[4] & 1) != 0 )
      ;
    alloc_tx_event(dword_114FE4, v7, v8);
  }
  else
  {
    v0 = 16;
  }
  v1 = off_114FCC;
  if ( (*((uint32_t *)off_114FCC + 74) & 0x80) != 0 )
  {
    v2 = off_114FD0;
    *((uint32_t *)off_114FCC + 74) = 128;
    if ( (v2[1] & 0x20000) != 0 )
    {
      v1[65] = 2;
      v2[1] &= ~0x20000u;
      v2[1] |= 0x40000u;
    }
  }
  v3 = off_114FD0;
  if ( (*((uint32_t *)off_114FD0 + 2) & 0x20000) != 0 )
  {
    *((uint32_t *)off_114FCC + 65) = 8;
    v3[2] &= ~0x20000u;
    v3[2] |= 0x40000u;
  }
  v4 = off_114FD4;
  *((uint32_t *)off_114FD4 + 34) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  v4[34] = 1;
  __dsb(0xFu);
  __isb(0xFu);
  nvic_disable_irq15();
  if ( *(uint8_t *)(*(uint32_t *)off_114FD8 + 3) )
    check_initialized();
  __disable_irq();
  return v0;
}

