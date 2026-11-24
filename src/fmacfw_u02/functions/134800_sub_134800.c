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


extern uint32_t dword_134910;
extern uint32_t off_134900;
extern uint32_t off_134904;
extern uint32_t off_134908;

// bt_send_host_message @ 0x134800, size 256 bytes
int  bt_send_host_message(int a1)
{
  int v1; // lr
  int v3; // r7
  uint8_t *v4; // r6
  int v5; // r0
  unsigned int *v6; // r3
  uint8_t *v7; // r5
  uint8_t *v8; // r0
  uint8_t *v9; // r0
  int v10; // r0
  int v11; // r1
  int v13; // r0

  v3 = v1;
  v4 = (uint8_t *)ke_msg_alloc(5145, 5, 6, 2);
  v5 = ke_msg_alloc(5143, 5, 6, 2);
  v6 = (unsigned int *)off_134900;
  v7 = (uint8_t *)v5;
  if ( (*(uint32_t *)off_134900 & 0x4000000) != 0 )
  {
    *(uint32_t *)off_134900 &= ~0x4000000u;
    *v6 = *v6 & 0xFF3FFFFF | 0x800000;
  }
  *((uint8_t *)off_134908 + 73) = *(uint8_t *)off_134904;
  event_dispatch("delete reources: %x\n", v3);
  check_flag_and_proceed();
  dma_rx_setup(a1);
  rf_scan_chan(*(uint8_t *)(a1 + 116));
  *v4 = 0;
  v4[1] = *(uint8_t *)(a1 + 107);
  cmd_handler_a(dword_134910, (uint32_t *)v4 - 3);
  if ( *(uint8_t *)(a1 + 108) )
  {
    v13 = ke_msg_alloc(30, 0, 6, 4);
    *(uint8_t *)(v13 + 2) = 0;
    *(uint8_t *)(v13 + 3) = *(uint8_t *)(a1 + 107);
    cmd_handler_a(dword_134910, (uint32_t *)(v13 - 12));
  }
  if ( *(uint8_t *)(a1 + 116) != 255 )
  {
    v8 = (uint8_t *)ke_msg_alloc(12, 0, 6, 1);
    *v8 = *(uint8_t *)(a1 + 116);
    cmd_handler_a(dword_134910, (uint32_t *)v8 - 3);
  }
  if ( *(uint32_t *)(a1 + 72) )
  {
    v9 = (uint8_t *)ke_msg_alloc(57, 0, 6, 1);
    *v9 = *(uint8_t *)(a1 + 107);
    cmd_handler_a(dword_134910, (uint32_t *)v9 - 3);
  }
  *v7 = 0;
  v7[1] = *(uint8_t *)(a1 + 107);
  v10 = cmd_handler_a(dword_134910, (uint32_t *)v7 - 3);
  return bt_is_controller_ready(v10, v11);
}
