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

extern uint32_t dword_117530;
extern uint32_t dword_117518;
extern uint32_t dword_11751C;
extern uint32_t off_117520;
extern uint32_t off_117524;
extern uint32_t off_117528;
extern uint32_t off_11752C;

// phy_band_validate @ 0x11749c, size 124 bytes
int  phy_band_validate(int a1)
{
  uint32_t *v2; // r5
  int v3; // r3
  int v4; // r4
  uint32_t *v5; // r2
  int *v6; // r5
  int v7; // r1
  int result; // r0
  int *v9; // r3
  int v10; // r3

  if ( a1 == 5 )
    v2 = (uint32_t *)dword_117530;
  else
    v2 = (uint32_t *)(dword_117518 + 84 * a1);
  rf_tx_setup(a1, dword_11751C + 8 * a1, 0);
  rf_tx_setup(a1, v2 + 3, 0);
  *v2 = 0;
  v2[5] = 0;
  init_event_slot(a1);
  v3 = *(uint32_t *)off_117520;
  v4 = 1 << a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_117524 = 1;
  }
  v5 = off_117528;
  v6 = (int *)off_117520;
  v7 = *(uint32_t *)off_117528;
  result = *(uint32_t *)off_117528 + 1;
  *(uint32_t *)off_117528 = result;
  *v6 = v3 & ~v4;
  if ( result )
  {
    v9 = (int *)off_117524;
    *v5 = v7;
    v10 = *v9;
    if ( !v7 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  *(uint32_t *)off_11752C = v4;
  return result;
}

