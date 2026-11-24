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


extern uint32_t dword_11EC98;
extern uint32_t dword_11ECA0;
extern uint32_t dword_11ECA8;
extern uint32_t dword_11EE9C;
extern uint32_t dword_11EEA0;
extern uint32_t dword_11EEA8;
extern uint32_t off_11EC78;
extern uint32_t off_11EC7C;
extern uint32_t off_11EC80;
extern uint32_t off_11EC84;
extern uint32_t off_11EC8C;
extern uint32_t off_11EC90;
extern uint32_t off_11EC94;
extern uint32_t off_11EC9C;
extern uint32_t off_11ECA4;
extern uint32_t off_11EE98;
extern uint32_t off_11EEA4;
extern uint32_t off_11EEAC;
extern uint32_t off_11EEB0;
extern uint32_t off_11EEB4;
extern uint32_t off_11EEB8;
extern uint32_t off_11EEBC;
extern uint32_t off_11EEC0;
extern uint32_t off_11EEC4;
extern uint32_t off_11EEC8;

// rx_packet_setup @ 0x11ea44, size 1106 bytes
int  rx_packet_setup(int a1)
{
  uint32_t *v1; // r8
  int v2; // r10
  int v3; // r11
  uint32_t *v4; // r6
  uint8_t **v5; // r5
  uint16_t v6; // r2
  uint8_t *v7; // r3
  int v8; // r4
  int v9; // r3
  unsigned int v10; // r7
  int v11; // r3
  int *v12; // r6
  int v13; // r11
  int v14; // r3
  uint8_t v15; // r7
  uint32_t *v16; // r4
  int v17; // r11
  uint32_t *v18; // r0
  int v19; // r3
  uint16_t *v20; // r6
  int v21; // r2
  int *v22; // r7
  int v23; // r0
  int v24; // r3
  int v25; // r2
  uint16_t *v27; // r7
  int *v28; // r9
  unsigned int v29; // r1
  int v30; // r0
  uint32_t *v31; // r0
  int v32; // r12
  int v33; // r3
  uint32_t *v34; // r1
  uint8_t *v35; // r12
  int v36; // r0
  char v37; // r2
  int v38; // r0
  int v39; // r3
  int *v40; // r2
  int v41; // r3
  int v42; // r1
  int v43; // r3
  unsigned int CPSR; // r0
  uint32_t *v45; // r3
  uint32_t *v46; // r0
  int v47; // r1
  int v48; // r2
  uint32_t *v49; // r2
  uint32_t *v50; // r5
  uint32_t *v51; // r0
  int v52; // r7
  int v53; // r2
  int v54; // r12
  int v55; // r2
  uint8_t *v56; // r1
  char v57; // r2
  uint8_t *v58; // r3
  int v59; // r1
  int *v60; // r4
  int v61; // r0
  int v62; // r3
  int v63; // r2
  int a2; // [sp+Ch] [bp-10h]
  uint16_t a4; // [sp+12h] [bp-Ah] BYREF
  int a4_2[2]; // [sp+14h] [bp-8h] BYREF

  v4 = off_11EC78;
  v5 = (uint8_t **)off_11EC7C;
  v6 = *((uint8_t *)off_11EC78 + 50);
  v7 = *(uint8_t **)off_11EC7C;
  v8 = a1;
  a4_2[0] = *(uint32_t *)(a1 + 28);
  a4 = v6;
  v9 = *v7;
  if ( v9 == 3 )
  {
    v2 = jump_to_10ca3c();
    v9 = **v5;
    v3 = v2 + 60;
  }
  if ( v9 == 2 )
  {
    v27 = off_11EC9C;
    if ( !*((uint32_t *)off_11EC9C + 2057) )
    {
      v59 = a4_2[0];
      *(uint8_t *)(v8 + 16) |= 1u;
      tx_timestamp_get(v8, v59);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_11EEAC = 1;
      }
      v60 = (int *)off_11EEB0;
      ++*(uint32_t *)off_11EEB0;
      v61 = rf_calib_init();
      if ( *v60 )
      {
        v62 = *v60 - 1;
        v63 = *(uint32_t *)off_11EEAC;
        *v60 = v62;
        if ( !v62 )
        {
          if ( v63 )
            __enable_irq();
        }
      }
      return printf_wrapper("err, no buf %d\n", v61);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11EC90 = 1;
    }
    v28 = (int *)off_11EC94;
    v29 = (uint16_t)v27[4122];
    v30 = dword_11ECA0;
    ++*(uint32_t *)off_11EC94;
    if ( v29 > 0x186 )
      v27[4122] = 0;
    v31 = list_pop_front(v30);
    v32 = *(uint32_t *)off_11ECA4;
    v33 = (uint16_t)v27[4122];
    *((uint16_t *)v31 + 6) = v33;
    v34 = (uint32_t *)(v32 + 8 * v33);
    v34[1] = v8 + 48;
    *v34 = dword_11ECA8;
    v35 = off_11EC8C;
    v31[1] = v34;
    v1 = v31;
    v36 = *v28;
    LOBYTE(v34) = *((uint8_t *)v27 + 3074) + 1;
    v37 = v35[3] + 1;
    v27[4122] = v33 + 1;
    *((uint8_t *)v27 + 3074) = (uint8_t)v34;
    v35[3] = v37;
    if ( v36 )
    {
      v38 = v36 - 1;
      v39 = *(uint32_t *)off_11EC90;
      *v28 = v38;
      if ( !v38 )
      {
        if ( v39 )
          __enable_irq();
      }
    }
    v10 = *(uint16_t *)(v8 + 48);
    if ( **(uint16_t **)off_11EC80 >= 0 )
    {
LABEL_37:
      v9 = **v5;
      if ( v9 == 2 )
      {
        rx_packet_isr(a4_2, v10, &a4);
        goto LABEL_7;
      }
LABEL_5:
      if ( v9 == 1 )
      {
        tx_packet_isr(a4_2, v10, &a4);
      }
      else
      {
        rx_adv_packet_isr(a4_2, v10, v3, &a4, 0);
        v4[7] = v10 + v3;
      }
LABEL_7:
      timer_count_read((uint64_t *)(v8 + 88), 0);
      v11 = **v5;
      if ( v11 == 3 )
      {
        v40 = (int *)off_11EE98;
        v41 = *((uint32_t *)off_11EE98 + 1);
        *(uint32_t *)(v8 + 100) = dword_11EE9C;
        *(uint32_t *)(v8 + 104) = v8 + 48;
        v42 = dword_11EEA0;
        *(uint32_t *)(v8 + 108) = v2;
        *(uint32_t *)(v41 + 32) = v8 + 104;
        *(uint32_t *)(v8 + 112) = v42;
        *(uint32_t *)(v8 + 116) = 58;
        *(uint32_t *)(v8 + 120) = 58;
        a2 = v8 + 104;
        *(uint32_t *)(v8 + 124) = 262148;
        *(uint32_t *)(v8 + 136) = 0;
        goto LABEL_41;
      }
      if ( v11 != 1 )
      {
        if ( v11 == 2 )
        {
          v20 = (uint16_t *)off_11EEC0;
          if ( *((uint8_t *)off_11EEC0 + 2) )
          {
LABEL_17:
            v21 = v1[1];
            v1[2] = *v20 + 58;
            *(uint8_t *)(v21 + 3) &= 0x3Fu;
            *((uint8_t *)v1 + 14) = *((uint8_t *)v20 + 3);
            *v1 = 0;
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(uint32_t *)off_11EC90 = 1;
            }
            v22 = (int *)off_11EC94;
            v23 = dword_11EC98;
            ++*(uint32_t *)off_11EC94;
            check_abort_flag(v23, v1);
            rf_calib_init();
            if ( *v22 )
            {
              v24 = *v22 - 1;
              v25 = *(uint32_t *)off_11EC90;
              *v22 = v24;
              if ( !v24 )
              {
                if ( v25 )
                  __enable_irq();
              }
            }
            *(uint32_t *)v20 = 0;
            *((uint32_t *)v20 + 1) = 0;
            if ( **v5 != 3 )
              return tx_timestamp_get(v8, a4_2[0]);
            goto LABEL_65;
          }
        }
        return tx_timestamp_get(v8, a4_2[0]);
      }
      v12 = (int *)off_11EC84;
      if ( *((uint8_t *)off_11EC84 + 32) )
      {
        v51 = critical_enter_0();
        v52 = (int)v51;
        if ( v51 )
        {
          if ( *((uint8_t *)v12 + 32) )
          {
            v53 = *v12;
            v54 = v12[1] + 1;
            v51[2] = (v54 << 24) & 0x7F000000 | v51[2] & 0x80FFFFFF;
            v12[1] = v54;
            rf_set_tx_channel(v51, v8 + 48, v53, 0x3Au, 0);
            v55 = LOBYTE(((uint32_t *)(uintptr_t)off_11EEC4)[48]);
            v12[3] += 58;
            if ( v55 )
              bt_notify_event(v52);
            else
              ke_int_lock(v52, v12[1], v12[2]);
            v56 = off_11EEC8;
            v57 = *(uint8_t *)off_11EEC8;
            v12[1] = 0;
            v12[3] = 0;
            *v12 = 0;
            v12[2] = 0;
            *((uint8_t *)v12 + 32) = 0;
            v58 = *v5;
            *v56 = v57 | 1;
            v19 = *v58;
            if ( v19 == 2 )
              goto LABEL_16;
            goto LABEL_64;
          }
        }
        else
        {
          *(uint8_t *)(v8 + 16) |= 1u;
          ke_event_schedule_1(aNoTxDscrHdr_0);
          *((uint8_t *)v12 + 32) = 0;
        }
      }
      state_check_feature(1024, aNoTxDscrHdr);
      v13 = *v12;
      *(uint8_t *)(v8 + 16) |= 1u;
      if ( v13 && v12[1] )
      {
        v14 = v8;
        v15 = 0;
        v16 = (uint32_t *)v13;
        v17 = v14;
        do
        {
          v18 = v16;
          v16 = (uint32_t *)v16[1];
          critical_enter_1(v18);
          ++v15;
        }
        while ( v15 < (unsigned int)v12[1] );
        v8 = v17;
      }
      v12[1] = 0;
      v12[3] = 0;
      *v12 = 0;
      v12[2] = 0;
      v19 = **v5;
      if ( v19 == 2 )
      {
LABEL_16:
        v20 = (uint16_t *)off_11EC8C;
        if ( *((uint8_t *)off_11EC8C + 2) )
          goto LABEL_17;
        return tx_timestamp_get(v8, a4_2[0]);
      }
LABEL_64:
      if ( v19 == 3 )
      {
LABEL_65:
        v40 = (int *)off_11EE98;
LABEL_41:
        ke_event_process(*v40, a2, 5);
        while ( (*(uint32_t *)off_11EEA4 & 0x800) == 0 )
          ;
        v43 = *(uint32_t *)off_11EEA4;
        if ( (*(uint32_t *)off_11EEA4 & 0x40000) != 0 )
          *(uint32_t *)off_11EEA4 |= 0x4000000u;
        if ( (v43 & 0x800) != 0 )
        {
          CPSR = __get_CPSR();
          *(uint32_t *)(dword_11EEA8 + 4428) |= 0x8000000u;
          if ( CPSR )
          {
            *((uint32_t *)off_11EEB4 + 5) = 0;
          }
          else
          {
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(uint32_t *)off_11EEAC = 1;
            }
            v45 = off_11EEB0;
            v46 = off_11EEB4;
            v47 = *(uint32_t *)off_11EEB0;
            v48 = *(uint32_t *)off_11EEB0 + 1;
            *(uint32_t *)off_11EEB0 = v48;
            v46[5] = 0;
            if ( v48 )
            {
              v49 = off_11EEAC;
              *v45 = v47;
              if ( !v47 )
              {
                if ( *v49 )
                  __enable_irq();
              }
            }
          }
        }
        v50 = off_11EEB8;
        while ( !*(uint32_t *)off_11EEB8 )
          ;
        check_abort_flag(((uint32_t *)(uintptr_t)off_11EEBC)[0] + 556, (uint32_t *)(v2 - 20));
        *v50 = 1;
        pmu_ctrl_write_8();
        return tx_timestamp_get(v8, a4_2[0]);
      }
      return tx_timestamp_get(v8, a4_2[0]);
    }
  }
  else
  {
    v10 = *(uint16_t *)(v8 + 48);
    if ( **(uint16_t **)off_11EC80 >= 0 )
      goto LABEL_5;
  }
  if ( !v10 )
    return ke_int_lock_1((int)aMpduLen0, (int)aRxlMpduTransfe, 1545);
  if ( v10 <= 0x3000 )
    goto LABEL_37;
  return ke_int_lock_1((int)aMpduLenRwnxMax, (int)aRxlMpduTransfe, 1547);
}
