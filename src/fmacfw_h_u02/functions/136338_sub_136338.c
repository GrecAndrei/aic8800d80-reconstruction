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

extern uint32_t dword_136520;
extern uint32_t dword_136500;
extern uint32_t off_1364FC;
extern uint32_t off_136504;
extern uint32_t dword_13650C;
extern uint32_t dword_136508;
extern uint32_t off_136524;
extern uint32_t off_136510;
extern uint32_t off_13651C;
extern uint32_t off_136514;
extern uint32_t dword_136518;

// le_connection_update @ 0x136338, size 450 bytes
int  le_connection_update(int a1, int a2, int16_t a3, int16_t a4)
{
  int v4; // r8
  int v8; // r6
  int v9; // r5
  char v10; // r5
  char *v11; // r0
  char v13; // r2
  int16_t v14; // r3
  int v15; // r3
  uint8_t *v16; // r10
  char v17; // r2
  int v18; // r1
  int16_t v19; // r2
  int v20; // r9
  int v21; // r0
  int v22; // r3
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // r0
  int v26; // r2
  uint8_t v27; // [sp+3h] [bp-11h] BYREF
  int v28; // [sp+4h] [bp-10h] BYREF
  int v29; // [sp+8h] [bp-Ch]
  int16_t v30; // [sp+Ch] [bp-8h]

  v4 = dword_136520;
  check_feature_flag(256, dword_136500, *(uint32_t *)(a2 + 20), *((uint8_t *)off_1364FC + 413));
  v8 = *(uint8_t *)(a2 + 51);
  v9 = v4 + 1320 * v8;
  if ( *(uint8_t *)(v9 + 106) != 2 )
  {
    v10 = 4;
LABEL_3:
    v11 = (char *)tx_send_pdu(7169, a4, a3, 4u);
    *v11 = v10;
    v11[1] = *(uint8_t *)(a2 + 51);
    rx_process_packet((int)v11);
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
  if ( **(int16_t **)off_136504 < 0 && *(uint32_t *)(v9 + 72) )
    irq_disable_mmio_write(dword_13650C, dword_136508, 105);
  v13 = *(uint8_t *)(a2 + 28);
  LOBYTE(v28) = *(uint8_t *)(a2 + 16);
  v14 = *(uint16_t *)(a2 + 14);
  BYTE1(v28) = v13;
  HIWORD(v28) = v14;
  v15 = *(uint32_t *)(a2 + 24);
  v16 = off_136524;
  LOWORD(v29) = *(uint32_t *)(a2 + 20);
  v17 = *(uint8_t *)(a2 + 18);
  HIWORD(v29) = v15;
  LOBYTE(v15) = *(uint8_t *)(a2 + 17);
  *(uint32_t *)off_136524 = a2;
  LOBYTE(v30) = v17;
  HIBYTE(v30) = v15;
  if ( cfm_radio_check((uint8_t *)&v28, &v27) )
  {
    v10 = 1;
    goto LABEL_3;
  }
  v18 = v29;
  v19 = v30;
  v20 = v4 + 1320 * v8;
  *(uint32_t *)(v20 + 412) = v28;
  *(uint32_t *)(v20 + 416) = v18;
  *(uint8_t *)(v20 + 464) = 0;
  *(uint16_t *)(v20 + 420) = v19;
  compute_byte_delta(v20);
  if ( BYTE1(v28) == 2 )
    check_non_null((int *)(v4 + 1320 * v8), 1, 0);
  v21 = bsscfg_index(*(uint8_t *)(a2 + 51), v27);
  if ( *((uint8_t *)off_136510 + 18) + *((uint8_t *)off_136510 + 17) == 1
    && !*(uint8_t *)(v4 + 1320 * v8 + 1224) )
  {
    *(uint8_t *)off_13651C = 0;
    rf_rate_code_check(v21);
  }
  if ( !*(uint8_t *)(a2 + 16) )
  {
    v25 = handle_rx_packet((uint8_t *)(1320 * v8 + 424 + v4), 1) & 0xF;
    if ( v25 )
      *(uint8_t *)(v4 + 1320 * v8 + 461) = 31 - __clz(v25);
    else
      *(uint8_t *)(v4 + 1320 * v8 + 461) = 1;
  }
  send_hci_event();
  if ( !*(uint32_t *)off_136514 )
  {
    v22 = v4 + 1320 * v8;
    v23 = *(uint16_t *)(v22 + 416);
    if ( v23 <= 0x1387 )
    {
      v26 = v23 | (*(uint8_t *)(v22 + 413) << 16);
      bt_set_address(v26 | 0x80000000, 4999, v26);
    }
  }
  v24 = dword_136518;
  v16[14] = v16[15];
  v16[13] = 0;
  mem_set_util(v24);
  return 1;
}

