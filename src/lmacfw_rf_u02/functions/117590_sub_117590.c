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


extern uint32_t dword_117888;
extern uint32_t dword_11788C;
extern uint32_t dword_117894;
extern uint32_t dword_1178A0;
extern uint32_t dword_1178A4;
extern uint32_t dword_1178B0;
extern uint32_t off_11786C;
extern uint32_t off_117870;
extern uint32_t off_117874;
extern uint32_t off_11787C;
extern uint32_t off_117880;
extern uint32_t off_117884;
extern uint32_t off_117890;
extern uint32_t off_117898;
extern uint32_t off_11789C;
extern uint32_t off_1178A8;
extern uint32_t off_1178AC;
extern uint32_t off_117944;
extern uint32_t off_117948;

// tx_acl_queue_process @ 0x117590, size 936 bytes
int  tx_acl_queue_process(int a1)
{
  int v1; // r2
  int v2; // r6
  uint32_t *v3; // r9
  uint8_t **v4; // r5
  uint8_t *v5; // r3
  int v7; // r3
  unsigned int v8; // r1
  int v9; // r3
  int *v10; // r6
  uint32_t *v11; // r10
  uint8_t v12; // r8
  uint32_t *v13; // r0
  uint8_t *v14; // r2
  uint8_t *v15; // r5
  int v16; // r2
  int *v17; // r6
  int v18; // r0
  int v19; // r3
  int v20; // r2
  uint16_t *v22; // r7
  int *v23; // r8
  int v24; // cc
  int v25; // r0
  int v26; // r10
  uint32_t *v27; // r0
  int v28; // r12
  int v29; // r3
  int *v30; // r0
  uint8_t *v31; // r12
  int v32; // r1
  char v33; // r10
  int v34; // r1
  int v35; // r3
  uint32_t *v36; // r1
  int v37; // r1
  int v38; // r0
  uint32_t *v39; // r0
  int v40; // r8
  int v41; // r2
  int v42; // r12
  int v43; // r2
  uint8_t *v44; // r0
  int v45; // r1
  int *v46; // r4
  int v47; // r0
  int v48; // r3
  int v49; // r2
  int v50; // [sp+Ch] [bp-Ch]
  uint8_t a4[6]; // [sp+12h] [bp-6h] BYREF

  v4 = (uint8_t **)off_11786C;
  v5 = *(uint8_t **)off_11786C;
  *(uint32_t *)&a4[2] = *(uint32_t *)(a1 + 28);
  *(uint16_t *)a4 = 0;
  v7 = *v5;
  if ( v7 == 3 )
  {
    v2 = return_0();
    v7 = **v4;
    v1 = v2 + 56;
  }
  if ( v7 == 2 )
  {
    v22 = off_117890;
    if ( !*((uint32_t *)off_117890 + 2057) )
    {
      v45 = *(uint32_t *)&a4[2];
      *(uint8_t *)(a1 + 16) |= 1u;
      ll_timer_offset_get(a1, v45);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_117944 = 1;
      }
      v46 = (int *)off_117948;
      ++*(uint32_t *)off_117948;
      v47 = process_event();
      if ( *v46 )
      {
        v48 = *v46 - 1;
        v49 = *(uint32_t *)off_117944;
        *v46 = v48;
        if ( !v48 )
        {
          if ( v49 )
            __enable_irq();
        }
      }
      return log_printf("err, no buf %d\n", v47);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_117880 = 1;
    }
    v23 = (int *)off_117884;
    v50 = v1;
    v24 = (uint16_t)v22[4122] > 0x186u;
    ++*(uint32_t *)off_117884;
    v25 = dword_117894;
    v26 = dword_1178B0;
    if ( v24 )
      v22[4122] = 0;
    v27 = list_pop_front(v25);
    v1 = v50;
    v28 = *(uint32_t *)off_117898;
    v3 = v27;
    v29 = (uint16_t)v22[4122];
    *((uint16_t *)v27 + 6) = v29;
    v30 = (int *)(v28 + 8 * v29);
    v30[1] = a1 + 48;
    *v30 = v26;
    v31 = off_11787C;
    v3[1] = v30;
    v32 = *v23;
    v33 = *((uint8_t *)v22 + 3074) + 1;
    LOBYTE(v30) = v31[3] + 1;
    v22[4122] = v29 + 1;
    *((uint8_t *)v22 + 3074) = v33;
    v31[3] = (uint8_t)v30;
    if ( v32 )
    {
      v34 = v32 - 1;
      v35 = *(uint32_t *)off_117880;
      *v23 = v34;
      if ( !v34 )
      {
        if ( v35 )
          __enable_irq();
      }
    }
    v8 = *(uint16_t *)(a1 + 48);
    if ( **(uint16_t **)off_117870 >= 0 )
    {
LABEL_37:
      v7 = **v4;
      if ( v7 == 2 )
      {
        wlan_rf_init((int *)&a4[2], v8, a4);
        goto LABEL_7;
      }
LABEL_5:
      if ( v7 == 1 )
        tx_send_packet((int *)&a4[2], v8, a4);
      else
        rx_parse_packet(&a4[2], v8, v1, a4, 0);
LABEL_7:
      mac_time_get((uint64_t *)(a1 + 88), 0);
      v9 = **v4;
      if ( v9 == 3 )
      {
        v36 = off_11789C;
        *(uint32_t *)(a1 + 96) = dword_1178A0;
        v37 = v36[1];
        *(uint32_t *)(a1 + 104) = v2;
        *(uint32_t *)(a1 + 100) = a1 + 48;
        v38 = dword_1178A4;
        *(uint32_t *)(v37 + 32) = a1 + 100;
        *(uint32_t *)(a1 + 108) = v38;
        *(uint32_t *)(a1 + 132) = 0;
        *(uint32_t *)(a1 + 112) = 54;
        *(uint32_t *)(a1 + 116) = 54;
        *(uint32_t *)(a1 + 120) = 262148;
LABEL_24:
        ll_timer_offset_get(a1, *(int *)&a4[2]);
        return check_kernel_state(dword_11788C, (uint32_t *)a1);
      }
      if ( v9 == 1 )
      {
        v10 = (int *)off_117874;
        if ( !*((uint8_t *)off_117874 + 32) )
          goto LABEL_10;
        v39 = irq_disable();
        v40 = (int)v39;
        if ( v39 )
        {
          if ( *((uint8_t *)v10 + 32) )
          {
            v41 = *v10;
            v42 = v10[1] + 1;
            v39[2] = (v42 << 24) & 0x7F000000 | v39[2] & 0x80FFFFFF;
            v10[1] = v42;
            set_radio_channel(v39, a1 + 48, v41, 0x36u, 0);
            v43 = *((uint8_t *)off_1178A8 + 192);
            v10[3] += 54;
            if ( v43 )
              scan_ctrl_update(v40);
            else
              irq_disable_set_flag_3(v40, v10[1], v10[2]);
            v44 = *v4;
            *(uint8_t *)off_1178AC |= 1u;
            v10[1] = 0;
            v10[3] = 0;
            *v10 = 0;
            v10[2] = 0;
            *((uint8_t *)v10 + 32) = 0;
            v9 = *v44;
            goto LABEL_15;
          }
        }
        else
        {
          *(uint8_t *)(a1 + 16) |= 1u;
          dispatch_event_handler_1(aNoTxDscrHdr_0);
          *((uint8_t *)v10 + 32) = 0;
        }
LABEL_10:
        check_interrupt_flag(1024, aNoTxDscrHdr);
        v11 = (uint32_t *)*v10;
        *(uint8_t *)(a1 + 16) |= 1u;
        if ( v11 && v10[1] )
        {
          v12 = 0;
          do
          {
            v13 = v11;
            v11 = (uint32_t *)v11[1];
            irq_disable_arg(v13);
            ++v12;
          }
          while ( v12 < (unsigned int)v10[1] );
        }
        v14 = *v4;
        v10[1] = 0;
        v10[3] = 0;
        *v10 = 0;
        v10[2] = 0;
        v9 = *v14;
      }
LABEL_15:
      if ( v9 == 2 )
      {
        v15 = off_11787C;
        if ( *((uint8_t *)off_11787C + 2) )
        {
          v16 = v3[1];
          v3[2] = *(uint16_t *)off_11787C + 58;
          *(uint8_t *)(v16 + 3) &= 0x3Fu;
          *((uint8_t *)v3 + 14) = v15[3];
          *v3 = 0;
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_117880 = 1;
          }
          v17 = (int *)off_117884;
          v18 = dword_117888;
          ++*(uint32_t *)off_117884;
          check_kernel_state(v18, v3);
          process_event();
          if ( *v17 )
          {
            v19 = *v17 - 1;
            v20 = *(uint32_t *)off_117880;
            *v17 = v19;
            if ( !v19 )
            {
              if ( v20 )
                __enable_irq();
            }
          }
          *(uint32_t *)v15 = 0;
          *((uint32_t *)v15 + 1) = 0;
        }
      }
      goto LABEL_24;
    }
  }
  else
  {
    v8 = *(uint16_t *)(a1 + 48);
    if ( **(uint16_t **)off_117870 >= 0 )
      goto LABEL_5;
  }
  if ( !v8 )
    return ke_int_lock_1((int)aMpduLen0, (int)aRxlMpduTransfe, 1545);
  if ( v8 <= 0x3000 )
    goto LABEL_37;
  return ke_int_lock_1((int)aMpduLenRwnxMax, (int)aRxlMpduTransfe, 1547);
}
