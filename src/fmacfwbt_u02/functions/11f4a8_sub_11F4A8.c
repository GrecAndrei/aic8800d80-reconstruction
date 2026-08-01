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

extern uint32_t dword_11F5AC;
extern uint32_t dword_11F5C8;
extern uint32_t dword_11F5B4;
extern uint32_t off_11F5B8;
extern uint32_t off_11F5BC;
extern uint32_t dword_11F5C0;
extern uint32_t off_11F5C4;

// wlc_phy_cal_init @ 0x11f4a8, size 260 bytes
// Doc: sub_121F4A8 [mac]: Processes indexed per-station context entry with size-scaled offsets
// sub_121F4A8 [mac]: Processes indexed per-station context entry with size-scaled offsets
unsigned int  wlc_phy_cal_init(int a1)
{
  int v1; // r7
  int v2; // r8
  int v3; // r4
  int v4; // r6
  uint32_t *v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r0
  int v10; // r12
  int v11; // r0
  unsigned int result; // r0
  int *v13; // r0
  int v14; // r2
  int *v15; // r3

  v1 = dword_11F5AC;
  v2 = dword_11F5C8;
  v3 = dword_11F5AC + 696 * a1;
  v4 = 1320 * *(uint8_t *)(v3 + 34);
  if ( *(uint8_t *)(dword_11F5C8 + v4 + 1224) )
    --*(uint8_t *)(dword_11F5C8 + v4 + 1226);
  state_check_feature(256, dword_11F5B4);
  check_abort_flag_3(v4 + 240 + v2, v3);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11F5B8 = 1;
  }
  v6 = off_11F5BC;
  v7 = v1 + 696 * a1;
  v8 = *(uint32_t *)off_11F5BC;
  v9 = *(uint32_t *)(v7 + 44);
  v10 = *(uint32_t *)off_11F5BC + 1;
  *(uint32_t *)off_11F5BC = v10;
  *(uint8_t *)(v7 + 37) = 0;
  if ( v9 )
  {
    *(uint8_t *)(v9 + 37) = 0;
    if ( !v10 )
    {
LABEL_7:
      wlc_bsscfg_llc_flush(v9);
      check_abort_flag(dword_11F5C0);
      goto LABEL_8;
    }
    v13 = (int *)off_11F5B8;
    *v6 = v8;
    v14 = *v13;
    if ( v8 )
    {
      v9 = *(uint32_t *)(v7 + 44);
      goto LABEL_7;
    }
  }
  else
  {
    if ( !v10 )
      goto LABEL_8;
    v15 = (int *)off_11F5B8;
    *v6 = v8;
    v14 = *v15;
    if ( v8 )
      goto LABEL_8;
  }
  if ( v14 )
    __enable_irq();
  v9 = *(uint32_t *)(v1 + 696 * a1 + 44);
  if ( v9 )
    goto LABEL_7;
LABEL_8:
  wlc_bsscfg_llc_flush(v3);
  v11 = check_abort_flag(dword_11F5C0);
  result = find_pending_command(v11);
  if ( !result )
  {
    if ( *((uint8_t *)off_11F5C4 + 408) )
      return dma_tx_setup(v2 + v4);
    else
      return write_mmio_byte(0xC2u);
  }
  return result;
}

