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


extern uint32_t dword_136518;
extern uint32_t dword_136520;
extern uint32_t off_1364FC;
extern uint32_t off_136504;
extern uint32_t off_136510;
extern uint32_t off_136514;
extern uint32_t off_13651C;
extern uint32_t off_136524;

// le_connection_update @ 0x136338, size 450 bytes
int  le_connection_update(int a1, int a2, int a3, int a4)
{
  int v4; // r8
  uint16_t v6; // r7
  uint16_t v7; // r9
  int v8; // r6
  int v9; // r5
  char v10; // r5
  char *v11; // r0
  char v13; // r2
  uint16_t v14; // r3
  int v15; // r3
  uint8_t *v16; // r10
  int v17; // r2
  int v18; // r3
  int v19; // r1
  uint16_t v20; // r2
  int v21; // r9
  int v22; // r3
  unsigned int v23; // r2
  uint32_t *v24; // r0
  unsigned int v25; // r0
  uint8_t a2a; // [sp+3h] [bp-11h] BYREF
  int a1a; // [sp+4h] [bp-10h] BYREF
  int v28; // [sp+8h] [bp-Ch]
  uint16_t v29; // [sp+Ch] [bp-8h]

  v4 = dword_136520;
  v6 = a3;
  v7 = a4;
  check_feature_flag(256, "ap start:%d, radar=%d\r\n", *(uint32_t *)(a2 + 20), BYTE1(((uint32_t *)(uintptr_t)off_1364FC)[103]));
  v8 = *(uint8_t *)(a2 + 51);
  v9 = v4 + 1320 * v8;
  if ( *(uint8_t *)(v9 + 106) != 2 )
  {
    v10 = 4;
LABEL_3:
    v11 = (char *)tx_send_pdu(7169, v7, v6, 4);
    *v11 = v10;
    v11[1] = *(uint8_t *)(a2 + 51);
    rx_process_packet_1((int)v11);
    return 0;
  }
  if ( hci_cmd_handler(7u) )
  {
    v10 = 8;
    goto LABEL_3;
  }
  if ( *(uint8_t *)(v9 + 108) )
  {
    v10 = 9;
    goto LABEL_3;
  }
  if ( **(uint16_t **)off_136504 < 0 && *(uint32_t *)(v9 + 72) )
    irq_disable_mmio_write((int)aVifChanCtxtNul_0, (int)aApmStartReqHan, 105);
  v13 = *(uint8_t *)(a2 + 28);
  LOBYTE(a1a) = *(uint8_t *)(a2 + 16);
  v14 = *(uint16_t *)(a2 + 14);
  BYTE1(a1a) = v13;
  HIWORD(a1a) = v14;
  v15 = *(uint32_t *)(a2 + 24);
  v16 = off_136524;
  LOWORD(v28) = *(uint32_t *)(a2 + 20);
  v17 = *(uint8_t *)(a2 + 18);
  HIWORD(v28) = v15;
  v18 = *(uint8_t *)(a2 + 17);
  *(uint32_t *)off_136524 = a2;
  LOBYTE(v29) = v17;
  HIBYTE(v29) = v18;
  if ( cfm_radio_check((uint8_t *)&a1a, &a2a, v17, v18) )
  {
    v10 = 1;
    goto LABEL_3;
  }
  v19 = v28;
  v20 = v29;
  v21 = v4 + 1320 * v8;
  *(uint32_t *)(v21 + 412) = a1a;
  *(uint32_t *)(v21 + 416) = v19;
  *(uint8_t *)(v21 + 464) = 0;
  *(uint16_t *)(v21 + 420) = v20;
  compute_byte_delta(v21);
  if ( BYTE1(a1a) == 2 )
    check_non_null((int *)(v4 + 1320 * v8), 1, 0);
  bsscfg_index(*(uint8_t *)(a2 + 51), a2a);
  if ( *((uint8_t *)off_136510 + 18) + *((uint8_t *)off_136510 + 17) == 1
    && !*(uint8_t *)(v4 + 1320 * v8 + 1224) )
  {
    *(uint8_t *)off_13651C = 0;
    rf_rate_code_check();
  }
  if ( !*(uint8_t *)(a2 + 16) )
  {
    v25 = handle_rx_packet((uint8_t *)(1320 * v8 + 424 + v4), 1) & 0xF;
    if ( v25 )
      *(uint8_t *)(v4 + 1320 * v8 + 461) = 31 - __clz(v25);
    else
      *(uint8_t *)(v4 + 1320 * v8 + 461) = 1;
  }
  send_hci_event_1();
  if ( !*(uint32_t *)off_136514 )
  {
    v22 = v4 + 1320 * v8;
    v23 = *(uint16_t *)(v22 + 416);
    if ( v23 <= 0x1387 )
      bt_set_address(v23 | (*(uint8_t *)(v22 + 413) << 16) | 0x80000000);
  }
  v24 = (uint32_t *)dword_136518;
  v16[14] = v16[15];
  v16[13] = 0;
  mem_set_util(v24);
  return 1;
}
