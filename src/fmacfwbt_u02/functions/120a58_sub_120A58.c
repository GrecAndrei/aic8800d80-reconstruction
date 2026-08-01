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

extern uint32_t off_120AB0;

// run_deferred_init @ 0x120a58, size 88 bytes
uint32_t *run_deferred_init()
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

  v0 = off_120AB0;
  if ( !*((uint8_t *)off_120AB0 + 2) )
    mmio_poll_status();
  init_ctx_struct();
  si_attach();
  v1 = wlc_attach();
  inited = tx_slot_state_init(v1);
  v3 = mm_state_idle(inited);
  hw_init(v3);
  v4 = bt_init();
  if ( v0[2] )
    v5 = nullsub_4(v4);
  else
    v5 = is_tx_ready();
  v6 = env_list_init_1903c8(v5);
  v7 = bt_reset_controller(v6);
  v8 = bt_init(v7);
  v9 = rx_env_list_init(v8);
  reset_bt_env(v9);
  check_hw_flag();
  return hal_phy_init();
}

