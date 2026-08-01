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

extern uint32_t off_118670;

// start_firmware @ 0x118624, size 76 bytes
// Doc: start_firmware [rf]: Checks LMAC RF state flags from shared control struct
// start_firmware [rf]: Checks LMAC RF state flags from shared control struct
uint32_t *start_firmware()
{
  uint8_t *v0; // r4
  int inited; // r0
  int updated; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0

  v0 = off_118670;
  if ( !*((uint8_t *)off_118670 + 2) )
    rf_cmd_strobe();
  init_link_manager();
  btcoex_reset_context();
  inited = init_table_185d40();
  init_three_entries(inited);
  ble_ll_init();
  if ( v0[2] )
    updated = timestamp_add();
  else
    updated = call_sub_117410_then_11683c();
  v3 = log_18630c(updated);
  v4 = ke_timer_flush(v3);
  v5 = env_reset(v4);
  log_two_strings(v5);
  rf_init();
  return rf_clock_enable();
}

