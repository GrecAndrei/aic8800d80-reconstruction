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
extern uint32_t dword_136B04;
extern uint32_t off_136B00;
extern uint32_t off_136AFC;

// rf_send_command_0x1419 @ 0x1369cc, size 290 bytes
uint32_t * rf_send_command_0x1419(int a1)
{
  uint8_t *v2; // r6
  int v3; // r0
  uint8_t *v4; // r5
  int v5; // r1
  unsigned int v6; // r2
  int *v7; // r3
  uint8_t *v8; // r0
  uint8_t *v9; // r3
  char *v10; // r0
  int v12; // r0
  int v13; // r0

  v2 = (uint8_t *)ke_msg_alloc(5145, 5, 7, 2u);
  v3 = ke_msg_alloc(5143, 5, 7, 2u);
  *(uint8_t *)(dword_136AF0 + 696 * (*(uint8_t *)(a1 + 107) + 32) + 37) = 0;
  v4 = (uint8_t *)v3;
  bt_get_buffer();
  *v2 = 0;
  v2[1] = *(uint8_t *)(a1 + 107);
  cmd_handler_a(dword_136AF4, (uint32_t *)v2 - 3);
  v7 = *((int **)off_136AF8 + 2);
  if ( v7 )
  {
    v5 = 4999;
    while ( 1 )
    {
      if ( (int *)a1 != v7 )
      {
        v6 = *((uint8_t *)v7 + 108);
        if ( *((uint8_t *)v7 + 108) )
        {
          v6 = *((uint16_t *)v7 + 208);
          if ( v6 <= 0x1387 )
            break;
        }
      }
      v7 = (int *)*v7;
      if ( !v7 )
        goto LABEL_7;
    }
    callback_post(v6 | (*((uint8_t *)v7 + 413) << 16) | 0x80000000, 4999, v6);
  }
  else
  {
LABEL_7:
    callback_post(0, v5, v6);
  }
  is_valid_id((int *)a1, 0, 0);
  if ( *(uint8_t *)(a1 + 108) )
  {
    v12 = ke_msg_alloc(30, 0, 7, 4u);
    *(uint8_t *)(v12 + 2) = 0;
    *(uint8_t *)(v12 + 3) = *(uint8_t *)(a1 + 107);
    cmd_handler_a(dword_136AF4, (uint32_t *)(v12 - 12));
  }
  if ( *(uint32_t *)(a1 + 72) )
  {
    v8 = (uint8_t *)ke_msg_alloc(57, 0, 7, 1u);
    *v8 = *(uint8_t *)(a1 + 107);
    cmd_handler_a(dword_136AF4, (uint32_t *)v8 - 3);
  }
  *v4 = 0;
  v4[1] = *(uint8_t *)(a1 + 107);
  cmd_handler_a(dword_136AF4, (uint32_t *)v4 - 3);
  bt_ready_check();
  if ( !*(uint8_t *)(a1 + 1224) )
  {
    v13 = dword_136B04;
    *(uint8_t *)off_136B00 = 0;
    event_dispatch(v13);
  }
  v9 = off_136AFC;
  v10 = (char *)off_136AFC + 20;
  *((uint8_t *)off_136AFC + 13) = 0;
  v9[14] = 0;
  fault_handler((int)v10);
  return rx_phy_status_parse(7u, 3);
}

