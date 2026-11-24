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


extern uint32_t off_114C44;
extern uint32_t off_114C48;
extern uint32_t off_114C4C;
extern uint32_t off_114C50;
extern uint32_t off_114C54;
extern uint32_t off_114C5C;
extern uint32_t off_114C64;

// wait_hw_ready @ 0x114b5c, size 230 bytes
int wait_hw_ready()
{
  int v0; // r4
  uint32_t *v1; // r3
  uint32_t *v2; // r2
  uint32_t *v3; // r3
  int v4; // r3
  int v6; // r2

  if ( **(uint8_t **)off_114C44 == 2 )
  {
    if ( util_read_status() )
      v0 = off_114C64[87];
    else
      v0 = 16;
    rf_init_1();
    *(uint32_t *)(off_114C50 + 136) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    dispatch_event_handler_1(aSftDis);
    v6 = off_114C5C;
    *(uint32_t *)(off_114C5C + 0x804) |= 2u;
    *(uint32_t *)(v6 + 0x10) |= 1u;
    while ( (*(uint32_t *)(v6 + 0x10) & 1) != 0 )
      ;
    dispatch_event_handler_1(aSftrstDone);
  }
  else
  {
    v0 = 16;
  }
  v1 = off_114C48;
  if ( (*((uint32_t *)off_114C48 + 74) & 0x80) != 0 )
  {
    v2 = off_114C4C;
    *((uint32_t *)off_114C48 + 74) = 128;
    if ( (v2[1] & 0x20000) != 0 )
    {
      v1[65] = 2;
      v2[1] &= ~0x20000u;
      v2[1] |= 0x40000u;
    }
  }
  v3 = off_114C4C;
  if ( (*((uint32_t *)off_114C4C + 2) & 0x20000) != 0 )
  {
    *((uint32_t *)off_114C48 + 65) = 8;
    v3[2] &= ~0x20000u;
    v3[2] |= 0x40000u;
  }
  v4 = off_114C50;
  *(uint32_t *)(off_114C50 + 136) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  *(uint32_t *)(v4 + 136) = 1;
  __dsb(0xFu);
  __isb(0xFu);
  trace_sync();
  if ( *(uint8_t *)(*(uint32_t *)off_114C54 + 3) )
    check_rx_active();
  __disable_irq();
  return v0;
}
