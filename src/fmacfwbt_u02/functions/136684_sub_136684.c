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


extern uint32_t dword_136824;
extern uint32_t off_136808;
extern uint32_t off_136810;
extern uint32_t off_136814;
extern uint32_t off_136820;

// rf_cal_configure @ 0x136684, size 388 bytes
int  rf_cal_configure(int a1, int a2, int a3, int a4)
{
  int v4; // r8
  uint16_t v6; // r7
  uint16_t v7; // r9
  int v8; // r6
  int v9; // r5
  char v10; // r5
  char *v11; // r0
  char v13; // r3
  uint16_t v14; // r3
  int v15; // r3
  char v16; // r2
  int v17; // r1
  uint16_t v18; // r2
  int v19; // r9
  int v20; // r3
  unsigned int v21; // r2
  unsigned int v22; // r0
  uint8_t a2a; // [sp+3h] [bp-Dh] BYREF
  int a1a; // [sp+4h] [bp-Ch] BYREF
  int v25; // [sp+8h] [bp-8h]
  uint16_t v26; // [sp+Ch] [bp-4h]

  v4 = dword_136824;
  v6 = a3;
  v7 = a4;
  state_check_feature(256, "ap start:%d, radar=%d\r\n", *(uint32_t *)(a2 + 20), BYTE1(((uint32_t *)(uintptr_t)off_136808)[103]));
  v8 = *(uint8_t *)(a2 + 51);
  v9 = v4 + 1320 * v8;
  if ( *(uint8_t *)(v9 + 106) != 2 )
  {
    v10 = 4;
LABEL_3:
    v11 = (char *)bt_buf_alloc(7169, v7, v6, 4);
    *v11 = v10;
    v11[1] = *(uint8_t *)(a2 + 51);
    hci_evt_send((int)v11);
    return 0;
  }
  if ( hci_cmd_send_short(7u) )
  {
    v10 = 8;
    goto LABEL_3;
  }
  if ( *(uint8_t *)(v9 + 108) )
  {
    v10 = 9;
    goto LABEL_3;
  }
  if ( **(uint16_t **)off_136810 < 0 && *(uint32_t *)(v9 + 72) )
    mmio_irq_clear((int)aVifChanCtxtNul_0, (int)aApmStartReqHan, 105);
  v13 = *(uint8_t *)(a2 + 16);
  *(uint32_t *)off_136814 = a2;
  LOBYTE(a1a) = v13;
  v14 = *(uint16_t *)(a2 + 14);
  BYTE1(a1a) = *(uint8_t *)(a2 + 28);
  HIWORD(a1a) = v14;
  v15 = *(uint32_t *)(a2 + 24);
  LOWORD(v25) = *(uint32_t *)(a2 + 20);
  v16 = *(uint8_t *)(a2 + 18);
  HIWORD(v25) = v15;
  LOBYTE(v15) = *(uint8_t *)(a2 + 17);
  LOBYTE(v26) = v16;
  HIBYTE(v26) = v15;
  if ( find_free_conn((uint8_t *)&a1a, &a2a) )
  {
    v10 = 1;
    goto LABEL_3;
  }
  v17 = v25;
  v18 = v26;
  v19 = v4 + 1320 * v8;
  *(uint32_t *)(v19 + 412) = a1a;
  *(uint32_t *)(v19 + 416) = v17;
  *(uint8_t *)(v19 + 464) = 0;
  *(uint16_t *)(v19 + 420) = v18;
  scan_rssi_compare(v19);
  if ( BYTE1(a1a) == 2 )
    bt_coex_control((int *)(v4 + 1320 * v8), 1, 0);
  update_entries_from_config(*(uint8_t *)(a2 + 51), a2a);
  if ( !*(uint8_t *)(a2 + 16) )
  {
    v22 = llm_decrypt_adv_payload((uint8_t *)(1320 * v8 + 424 + v4), 1) & 0xF;
    if ( v22 )
      *(uint8_t *)(v4 + 1320 * v8 + 461) = 31 - __clz(v22);
    else
      *(uint8_t *)(v4 + 1320 * v8 + 461) = 1;
  }
  rf_cal_init();
  if ( !*(uint32_t *)off_136820 )
  {
    v20 = v4 + 1320 * v8;
    v21 = *(uint16_t *)(v20 + 416);
    if ( v21 <= 0x1387 )
      hw_reg_write(v21 | (*(uint8_t *)(v20 + 413) << 16) | 0x80000000);
  }
  return 1;
}
