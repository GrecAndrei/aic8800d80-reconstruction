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

// rf_copy_cal_params @ 0x1359cc, size 148 bytes
// positive sp value has been detected, the output may be wrong!
void  rf_copy_cal_params(
        int a1,
        int16_t a2,
        int *a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  int v11; // r4
  int v12; // r5
  int v13; // r7
  int16_t v14; // r8
  char v15; // r9
  int v16; // r12
  int16_t v17; // r1
  int v18; // r0
  int16_t v19; // r6
  int v20; // r4
  int v21; // r4
  int v22; // r3
  int v23; // r2
  int v24; // r1
  uint64_t v25; // r2

  *(uint16_t *)(a4 + 116) = *((uint16_t *)a3 + 2);
  v17 = a2 + 1;
  v18 = *(uint32_t *)(v11 + 100);
  v19 = *(uint16_t *)(v11 + 104);
  v20 = *a3;
  *(uint32_t *)(a4 + 118) = v18;
  LOWORD(v18) = *((uint16_t *)a3 + 2);
  *(uint8_t *)(a4 + 109) = v15;
  *(uint8_t *)(a4 + 110) = v15;
  *(uint8_t *)(a4 + 111) = v15;
  *(uint16_t *)(a4 + 122) = v19;
  *(uint32_t *)(a4 + 124) = v20;
  *(uint16_t *)(a4 + 128) = v18;
  *(uint16_t *)(v16 + 508) = v17;
  *(uint16_t *)(a4 + 130) = 16 * v17;
  *(uint8_t *)(v13 + 28) = *(uint8_t *)(v12 + 8);
  *(uint8_t *)(v13 + 29) = *(uint8_t *)(v12 + 7);
  v21 = a4 + 108;
  *(uint8_t *)(v13 + 51) = v15;
  *(uint8_t *)(v13 + 53) = v15;
  bt_get_conn_ctx(v13, 208, 8);
  mac_rx_process_ack(v13, v21, 24);
  v22 = *(uint8_t *)(v13 + 51) + 24;
  v23 = v22 + v21;
  *(uint8_t *)(v22 + v21) = 8;
  *(uint8_t *)(v23 + 1) = 1;
  v24 = *(uint32_t *)(v13 + 76);
  *(uint16_t *)(v23 + 2) = v14;
  HIDWORD(v25) = v22 + *(uint8_t *)(v13 + 53) + 4;
  LODWORD(v25) = *(uint32_t *)(v24 + 28) - 1 + HIDWORD(v25);
  HIDWORD(v25) += 4;
  *(uint64_t *)(v24 + 32) = v25;
  ble_event_dispatch(v13, 5);
  
}

