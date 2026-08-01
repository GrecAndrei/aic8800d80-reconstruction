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

extern uint32_t dword_134D88;
extern uint32_t off_134D7C;
extern uint32_t off_134D80;
extern uint32_t dword_134D84;

// bt_get_profile_ctx @ 0x134bd0, size 428 bytes
uint32_t *bt_get_profile_ctx()
{
  int v0; // r10
  int v1; // r5
  uint8_t *v2; // r9
  int v3; // r7
  int v4; // r4
  int v5; // r6
  int v6; // r11
  uint8_t *v7; // r8
  int v8; // r0
  void *v9; // r3
  int v10; // r0
  int v11; // r3
  int v12; // r0
  int v13; // r6
  int v14; // r6
  int v15; // r7
  int *v16; // r10
  int v17; // r0
  int v18; // t1
  int v19; // r0
  int *v21; // r6
  int v22; // [sp+0h] [bp-Ch]

  v0 = dword_134D88;
  v1 = *((uint32_t *)off_134D7C + 4);
  v22 = *(uint8_t *)(v1 + 61);
  v2 = (uint8_t *)ke_msg_alloc(5145, 5, 6, 2u);
  v3 = ke_msg_alloc(24, 0, 6, 8u);
  v4 = 1320 * v22;
  v5 = ke_msg_alloc(22, 0, 6, 8u);
  v6 = ke_msg_alloc(20, 0, 6, 4u);
  v7 = (uint8_t *)ke_msg_alloc(5143, 5, 6, 2u);
  check_flag_and_proceed();
  *v2 = 1;
  v2[1] = *(uint8_t *)(v1 + 61);
  cmd_handler_a((int)off_134D7C + 24, (uint32_t *)v2 - 3);
  v8 = *(uint32_t *)(v0 + 1320 * v22 + 368);
  *(uint16_t *)(v3 + 4) = *(uint16_t *)(v0 + 1320 * v22 + 372);
  v9 = off_134D7C;
  *(uint32_t *)v3 = v8;
  *(uint8_t *)(v3 + 6) = *(uint8_t *)(v1 + 61);
  cmd_handler_a((int)v9 + 24, (uint32_t *)(v3 - 12));
  *(uint8_t *)(v5 + 5) = *(uint8_t *)(v0 + 1320 * v22 + 412);
  v10 = bt_process_msg((uint8_t *)(1320 * v22 + 424 + v0), 1);
  v11 = *(uint8_t *)(v5 + 5);
  *(uint32_t *)v5 = v10;
  *(uint8_t *)(v5 + 4) = *(uint8_t *)(v1 + 61);
  if ( !v11 )
  {
    if ( (v10 & 1) != 0 )
    {
      *((uint32_t *)off_134D80 + 5) = 1024;
    }
    else if ( (v10 & 0x10) != 0 )
    {
      *((uint32_t *)off_134D80 + 5) = 4;
    }
  }
  cmd_handler_a(dword_134D84, (uint32_t *)(v5 - 12));
  v12 = dword_134D84;
  v13 = v0 + 1320 * v22;
  *(uint16_t *)v6 = *(uint16_t *)(v13 + 422);
  *(uint8_t *)(v6 + 2) = *(uint8_t *)(v1 + 61);
  cmd_handler_a(v12, (uint32_t *)(v6 - 12));
  if ( (*(uint32_t *)(v13 + 472) & 8) != 0 )
  {
    v21 = (int *)ke_msg_alloc(113, 0, 6, 4u);
    *v21 = rf_get_tx_chan(v0 + v4 + 248);
    cmd_handler_a(dword_134D84, v21 - 3);
  }
  v14 = 0;
  v15 = dword_134D84;
  v16 = (int *)(v0 + v4 + 440);
  do
  {
    v17 = ke_msg_alloc(26, 0, 6, 8u);
    v18 = *v16++;
    *(uint32_t *)v17 = v18;
    *(uint8_t *)(v17 + 5) = v14;
    *(uint8_t *)(v17 + 6) = *(uint8_t *)(v1 + 61);
    *(uint8_t *)(v17 + 4) = 0;
    ++v14;
    cmd_handler_a(v15, (uint32_t *)(v17 - 12));
  }
  while ( v14 != 4 );
  *v7 = 1;
  v19 = dword_134D84;
  v7[1] = *(uint8_t *)(v1 + 61);
  cmd_handler_a(v19, (uint32_t *)v7 - 3);
  bt_is_controller_ready();
  return rx_phy_status_parse(6u, 4);
}

