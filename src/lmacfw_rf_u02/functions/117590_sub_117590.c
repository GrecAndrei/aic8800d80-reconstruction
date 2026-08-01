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

extern uint32_t off_11786C;
extern uint32_t off_117890;
extern uint32_t off_117944;
extern uint32_t off_117948;
extern uint32_t dword_11794C;
extern uint32_t off_117880;
extern uint32_t off_117884;
extern uint32_t dword_117894;
extern uint32_t dword_1178B0;
extern uint32_t off_117898;
extern uint32_t off_11787C;
extern uint32_t off_117870;
extern uint32_t off_11789C;
extern uint32_t dword_1178A0;
extern uint32_t dword_1178A4;
extern uint32_t dword_11788C;
extern uint32_t off_117874;
extern uint32_t off_1178A8;
extern uint32_t off_1178AC;
extern uint32_t dword_117950;
extern uint32_t dword_117878;
extern uint32_t dword_117888;
extern uint32_t dword_11793C;
extern uint32_t dword_117938;
extern uint32_t dword_117940;

// tx_acl_queue_process @ 0x117590, size 936 bytes
int  tx_acl_queue_process(int a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r9
  uint8_t **v5; // r5
  uint8_t *v6; // r3
  int v8; // r3
  unsigned int v9; // r1
  int v10; // r2
  int v11; // r3
  int *v12; // r6
  int v13; // r3
  int v14; // r10
  uint8_t v15; // r8
  uint8_t *v16; // r2
  uint8_t *v17; // r5
  int v18; // r2
  int *v19; // r6
  int v20; // r0
  int v21; // r0
  int v22; // r1
  int v23; // r3
  int v24; // r2
  uint16_t *v26; // r7
  int *v27; // r8
  int v28; // cc
  int v29; // r0
  int v30; // r10
  int v31; // r0
  int v32; // r12
  int v33; // r3
  int *v34; // r0
  uint8_t *v35; // r12
  int v36; // r1
  char v37; // r10
  int v38; // r1
  int v39; // r3
  uint32_t *v40; // r1
  int v41; // r1
  int v42; // r0
  uint32_t *v43; // r0
  int v44; // r1
  int v45; // r8
  int v46; // r2
  int v47; // r12
  int v48; // r2
  uint8_t *v49; // r0
  int v50; // r1
  int v51; // r1
  unsigned int CPSR; // r3
  int *v53; // r4
  int v54; // r0
  int v55; // r2
  int v56; // r3
  int v57; // r0
  int v58; // [sp+Ch] [bp-Ch]
  int16_t v59; // [sp+12h] [bp-6h] BYREF
  int v60; // [sp+14h] [bp-4h] BYREF

  v5 = (uint8_t **)off_11786C;
  v6 = *(uint8_t **)off_11786C;
  v60 = *(uint32_t *)(a1 + 28);
  v59 = 0;
  v8 = *v6;
  if ( v8 == 3 )
  {
    v3 = return_0();
    v8 = **v5;
    a3 = v3 + 56;
  }
  if ( v8 == 2 )
  {
    v26 = off_117890;
    if ( !*((uint32_t *)off_117890 + 2057) )
    {
      v50 = v60;
      *(uint8_t *)(a1 + 16) |= 1u;
      ll_timer_offset_get(a1, v50);
      CPSR = __get_CPSR();
      if ( (CPSR & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_117944 = 1;
      }
      v53 = (int *)off_117948;
      ++*(uint32_t *)off_117948;
      v54 = process_event(CPSR << 31, v51);
      if ( *v53 )
      {
        v56 = *v53 - 1;
        v55 = *(uint32_t *)off_117944;
        *v53 = v56;
        if ( !v56 )
        {
          if ( v55 )
            __enable_irq();
        }
      }
      return log_printf(dword_11794C, v54, v55);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_117880 = 1;
    }
    v27 = (int *)off_117884;
    v58 = a3;
    v28 = (uint16_t)v26[4122] > 0x186u;
    ++*(uint32_t *)off_117884;
    v29 = dword_117894;
    v30 = dword_1178B0;
    if ( v28 )
      v26[4122] = 0;
    v31 = list_pop_front(v29);
    a3 = v58;
    v32 = *(uint32_t *)off_117898;
    v4 = v31;
    v33 = (uint16_t)v26[4122];
    *(uint16_t *)(v31 + 12) = v33;
    v34 = (int *)(v32 + 8 * v33);
    v34[1] = a1 + 48;
    *v34 = v30;
    v35 = off_11787C;
    *(uint32_t *)(v4 + 4) = v34;
    v36 = *v27;
    v37 = *((uint8_t *)v26 + 3074) + 1;
    LOBYTE(v34) = v35[3] + 1;
    v26[4122] = v33 + 1;
    *((uint8_t *)v26 + 3074) = v37;
    v35[3] = (uint8_t)v34;
    if ( v36 )
    {
      v38 = v36 - 1;
      v39 = *(uint32_t *)off_117880;
      *v27 = v38;
      if ( !v38 )
      {
        if ( v39 )
          __enable_irq();
      }
    }
    v9 = *(uint16_t *)(a1 + 48);
    v8 = **(int16_t **)off_117870;
    if ( v8 >= 0 )
    {
LABEL_37:
      v8 = **v5;
      if ( v8 == 2 )
      {
        wlan_rf_init(&v60, v9, &v59);
        goto LABEL_7;
      }
LABEL_5:
      if ( v8 == 1 )
        tx_send_packet(&v60, v9, &v59);
      else
        rx_parse_packet(&v60, v9, a3, &v59, 0);
LABEL_7:
      mac_time_get((uint64_t *)(a1 + 88), 0);
      v11 = **v5;
      if ( v11 == 3 )
      {
        v40 = off_11789C;
        *(uint32_t *)(a1 + 96) = dword_1178A0;
        v41 = v40[1];
        *(uint32_t *)(a1 + 104) = v3;
        *(uint32_t *)(a1 + 100) = a1 + 48;
        v42 = dword_1178A4;
        *(uint32_t *)(v41 + 32) = a1 + 100;
        *(uint32_t *)(a1 + 108) = v42;
        *(uint32_t *)(a1 + 132) = 0;
        *(uint32_t *)(a1 + 112) = 54;
        *(uint32_t *)(a1 + 116) = 54;
        *(uint32_t *)(a1 + 120) = 262148;
LABEL_24:
        ll_timer_offset_get(a1, v60);
        return check_kernel_state(dword_11788C);
      }
      if ( v11 == 1 )
      {
        v12 = (int *)off_117874;
        v13 = *((uint8_t *)off_117874 + 32);
        if ( !*((uint8_t *)off_117874 + 32) )
          goto LABEL_10;
        v43 = (uint32_t *)irq_disable();
        v45 = (int)v43;
        if ( v43 )
        {
          v13 = *((uint8_t *)v12 + 32);
          if ( *((uint8_t *)v12 + 32) )
          {
            v46 = *v12;
            v47 = v12[1] + 1;
            v43[2] = (v47 << 24) & 0x7F000000 | v43[2] & 0x80FFFFFF;
            v12[1] = v47;
            set_radio_channel(v43, a1 + 48, v46, 0x36u, 0);
            v48 = *((uint8_t *)off_1178A8 + 192);
            v12[3] += 54;
            if ( v48 )
              scan_ctrl_update(v45);
            else
              irq_disable_set_flag_3(v45, v12[1], v12[2]);
            v49 = *v5;
            *(uint8_t *)off_1178AC |= 1u;
            v12[1] = 0;
            v12[3] = 0;
            *v12 = 0;
            v12[2] = 0;
            *((uint8_t *)v12 + 32) = 0;
            v11 = *v49;
            goto LABEL_15;
          }
        }
        else
        {
          v57 = dword_117950;
          *(uint8_t *)(a1 + 16) |= 1u;
          dispatch_event_handler(v57, v44);
          *((uint8_t *)v12 + 32) = 0;
        }
LABEL_10:
        check_interrupt_flag(1024, dword_117878, v10, v13);
        v14 = *v12;
        *(uint8_t *)(a1 + 16) |= 1u;
        if ( v14 && v12[1] )
        {
          v15 = 0;
          do
          {
            v14 = *(uint32_t *)(v14 + 4);
            irq_disable_arg();
            ++v15;
          }
          while ( v15 < (unsigned int)v12[1] );
        }
        v16 = *v5;
        v12[1] = 0;
        v12[3] = 0;
        *v12 = 0;
        v12[2] = 0;
        v11 = *v16;
      }
LABEL_15:
      if ( v11 == 2 )
      {
        v17 = off_11787C;
        if ( *((uint8_t *)off_11787C + 2) )
        {
          v18 = *(uint32_t *)(v4 + 4);
          *(uint32_t *)(v4 + 8) = *(uint16_t *)off_11787C + 58;
          *(uint8_t *)(v18 + 3) &= 0x3Fu;
          *(uint8_t *)(v4 + 14) = v17[3];
          *(uint32_t *)v4 = 0;
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_117880 = 1;
          }
          v19 = (int *)off_117884;
          v20 = dword_117888;
          ++*(uint32_t *)off_117884;
          v21 = check_kernel_state(v20);
          process_event(v21, v22);
          if ( *v19 )
          {
            v23 = *v19 - 1;
            v24 = *(uint32_t *)off_117880;
            *v19 = v23;
            if ( !v23 )
            {
              if ( v24 )
                __enable_irq();
            }
          }
          *(uint32_t *)v17 = 0;
          *((uint32_t *)v17 + 1) = 0;
        }
      }
      goto LABEL_24;
    }
  }
  else
  {
    v9 = *(uint16_t *)(a1 + 48);
    if ( **(int16_t **)off_117870 >= 0 )
      goto LABEL_5;
  }
  if ( !v9 )
    return ke_int_lock(dword_11793C, dword_117938, 1545, v8);
  if ( v9 <= 0x3000 )
    goto LABEL_37;
  return ke_int_lock(dword_117940, dword_117938, 1547, v8);
}

