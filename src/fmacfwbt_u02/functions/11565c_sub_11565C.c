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


extern uint32_t off_115744;
extern uint32_t off_115748;
extern uint32_t off_11574C;
extern uint32_t off_115750;
extern uint32_t off_115754;
extern uint32_t off_11575C;
extern uint32_t off_115764;

// rf_mode_switch @ 0x11565c, size 230 bytes
int rf_mode_switch()
{
  int v0; // r4
  uint32_t *v1; // r3
  uint32_t *v2; // r2
  uint32_t *v3; // r3
  uint32_t *v4; // r3
  uint32_t *v6; // r2

  if ( **(uint8_t **)off_115744 == 2 )
  {
    if ( get_global_state() )
      v0 = ((uint32_t *)(uintptr_t)off_115764)[87];
    else
      v0 = 16;
    rf_init_bb();
    *((uint32_t *)off_115750 + 34) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    ke_event_schedule_1(aSftDis);
    v6 = off_11575C;
    *((uint32_t *)off_11575C + 513) |= 2u;
    v6[4] |= 1u;
    while ( (v6[4] & 1) != 0 )
      ;
    ke_event_schedule_1(aSftrstDone);
  }
  else
  {
    v0 = 16;
  }
  v1 = off_115748;
  if ( (*((uint32_t *)off_115748 + 74) & 0x80) != 0 )
  {
    v2 = off_11574C;
    *((uint32_t *)off_115748 + 74) = 128;
    if ( (v2[1] & 0x20000) != 0 )
    {
      v1[65] = 2;
      v2[1] &= ~0x20000u;
      v2[1] |= 0x40000u;
    }
  }
  v3 = off_11574C;
  if ( (*((uint32_t *)off_11574C + 2) & 0x20000) != 0 )
  {
    *((uint32_t *)off_115748 + 65) = 8;
    v3[2] &= ~0x20000u;
    v3[2] |= 0x40000u;
  }
  v4 = off_115750;
  *((uint32_t *)off_115750 + 34) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  v4[34] = 1;
  __dsb(0xFu);
  __isb(0xFu);
  irq_disable();
  if ( *(uint8_t *)(*(uint32_t *)off_115754 + 3) )
    get_core_state();
  __disable_irq();
  return v0;
}
