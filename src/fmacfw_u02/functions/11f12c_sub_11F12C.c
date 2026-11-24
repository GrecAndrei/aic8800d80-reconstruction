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


extern uint32_t dword_11F270;
extern uint32_t dword_11F284;
extern uint32_t dword_11F294;
extern uint32_t off_11F27C;
extern uint32_t off_11F280;
extern uint32_t off_11F288;
extern uint32_t off_11F28C;
extern uint32_t off_11F290;

// llm_conn_calc_ptr @ 0x11f12c, size 322 bytes
int  llm_conn_calc_ptr(unsigned int a1, int a2, int a3, int a4)
{
  int v4; // r7
  int v5; // r8
  int v6; // r5
  int v7; // r9
  int v8; // r6
  int v9; // r3
  uint32_t *v11; // r2
  unsigned int v12; // r3
  int v13; // r1
  int v14; // r0
  int v15; // r12
  int result; // r0
  int v17; // r8
  int *v18; // r0
  int v19; // r2
  int *v20; // r3
  int v21; // r3

  v4 = dword_11F270;
  v5 = dword_11F294;
  v6 = dword_11F270 + 696 * a1;
  v7 = *(uint8_t *)(v6 + 34);
  v8 = 1320 * v7;
  v9 = dword_11F294 + 1320 * v7;
  if ( *(uint8_t *)(v9 + 1224) )
    --*(uint8_t *)(v9 + 1226);
  check_status_bits(256, "%s: sta_idx=%d\n", aStaMgmtUnregis, a1);
  cmd_handler_c(v8 + 240 + v5, (uint32_t *)v6);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11F27C = 1;
  }
  v11 = off_11F280;
  v12 = v4 + 696 * a1;
  v13 = *(uint32_t *)off_11F280;
  v14 = *(uint32_t *)(v12 + 44);
  v15 = *(uint32_t *)off_11F280 + 1;
  *(uint32_t *)off_11F280 = v15;
  *(uint8_t *)(v12 + 37) = 0;
  if ( v14 )
  {
    *(uint8_t *)(v14 + 37) = 0;
    if ( !v15 )
    {
LABEL_7:
      llc_aes_ccm_setup(v14);
      cmd_handler_a(dword_11F284, *(uint32_t **)(v4 + 696 * a1 + 44));
      goto LABEL_8;
    }
    v18 = (int *)off_11F27C;
    *v11 = v13;
    v19 = *v18;
    if ( v13 )
    {
      v14 = *(uint32_t *)(v12 + 44);
      goto LABEL_7;
    }
  }
  else
  {
    if ( !v15 )
      goto LABEL_8;
    v20 = (int *)off_11F27C;
    *v11 = v13;
    v19 = *v20;
    if ( v13 )
      goto LABEL_8;
  }
  if ( v19 )
    __enable_irq();
  v14 = *(uint32_t *)(v4 + 696 * a1 + 44);
  if ( v14 )
    goto LABEL_7;
LABEL_8:
  llc_aes_ccm_setup(v6);
  cmd_handler_a(dword_11F284, (uint32_t *)v6);
  result = get_phy_channel();
  if ( !result )
  {
    if ( LOBYTE(((uint32_t *)(uintptr_t)off_11F288)[102]) )
      result = mmio_update(v5 + v8);
    else
      result = write_phy_config(0xC2u);
  }
  if ( a1 <= 0x1F )
  {
    v17 = v5 + 1320 * v7;
    if ( *(uint8_t *)(v17 + 106) == 2 && !*(uint8_t *)(v17 + 1224) )
    {
      if ( !*(uint8_t *)off_11F28C
        || (v21 = (uint8_t)(*(uint8_t *)off_11F28C - 1), *(uint8_t *)off_11F28C = v21, !v21) )
      {
        if ( *((uint8_t *)off_11F290 + 18) + *((uint8_t *)off_11F290 + 17) == 1 )
          return set_bt_irq_flag();
      }
    }
  }
  return result;
}
