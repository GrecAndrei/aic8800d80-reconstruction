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

extern uint32_t off_11E6F8;
extern uint32_t off_11E6FC;
extern uint32_t off_11E71C;
extern uint32_t off_11E92C;
extern uint32_t off_11E930;
extern uint32_t dword_11E958;
extern uint32_t off_11E710;
extern uint32_t off_11E714;
extern uint32_t dword_11E720;
extern uint32_t off_11E724;
extern uint32_t dword_11E728;
extern uint32_t off_11E70C;
extern uint32_t off_11E700;
extern uint32_t off_11E918;
extern uint32_t dword_11E91C;
extern uint32_t dword_11E920;
extern uint32_t off_11E940;
extern uint32_t dword_11E718;
extern uint32_t off_11E704;
extern uint32_t off_11E944;
extern uint32_t off_11E948;
extern uint32_t dword_11E95C;
extern uint32_t dword_11E708;
extern uint32_t off_11E924;
extern uint32_t dword_11E928;
extern uint32_t off_11E934;
extern uint32_t off_11E938;
extern uint32_t off_11E93C;
extern uint32_t dword_11E950;
extern uint32_t dword_11E94C;
extern uint32_t dword_11E954;

// tx_packet_complete @ 0x11e4c4, size 1106 bytes
int  tx_packet_complete(int a1)
{
  int v1; // r8
  int v2; // r10
  int v3; // r11
  uint32_t *v4; // r6
  uint8_t **v5; // r5
  int16_t v6; // r2
  uint8_t *v7; // r3
  int v8; // r4
  int v9; // r3
  unsigned int v10; // r7
  int v11; // r3
  int *v12; // r6
  int v13; // r11
  int v14; // r3
  uint8_t v15; // r7
  int v16; // r4
  int v17; // r11
  int v18; // r3
  uint16_t *v19; // r6
  int v20; // r2
  int *v21; // r7
  int v22; // r0
  int v23; // r0
  int v24; // r1
  int v25; // r3
  int v26; // r2
  uint16_t *v28; // r7
  int *v29; // r9
  unsigned int v30; // r1
  int v31; // r0
  int v32; // r0
  int v33; // r12
  int v34; // r3
  uint32_t *v35; // r1
  uint8_t *v36; // r12
  int v37; // r0
  char v38; // r2
  int v39; // r0
  int v40; // r3
  int *v41; // r2
  int v42; // r3
  int v43; // r1
  int v44; // r3
  unsigned int CPSR; // r0
  uint32_t *v46; // r3
  uint32_t *v47; // r0
  int v48; // r1
  int v49; // r2
  uint32_t *v50; // r2
  uint32_t *v51; // r5
  uint32_t *v52; // r0
  int v53; // r1
  int v54; // r2
  int v55; // r7
  int v56; // r2
  int v57; // r12
  int v58; // r2
  uint8_t *v59; // r1
  char v60; // r2
  uint8_t *v61; // r3
  int v62; // r1
  int v63; // r0
  int v64; // r1
  int *v65; // r4
  int v66; // r0
  int v67; // r2
  int v68; // r3
  int v69; // r0
  int v70; // [sp+Ch] [bp-10h]
  int16_t v71; // [sp+12h] [bp-Ah] BYREF
  int v72[2]; // [sp+14h] [bp-8h] BYREF

  v4 = off_11E6F8;
  v5 = (uint8_t **)off_11E6FC;
  v6 = *((uint8_t *)off_11E6F8 + 50);
  v7 = *(uint8_t **)off_11E6FC;
  v8 = a1;
  v72[0] = *(uint32_t *)(a1 + 28);
  v71 = v6;
  v9 = *v7;
  if ( v9 == 3 )
  {
    v2 = list_foreach();
    v9 = **v5;
    v3 = v2 + 60;
  }
  if ( v9 == 2 )
  {
    v28 = off_11E71C;
    if ( !*((uint32_t *)off_11E71C + 2057) )
    {
      v62 = v72[0];
      *(uint8_t *)(v8 + 16) |= 1u;
      v63 = ble_get_rssi(v8, v62);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_11E92C = 1;
      }
      v65 = (int *)off_11E930;
      ++*(uint32_t *)off_11E930;
      v66 = rf_is_idle(v63, v64);
      if ( *v65 )
      {
        v68 = *v65 - 1;
        v67 = *(uint32_t *)off_11E92C;
        *v65 = v68;
        if ( !v68 )
        {
          if ( v67 )
            __enable_irq();
        }
      }
      return debug_printf(dword_11E958, v66, v67);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11E710 = 1;
    }
    v29 = (int *)off_11E714;
    v30 = (uint16_t)v28[4122];
    v31 = dword_11E720;
    ++*(uint32_t *)off_11E714;
    if ( v30 > 0x186 )
      v28[4122] = 0;
    v32 = list_pop(v31);
    v33 = *(uint32_t *)off_11E724;
    v34 = (uint16_t)v28[4122];
    *(uint16_t *)(v32 + 12) = v34;
    v35 = (uint32_t *)(v33 + 8 * v34);
    v35[1] = v8 + 48;
    *v35 = dword_11E728;
    v36 = off_11E70C;
    *(uint32_t *)(v32 + 4) = v35;
    v1 = v32;
    v37 = *v29;
    LOBYTE(v35) = *((uint8_t *)v28 + 3074) + 1;
    v38 = v36[3] + 1;
    v28[4122] = v34 + 1;
    *((uint8_t *)v28 + 3074) = (uint8_t)v35;
    v36[3] = v38;
    if ( v37 )
    {
      v39 = v37 - 1;
      v40 = *(uint32_t *)off_11E710;
      *v29 = v39;
      if ( !v39 )
      {
        if ( v40 )
          __enable_irq();
      }
    }
    v10 = *(uint16_t *)(v8 + 48);
    v9 = **(int16_t **)off_11E700;
    if ( v9 >= 0 )
    {
LABEL_37:
      v9 = **v5;
      if ( v9 == 2 )
      {
        rx_packet_handler(v72, v10, &v71);
        goto LABEL_7;
      }
LABEL_5:
      if ( v9 == 1 )
      {
        rx_packet_process(v72, v10, &v71);
      }
      else
      {
        rx_packet_parse(v72, v10, v3, &v71, 0);
        v4[7] = v10 + v3;
      }
LABEL_7:
      unknown_1018f0((uint64_t *)(v8 + 88), 0);
      v11 = **v5;
      if ( v11 == 3 )
      {
        v41 = (int *)off_11E918;
        v42 = *((uint32_t *)off_11E918 + 1);
        *(uint32_t *)(v8 + 100) = dword_11E91C;
        *(uint32_t *)(v8 + 104) = v8 + 48;
        v43 = dword_11E920;
        *(uint32_t *)(v8 + 108) = v2;
        *(uint32_t *)(v42 + 32) = v8 + 104;
        *(uint32_t *)(v8 + 112) = v43;
        *(uint32_t *)(v8 + 116) = 58;
        *(uint32_t *)(v8 + 120) = 58;
        v70 = v8 + 104;
        *(uint32_t *)(v8 + 124) = 262148;
        *(uint32_t *)(v8 + 136) = 0;
        goto LABEL_41;
      }
      if ( v11 != 1 )
      {
        if ( v11 == 2 )
        {
          v19 = (uint16_t *)off_11E940;
          if ( *((uint8_t *)off_11E940 + 2) )
          {
LABEL_17:
            v20 = *(uint32_t *)(v1 + 4);
            *(uint32_t *)(v1 + 8) = *v19 + 58;
            *(uint8_t *)(v20 + 3) &= 0x3Fu;
            *(uint8_t *)(v1 + 14) = *((uint8_t *)v19 + 3);
            *(uint32_t *)v1 = 0;
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(uint32_t *)off_11E710 = 1;
            }
            v21 = (int *)off_11E714;
            v22 = dword_11E718;
            ++*(uint32_t *)off_11E714;
            v23 = wlan_ioctl_handler_1(v22);
            rf_is_idle(v23, v24);
            if ( *v21 )
            {
              v25 = *v21 - 1;
              v26 = *(uint32_t *)off_11E710;
              *v21 = v25;
              if ( !v25 )
              {
                if ( v26 )
                  __enable_irq();
              }
            }
            *(uint32_t *)v19 = 0;
            *((uint32_t *)v19 + 1) = 0;
            if ( **v5 != 3 )
              return ble_get_rssi(v8, v72[0]);
            goto LABEL_65;
          }
        }
        return ble_get_rssi(v8, v72[0]);
      }
      v12 = (int *)off_11E704;
      if ( *((uint8_t *)off_11E704 + 32) )
      {
        v52 = (uint32_t *)mmio_read_0();
        v55 = (int)v52;
        if ( v52 )
        {
          if ( *((uint8_t *)v12 + 32) )
          {
            v56 = *v12;
            v57 = v12[1] + 1;
            v52[2] = (v57 << 24) & 0x7F000000 | v52[2] & 0x80FFFFFF;
            v12[1] = v57;
            tx_desc_set_control(v52, v8 + 48, v56, 0x3Au, 0);
            v58 = *((uint8_t *)off_11E944 + 192);
            v12[3] += 58;
            if ( v58 )
              op_mode_get(v55);
            else
              memmove(v55, v12[1], v12[2]);
            v59 = off_11E948;
            v60 = *(uint8_t *)off_11E948;
            v12[1] = 0;
            v12[3] = 0;
            *v12 = 0;
            v12[2] = 0;
            *((uint8_t *)v12 + 32) = 0;
            v61 = *v5;
            *v59 = v60 | 1;
            v18 = *v61;
            if ( v18 == 2 )
              goto LABEL_16;
            goto LABEL_64;
          }
        }
        else
        {
          v69 = dword_11E95C;
          *(uint8_t *)(v8 + 16) |= 1u;
          alloc_tx_event(v69, v53, v54);
          *((uint8_t *)v12 + 32) = 0;
        }
      }
      check_feature_flag(1024, dword_11E708);
      v13 = *v12;
      *(uint8_t *)(v8 + 16) |= 1u;
      if ( v13 && v12[1] )
      {
        v14 = v8;
        v15 = 0;
        v16 = v13;
        v17 = v14;
        do
        {
          v16 = *(uint32_t *)(v16 + 4);
          mmio_write_0();
          ++v15;
        }
        while ( v15 < (unsigned int)v12[1] );
        v8 = v17;
      }
      v12[1] = 0;
      v12[3] = 0;
      *v12 = 0;
      v12[2] = 0;
      v18 = **v5;
      if ( v18 == 2 )
      {
LABEL_16:
        v19 = (uint16_t *)off_11E70C;
        if ( *((uint8_t *)off_11E70C + 2) )
          goto LABEL_17;
        return ble_get_rssi(v8, v72[0]);
      }
LABEL_64:
      if ( v18 == 3 )
      {
LABEL_65:
        v41 = (int *)off_11E918;
LABEL_41:
        handle_radio_event(*v41, v70, 5);
        while ( (*(uint32_t *)off_11E924 & 0x800) == 0 )
          ;
        v44 = *(uint32_t *)off_11E924;
        if ( (*(uint32_t *)off_11E924 & 0x40000) != 0 )
          *(uint32_t *)off_11E924 |= 0x4000000u;
        if ( (v44 & 0x800) != 0 )
        {
          CPSR = __get_CPSR();
          *(uint32_t *)(dword_11E928 + 4428) |= 0x8000000u;
          if ( CPSR )
          {
            *((uint32_t *)off_11E934 + 5) = 0;
          }
          else
          {
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(uint32_t *)off_11E92C = 1;
            }
            v46 = off_11E930;
            v47 = off_11E934;
            v48 = *(uint32_t *)off_11E930;
            v49 = *(uint32_t *)off_11E930 + 1;
            *(uint32_t *)off_11E930 = v49;
            v47[5] = 0;
            if ( v49 )
            {
              v50 = off_11E92C;
              *v46 = v48;
              if ( !v48 )
              {
                if ( *v50 )
                  __enable_irq();
              }
            }
          }
        }
        v51 = off_11E938;
        while ( !*(uint32_t *)off_11E938 )
          ;
        wlan_ioctl_handler_1(*(uint32_t *)off_11E93C + 620);
        *v51 = 1;
        rf_cmd_sleep();
        return ble_get_rssi(v8, v72[0]);
      }
      return ble_get_rssi(v8, v72[0]);
    }
  }
  else
  {
    v10 = *(uint16_t *)(v8 + 48);
    if ( **(int16_t **)off_11E700 >= 0 )
      goto LABEL_5;
  }
  if ( !v10 )
    return unknown_12f2c8(dword_11E950, dword_11E94C, 1545, v9);
  if ( v10 <= 0x3000 )
    goto LABEL_37;
  return unknown_12f2c8(dword_11E954, dword_11E94C, 1547, v9);
}

