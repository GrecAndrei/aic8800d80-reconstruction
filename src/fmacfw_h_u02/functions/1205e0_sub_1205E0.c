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

extern uint32_t off_120638;

// get_rf_state @ 0x1205e0, size 88 bytes
uint32_t *get_rf_state()
{
  uint8_t *v0; // r4
  int *v1; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0

  v0 = off_120638;
  if ( !*((uint8_t *)off_120638 + 2) )
    rf_hw_init();
  init_fw_config();
  reset_controller_block();
  v1 = controller_init_pools();
  v2 = init_all_chan_entries(v1);
  v3 = mfp_key_clear(v2);
  rf_patch_init(v3);
  v4 = system_init_seq();
  if ( v0[2] )
    v5 = nullsub_4(v4);
  else
    v5 = dma_poll_status();
  v6 = deinit_global_0x18fb00(v5);
  v7 = reset_global_config(v6);
  v8 = llc_env_init(v7);
  v9 = deinit_bt_global_0x190688(v8);
  init_bt_global_0x190310(v9);
  ke_get_state();
  return rf_phy_init();
}

