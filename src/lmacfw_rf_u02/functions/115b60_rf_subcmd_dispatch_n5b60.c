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

extern uint32_t dword_115C84;
extern uint32_t off_115C74;
extern uint32_t dword_115C80;
extern uint32_t off_115C78;
extern uint32_t off_115C7C;
extern uint32_t dword_115C88;

// llm_scan_pdu_cfg @ 0x115b60, size 276 bytes
// Doc: rf_register_access_helper [rf]: Helper wrapping RF register access (pushes r4-r6,lr)
// rf_register_access_helper [rf]: Helper wrapping RF register access (pushes r4-r6,lr)
int  llm_scan_pdu_cfg(int a1, int a2)
{
  uint8_t *v4; // r3
  char *v5; // r0
  int *v6; // r5
  int v7; // r2
  int v8; // r3
  int v9; // r3
  int v10; // r2
  int v11; // r2
  int v12; // r1
  int16_t v13; // r3
  int *v14; // r3
  int v15; // r3
  int v16; // r2
  int v17; // r3
  int v18; // r2
  int v20; // r3
  int v21; // r0
  uint32_t *v22; // r3

  if ( a2 == 5 )
  {
    v5 = (char *)dword_115C84;
    v4 = (uint8_t *)(dword_115C84 - 112);
  }
  else
  {
    v4 = off_115C74;
    v5 = (char *)off_115C74 + 28 * a2;
  }
  if ( v4[142] )
  {
    v20 = *(uint8_t *)(a1 + 16);
    if ( v20 == 255 )
    {
      wlan_tx_kick(a1, 0);
      return 0;
    }
    else
    {
      v21 = dword_115C80;
      *(uint8_t *)(a1 + 14) = a2;
      *(uint8_t *)(a1 + 53) = 1;
      check_kernel_state(v21 + 152 * (int16_t)v20 + 48);
      return 1;
    }
  }
  *(uint32_t *)(*(uint32_t *)(a1 + 32) + 64) |= 0x100u;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_115C78 = 1;
  }
  v6 = (int *)off_115C7C;
  v7 = *((uint32_t *)v5 + 5);
  ++*(uint32_t *)off_115C7C;
  if ( v7 )
  {
    check_kernel_state(v5 + 12);
    v8 = *v6;
    if ( *v6 )
    {
LABEL_8:
      v9 = v8 - 1;
      v10 = *(uint32_t *)off_115C78;
      *v6 = v9;
      if ( !v9 && v10 )
        __enable_irq();
    }
  }
  else
  {
    v22 = *(uint32_t **)(a1 + 28);
    v22[4] = dword_115C88;
    v22[2] = a1;
    v22[3] = a1;
    check_kernel_state(v5 + 12);
    v8 = *v6;
    if ( *v6 )
      goto LABEL_8;
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_115C78 = 1;
  }
  v11 = *v6;
  v12 = *v6 + 1;
  v13 = *(uint16_t *)(a1 + 38) | 1;
  *v6 = v12;
  *(uint16_t *)(a1 + 38) = v13;
  if ( v12 )
  {
    v14 = (int *)off_115C78;
    *v6 = v11;
    v15 = *v14;
    if ( !v11 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_115C78 = 1;
  }
  v16 = *(uint32_t *)(a1 + 28);
  ++*v6;
  rx_pkt_status_update(a1, a1, v16, a2);
  if ( *v6 )
  {
    v17 = *v6 - 1;
    v18 = *(uint32_t *)off_115C78;
    *v6 = v17;
    if ( !v17 )
    {
      if ( v18 )
        __enable_irq();
    }
  }
  return 1;
}

