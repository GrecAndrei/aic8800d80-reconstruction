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

extern uint32_t off_134B1C;
extern uint32_t dword_134B28;
extern uint32_t off_134B24;
extern uint32_t off_134B20;
extern uint32_t dword_134B2C;

// write_hw_mmio_word @ 0x134a1c, size 256 bytes
int  write_hw_mmio_word(int a1)
{
  int v1; // lr
  int v3; // r7
  uint8_t *v4; // r6
  int v5; // r0
  unsigned int *v6; // r3
  uint8_t *v7; // r5
  int v8; // r0
  uint8_t *v9; // r0
  uint8_t *v10; // r0
  int v12; // r0

  v3 = v1;
  v4 = (uint8_t *)bt_buf_alloc(5145, 5, 6, 2u);
  v5 = bt_buf_alloc(5143, 5, 6, 2u);
  v6 = (unsigned int *)off_134B1C;
  v7 = (uint8_t *)v5;
  if ( (*(uint32_t *)off_134B1C & 0x4000000) != 0 )
  {
    *(uint32_t *)off_134B1C &= ~0x4000000u;
    *v6 = *v6 & 0xFF3FFFFF | 0x800000;
  }
  v8 = dword_134B28;
  *((uint8_t *)off_134B24 + 73) = *(uint8_t *)off_134B20;
  ke_event_schedule(v8, v3);
  llm_reset_cleanup();
  conn_prepare(a1);
  rf_calibrate(*(uint8_t *)(a1 + 116));
  *v4 = 0;
  v4[1] = *(uint8_t *)(a1 + 107);
  check_abort_flag(dword_134B2C, (uint32_t *)v4 - 3);
  if ( *(uint8_t *)(a1 + 108) )
  {
    v12 = bt_buf_alloc(30, 0, 6, 4u);
    *(uint8_t *)(v12 + 2) = 0;
    *(uint8_t *)(v12 + 3) = *(uint8_t *)(a1 + 107);
    check_abort_flag(dword_134B2C, (uint32_t *)(v12 - 12));
  }
  if ( *(uint8_t *)(a1 + 116) != 255 )
  {
    v9 = (uint8_t *)bt_buf_alloc(12, 0, 6, 1u);
    *v9 = *(uint8_t *)(a1 + 116);
    check_abort_flag(dword_134B2C, (uint32_t *)v9 - 3);
  }
  if ( *(uint32_t *)(a1 + 72) )
  {
    v10 = (uint8_t *)bt_buf_alloc(57, 0, 6, 1u);
    *v10 = *(uint8_t *)(a1 + 107);
    check_abort_flag(dword_134B2C, (uint32_t *)v10 - 3);
  }
  *v7 = 0;
  v7[1] = *(uint8_t *)(a1 + 107);
  check_abort_flag(dword_134B2C, (uint32_t *)v7 - 3);
  return check_hw_ready_status();
}

