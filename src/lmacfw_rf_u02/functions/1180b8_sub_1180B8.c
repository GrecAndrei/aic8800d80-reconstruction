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


extern uint32_t dword_118290;
extern uint32_t dword_1182BC;
extern uint32_t off_118294;
extern uint32_t off_118298;
extern uint32_t off_11829C;
extern uint32_t off_1182A0;
extern uint32_t off_1182AC;
extern uint32_t off_1182B0;
extern uint32_t off_1182C0;
extern uint32_t off_1182C4;

// link_context_by_index @ 0x1180b8, size 470 bytes
int  link_context_by_index(int a1)
{
  int v2; // r8
  int v3; // r9
  int v4; // r3
  int v5; // r5
  int v6; // r6
  int v7; // r2
  int v8; // r3
  int v9; // r4
  void *v10; // r5
  int v11; // r3
  uint16_t **v13; // r11
  int *v14; // r10
  int v15; // r1
  unsigned int v16; // r3
  int v17; // r2
  unsigned int v18; // r3
  int v19; // r3
  int v20; // r2
  int v21; // [sp+0h] [bp-Ch]
  int v22; // [sp+4h] [bp-8h]

  v2 = dword_1182BC;
  v3 = dword_1182BC + 224 * a1;
  check_kernel_state_alt2(dword_118290, (uint32_t *)v3);
  v4 = *(uint8_t *)(v3 + 94);
  v5 = 224 * a1;
  if ( v4 == 2 )
  {
    v6 = off_118294;
    v7 = (uint8_t)(*(uint8_t *)(off_118294 + 0x12) - 1);
    *(uint8_t *)(off_118294 + 0x12) = v7;
    if ( v7 )
    {
      if ( *(uint8_t *)(v6 + 0x11) + v7 != 1 )
        goto LABEL_7;
      goto LABEL_12;
    }
    rf_disable();
LABEL_4:
    v7 = *(uint8_t *)(v6 + 0x12);
    v8 = *(uint8_t *)(v6 + 0x11) + v7;
    if ( v8 != 1 )
      goto LABEL_5;
    goto LABEL_12;
  }
  if ( v4 == 4 )
  {
    if ( sys_ready_check() )
      ctrl_bit3_set(0);
    v6 = off_118294;
    v7 = *(uint8_t *)(off_118294 + 0x12);
    v8 = *(uint8_t *)(off_118294 + 0x11) + v7;
    *(uint8_t *)(off_118294 + 0x10) = -1;
    if ( v8 != 1 )
      goto LABEL_5;
    goto LABEL_12;
  }
  v6 = off_118294;
  if ( *(uint8_t *)(v3 + 94) )
    goto LABEL_4;
  v7 = *(uint8_t *)(off_118294 + 0x12);
  v19 = (uint8_t)(*(uint8_t *)(off_118294 + 0x11) - 1);
  *(uint8_t *)(off_118294 + 0x11) = v19;
  v8 = v19 + v7;
  if ( v8 != 1 )
    goto LABEL_5;
LABEL_12:
  v13 = (uint16_t **)off_1182C0;
  v14 = off_1182C4;
  v15 = **(uint16_t **)off_1182C0;
  v16 = off_1182C4[1] & 0xFFFFFFEF;
  off_1182C4[1] = v16;
  if ( v15 < 0 && *(uint32_t *)off_1182B0 << 28 )
  {
    flash_cmd_exec((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
    v20 = *(uint8_t *)(v6 + 0x12);
    v8 = *(uint8_t *)(v6 + 0x11) + v20;
    *(uint32_t *)off_1182AC = *v14 | v14[1];
    if ( v8 != 1 )
      goto LABEL_5;
    if ( v20 )
      goto LABEL_7;
  }
  else
  {
    *(uint32_t *)off_1182AC = v16 | *v14;
    if ( v7 )
      goto LABEL_7;
  }
  v17 = **v13;
  v18 = v14[1] & 0xFFFFFEFF;
  v14[1] = v18;
  if ( v17 >= 0 )
  {
    *(uint32_t *)off_1182AC = v18 | *v14;
    goto LABEL_7;
  }
  if ( !(*(uint32_t *)off_1182B0 << 28) )
  {
    *(uint32_t *)off_1182AC = v18 | *v14;
    goto LABEL_7;
  }
  flash_cmd_exec((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
  v8 = *(uint8_t *)(v6 + 0x11) + *(uint8_t *)(v6 + 0x12);
  *(uint32_t *)off_1182AC = *v14 | v14[1];
LABEL_5:
  if ( !v8 )
    *(uint32_t *)off_118298 = 0;
LABEL_7:
  ke_exit_critical((uint32_t *)(v5 + 24 + v2));
  ke_exit_critical((uint32_t *)(v5 + 48 + v2));
  tx_slot_get_busy(*(uint8_t *)(v2 + 224 * a1 + 95));
  *(uint32_t *)off_11829C = 0;
  if ( *(uint8_t *)(v6 + 0x12) + *(uint8_t *)(v6 + 0x11) <= 1 )
    btcoex_check_state();
  memset_thunk((int *)v3, 0, 0xE0u);
  v22 = a1;
  v9 = v2 + 224 * a1;
  v10 = off_1182A0;
  v21 = *(uint8_t *)(v6 + 0x12);
  v11 = v21 + *(uint8_t *)(v6 + 0x11);
  *(uint32_t *)(v9 + 56) = v3;
  *(uint8_t *)(v9 + 94) = 5;
  *(uint8_t *)(v9 + 97) = 127;
  *(uint32_t *)(v9 + 52) = v10;
  check_interrupt_flag(256, "%s:%d,%d,%d\r\n", aVifMgmtUnregis, v11, v21, v22);
  return check_kernel_state(off_118294, (uint32_t *)v3);
}
