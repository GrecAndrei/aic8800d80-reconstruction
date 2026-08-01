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

extern uint32_t off_123878;
extern uint32_t off_12387C;
extern uint32_t off_123880;

// parse_parameter @ 0x12380c, size 106 bytes
int  parse_parameter(int a1, int a2, int a3, int a4)
{
  int *v4; // r4
  uint32_t *v5; // r5
  int v6; // r6
  uint64_t v7; // r0
  int v8; // r2
  int v9; // r0
  int v10; // r0
  int v11; // r3
  int v12; // r3
  int v13; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_123878 = 1;
  }
  v4 = (int *)off_12387C;
  v5 = off_123880;
  v6 = *(uint32_t *)off_123880;
  ++*(uint32_t *)off_12387C;
  v7 = rf_set_power_on();
  v9 = check_clock_status(v7, SHIDWORD(v7), v8);
  v10 = unknown_handler_12c798(v9);
  vendor_platform_init(v10);
  alloc_shared_ctx();
  get_rf_state();
  v11 = *v4;
  *v5 = v6;
  if ( v11 )
  {
    v12 = v11 - 1;
    v13 = *(uint32_t *)off_123878;
    *v4 = v12;
    if ( !v12 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  mac_write_header_word(1, a4, a3);
  hci_cmd_preprocess(0);
  return 0;
}

