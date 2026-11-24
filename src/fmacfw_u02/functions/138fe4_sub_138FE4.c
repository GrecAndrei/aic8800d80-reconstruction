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


extern uint32_t dword_139288;
extern uint32_t dword_139294;
extern uint32_t dword_139298;
extern uint32_t off_139284;
extern uint32_t off_139290;
extern uint32_t off_13929C;

// ll_rx_irq @ 0x138fe4, size 672 bytes
int  ll_rx_irq(int a1, int a2, int a3)
{
  uint16_t *v3; // r6
  char v5; // r5
  int v7; // r10
  int v8; // r9
  int v9; // r7
  uint32_t *v10; // r4
  int v11; // r2
  uint16_t v13; // r2
  char v14; // r1
  volatile unsigned int v15; // r1
  void *v16; // r3
  uint64_t v17; // r2
  int v18; // r0
  volatile unsigned int v19; // r3
  int v20; // r0
  int v21; // r5
  uint16_t v22; // r3
  uint16_t v23; // r6
  uint16_t v24; // r1
  int v25; // r0
  int v26; // r3
  uint32_t *v27; // r0
  uint64_t a2a[3]; // [sp+8h] [bp-18h] BYREF

  v3 = off_139284;
  v5 = a2;
  if ( a3 )
  {
    v7 = *((uint8_t *)off_139284 + 7);
    v8 = *(uint16_t *)off_139284 & 0x400;
    if ( (*(uint16_t *)off_139284 & 0x400) == 0 )
      goto LABEL_3;
LABEL_14:
    v10 = *((uint32_t **)off_139284 + 22);
    v11 = *((uint16_t *)off_139284 + 2);
    v9 = *((uint8_t *)off_139284 + 6);
    if ( v10 )
      goto LABEL_7;
LABEL_15:
    if ( v9 )
      return 0;
    v10 = mem_word_load(dword_139288);
    if ( !v10 )
    {
      v27 = mem_word_load(dword_139294);
      v10 = v27;
      if ( **(uint16_t **)off_13929C < 0 && !v27 )
        mmio_clear_register((int)aDefragNull, (int)aRxuCntrlDefrag, 1111);
      tx_power_lookup(0, 4, v10[5]);
    }
    v13 = v3[2];
    *((uint8_t *)v10 + 6) = v5;
    *((uint8_t *)v10 + 7) = v7;
    *((uint8_t *)v10 + 8) = 1;
    *((uint8_t *)v10 + 4) = 0;
    v14 = *((uint8_t *)v3 + 8);
    v10[4] = 0;
    *((uint8_t *)v10 + 9) = v14;
    v15 = (*(volatile uint32_t *)0x40501010u);
    v16 = off_139290;
    *((uint16_t *)v10 + 5) = v13;
    v10[14] = v16;
    v10[15] = v10;
    unknown_worker(v10 + 13, v15 + 100000);
    if ( (v3[24] & 1) != 0 )
      ll_state_machine_1(a1, v10 + 7, 1, 0);
    *(uint32_t *)(a1 + 96) &= ~0x20u;
    rf_get_rssi_3(a1, 1);
    HIDWORD(v17) = *((uint32_t *)v3 + 16);
    LODWORD(v17) = *((uint32_t *)v3 + 7);
    v18 = dword_139294;
    *((uint64_t *)v10 + 2) = v17;
    *((uint8_t *)v10 + 5) = *((uint8_t *)v3 + 49);
    *((uint16_t *)v10 + 6) = *(uint16_t *)(a1 + 48);
    cmd_handler_a(v18, v10);
    goto LABEL_20;
  }
  v8 = *(uint16_t *)off_139284 & 0x400;
  v7 = 0;
  if ( (*(uint16_t *)off_139284 & 0x400) != 0 )
    goto LABEL_14;
LABEL_3:
  v9 = *((uint8_t *)off_139284 + 6);
  if ( *((uint8_t *)off_139284 + 6) )
  {
    v10 = *((uint32_t **)off_139284 + 22);
    v11 = *((uint16_t *)off_139284 + 2);
    if ( !v10 )
      return *((uint32_t *)off_139284 + 22);
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
      if ( ll_state_machine_1(a1, v10 + 7, 0, v8 == 0) )
      {
        v26 = *(uint32_t *)(a1 + 96);
        if ( !v8 )
        {
          *((uint16_t *)v10 + 6) -= 8;
          *(uint32_t *)(a1 + 96) = v26 & 0xFFFFFF9F | 0x40;
          mac_mcps_request(a1, v21, v10[4], *((uint8_t *)v10 + 9), 0, 0);
          v10[4] += v21;
          v23 = 1;
          goto LABEL_30;
        }
        *(uint32_t *)(a1 + 96) = v26 & 0xFFFFFF9F | 0x40;
        mac_mcps_request(a1, v21, v10[4], *((uint8_t *)v10 + 9), 0, 0);
        v10[4] += v21;
LABEL_20:
        v19 = (*(volatile uint32_t *)0x40501010u);
        v10[6] = v19;
        return 1;
      }
      v23 = 4;
    }
    else
    {
      v23 = 1;
    }
    *(uint32_t *)(a1 + 96) = *(uint32_t *)(a1 + 96) & 0xFFFFFF9F | 0x40;
    mac_mcps_request(a1, v21, v10[4], *((uint8_t *)v10 + 9), 0, 0);
    v10[4] += v21;
    if ( !v8 )
    {
LABEL_30:
      if ( *((uint8_t *)v10 + 5) )
        v24 = 24;
      else
        v24 = 8;
      v25 = tx_power_lookup(0, v24, v10[5]);
      if ( v25 )
        *(uint32_t *)(v25 + 72) = *((uint16_t *)v10 + 6);
      tx_power_lookup(0, v23, v10[5]);
      fault_handler(v10 + 13);
      cmd_handler_c(dword_139294, v10);
      cmd_handler_a(dword_139288, v10);
      goto LABEL_20;
    }
    goto LABEL_20;
  }
  if ( (*((uint8_t *)off_139284 + 48) & 1) != 0 )
  {
    if ( !ll_state_machine_1(a1, a2a, 1, 1) )
      return v9;
    *(uint16_t *)(a1 + 48) -= 8;
  }
  v20 = dword_139298 + 1320 * *((uint8_t *)v3 + 10);
  if ( *(uint8_t *)(v20 + 1227)
    && phy_config_set(
         (uint8_t *)(v20 + 107),
         (uint32_t *)(v20 + 1228),
         *(uint32_t *)(*(uint32_t *)(a1 + 28) + 8),
         a3) == 1 )
  {
    return v9;
  }
  rf_get_rssi_3(a1, 3);
  return 1;
}
