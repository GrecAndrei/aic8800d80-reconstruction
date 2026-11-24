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


extern uint32_t dword_136658;
extern uint32_t dword_136660;
extern uint32_t off_13663C;
extern uint32_t off_136644;
extern uint32_t off_136650;
extern uint32_t off_136654;
extern uint32_t off_13665C;
extern uint32_t off_136664;

// bt_rx_process @ 0x136478, size 450 bytes
int  bt_rx_process(int a1, int a2, int a3, int a4)
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
  char v17; // r2
  int v18; // r1
  uint16_t v19; // r2
  int v20; // r9
  int v21; // r3
  unsigned int v22; // r2
  uint32_t *v23; // r0
  unsigned int v24; // r0
  uint8_t a2a; // [sp+3h] [bp-11h] BYREF
  int a1a; // [sp+4h] [bp-10h] BYREF
  int v27; // [sp+8h] [bp-Ch]
  uint16_t v28; // [sp+Ch] [bp-8h]

  v4 = dword_136660;
  v6 = a3;
  v7 = a4;
  check_status_bits(256, "ap start:%d, radar=%d\r\n", *(uint32_t *)(a2 + 20), BYTE1(((uint32_t *)(uintptr_t)off_13663C)[103]));
  v8 = *(uint8_t *)(a2 + 51);
  v9 = v4 + 1320 * v8;
  if ( *(uint8_t *)(v9 + 106) != 2 )
  {
    v10 = 4;
LABEL_3:
    v11 = (char *)ke_msg_alloc(7169, v7, v6, 4);
    *v11 = v10;
    v11[1] = *(uint8_t *)(a2 + 51);
    ke_msg_send_2((int)v11);
    return 0;
  }
  if ( rx_rate_field_parse(7u) )
  {
    v10 = 8;
    goto LABEL_3;
  }
  if ( *(uint8_t *)(v9 + 108) )
  {
    v10 = 9;
    goto LABEL_3;
  }
  if ( **(uint16_t **)off_136644 < 0 && *(uint32_t *)(v9 + 72) )
    mmio_clear_register((int)aVifChanCtxtNul_0, (int)aApmStartReqHan, 105);
  v13 = *(uint8_t *)(a2 + 28);
  LOBYTE(a1a) = *(uint8_t *)(a2 + 16);
  v14 = *(uint16_t *)(a2 + 14);
  BYTE1(a1a) = v13;
  HIWORD(a1a) = v14;
  v15 = *(uint32_t *)(a2 + 24);
  v16 = off_136664;
  LOWORD(v27) = *(uint32_t *)(a2 + 20);
  v17 = *(uint8_t *)(a2 + 18);
  HIWORD(v27) = v15;
  LOBYTE(v15) = *(uint8_t *)(a2 + 17);
  *(uint32_t *)off_136664 = a2;
  LOBYTE(v28) = v17;
  HIBYTE(v28) = v15;
  if ( scan_find_empty_slot((uint8_t *)&a1a, &a2a) )
  {
    v10 = 1;
    goto LABEL_3;
  }
  v18 = v27;
  v19 = v28;
  v20 = v4 + 1320 * v8;
  *(uint32_t *)(v20 + 412) = a1a;
  *(uint32_t *)(v20 + 416) = v18;
  *(uint8_t *)(v20 + 464) = 0;
  *(uint16_t *)(v20 + 420) = v19;
  rf_temperature_comp(v20);
  if ( BYTE1(a1a) == 2 )
    is_valid_id((int *)(v4 + 1320 * v8), 1, 0);
  sta_lookup_by_bss(*(uint8_t *)(a2 + 51), a2a);
  if ( *((uint8_t *)off_136650 + 18) + *((uint8_t *)off_136650 + 17) == 1
    && !*(uint8_t *)(v4 + 1320 * v8 + 1224) )
  {
    *(uint8_t *)off_13665C = 0;
    set_bt_irq_flag();
  }
  if ( !*(uint8_t *)(a2 + 16) )
  {
    v24 = bt_process_msg((uint8_t *)(1320 * v8 + 424 + v4), 1) & 0xF;
    if ( v24 )
      *(uint8_t *)(v4 + 1320 * v8 + 461) = 31 - __clz(v24);
    else
      *(uint8_t *)(v4 + 1320 * v8 + 461) = 1;
  }
  ke_send_event_0x18();
  if ( !*(uint32_t *)off_136654 )
  {
    v21 = v4 + 1320 * v8;
    v22 = *(uint16_t *)(v21 + 416);
    if ( v22 <= 0x1387 )
      callback_post(v22 | (*(uint8_t *)(v21 + 413) << 16) | 0x80000000);
  }
  v23 = (uint32_t *)dword_136658;
  v16[14] = v16[15];
  v16[13] = 0;
  fault_handler(v23);
  return 1;
}
