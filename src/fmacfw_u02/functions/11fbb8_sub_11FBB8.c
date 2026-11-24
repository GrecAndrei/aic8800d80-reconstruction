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


extern uint32_t dword_11FEBC;
extern uint32_t dword_11FEC0;
extern uint32_t dword_11FEE4;
extern uint32_t dword_120018;
extern uint32_t off_11FEC4;
extern uint32_t off_11FEC8;
extern uint32_t off_11FECC;
extern uint32_t off_11FED0;
extern uint32_t off_11FED4;
extern uint32_t off_11FED8;
extern uint32_t off_11FEEC;
extern uint32_t off_11FEF4;
extern uint32_t off_11FEF8;
extern uint32_t off_11FEFC;
extern uint32_t off_11FF00;
extern uint32_t off_11FF04;
extern uint32_t off_11FF08;
extern uint32_t off_12000C;
extern uint32_t off_120010;
extern uint32_t off_120014;
extern uint32_t off_12001C;
extern uint32_t off_120020;
extern uint32_t off_12002C;
extern uint32_t off_120030;

// get_object_by_index @ 0x11fbb8, size 1108 bytes
int  get_object_by_index(int a1)
{
  int v2; // r6
  int *v3; // r8
  int v4; // r3
  uint8_t *v5; // r5
  int v6; // r2
  int v7; // r3
  int v8; // r3
  int v9; // r4
  void *v10; // r6
  int v11; // r3
  int *v13; // r10
  int v14; // r9
  int v15; // r3
  uint32_t **v16; // r7
  int v17; // r5
  int v18; // r11
  int v19; // r0
  int v20; // r3
  int v21; // r2
  int v22; // r0
  int v23; // r3
  int v24; // r2
  uint16_t **v25; // r10
  uint32_t *v26; // r7
  int v27; // r1
  int v28; // r9
  unsigned int v29; // r3
  uint32_t *v30; // r0
  uint32_t *v31; // r3
  int v32; // r1
  int v33; // r2
  unsigned int v34; // r3
  int v35; // r3
  int v36; // r0
  int v37; // r3
  int v38; // r1
  int *v39; // r7
  int v40; // r3
  int v41; // r1
  int v42; // r2
  int v43; // r3
  uint32_t *v44; // r12
  uint32_t *v45; // r1
  int v46; // r0
  int v47; // [sp+0h] [bp-24h]
  int v48; // [sp+4h] [bp-20h]
  int a2; // [sp+8h] [bp-1Ch]
  int v50; // [sp+Ch] [bp-18h]
  int v51; // [sp+10h] [bp-14h]
  int *v52; // [sp+14h] [bp-10h]
  int v53; // [sp+1Ch] [bp-8h]

  v2 = dword_11FEBC;
  v3 = (int *)(dword_11FEBC + 1320 * a1);
  v50 = 1320 * a1;
  cmd_handler_c(dword_11FEC0, v3);
  if ( *((int **)off_11FEC4 + 8) == v3 )
    *((uint32_t *)off_11FEC4 + 8) = 0;
  v4 = *(uint8_t *)(v2 + 1320 * a1 + 106);
  if ( v4 == 2 )
  {
    v13 = (int *)off_11FF04;
    v52 = v3;
    v14 = dword_11FEE4 + 696 * (a1 + 32);
    v15 = dword_11FEE4 + 8 * (87 * (a1 + 32) + 78);
    v53 = off_11FEC8;
    --*(uint8_t *)(off_11FEC8 + 0x12);
    a2 = v15;
    *(uint8_t *)(v14 + 37) = 0;
    v16 = (uint32_t **)(v2 + 8 * (165 * (uint16_t)a1 + 159));
    v17 = 0;
    do
    {
      if ( *(uint32_t *)(v14 + 584) )
        rf_tx_setup((uint8_t)v17, a2 - 40, 0);
      if ( *(uint32_t *)(v14 + 624) )
        rf_tx_setup((uint8_t)v17, a2, 0);
      if ( v3[318] || v3[308] )
      {
        v18 = (int)(v16 - 10);
        v51 = read_u32(v16);
        v19 = read_u32(v16 - 10);
        event_dispatch("vif unregister:%d, %d\n", v51, v19);
      }
      else
      {
        v18 = (int)(v16 - 10);
      }
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_11FEEC = 1;
      }
      ++*v13;
      rf_tx_setup((uint8_t)v17, (int)v16, 0);
      rf_tx_setup((uint8_t)v17, v18, 0);
      if ( *v13 )
      {
        v20 = *v13 - 1;
        v21 = *(uint32_t *)off_11FEEC;
        *v13 = v20;
        if ( !v20 )
        {
          if ( v21 )
            __enable_irq();
        }
      }
      ++v17;
      v14 += 8;
      v16 += 2;
      v3 += 2;
      a2 += 8;
    }
    while ( v17 != 5 );
    v3 = v52;
    v5 = (uint8_t *)v53;
    if ( *(uint32_t *)(v2 + 1320 * a1 + 1312) )
    {
      v22 = read_u32((uint32_t **)(v50 + 1312 + v2));
      event_dispatch("vif unregister mgmt:%d\n", v22);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11FEEC = 1;
    }
    ++*v13;
    rf_tx_setup(5u, v50 + 1312 + v2, 0);
    if ( *v13 )
    {
      v23 = *v13 - 1;
      v24 = *(uint32_t *)off_11FEEC;
      *v13 = v23;
      if ( !v23 )
      {
        if ( v24 )
          __enable_irq();
      }
    }
    v6 = *(uint8_t *)(v53 + 18);
    if ( !*(uint8_t *)(v53 + 18) )
    {
      mac_irq_disable_1();
LABEL_6:
      v6 = (uint8_t)v5[18];
      v7 = (uint8_t)v5[17] + v6;
      if ( v7 != 1 )
        goto LABEL_7;
      goto LABEL_40;
    }
    if ( *(uint8_t *)(v53 + 17) + v6 != 1 )
      goto LABEL_9;
  }
  else
  {
    if ( v4 != 4 )
    {
      v5 = (uint8_t *)off_11FEC8;
      if ( !*(uint8_t *)(v2 + 1320 * a1 + 106) )
      {
        v6 = *(uint8_t *)(off_11FEC8 + 0x12);
        v35 = (uint8_t)(*(uint8_t *)(off_11FEC8 + 0x11) - 1);
        *(uint8_t *)(off_11FEC8 + 0x11) = v35;
        v7 = v35 + v6;
        if ( v7 != 1 )
          goto LABEL_7;
        goto LABEL_40;
      }
      goto LABEL_6;
    }
    if ( rf_check_status() )
      rf_set_pa_bit(0);
    v5 = off_12000C;
    v36 = *((uint8_t *)off_12000C + 16);
    v37 = v2 + 1320 * v36;
    v38 = *(uint32_t *)(v37 + 72);
    *(uint32_t *)(v37 + 4) &= ~0x80u;
    if ( v38 )
      sta_get_by_index(v36);
    v6 = (uint8_t)v5[18];
    if ( v5[18] )
    {
      mac_irq_enable_1();
      v6 = (uint8_t)v5[18];
    }
    else
    {
      v39 = (int *)off_120014;
      v40 = dword_120018;
      v41 = **(uint16_t **)off_120010;
      *(uint32_t *)off_120014 = dword_120018;
      if ( v41 < 0 )
      {
        v6 = *(uint32_t *)off_120020 & 0xF;
        if ( v6 )
        {
          call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
          v40 = *v39;
          v6 = (uint8_t)v5[18];
        }
      }
      *(uint32_t *)off_12001C = v40 | v39[1];
    }
    v7 = (uint8_t)v5[17] + v6;
    v5[16] = -1;
    if ( v7 != 1 )
      goto LABEL_7;
  }
LABEL_40:
  v25 = (uint16_t **)off_11FF08;
  v26 = off_11FEF4;
  v27 = **(uint16_t **)off_11FF08;
  v28 = *((uint32_t *)v5 + 2);
  v29 = *((uint32_t *)off_11FEF4 + 1) & 0xFFFFFFEF;
  *((uint32_t *)off_11FEF4 + 1) = v29;
  if ( v27 >= 0 || !(*(uint32_t *)off_120020 << 28) )
  {
    v30 = off_11FEF8;
    *(uint32_t *)off_11FF00 = v29 | *v26;
    v31 = off_11FEFC;
    v32 = *(uint16_t *)(v28 + 68);
    *v30 = *(uint32_t *)(v28 + 64);
    *v31 = v32;
    if ( v6 )
      goto LABEL_9;
LABEL_42:
    v33 = **v25;
    v34 = v26[1] & 0xFFFFFEFF;
    v26[1] = v34;
    if ( v33 >= 0 || !(*(uint32_t *)off_120020 << 28) )
    {
      *(uint32_t *)off_11FF00 = v34 | *v26;
      goto LABEL_9;
    }
    call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
    v7 = (uint8_t)v5[17] + (uint8_t)v5[18];
    *(uint32_t *)off_12001C = *v26 | v26[1];
    goto LABEL_7;
  }
  call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
  v42 = (uint8_t)v5[18];
  v43 = (uint8_t)v5[17];
  v44 = off_120030;
  *(uint32_t *)off_12001C = *v26 | v26[1];
  v7 = v43 + v42;
  v45 = off_12002C;
  v46 = *(uint16_t *)(v28 + 68);
  *v44 = *(uint32_t *)(v28 + 64);
  *v45 = v46;
  if ( v7 == 1 )
  {
    if ( v42 )
      goto LABEL_9;
    goto LABEL_42;
  }
LABEL_7:
  if ( !v7 )
    *(uint32_t *)off_11FECC = 0;
LABEL_9:
  fault_handler((uint32_t *)(v50 + 24 + v2));
  fault_handler((uint32_t *)(v50 + 48 + v2));
  v8 = v2 + 1320 * a1;
  if ( *(uint8_t *)(v8 + 1224) )
  {
    llc_evt_is_valid(*(uint8_t *)(v8 + 1225), 1);
    --v5[19];
  }
  tx_queue_entry_get(*(uint8_t *)(v2 + 1320 * a1 + 107));
  if ( *((int **)off_11FED0 + 4) == v3 )
    *((uint32_t *)off_11FED0 + 4) = 0;
  *(uint32_t *)off_11FED4 = 0;
  if ( (uint8_t)v5[18] + (uint8_t)v5[17] <= 1 )
    scan_active_get();
  memset(v3, 0, 0x528u);
  v48 = a1;
  v9 = v2 + 1320 * a1;
  v10 = off_11FED8;
  v47 = (uint8_t)v5[18];
  v11 = v47 + (uint8_t)v5[17];
  *(uint8_t *)(v9 + 106) = 5;
  *(uint32_t *)(v9 + 56) = v3;
  *(uint32_t *)(v9 + 52) = v10;
  *(uint8_t *)(v9 + 109) = 127;
  *(uint8_t *)(v9 + 110) = 127;
  check_status_bits(256, "%s:%d,%d,%d\r\n", aVifMgmtUnregis, v11, v47, v48);
  return cmd_handler_a(off_11FEC8, v3);
}
