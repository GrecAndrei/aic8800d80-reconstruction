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

extern uint32_t off_133644;
extern uint32_t dword_1337B0;
extern uint32_t off_133628;
extern uint32_t dword_133640;
extern uint32_t dword_13363C;
extern uint32_t dword_133648;
extern uint32_t dword_133630;
extern uint32_t dword_13362C;
extern uint32_t dword_133638;
extern uint32_t dword_133634;

// rf_calibrate_init @ 0x1331d4, size 1500 bytes
uint8_t * rf_calibrate_init(int a1, int16_t a2, unsigned int a3)
{
  int v4; // r3
  int v5; // r6
  int v6; // r0
  int v7; // r7
  int *v8; // r4
  unsigned int v9; // r8
  uint8_t *v10; // r9
  uint16_t v11; // r11
  int v12; // r6
  uint8_t *v13; // r11
  uint8_t *v14; // s17
  int v15; // r2
  int v16; // r1
  uint8_t *result; // r0
  int v18; // r6
  int v19; // r3
  int v20; // r1
  int16_t v21; // r3
  int v22; // r9
  int16_t **v23; // r10
  int v24; // r0
  int v25; // r2
  int16_t v26; // r3
  int v27; // r1
  unsigned int v28; // r3
  unsigned int v29; // r6
  int v30; // r2
  int v31; // r2
  char v32; // r12
  int v33; // r3
  char v34; // r0
  int v35; // r1
  char v36; // r2
  int v37; // r3
  char v38; // r0
  int v39; // r0
  int v40; // r1
  char v41; // r0
  int v42; // r2
  char v43; // lr
  int v44; // r0
  char v45; // r2
  int v46; // r1
  char v47; // lr
  int v48; // r11
  int *v49; // r4
  int v50; // r0
  int v51; // t1
  uint8_t *v52; // r0
  char v53; // r2
  int16_t v54; // r3
  uint8_t *v55; // r0
  unsigned int v56; // r3
  int v57; // r3
  int v58; // r0
  int *v59; // r0
  unsigned int v60; // r2
  int v61; // r3
  int v62; // r3
  uint8_t *v63; // r0
  int v64; // r0
  uint64_t v65; // kr00_8
  unsigned int v66; // [sp+4h] [bp-20h]
  int v67; // [sp+8h] [bp-1Ch]
  uint8_t *v68; // [sp+Ch] [bp-18h]
  int v69; // [sp+Ch] [bp-18h]
  int *v70; // [sp+Ch] [bp-18h]
  int v72; // [sp+14h] [bp-10h]
  uint8_t *v73; // [sp+14h] [bp-10h]
  uint8_t v74[5]; // [sp+1Fh] [bp-5h] BYREF

  v4 = *(uint32_t *)(a1 + 468);
  v5 = *(uint8_t *)(a1 + 464);
  v6 = *(uint8_t *)(a1 + 412);
  v7 = *(uint16_t *)(a1 + 462);
  v8 = *(int **)(a1 + 240);
  v9 = *(uint8_t *)(a1 + 413);
  v67 = v5;
  *(uint16_t *)(a1 + 462) = 0;
  v66 = v4 & 0xFF000000;
  v10 = (uint8_t *)(a3 + 36);
  v11 = a2 - 36;
  if ( v6 )
    goto LABEL_2;
  v12 = v11;
  v52 = memmove_2(v10, v11);
  if ( !v52 )
    goto LABEL_2;
  v53 = v52[2];
  v54 = *(uint16_t *)(a1 + 462) & 0xFFF8;
  if ( (v53 & 1) != 0 )
    v54 |= 1u;
  *(uint16_t *)(a1 + 462) = v54;
  if ( (v53 & 4) != 0 )
    *(uint16_t *)(a1 + 462) |= 4u;
  else
LABEL_2:
    v12 = v11;
  if ( (*(uint32_t *)(a1 + 472) & 1) != 0 )
  {
    v48 = *(uint8_t *)(a1 + 106);
    if ( !*(uint8_t *)(a1 + 106) )
    {
      rf_get_cal_status(v10, v12, a1 + 440, v74);
      if ( v74[0] )
      {
        v70 = v8;
        v49 = (int *)(a1 + 440);
        do
        {
          v50 = bt_buf_alloc(26, 0, 5, 8u);
          v51 = *v49++;
          *(uint32_t *)v50 = v51;
          *(uint8_t *)(v50 + 5) = v48;
          *(uint8_t *)(v50 + 6) = *(uint8_t *)(a1 + 107);
          ++v48;
          *(uint8_t *)(v50 + 4) = 0;
          hci_evt_send(v50);
        }
        while ( v48 != 4 );
        v8 = v70;
      }
    }
  }
  v13 = off_133644;
  if ( (*((uint8_t *)off_133644 + 374) & 1) == 0 )
  {
    v14 = (uint8_t *)(*((uint8_t *)off_133644 + 374) & 1);
    v68 = v14;
LABEL_6:
    llm_adv_reset((int)v14, v68, a1 + 248);
    goto LABEL_7;
  }
  v14 = parse_data_8(v10, v12);
  if ( (v13[374] & 6) != 0 )
  {
    v68 = parse_data_9(v10, v12);
    if ( !*(uint8_t *)(a1 + 106) )
    {
      v63 = memmove_3(v10, v12);
      if ( v63
        && (*(uint32_t *)(dword_1337B0 + 696 * *(uint8_t *)(a1 + 116) + 4) & 0x24) != 0
        && (v63[2] & 0x80u) == 0 )
      {
        rf_config_chan_table(*(uint8_t *)(a1 + 116), v63[2] & 3);
      }
      if ( (*(uint32_t *)(a1 + 472) & 8) != 0 )
      {
        v73 = (uint8_t *)bt_buf_alloc(109, 0, 5, 2u);
        rf_phy_unpack(v10, v12, v73);
        hci_evt_send((int)v73);
        rf_get_cal_status2(v10, v12, a1 + 348, v74);
        if ( v74[0] )
        {
          v64 = bt_buf_alloc(107, 0, 5, 0x10u);
          v65 = *(uint64_t *)(a1 + 352);
          *(uint32_t *)v64 = *(uint32_t *)(a1 + 348);
          *(uint32_t *)(v64 + 12) = *(uint32_t *)(a1 + 360);
          *(uint64_t *)(v64 + 4) = v65;
          hci_evt_send(v64);
        }
      }
    }
    if ( (v13[374] & 4) == 0 )
      goto LABEL_6;
    v55 = rf_set_cal_u32_dc(v10, v12, a1 + 248);
    if ( v55 )
    {
      v56 = *(uint32_t *)(a1 + 468);
      v72 = (v56 >> 4) & 0x3FF;
      if ( *(uint8_t *)(a1 + 106) == 2 )
      {
        v57 = v56 | 0x10000;
        *(uint32_t *)(a1 + 468) = v57;
        *(uint32_t *)(v55 + 3) = v57;
      }
      if ( !v72 )
        goto LABEL_102;
    }
    else
    {
      LOWORD(v72) = 1023;
    }
    v58 = bt_buf_alloc(111, 0, 5, 4u);
    *(uint16_t *)v58 = v72;
    *(uint8_t *)(v58 + 2) = *(uint8_t *)(a1 + 107);
    hci_evt_send(v58);
LABEL_102:
    if ( (*(uint32_t *)(a1 + 468) & 0xFF000000) != v66 )
    {
      v59 = (int *)bt_buf_alloc(113, 0, 5, 4u);
      v60 = *(uint32_t *)(a1 + 468);
      v61 = HIBYTE(v60) & 0x3F;
      if ( (v60 & 0x40000000) != 0 )
        v62 = v61 | 0x300;
      else
        v62 = v61 | 0x100;
      *v59 = v62;
      hci_evt_send((int)v59);
    }
    goto LABEL_6;
  }
  llm_adv_reset((int)v14, 0, a1 + 248);
LABEL_7:
  v15 = (uint8_t)rf_parse_cal_entry(v10, v12, v74, a1 + 1212);
  if ( v15 )
  {
    if ( *(uint8_t *)(a1 + 106) )
    {
      if ( *(uint8_t *)(a1 + 106) == 2 )
        *(uint8_t *)(a1 + 231) = v15;
    }
    else
    {
      v16 = *(uint8_t *)(a1 + 146);
      if ( *(uint8_t *)(a1 + 146)
        || *(uint8_t *)(a1 + 148)
        && v74[0] == 1
        && (v69 = v15,
            mmio_write_phy(*(uint8_t *)(a1 + 107), v16),
            v16 = *(uint8_t *)(a1 + 146),
            v15 = v69,
            *(uint8_t *)(a1 + 146)) )
      {
        if ( v15 != v16 )
          *(uint8_t *)(a1 + 148) = 1;
      }
      *(uint8_t *)(a1 + 146) = v15;
    }
  }
  result = rf_set_cal_byte_d8(v10, v12, a1 + 248);
  if ( *(uint8_t *)(a1 + 464) != v67 )
    result = (uint8_t *)scan_rssi_compare(a1);
  if ( *(uint8_t *)(a1 + 413) > v9 )
  {
    if ( !*(uint32_t *)(a1 + 72) )
      rx_packet_handler(a3, 32, 1, 0);
    v18 = bt_buf_alloc(59, 0, 5, 0xCu);
    v19 = *(uint32_t *)(a1 + 72);
    if ( **(int16_t **)off_133628 < 0 && !v19 )
    {
      mmio_irq_clear(dword_133640, dword_13363C, 70);
      v19 = *(uint32_t *)(a1 + 72);
    }
    *(uint8_t *)v18 = *(uint8_t *)(v19 + 24);
    v20 = *(uint32_t *)(a1 + 416);
    v21 = *(uint16_t *)(a1 + 420);
    *(uint32_t *)(v18 + 2) = *(uint32_t *)(a1 + 412);
    *(uint32_t *)(v18 + 6) = v20;
    *(uint16_t *)(v18 + 10) = v21;
    result = (uint8_t *)hci_evt_send(v18);
  }
  if ( v8 )
  {
    v22 = dword_133648;
    v23 = (int16_t **)off_133628;
    do
    {
      if ( *(uint16_t *)(a1 + 462) != v7 )
      {
        ke_event_schedule(v22, v7);
        v24 = *((uint8_t *)v8 + 35);
        v25 = *(uint16_t *)(a1 + 462) << 29;
        v26 = *((uint8_t *)v8 + 350) | 2;
        v27 = 0;
        *((uint8_t *)v8 + 350) = v26;
        if ( v25 >= 0 )
          v26 = 1024;
        v8[86] = 0;
        if ( v25 >= 0 )
        {
          *((uint16_t *)v8 + 174) = v26;
          v27 = 1;
        }
        else
        {
          *((uint16_t *)v8 + 174) = 0;
        }
        result = (uint8_t *)fetch_connection_params(v24, v27);
      }
      v28 = *(uint8_t *)(a1 + 413);
      if ( v28 == v9 )
        goto LABEL_48;
      v29 = *((uint8_t *)v8 + 308);
      if ( v28 == 4 )
      {
        if ( v29 <= 3 )
        {
          if ( v29 >= 2 )
            v29 = 2;
          goto LABEL_38;
        }
      }
      else
      {
        if ( v28 >= v29 )
          v28 = *((uint8_t *)v8 + 308);
        if ( v28 != 4 )
        {
          v29 = (uint8_t)v28;
          goto LABEL_38;
        }
      }
      v29 = 3;
LABEL_38:
      if ( *((uint8_t *)v8 + 309) != v29 )
      {
        v30 = v8[1];
        if ( (v30 & 0x20) != 0 )
        {
          if ( **v23 < 0 && (v13[374] & 4) == 0 )
            mmio_irq_clear(dword_133630, dword_13362C, 463);
          v31 = 14;
          v32 = 7;
          do
          {
            v33 = ((int)*((uint16_t *)v8 + 135) >> v31) & 3;
            v34 = v32 - 1;
            v31 -= 2;
            if ( v33 != 3 )
              break;
            --v32;
          }
          while ( v34 );
          v35 = 14;
          v36 = 7;
          do
          {
            v37 = ((int)*((uint16_t *)v13 + 40) >> v35) & 3;
            v38 = v36 - 1;
            v35 -= 2;
            if ( v37 != 3 )
              break;
            --v36;
          }
          while ( v38 );
        }
        else if ( (v30 & 4) != 0 )
        {
          if ( **v23 < 0 && (v13[374] & 2) == 0 )
            mmio_irq_clear(dword_133638, dword_13362C, 476);
          v40 = 14;
          v41 = 7;
          do
          {
            v42 = ((int)*((uint16_t *)v8 + 122) >> v40) & 3;
            v43 = v41 - 1;
            v40 -= 2;
            if ( v42 != 3 )
              break;
            --v41;
          }
          while ( v43 );
          v44 = 14;
          v45 = 7;
          do
          {
            v46 = ((int)*((uint16_t *)v13 + 28) >> v44) & 3;
            v47 = v45 - 1;
            v44 -= 2;
            if ( v46 != 3 )
              break;
            --v45;
          }
          while ( v47 );
        }
        else if ( **v23 < 0 && (v13[374] & 1) == 0 )
        {
          mmio_irq_clear(dword_133634, dword_13362C, 487);
        }
        v39 = *((uint8_t *)v8 + 35);
        *((uint8_t *)v8 + 309) = v29;
        result = (uint8_t *)get_connection_state(v39);
        *((uint8_t *)v8 + 350) |= 8u;
      }
LABEL_48:
      if ( (*(uint32_t *)(a1 + 468) & 0xFF000000) != v66 && (v8[1] & 0x20) != 0 )
        *((uint8_t *)v8 + 350) |= 0x40u;
      v8 = (int *)*v8;
    }
    while ( v8 );
  }
  return result;
}

