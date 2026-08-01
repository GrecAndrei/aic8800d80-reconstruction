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

extern uint32_t off_134DDC;
extern uint32_t off_134DE4;
extern uint32_t dword_134DE0;
extern uint32_t dword_134DE8;

// rx_desc_read_status @ 0x134cac, size 302 bytes
int rx_desc_read_status()
{
  int v0; // r6
  int16_t v1; // r7
  int v2; // r8
  int v3; // r0
  int v4; // r0
  int v5; // r4
  int v6; // r5
  uint16_t *v7; // r1
  int v8; // r3
  int16_t v9; // r2
  int v10; // t1
  int v11; // r0
  int v12; // r3
  int v13; // r6
  int v14; // r9
  int v15; // r0
  int v16; // r5
  uint32_t *v17; // r1
  int result; // r0
  int v19; // r6

  v0 = *((uint32_t *)off_134DDC + 2);
  v1 = *((uint16_t *)off_134DDC + 6);
  v2 = *(uint8_t *)(v0 + 116);
  if ( *(uint8_t *)(v0 + 1224) )
  {
    v3 = 1;
  }
  else
  {
    v3 = *(uint8_t *)(v0 + 412);
    if ( *(uint8_t *)(v0 + 412) )
      v3 = 1;
  }
  v4 = event_notify(v3, 512);
  v5 = v4;
  if ( !v4 )
    return mac_tx_start();
  scan_done_check(v0, v4);
  v6 = *(uint32_t *)(v5 + 72);
  v7 = off_134DE4;
  v8 = dword_134DE0 + 696 * v2;
  v9 = *((uint16_t *)off_134DE4 + 254);
  v10 = *(uint32_t *)(v8 + 38);
  v8 += 38;
  *(uint32_t *)(v6 + 112) = v10;
  *(uint8_t *)(v6 + 108) = -64;
  *(uint16_t *)(v6 + 116) = *(uint16_t *)(v8 + 4);
  *(uint32_t *)(v6 + 118) = *(uint32_t *)(v0 + 100);
  *(uint16_t *)(v6 + 122) = *(uint16_t *)(v0 + 104);
  v11 = *(uint32_t *)v8;
  *(uint16_t *)(v6 + 128) = *(uint16_t *)(v8 + 4);
  ++v9;
  v12 = dword_134DE8;
  *(uint32_t *)(v6 + 124) = v11;
  *(uint8_t *)(v6 + 109) = 0;
  *(uint8_t *)(v6 + 110) = 0;
  *(uint8_t *)(v6 + 111) = 0;
  v7[254] = v9;
  *(uint16_t *)(v6 + 130) = 16 * v9;
  *(uint32_t *)(v5 + 88) = v12;
  *(uint32_t *)(v5 + 92) = v0;
  *(uint8_t *)(v5 + 28) = *(uint8_t *)(v0 + 107);
  *(uint8_t *)(v5 + 29) = *(uint8_t *)(v0 + 116);
  *(uint8_t *)(v5 + 51) = 0;
  *(uint8_t *)(v5 + 53) = 0;
  v13 = bt_get_conn_ctx(v5, 192, 0);
  v14 = v6 + 108;
  if ( v13 == 1 )
  {
    mac_rx_process_ack(v5, v6 + 108, 24);
    v19 = *(uint8_t *)(v5 + 51) + 24;
    v16 = util_store_u16_return_2((uint16_t *)(v14 + v19), v1) + v19 + *(uint8_t *)(v5 + 53);
  }
  else
  {
    v15 = util_store_u16_return_2((uint16_t *)(v6 + 132), v1);
    v16 = v15 + 24;
    if ( v13 == 2 )
      v16 += bt_check_conn_active(v5, v14, v15 + 24);
  }
  v17 = *(uint32_t **)(v5 + 76);
  v17[8] = v17[7] - 1 + v16;
  v17[9] = v16 + 4;
  result = ble_event_dispatch(v5, 3);
  if ( !result )
    return mac_tx_start();
  return result;
}

