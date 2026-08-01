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

extern uint32_t off_120778;

// get_bt_state @ 0x120720, size 88 bytes
// Doc: get_bt_state [mac]: Initialize MAC/PHY from config table at 0x182b64
// get_bt_state [mac]: Initialize MAC/PHY from config table at 0x182b64
uint32_t *get_bt_state()
{
  uint8_t *v0; // r4
  int *v1; // r0
  int inited; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0

  v0 = off_120778;
  if ( !*((uint8_t *)off_120778 + 2) )
    bb_enable();
  clear_transmit_context();
  ble_sched_init();
  v1 = ble_event_set();
  inited = tx_queue_flush(v1);
  v3 = wlc_mfp_key_clear(inited);
  llc_reset(v3);
  v4 = chip_init_sequence();
  if ( v0[2] )
    v5 = nullsub_4(v4);
  else
    v5 = rf_poll();
  v6 = get_soc_handle(v5);
  v7 = rf_env_reset(v6);
  v8 = stat_clear(v7);
  v9 = lock_core_pair(v8);
  init_timer(v9);
  bt_get_state();
  return poll_rf_interrupts();
}

