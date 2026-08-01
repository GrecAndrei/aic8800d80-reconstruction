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

extern uint32_t off_11F9BC;
extern uint32_t off_11FA18;
extern uint32_t dword_11F9A4;
extern uint32_t off_11F9AC;
extern uint32_t off_11F9B0;
extern uint32_t off_11F9B4;
extern uint32_t off_11F9A8;
extern uint32_t dword_11F9B8;
extern uint32_t dword_11F9C0;
extern uint32_t dword_11F9C4;
extern uint32_t dword_11F9C8;
extern uint32_t dword_11F9CC;
extern uint32_t dword_11FA04;
extern uint32_t dword_11FA08;
extern uint32_t off_11F9D4;
extern uint32_t dword_11FA0C;
extern uint32_t off_11F9D0;
extern uint32_t off_11FA68;
extern uint32_t dword_11FA70;
extern uint32_t dword_11FA6C;
extern uint32_t off_11F9D8;
extern uint32_t dword_11FA74;
extern uint32_t dword_11FA10;
extern uint32_t dword_11FA14;
extern uint32_t off_11F9F8;
extern uint32_t dword_11FA00;
extern uint32_t dword_11F9FC;
extern uint32_t off_11F9DC;
extern uint32_t dword_11F9F4;
extern uint32_t dword_11F9F0;
extern uint32_t dword_11F9E0;
extern uint32_t off_11F9E4;
extern uint32_t dword_11F9EC;

// transmit_radio_packet @ 0x11f680, size 1000 bytes
int  transmit_radio_packet(int *a1, int a2, int a3, uint8_t *a4)
{
  uint8_t *v4; // r9
  int **v5; // r4
  int result; // r0
  int v7; // r0
  int v8; // r6
  int v9; // r7
  int v10; // r8
  int v11; // r11
  int *v12; // r5
  int v13; // r10
  uint32_t *v14; // r3
  uint32_t *v15; // r1
  uint32_t *v16; // r2
  int v17; // r0
  int v18; // r2
  int v19; // r4
  char v20; // r3
  int v21; // r3
  int v22; // r2
  int v23; // r3
  int v24; // r3
  uint32_t *v25; // r5
  int v26; // r1
  int v27; // r2
  int v28; // r0
  int v29; // r5
  int v30; // r0
  int v31; // r3
  uint32_t *v32; // r3
  int v33; // zf
  int v34; // r0
  int v35; // r1
  int v36; // r0
  int16_t **v37; // r3
  char v38; // r2
  int v39; // r5
  int v40; // r3
  int v41; // r6
  int *v42; // r5
  int v43; // r3
  int v44; // r2
  int v45; // r2
  int v46; // r2
  int v47; // r0
  int v52; // [sp+20h] [bp-1Ch]
  int v53; // [sp+24h] [bp-18h]
  uint8_t v54; // [sp+2Bh] [bp-11h] BYREF
  uint32_t v55[4]; // [sp+2Ch] [bp-10h] BYREF

  v4 = off_11F9BC;
  if ( !*(uint32_t *)off_11F9BC )
    return 1;
  if ( a3 )
  {
    if ( a2 == 2 && *(uint8_t *)off_11FA18 )
      return 1;
    v5 = *((int ***)off_11F9BC + 2);
    if ( v5 )
    {
      if ( *((uint8_t *)off_11F9BC + 19) == 2 )
        return 1;
      goto LABEL_8;
    }
LABEL_52:
    rf_init(a1);
    goto LABEL_11;
  }
  v5 = *((int ***)off_11F9BC + 2);
  if ( !v5 )
    goto LABEL_52;
LABEL_8:
  v7 = dword_11F9A4;
  v8 = *a1;
  v52 = *a1;
  v9 = 0;
  v53 = *((uint16_t *)a1 + 2);
  v10 = 0;
  v11 = v53;
  do
  {
    v12 = v5[25];
    v13 = *((uint16_t *)v5 + 52);
    alloc_tx_event(v7, v12, v13);
    v5 = (int **)*v5;
    v7 = dword_11F9A4;
    v10 |= (unsigned int)v12 ^ v8;
    v8 &= (unsigned int)v12;
    v9 |= v13 ^ v11;
    v11 &= v13;
  }
  while ( v5 );
  v14 = off_11F9AC;
  v15 = off_11F9B0;
  v16 = off_11F9B4;
  *(uint32_t *)off_11F9A8 = v9 | 0x300;
  *v14 = v10;
  *v15 = v52;
  *v16 = v53;
  alloc_tx_event(dword_11F9B8, v52, v53);
LABEL_11:
  v17 = list_pop(off_11F9BC);
  v18 = dword_11F9C0;
  *(uint8_t *)(v17 + 106) = a2;
  v19 = v17;
  v20 = dword_11F9C4;
  *(uint32_t *)(v17 + 100) = *a1;
  *(uint16_t *)(v17 + 104) = *((uint16_t *)a1 + 2);
  v21 = (uint8_t)(v20 * ((v17 - v18) >> 3));
  *(uint8_t *)(v17 + 1224) = a3;
  v22 = dword_11F9C8;
  *(uint32_t *)(v17 + 12) = 2627;
  *(uint32_t *)(v17 + 16) = v22;
  *(uint32_t *)(v17 + 20) = dword_11F9CC;
  *(uint16_t *)(v17 + 1222) = 1023;
  *(uint32_t *)(v17 + 8) = 2631;
  *(uint8_t *)(v17 + 107) = v21;
  *(uint8_t *)(v17 + 84) = v21;
  *(uint8_t *)(v17 + 109) = 127;
  *(uint8_t *)(v17 + 110) = 127;
  *(uint32_t *)(v17 + 72) = 0;
  *(uint8_t *)(v17 + 140) = 0;
  if ( a2 == 2 )
  {
    v38 = v4[18];
    if ( v38 )
    {
      v39 = a3;
    }
    else
    {
      rf_irq_enable(2631, 127);
      v38 = v4[18];
      v21 = *(uint8_t *)(v19 + 107);
      v39 = *(uint8_t *)(v19 + 1224);
    }
    v40 = dword_11FA04 + 696 * (v21 + 32);
    v4[18] = v38 + 1;
    *(uint8_t *)(v40 + 37) = 1;
    if ( v39 )
    {
      *(uint32_t *)(v19 + 28) = dword_11FA08;
      *(uint32_t *)(v19 + 32) = v19;
    }
    rf_chan_load(v19);
    v23 = (uint8_t)v4[17];
  }
  else if ( a2 == 4 )
  {
    if ( (uint8_t)v4[16] != 255 )
      return 1;
    v41 = *((uint32_t *)v4 + 2);
    v4[16] = v21;
    if ( v41 )
    {
      v42 = (int *)off_11F9D4;
      v43 = dword_11FA0C;
      v44 = **(int16_t **)off_11F9D0;
      *(uint32_t *)off_11F9D4 = dword_11FA0C;
      if ( v44 < 0 && *(uint32_t *)off_11FA68 << 28 )
      {
        mmio_write_field(dword_11FA70, dword_11FA6C, 472);
        v43 = *v42;
      }
      v45 = *(uint32_t *)(v41 + 72);
      *(uint32_t *)off_11F9D8 = v43 | v42[1];
      if ( v45 )
        bsscfg_current(*(uint8_t *)(v45 + 24));
      v23 = (uint8_t)v4[17];
    }
    else
    {
      v55[0] = dword_11FA74;
      v55[1] = 2437;
      rf_set_power_off(2631, 127);
      if ( cfm_radio_check(v55, &v54) )
        return 1;
      v47 = v54;
      *(uint32_t *)(v19 + 4) |= 0x80u;
      bsscfg_current(v47);
      v23 = (uint8_t)v4[17];
    }
  }
  else
  {
    v23 = (uint8_t)v4[17];
    if ( !a2 )
    {
      *(uint32_t *)(v17 + 28) = dword_11FA10;
      v46 = dword_11FA14;
      *(uint32_t *)(v17 + 32) = v17;
      v23 = (uint8_t)(v23 + 1);
      *(uint16_t *)(v17 + 146) = 0;
      *(uint32_t *)(v17 + 160) = v17;
      v4[17] = v23;
      *(uint8_t *)(v17 + 116) = -1;
      *(uint32_t *)(v17 + 156) = v46;
    }
  }
  v24 = v23 + (uint8_t)v4[18];
  if ( v24 > 1 || v4[18] )
  {
    v25 = off_11F9D4;
    v26 = **(int16_t **)off_11F9D0;
    v27 = *((uint32_t *)off_11F9D4 + 1) | 0x100;
    *((uint32_t *)off_11F9D4 + 1) = v27;
    if ( v26 < 0 && *(uint32_t *)off_11F9F8 << 28 )
    {
      mmio_write_field(dword_11FA00, dword_11F9FC, 472);
      v27 = v25[1];
      v24 = (uint8_t)v4[17] + (uint8_t)v4[18];
    }
    *(uint32_t *)off_11F9D8 = v27 | *v25;
  }
  if ( v24 == 1 )
    *(uint32_t *)off_11F9DC |= 1u;
  if ( a3 )
  {
    v34 = *(uint8_t *)(v19 + 107);
    v35 = a2;
    if ( a2 )
      v35 = 1;
    ++v4[19];
    v36 = bt_is_ready(v34, v35);
    v37 = (int16_t **)off_11F9D0;
    *(uint8_t *)(v19 + 1225) = v36;
    if ( **v37 < 0 && v36 == 255 )
      irq_disable_mmio_write(dword_11F9F4, dword_11F9F0, 498);
  }
  v28 = dword_11F9E0;
  *a4 = *(uint8_t *)(v19 + 107);
  wlan_ioctl_handler_1(v28);
  v29 = v19 + 1232;
  do
  {
    clear_stats_buf(v29);
    v30 = v29 + 40;
    v29 += 8;
    clear_stats_buf(v30);
  }
  while ( v29 != v19 + 1272 );
  clear_stats_buf(v19 + 1312);
  v31 = (uint8_t)v4[17] + (uint8_t)v4[18];
  *(uint32_t *)off_11F9E4 = 0;
  if ( v31 <= 1 )
    get_current_channel();
  check_feature_flag(256, dword_11F9EC);
  v32 = (uint32_t *)((uint8_t)v4[18] + (uint8_t)v4[17]);
  v33 = v32 == (uint32_t *)1;
  if ( v32 == (uint32_t *)1 )
    v32 = off_11F9A8;
  result = 0;
  if ( v33 )
    *v32 = 0;
  return result;
}

