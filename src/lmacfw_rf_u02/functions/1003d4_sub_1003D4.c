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


extern uint32_t off_100494;
extern uint32_t off_100498;
extern uint32_t off_10049C;
extern uint32_t off_1004A0;
extern uint32_t off_1004A4;
extern uint32_t off_1004A8;
extern uint32_t off_1004AC;
extern uint32_t off_1004B0;
extern uint32_t off_1004B4;
extern uint32_t off_1004B8;
extern uint32_t off_1004BC;
extern uint32_t off_1004C8;

// init_buffer_list @ 0x1003d4, size 190 bytes
void  init_buffer_list()
{
  int *v0; // r4
  uint32_t *v1; // r2
  uint32_t *v2; // r5
  uint32_t *v3; // r1
  uint32_t *v4; // r3
  uint32_t *v5; // r2
  uint32_t *v6; // r6
  uint32_t *v7; // r3
  uint16_t *v8; // r2
  uint8_t *v9; // r6

  v0 = off_100498;
  v1 = off_10049C;
  v2 = off_1004A0;
  *(uint32_t *)off_100494 = off_100498;
  *v1 = v0 + 3;
  v3 = off_1004A4;
  v4 = off_1004A8;
  v5 = off_1004AC;
  v6 = off_1004B0;
  *v2 = v0 + 19;
  *v3 = v0 + 34;
  *v4 = v0 + 38;
  *v6 = (char *)v0 + 178;
  *v5 = v0 + 44;
  process_state_update();
  if ( *(uint8_t *)*v2 == 1 )
  {
    v7 = off_1004B8;
    *((uint32_t *)off_1004B4 + 22) &= ~1u;
    v7[20] |= 1u;
    v7[20] &= ~2u;
  }
  enter_critical_section_2();
  mem_get_stats();
  sys_init();
  v8 = (uint16_t *)*v6;
  v9 = (uint8_t *)off_1004BC;
  *v8 |= 0x2000u;
  dispatch_event_handler_1("asic_ver=0x%x\r\n", *v9);
  radio_timer_snapshot();
  if ( *((uint8_t *)v0 + 363) )
  {
    rf_read_trim();
    rf_enable_2();
  }
  dispatch_event_handler_1("hosttype=%d, asic_ver=0x%x\r\n", *((uint8_t *)v0 + 76), *v9);
  rf_tx_power_get();
  bt_state_dispatch();
  if ( *(uint8_t *)*v2 == 3 )
    *(uint32_t *)off_1004C8 = 1;
  bt_driver_init();
}
