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


extern uint32_t dword_136AF0;
extern uint32_t dword_136AF4;
extern uint32_t off_136AF8;
extern uint32_t off_136AFC;
extern uint32_t off_136B00;

// rf_send_command_0x1419 @ 0x1369cc, size 290 bytes
int  rf_send_command_0x1419(int a1)
{
  uint8_t *v2; // r6
  int v3; // r0
  uint8_t *v4; // r5
  int *v5; // r3
  unsigned int v6; // r2
  uint8_t *v7; // r0
  int v8; // r0
  int v9; // r1
  uint8_t *v10; // r3
  uint32_t *v11; // r0
  int v13; // r0

  v2 = (uint8_t *)ke_msg_alloc(5145, 5, 7, 2);
  v3 = ke_msg_alloc(5143, 5, 7, 2);
  *(uint8_t *)(dword_136AF0 + 696 * (*(uint8_t *)(a1 + 107) + 32) + 37) = 0;
  v4 = (uint8_t *)v3;
  bt_get_buffer();
  *v2 = 0;
  v2[1] = *(uint8_t *)(a1 + 107);
  cmd_handler_a(dword_136AF4, (uint32_t *)v2 - 3);
  v5 = *((int **)off_136AF8 + 2);
  if ( v5 )
  {
    while ( 1 )
    {
      if ( (int *)a1 != v5 )
      {
        if ( *((uint8_t *)v5 + 108) )
        {
          v6 = *((uint16_t *)v5 + 208);
          if ( v6 <= 0x1387 )
            break;
        }
      }
      v5 = (int *)*v5;
      if ( !v5 )
        goto LABEL_6;
    }
    callback_post(v6 | (*((uint8_t *)v5 + 413) << 16) | 0x80000000);
  }
  else
  {
LABEL_6:
    callback_post(0);
  }
  is_valid_id((int *)a1, 0, 0);
  if ( *(uint8_t *)(a1 + 108) )
  {
    v13 = ke_msg_alloc(30, 0, 7, 4);
    *(uint8_t *)(v13 + 2) = 0;
    *(uint8_t *)(v13 + 3) = *(uint8_t *)(a1 + 107);
    cmd_handler_a(dword_136AF4, (uint32_t *)(v13 - 12));
  }
  if ( *(uint32_t *)(a1 + 72) )
  {
    v7 = (uint8_t *)ke_msg_alloc(57, 0, 7, 1);
    *v7 = *(uint8_t *)(a1 + 107);
    cmd_handler_a(dword_136AF4, (uint32_t *)v7 - 3);
  }
  *v4 = 0;
  v4[1] = *(uint8_t *)(a1 + 107);
  v8 = cmd_handler_a(dword_136AF4, (uint32_t *)v4 - 3);
  bt_ready_check(v8, v9);
  if ( !*(uint8_t *)(a1 + 1224) )
  {
    *(uint8_t *)off_136B00 = 0;
    event_dispatch(aApLpExit);
  }
  v10 = off_136AFC;
  v11 = (uint32_t *)((char *)off_136AFC + 20);
  *((uint8_t *)off_136AFC + 13) = 0;
  v10[14] = 0;
  fault_handler(v11);
  return rx_phy_status_parse(7u, 3);
}
