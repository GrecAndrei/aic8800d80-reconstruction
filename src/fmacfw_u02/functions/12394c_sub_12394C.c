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

extern uint32_t off_1239B8;
extern uint32_t off_1239BC;
extern uint32_t off_1239C0;

// unknown_handler @ 0x12394c, size 106 bytes
int  unknown_handler(int a1, int a2, int a3, int a4)
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
    *(uint32_t *)off_1239B8 = 1;
  }
  v4 = (int *)off_1239BC;
  v5 = off_1239C0;
  v6 = *(uint32_t *)off_1239C0;
  ++*(uint32_t *)off_1239BC;
  v7 = mmio_write_one();
  v9 = rf_get_status(v7, SHIDWORD(v7), v8);
  v10 = ke_int_lock_save(v9);
  ke_task_reset(v10);
  mem_pool_init();
  get_bt_state();
  v11 = *v4;
  *v5 = v6;
  if ( v11 )
  {
    v12 = v11 - 1;
    v13 = *(uint32_t *)off_1239B8;
    *v4 = v12;
    if ( !v12 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  ke_msg_send_no_param(1, a4, a3);
  rx_phy_status_parse(0);
  return 0;
}

