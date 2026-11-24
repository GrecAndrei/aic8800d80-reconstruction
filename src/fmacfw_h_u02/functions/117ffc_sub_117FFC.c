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


extern uint32_t dword_1182F4;
extern uint32_t dword_118308;
extern uint32_t dword_11830C;
extern uint32_t dword_118310;
extern uint32_t dword_118318;
extern uint32_t dword_1185B8;
extern uint32_t dword_1185DC;
extern uint32_t dword_1187E8;
extern uint32_t off_1182F0;
extern uint32_t off_1182F8;
extern uint32_t off_1182FC;
extern uint32_t off_118300;
extern uint32_t off_118304;
extern uint32_t off_118314;
extern uint32_t off_1185B4;
extern uint32_t off_1185CC;
extern uint32_t off_1185D8;
extern uint32_t off_1187CC;
extern uint32_t off_1187D0;
extern uint32_t off_1187DC;
extern uint32_t off_1187F4;
extern uint32_t off_1187FC;

// phy_calibrate_1 @ 0x117ffc, size 2000 bytes
uint32_t * phy_calibrate_1(int a1)
{
  int v1; // s16
  int v2; // r4
  uint32_t *v3; // r0
  int v4; // r4
  int *v5; // r7
  int v6; // r8
  int v7; // r6
  int v8; // r10
  int v9; // r11
  unsigned int v10; // r5
  int v11; // r9
  int v12; // r10
  int v13; // r3
  int v14; // r2
  uint8_t **v15; // r11
  int v16; // r9
  unsigned int v17; // r2
  unsigned int v18; // r1
  uint32_t *v19; // r0
  uint8_t *v20; // r3
  int v21; // r3
  int v22; // r2
  int v23; // r5
  int v24; // r2
  int v25; // r9
  int v26; // r3
  int v27; // r2
  uint16_t v28; // r1
  unsigned int v29; // r3
  unsigned int v30; // r2
  int v31; // r5
  int v32; // r3
  int v33; // r3
  int v34; // r11
  unsigned int v35; // r3
  int v36; // r2
  uint16_t *v37; // r2
  unsigned int v38; // r3
  unsigned int v39; // r1
  int v40; // r3
  int v41; // r10
  int v42; // r3
  int v43; // r3
  int v44; // r11
  unsigned int v45; // r3
  int v46; // r2
  int v47; // r1
  uint16_t v48; // r2
  void *v49; // r2
  int v50; // r2
  uint16_t v51; // r1
  void *v52; // r2
  unsigned int v53; // r6
  volatile unsigned int v54; // r0
  uint16_t v55; // r6
  int v56; // r1
  void *v57; // r2
  int a2; // [sp+4h] [bp-28h]
  int a3; // [sp+Ch] [bp-20h]
  int v61; // [sp+10h] [bp-1Ch]
  int v62; // [sp+10h] [bp-1Ch]
  int v63; // [sp+14h] [bp-18h]
  int v64; // [sp+14h] [bp-18h]
  int v65; // [sp+18h] [bp-14h]
  int v66; // [sp+1Ch] [bp-10h]
  uint32_t result[3]; // [sp+20h] [bp-Ch] BYREF

  v1 = dword_1182F4 + 8 * a1;
  v2 = ((uint32_t *)(uintptr_t)off_1182F8)[a1];
  if ( **(uint16_t **)off_1182F0 < 0 && (v2 & *(uint32_t *)off_1187DC) == 0 )
    irq_disable_mmio_write((int)aKeEvtGetEvtBit, (int)aTxlCfmEvt_0, 612);
  irq_disable_global_3(v2);
  v3 = clear_stats_buf(result);
  v4 = *(uint32_t *)(dword_1182F4 + 8 * a1);
  if ( v4 )
  {
    v5 = (int *)off_1182FC;
    a3 = 0;
    v65 = 0;
    a2 = 0;
    v6 = 0;
    do
    {
      v7 = *(uint32_t *)(v4 + 76);
      v8 = *(uint32_t *)(v4 + 68);
      v9 = *(uint8_t *)(v4 + 29);
      if ( *((uint8_t *)off_118300 + 512) == 1 )
      {
        *((uint8_t *)off_118300 + 512) = 0;
        v3 = (uint32_t *)irq_disable_global_2(512);
        if ( !v8 )
        {
LABEL_39:
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_118304 = 1;
          }
          ++*v5;
          list_pop(v1);
          if ( *v5 )
          {
            v21 = *v5 - 1;
            v22 = *(uint32_t *)off_118304;
            *v5 = v21;
            if ( !v21 )
            {
              if ( v22 )
                __enable_irq();
            }
          }
          v23 = *(uint8_t *)(v4 + 28);
          v24 = *(uint32_t *)(v7 + 4);
          v62 = v24;
          if ( *(uint8_t *)(dword_11830C + 696 * v9 + 36) != 1 || (v24 & 0x810000) != 0x10000 )
            rf_check_irq(v4);
          v25 = dword_118318;
          v26 = dword_118318 + 1320 * v23;
          v27 = *(uint8_t *)(v26 + 1224);
          if ( *(uint8_t *)(v26 + 1224) )
            v8 = dword_118310 + 140 * *(uint8_t *)(v26 + 1225);
          if ( *(uint8_t *)(v4 + 29) > 0x1Fu
            || (v28 = *(uint16_t *)(v4 + 30), (v28 & 8) != 0)
            || (v62 & 0x810000) != 0x10000
            || !*(uint8_t *)(dword_118318 + 1320 * v23 + 108) )
          {
LABEL_53:
            if ( *(int *)(*(uint32_t *)(v4 + 44) + 60) >= 0 || (v62 & 0x800000) == 0 )
              goto LABEL_54;
            v41 = *(uint32_t *)(v4 + 76);
            if ( **(uint16_t **)off_1185B4 >= 0 )
            {
              v42 = *(uint32_t *)(v41 + 28);
              if ( !v42 )
                goto LABEL_94;
LABEL_96:
              if ( (*(uint16_t *)v42 & 0x8000) != 0 && (*(uint16_t *)v42 & 0xC) == 8 && (*(uint32_t *)(v42 + 26) & 0x3F) == 7 )
                *(uint32_t *)(*(uint32_t *)(v4 + 44) + 60) &= ~0x80000000;
LABEL_54:
              if ( phy_switch_radio(v4, 0) )
              {
                v47 = *(uint32_t *)(v4 + 76);
                v48 = *(uint16_t *)(v4 + 30) | 1;
                *(uint32_t *)(v4 + 68) = 0;
                *(uint32_t *)(v47 + 72) = 0;
                *(uint32_t *)(v47 + 4) = 0;
                *(uint16_t *)(v4 + 30) = v48;
                *(uint16_t *)(v4 + 82) = 0;
                v49 = off_1185CC;
                *(uint32_t *)(v4 + 44) = 0;
                *(uint32_t *)(v4 + 36) = 0;
                list_foreach(
                  v25 + 8 * (165 * (uint16_t)v23 + a1 + 159),
                  (uint32_t *)v4,
                  (int ( *)(uint32_t *, uint32_t *))v49);
                v3 = (uint32_t *)irq_disable_global_2(512);
              }
              else
              {
                if ( *(uint16_t *)(v4 + 24) == 36488 && (*(uint32_t *)(v7 + 4) & 0xF) == 9 )
                {
                  v44 = dword_1185B8 + 696 * v9;
                  v45 = *(uint8_t *)(v44 + 669);
                  if ( v45 <= 1 )
                  {
                    v46 = *(uint32_t *)(*(uint32_t *)(v4 + 76) + 36);
                    if ( v46 != *(uint16_t *)(v44 + 670) )
                    {
                      *(uint8_t *)(v44 + 669) = v45 + 1;
                      *(uint16_t *)(v44 + 670) = v46;
                    }
                  }
                }
                v29 = *(uint8_t *)(v4 + 29);
                if ( v29 <= 0x1F )
                {
                  v30 = *(uint8_t *)(v4 + 27);
                  if ( v30 <= 8 )
                    *(uint32_t *)(dword_118308 + 4 * (9 * v29 + v30 + 2062)) -= *(uint16_t *)(v4 + 4);
                }
                rx_packet_ready(v4);
                check_cal_status(v4, (uint32_t *)(v7 + 4));
                if ( (*(uint16_t *)(v4 + 30) & 1) != 0 )
                  irq_disable_global_2(512);
                v3 = (uint32_t *)unknown_12f4b4((uint8_t)a1, v4);
              }
              goto LABEL_36;
            }
            if ( *(uint32_t *)(v4 + 72) )
            {
              v42 = *(uint32_t *)(v41 + 28);
              if ( v42 )
                goto LABEL_96;
              goto LABEL_125;
            }
            irq_disable_mmio_write((int)aTxlBufferGetTx, (int)aTxlBufferMachd_0, 518);
            v42 = *(uint32_t *)(v41 + 28);
            if ( v42 )
              goto LABEL_96;
            if ( **(uint16_t **)off_1187FC < 0 )
            {
LABEL_125:
              v43 = *(uint32_t *)(v41 + 24);
              if ( !v43 )
              {
                irq_disable_mmio_write((int)aThdFirstPbdPtr, (int)aTxlBufferMachd_0, 525);
                goto LABEL_94;
              }
            }
            else
            {
LABEL_94:
              v43 = *(uint32_t *)(v41 + 24);
            }
            v42 = *(uint32_t *)(v43 + 8);
            goto LABEL_96;
          }
          if ( *(uint8_t *)(dword_1187E8 + 696 * v9 + 36) != 1 )
          {
            if ( (v28 & 2) == 0 )
              goto LABEL_132;
            v64 = dword_118318 + 1320 * v23;
            if ( timer_expired(*(uint16_t *)(v4 + 64)) )
            {
              v27 = *(uint8_t *)(v64 + 1224);
LABEL_132:
              if ( !v27 || *(uint8_t *)(v8 + 112) != 1 || *(uint8_t *)(v8 + 133) )
                goto LABEL_53;
            }
          }
          alloc_tx_event("st %x, %d, %x\r\n", v62, a1, v4);
          v54 = (*(volatile uint32_t *)0x40501010u);
          v55 = *(uint16_t *)(v4 + 30);
          v56 = *(uint32_t *)(v4 + 76);
          v57 = off_1187CC;
          *(uint16_t *)(v4 + 64) = *((uint16_t *)off_1187F4 + 22) + (v54 >> 10);
          *(uint32_t *)(v4 + 68) = 0;
          *(uint32_t *)(v56 + 72) = 0;
          *(uint32_t *)(v56 + 4) = 0;
          *(uint16_t *)(v4 + 82) = 0;
          *(uint32_t *)(v4 + 44) = 0;
          *(uint32_t *)(v4 + 36) = 0;
          *(uint16_t *)(v4 + 30) = v55 | 1;
          list_foreach(
            v25 + 8 * (165 * (uint16_t)v23 + a1 + 159),
            (uint32_t *)v4,
            (int ( *)(uint32_t *, uint32_t *))v57);
          v3 = (uint32_t *)irq_disable_global_2(512);
          goto LABEL_36;
        }
      }
      else if ( !v8 )
      {
        goto LABEL_39;
      }
      if ( (*(uint8_t *)(v8 + 8) & 0x10) == 0 )
        return v3;
      v10 = *(uint32_t *)(v7 + 4) & 0xFF7FFFFF;
      v11 = *(uint8_t *)(v8 + 8) & 0x40;
      ++a2;
      *(uint32_t *)(v7 + 4) = v10;
      if ( v11 )
      {
        v37 = *(uint16_t **)(v8 + 224);
        if ( !v37
          || (v38 = (*(uint16_t *)(v4 + 32) - (*v37 >> 4)) & 0xFFF, v38 <= 0x7FE)
          && ((*v37 & 0xF) != 4 ? (v39 = 3) : (v39 = 15),
              v39 >= v38 >> 4 && (((int)(uint16_t)v37[(v38 >> 4) + 1] >> (v38 & 0xF)) & 1) != 0) )
        {
          ++a3;
          v40 = 8650752;
        }
        else
        {
          v40 = 0x40000;
        }
        v10 |= v40;
        *(uint32_t *)(v7 + 4) = v10;
      }
      v61 = phy_switch_radio(v4, 0);
      if ( (*(uint32_t *)(v4 + 36) & 0x380000) == 0x280000 )
        v6 = v4;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_118304 = 1;
      }
      ++*v5;
      v3 = list_pop(v1);
      if ( (*(uint32_t *)(v4 + 36) & 0x380000) == 0x380000 )
      {
        if ( **(uint16_t **)off_1185B4 < 0 && !v6 )
          irq_disable_mmio_write((int)aTxdescFirstNul, (int)aTxlCfmEvt_0, 706);
        if ( *(uint8_t *)(dword_1185B8 + 696 * v9 + 36) != 1 || v11 )
          mac_call_command(v6, a2, a3, v8);
        a3 = 0;
        v3 = (uint32_t *)decrement_refcount(v8);
        a2 = 0;
        v12 = 1;
      }
      else
      {
        v12 = 0;
      }
      if ( *v5 )
      {
        v13 = *v5 - 1;
        v14 = *(uint32_t *)off_118304;
        *v5 = v13;
        if ( !v13 )
        {
          if ( v14 )
            __enable_irq();
        }
      }
      if ( *(uint16_t *)(v4 + 24) == 36488 && (*(uint32_t *)(v7 + 4) & 0xF) == 9 )
      {
        v34 = dword_1185B8 + 696 * v9;
        v35 = *(uint8_t *)(v34 + 669);
        if ( v35 <= 1 )
        {
          v36 = *(uint32_t *)(*(uint32_t *)(v4 + 76) + 36);
          if ( v36 != *(uint16_t *)(v34 + 670) )
          {
            *(uint8_t *)(v34 + 669) = v35 + 1;
            *(uint16_t *)(v34 + 670) = v36;
          }
        }
      }
      if ( *(int *)(*(uint32_t *)(v4 + 44) + 60) < 0 )
      {
        if ( (v10 & 0x800000) != 0 )
        {
          v31 = *(uint32_t *)(v4 + 76);
          if ( **(uint16_t **)off_1185B4 >= 0 )
          {
            v32 = *(uint32_t *)(v31 + 28);
            if ( !v32 )
              goto LABEL_65;
LABEL_67:
            if ( (*(uint16_t *)v32 & 0x8000) != 0 && (*(uint16_t *)v32 & 0xC) == 8 && (*(uint32_t *)(v32 + 26) & 0x3F) == 7 )
              *(uint32_t *)(*(uint32_t *)(v4 + 44) + 60) &= ~0x80000000;
            v15 = (uint8_t **)off_1185D8;
            if ( !**(uint8_t **)off_1185D8 )
              goto LABEL_34;
            v16 = dword_1185DC;
            v63 = *(uint8_t *)(v4 + 28);
            v66 = dword_1185DC + 1320 * v63;
            goto LABEL_24;
          }
          if ( *(uint32_t *)(v4 + 72) )
          {
            v32 = *(uint32_t *)(v31 + 28);
            if ( v32 )
              goto LABEL_67;
            goto LABEL_111;
          }
          v3 = (uint32_t *)irq_disable_mmio_write((int)aTxlBufferGetTx, (int)aTxlBufferMachd_0, 518);
          v32 = *(uint32_t *)(v31 + 28);
          if ( v32 )
            goto LABEL_67;
          if ( **(uint16_t **)off_1187FC < 0 )
          {
LABEL_111:
            v33 = *(uint32_t *)(v31 + 24);
            if ( !v33 )
            {
              v3 = (uint32_t *)irq_disable_mmio_write((int)aThdFirstPbdPtr, (int)aTxlBufferMachd_0, 525);
              goto LABEL_65;
            }
          }
          else
          {
LABEL_65:
            v33 = *(uint32_t *)(v31 + 24);
          }
          v32 = *(uint32_t *)(v33 + 8);
          goto LABEL_67;
        }
        v15 = (uint8_t **)off_1185D8;
        if ( !**(uint8_t **)off_1185D8 )
          goto LABEL_34;
        v16 = dword_1185DC;
        v63 = *(uint8_t *)(v4 + 28);
        v66 = dword_1185DC + 1320 * v63;
      }
      else
      {
        v15 = (uint8_t **)off_118314;
        if ( !**(uint8_t **)off_118314 )
          goto LABEL_34;
        v16 = dword_118318;
        v63 = *(uint8_t *)(v4 + 28);
        v66 = dword_118318 + 1320 * v63;
        if ( (v10 & 0x800000) != 0 )
          goto LABEL_24;
      }
      if ( v61 && *(uint8_t *)(v16 + 1320 * v63 + 108) )
      {
        v50 = *(uint32_t *)(v4 + 76);
        v51 = *(uint16_t *)(v4 + 30) | 1;
        *(uint32_t *)(v4 + 68) = 0;
        *(uint32_t *)(v50 + 72) = 0;
        *(uint32_t *)(v50 + 4) = 0;
        *(uint16_t *)(v4 + 30) = v51;
        v52 = off_1187CC;
        *(uint16_t *)(v4 + 82) = 0;
        *(uint32_t *)(v4 + 44) = 0;
        *(uint32_t *)(v4 + 36) = 0;
        v3 = (uint32_t *)list_foreach(
                         v16 + 8 * (a1 + 159 + 165 * v63),
                         (uint32_t *)v4,
                         (int ( *)(uint32_t *, uint32_t *))v52);
        if ( v12 )
          goto LABEL_117;
        v65 = 1;
        goto LABEL_36;
      }
LABEL_24:
      v17 = *(uint8_t *)(v4 + 29);
      if ( v17 <= 0x1F )
      {
        v18 = *(uint8_t *)(v4 + 27);
        if ( v18 <= 8 )
          *(uint32_t *)(dword_118308 + 4 * (9 * v17 + v18 + 2062)) -= *(uint16_t *)(v4 + 4);
      }
      check_cal_status(v4, (uint32_t *)(v7 + 4));
      if ( (*(uint16_t *)(v4 + 30) & 1) != 0 )
      {
        irq_disable_global_2(512);
        v19 = *(uint32_t **)(v4 + 72);
        if ( !v19 )
        {
LABEL_101:
          alloc_tx_event("buffer is null in %s\n", aTxlCfmEvt);
          goto LABEL_31;
        }
      }
      else
      {
        v19 = *(uint32_t **)(v4 + 72);
        if ( !v19 )
          goto LABEL_101;
      }
      wait_for_state(v19);
      v20 = *v15;
      *(uint32_t *)(v4 + 72) = 0;
      if ( *v20 == 1 )
        invoke_handler();
LABEL_31:
      v3 = (uint32_t *)unknown_12f4b4((uint8_t)a1, v4);
      if ( v12 )
      {
        if ( v65 )
        {
LABEL_117:
          if ( phy_lock(v66) && !*((uint8_t *)off_1187D0 + 511) )
          {
            do
            {
              v53 = *(uint32_t *)(v16 + 8 * (165 * v63 + a1 + 159));
              if ( !v53 )
                break;
              list_pop(v16 + 8 * (a1 + 159 + 165 * v63));
              phy_txpower_calc(v53, (uint8_t)a1);
            }
            while ( !*((uint8_t *)off_1187D0 + 511) );
          }
        }
        v3 = (uint32_t *)irq_disable_global_2(512);
        v65 = 0;
LABEL_34:
        if ( v12 )
          v6 = 0;
      }
LABEL_36:
      v4 = *(uint32_t *)(dword_1182F4 + 8 * a1);
    }
    while ( v4 );
  }
  return v3;
}
