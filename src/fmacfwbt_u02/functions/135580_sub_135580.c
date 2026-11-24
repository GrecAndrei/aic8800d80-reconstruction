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


extern uint32_t dword_13575C;
extern uint32_t dword_13576C;
extern uint32_t dword_13577C;
extern uint32_t off_135750;
extern uint32_t off_135760;
extern uint32_t off_135764;
extern uint32_t off_135768;
extern uint32_t off_135770;
extern uint32_t off_135778;

// rf_lookup_alt_by_index @ 0x135580, size 462 bytes
int rf_lookup_alt_by_index()
{
  int v0; // r8
  int v1; // r9
  int v2; // r6
  uint8_t *v3; // r4
  int v4; // r11
  int v5; // r0
  uint32_t *v6; // r4
  uint8_t *v7; // r7
  int v8; // r10
  int v9; // r5
  uint16_t v10; // r3
  uint16_t *v11; // r2
  int v12; // r1
  int v13; // r11
  int v14; // t1
  int v15; // lr
  uint16_t v16; // r3
  int v17; // r6
  uint16_t v18; // r12
  uint16_t *v19; // r7
  int v20; // r3
  int v21; // r0
  uint32_t *v22; // r1
  int v23; // r2
  int v24; // cc
  int v25; // r2
  int v26; // r0
  int v27; // r3
  int v28; // r0
  uint8_t *v29; // r4
  unsigned int a3; // [sp+14h] [bp-10h]
  unsigned int a3a; // [sp+14h] [bp-10h]
  uint16_t a6; // [sp+1Ah] [bp-Ah] BYREF
  int a5; // [sp+1Ch] [bp-8h] BYREF

  v0 = dword_13577C;
  v1 = *((uint32_t *)off_135750 + 4);
  v2 = *(uint8_t *)(v1 + 61);
  v3 = (uint8_t *)(dword_13577C + 1320 * v2);
  v4 = v3[116];
  state_check_feature(256, "%s\r\n", aSmAssocReqSend);
  if ( !v3[1224] )
  {
    v5 = v3[412];
    if ( v3[412] )
      v5 = 1;
    v6 = event_notify(v5, 512);
    if ( v6 )
      goto LABEL_5;
    return event_dispatch_1(1);
  }
  v6 = event_notify(1, 512);
  if ( !v6 )
    return event_dispatch_1(1);
LABEL_5:
  v7 = off_135750;
  a3 = 1320 * v2;
  v8 = *((uint32_t *)off_135750 + 5);
  scan_done_check(v0 + 1320 * v2, (int)v6);
  v9 = v6[18];
  v10 = (uint8_t)v7[33];
  if ( v7[33] )
  {
    v11 = (uint16_t *)dword_13576C;
    v10 = 32;
  }
  else
  {
    v11 = nullptr;
  }
  v12 = dword_13575C;
  *(uint16_t *)(v9 + 108) = v10;
  v13 = v12 + 696 * v4;
  v14 = *(uint32_t *)(v13 + 38);
  v13 += 38;
  v15 = *(uint32_t *)v13;
  v16 = *((uint16_t *)off_135760 + 254);
  *(uint32_t *)(v9 + 112) = v14;
  v17 = v0 + 1320 * v2;
  *(uint16_t *)(v9 + 116) = *(uint16_t *)(v13 + 4);
  v18 = *(uint16_t *)(v13 + 4);
  *(uint32_t *)(v9 + 118) = *(uint32_t *)(v17 + 100);
  *(uint16_t *)(v9 + 122) = *(uint16_t *)(v17 + 104);
  ++v16;
  v19 = off_135760;
  *(uint32_t *)(v9 + 124) = v15;
  *(uint16_t *)(v9 + 128) = v18;
  *(uint8_t *)(v9 + 110) = 0;
  *(uint8_t *)(v9 + 111) = 0;
  LOWORD(v15) = 16 * v16;
  v19[254] = v16;
  v20 = *(uint8_t *)(v17 + 107);
  *(uint16_t *)(v9 + 130) = v15;
  v21 = rf_calc_tx_power_offset((uint8_t *)(v9 + 132), a3 + 248 + v0, v11, v20, &a5, &a6, v1);
  *((uint8_t *)v6 + 28) = *(uint8_t *)(v17 + 107);
  v22 = (uint32_t *)v6[19];
  *((uint8_t *)v6 + 29) = *(uint8_t *)(v17 + 116);
  v23 = a6;
  v24 = a6 > 0x320u;
  v22[8] = v22[7] + 23 + v21;
  v22[9] = v21 + 28;
  if ( v24 )
  {
    if ( **(uint16_t **)off_135770 < 0 )
      mmio_field_update(off_135778, (int)aSmAssocReqSend_0, 1115);
    *(uint16_t *)(v8 + 14) = 0;
  }
  else
  {
    if ( v23 )
    {
      v25 = v23 + v8 + 19;
      v26 = a5 - 19 - v8;
      v27 = v8 + 19;
      do
      {
        *(uint8_t *)(v27 + 1) = *(uint8_t *)(v26 + v27);
        ++v27;
      }
      while ( v27 != v25 );
      LOWORD(v23) = a6;
    }
    *(uint16_t *)(v8 + 14) = v23;
  }
  v28 = (int)v6;
  a3a = *(uint32_t *)(*(uint32_t *)off_135764 + 8);
  v6[22] = off_135768;
  v6[23] = v6;
  v29 = off_135750;
  ble_event_dispatch(v28, 5);
  v29[34] = 1;
  patch_aware_dispatch(6154, 6, a3a);
  return hci_cmd_send(6u, 8);
}
