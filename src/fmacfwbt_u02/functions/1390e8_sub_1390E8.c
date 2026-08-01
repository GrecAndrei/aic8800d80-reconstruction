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

extern uint32_t off_139388;
extern uint32_t dword_13938C;
extern uint32_t dword_139398;
extern uint32_t off_1393A0;
extern uint32_t dword_1393A8;
extern uint32_t dword_1393A4;
extern uint32_t off_139390;
extern uint32_t dword_139394;
extern uint32_t dword_13939C;

// rf_cal_handle_cmd @ 0x1390e8, size 672 bytes
int  rf_cal_handle_cmd(unsigned int a1, int a2, int a3)
{
  uint16_t *v3; // r6
  char v5; // r5
  int v7; // r10
  int v8; // r9
  int v9; // r7
  uint32_t *v10; // r4
  int v11; // r2
  int16_t v13; // r2
  char v14; // r1
  uint32_t *v15; // r3
  int v16; // r1
  int v17; // r3
  uint64_t v18; // r2
  int v19; // r0
  int v20; // r0
  unsigned int v21; // r5
  int16_t v22; // r3
  int16_t v23; // r6
  int16_t v24; // r1
  uint32_t *v25; // r0
  int v26; // r3
  uint32_t *v27; // r0
  uint8_t v28[24]; // [sp+8h] [bp-18h] BYREF

  v3 = off_139388;
  v5 = a2;
  if ( a3 )
  {
    v7 = *((uint8_t *)off_139388 + 7);
    v8 = *(uint16_t *)off_139388 & 0x400;
    if ( (*(uint16_t *)off_139388 & 0x400) == 0 )
      goto LABEL_3;
LABEL_14:
    v10 = *((uint32_t **)off_139388 + 22);
    v11 = *((uint16_t *)off_139388 + 2);
    v9 = *((uint8_t *)off_139388 + 6);
    if ( v10 )
      goto LABEL_7;
LABEL_15:
    if ( v9 )
      return 0;
    v10 = list_pop_front(dword_13938C);
    if ( !v10 )
    {
      v27 = list_pop_front(dword_139398);
      v10 = v27;
      if ( **(int16_t **)off_1393A0 < 0 && !v27 )
        mmio_irq_clear(dword_1393A8, dword_1393A4, 1111);
      tx_power_cal_read(0, 4, v10[5]);
    }
    v13 = v3[2];
    *((uint8_t *)v10 + 6) = v5;
    *((uint8_t *)v10 + 7) = v7;
    *((uint8_t *)v10 + 8) = 1;
    *((uint8_t *)v10 + 4) = 0;
    v14 = *((uint8_t *)v3 + 8);
    v15 = off_139390;
    v10[4] = 0;
    *((uint8_t *)v10 + 9) = v14;
    v16 = v15[4];
    v17 = dword_139394;
    *((uint16_t *)v10 + 5) = v13;
    v10[14] = v17;
    v10[15] = v10;
    ke_event_lock((int)(v10 + 13), v16 + 100000);
    if ( (v3[24] & 1) != 0 )
      rf_cal_process(a1, (int)(v10 + 7), 1, 0);
    *(uint32_t *)(a1 + 96) &= ~0x20u;
    rf_cal_freq_from_channel(a1, 1);
    HIDWORD(v18) = *((uint32_t *)v3 + 16);
    LODWORD(v18) = *((uint32_t *)v3 + 7);
    v19 = dword_139398;
    *((uint64_t *)v10 + 2) = v18;
    *((uint8_t *)v10 + 5) = *((uint8_t *)v3 + 49);
    *((uint16_t *)v10 + 6) = *(uint16_t *)(a1 + 48);
    check_abort_flag(v19, v10);
    goto LABEL_20;
  }
  v8 = *(uint16_t *)off_139388 & 0x400;
  v7 = 0;
  if ( (*(uint16_t *)off_139388 & 0x400) != 0 )
    goto LABEL_14;
LABEL_3:
  v9 = *((uint8_t *)off_139388 + 6);
  if ( *((uint8_t *)off_139388 + 6) )
  {
    v10 = *((uint32_t **)off_139388 + 22);
    v11 = *((uint16_t *)off_139388 + 2);
    if ( !v10 )
      return *((uint32_t *)off_139388 + 22);
LABEL_7:
    while ( *((uint8_t *)v10 + 6) != a2
         || *((uint8_t *)v10 + 7) != v7
         || *((uint16_t *)v10 + 5) != v11 )
    {
      v10 = (uint32_t *)*v10;
      if ( !v10 )
        goto LABEL_15;
    }
    if ( *((uint8_t *)v10 + 8) != v9 )
      return 0;
    v21 = (uint16_t)(*(uint16_t *)(a1 + 48) - *((uint8_t *)v10 + 9));
    v22 = *((uint16_t *)v10 + 6) + v21;
    *((uint8_t *)v10 + 8) = v9 + 1;
    *((uint16_t *)v10 + 6) = v22;
    if ( (v3[24] & 1) != 0 )
    {
      if ( rf_cal_process(a1, (int)(v10 + 7), 0, v8 == 0) )
      {
        v26 = *(uint32_t *)(a1 + 96);
        if ( !v8 )
        {
          *((uint16_t *)v10 + 6) -= 8;
          *(uint32_t *)(a1 + 96) = v26 & 0xFFFFFF9F | 0x40;
          tx_packet_setup(a1, v21, v10[4], *((uint8_t *)v10 + 9), 0, 0);
          v10[4] += v21;
          v23 = 1;
          goto LABEL_30;
        }
        *(uint32_t *)(a1 + 96) = v26 & 0xFFFFFF9F | 0x40;
        tx_packet_setup(a1, v21, v10[4], *((uint8_t *)v10 + 9), 0, 0);
        v10[4] += v21;
LABEL_20:
        v10[6] = *((uint32_t *)off_139390 + 4);
        return 1;
      }
      v23 = 4;
    }
    else
    {
      v23 = 1;
    }
    *(uint32_t *)(a1 + 96) = *(uint32_t *)(a1 + 96) & 0xFFFFFF9F | 0x40;
    tx_packet_setup(a1, v21, v10[4], *((uint8_t *)v10 + 9), 0, 0);
    v10[4] += v21;
    if ( !v8 )
    {
LABEL_30:
      if ( *((uint8_t *)v10 + 5) )
        v24 = 24;
      else
        v24 = 8;
      v25 = tx_power_cal_read(0, v24, v10[5]);
      if ( v25 )
        v25[18] = *((uint16_t *)v10 + 6);
      tx_power_cal_read(0, v23, v10[5]);
      ke_event_set_lock((int)(v10 + 13));
      check_abort_flag_3(dword_139398, v10);
      check_abort_flag(dword_13938C, v10);
      goto LABEL_20;
    }
    goto LABEL_20;
  }
  if ( (*((uint8_t *)off_139388 + 48) & 1) != 0 )
  {
    if ( !rf_cal_process(a1, (int)v28, 1, 1) )
      return v9;
    *(uint16_t *)(a1 + 48) -= 8;
  }
  v20 = dword_13939C + 1320 * *((uint8_t *)v3 + 10);
  if ( *(uint8_t *)(v20 + 1227)
    && rate_to_phy_mode((uint8_t *)(v20 + 107), (uint32_t *)(v20 + 1228), *(char **)(*(uint32_t *)(a1 + 28) + 8), a3) == 1 )
  {
    return v9;
  }
  rf_cal_freq_from_channel(a1, 3);
  return 1;
}

