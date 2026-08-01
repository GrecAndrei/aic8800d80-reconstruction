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

extern uint32_t off_123BEC;
extern uint32_t off_123BF0;
extern uint32_t off_123BF4;

// irq_disable_save @ 0x123b80, size 106 bytes
int  irq_disable_save(int a1, int a2, int a3, int a4)
{
  int *v4; // r4
  uint32_t *v5; // r5
  int v6; // r6
  uint64_t v7; // r0
  int v8; // r2
  int v9; // r0
  int v10; // r0
  int v11; // r3
  int v12; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_123BEC = 1;
  }
  v4 = (int *)off_123BF0;
  v5 = off_123BF4;
  v6 = *(uint32_t *)off_123BF4;
  ++*(uint32_t *)off_123BF0;
  v7 = mmio_write_poll_clear();
  v9 = sys_irq_dispatch(v7, SHIDWORD(v7), v8);
  v10 = irq_lock_small(v9);
  llm_env_reset(v10);
  controller_init();
  run_deferred_init();
  v11 = *v4;
  *v5 = v6;
  if ( v11 )
  {
    --v11;
    v12 = *(uint32_t *)off_123BEC;
    *v4 = v11;
    if ( !v11 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  hci_evt_alloc_send(1, a4, a3, v11);
  hci_cmd_send(0);
  return 0;
}

