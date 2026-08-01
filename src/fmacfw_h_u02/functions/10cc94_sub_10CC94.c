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

extern uint32_t off_10CF64;
extern uint32_t off_10CF6C;
extern uint32_t off_10CF70;
extern uint32_t off_10CF68;
extern uint32_t dword_10D05C;
extern uint32_t dword_10D058;
extern uint32_t dword_10D064;
extern uint32_t dword_10D060;
extern uint32_t dword_10CF90;
extern uint32_t off_10CF8C;
extern uint32_t dword_10D03C;
extern uint32_t off_10CF78;
extern uint32_t off_10D040;
extern uint32_t off_10D044;
extern uint32_t dword_10D048;
extern uint32_t dword_10D04C;
extern uint32_t dword_10D050;
extern uint32_t off_10CF80;
extern uint32_t off_10CF84;
extern uint32_t dword_10CF94;
extern uint32_t dword_10CF9C;
extern uint32_t dword_10CF98;
extern uint32_t off_10CF7C;
extern uint32_t dword_10CF88;
extern uint32_t off_10CF74;
extern uint32_t dword_10D054;

// rx_packet_dispatch @ 0x10cc94, size 936 bytes
int  rx_packet_dispatch(uint16_t *a1)
{
  uint8_t **v1; // r7
  uint8_t *v2; // r2
  int v3; // r3
  int v5; // r6
  int v6; // r5
  int v7; // r9
  unsigned int v8; // r2
  int v9; // r3
  uint32_t *v10; // r6
  uint32_t *v11; // r3
  int v12; // r0
  int v13; // r1
  int16_t v14; // lr
  uint8_t *v15; // r6
  unsigned int v16; // r2
  int16_t v17; // r12
  int v18; // r8
  int *v19; // r3
  int v20; // r10
  int v21; // r3
  int v22; // r0
  char v23; // r2
  int *v24; // r6
  int v25; // r0
  int v26; // r0
  int v27; // r3
  int v28; // r2
  int *v29; // r0
  int v30; // r1
  int v31; // r2
  uint16_t v32; // r2
  uint16_t v34; // r1
  uint16_t v35; // r2
  uint8_t *v36; // r3
  int *v37; // r6
  int v38; // r0
  int v39; // r3
  int v40; // r2
  uint32_t *v41; // r5
  int v42; // r0
  int v43; // r3
  int v44; // r8
  int v45; // r3
  int *v46; // r5
  int v47; // r1
  int v48; // r2
  int v49; // r1
  int v50; // r0
  int v51; // [sp+0h] [bp-8h]

  v1 = (uint8_t **)off_10CF64;
  v2 = *(uint8_t **)off_10CF64;
  v3 = **(uint8_t **)off_10CF64;
  if ( v3 != 3 )
  {
    v5 = 0;
    goto LABEL_3;
  }
  v41 = off_10CF6C;
  while ( !*(uint32_t *)off_10CF6C )
    ;
  if ( !*(uint32_t *)(*(uint32_t *)off_10CF70 + 516) )
  {
    v45 = **(int16_t **)off_10CF68;
    *(uint32_t *)off_10CF6C = 1;
    if ( v45 >= 0 )
    {
      v5 = 4;
      goto LABEL_50;
    }
    goto LABEL_71;
  }
  v42 = list_pop(*(uint32_t *)off_10CF70 + 516);
  v43 = **(int16_t **)off_10CF68;
  *v41 = 1;
  if ( v43 < 0 )
  {
    if ( v42 )
    {
      v44 = v42 + 4;
      if ( v42 == -4 )
      {
        irq_disable_mmio_write(dword_10D05C, dword_10D058, 1567);
        v5 = v44;
        v2 = *v1;
        goto LABEL_50;
      }
      goto LABEL_49;
    }
LABEL_71:
    v5 = 4;
    irq_disable_mmio_write(dword_10D064, dword_10D060, 973);
    v2 = *v1;
    goto LABEL_50;
  }
  v44 = v42 + 4;
LABEL_49:
  v2 = *v1;
  v5 = v44;
LABEL_50:
  *(uint32_t *)(v5 + 8) = dword_10CF90;
  v3 = *v2;
LABEL_3:
  if ( v3 == 1 )
  {
    if ( a1[5] <= 0x6Cu )
      v6 = mmio_read_2();
    else
      v6 = (*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10CF8C + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10CF8C + 4));
    if ( !v6 )
      goto LABEL_59;
    v34 = a1[3];
    v35 = a1[4];
    *(uint32_t *)(v6 + 12) = dword_10CF90;
    v36 = *v1;
    *(uint16_t *)(v6 + 6) = v34;
    *(uint16_t *)(v6 + 8) = v35;
    v5 = v6 + 4;
    if ( *v36 != 2 )
      goto LABEL_5;
  }
  else
  {
    v6 = 0;
    if ( v3 != 2 )
    {
LABEL_5:
      v7 = 0;
      goto LABEL_6;
    }
  }
  if ( a1[5] <= 0x6Cu )
    v6 = util_call_void();
  else
    v6 = (*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10CF8C + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10CF8C
                                                                                                 + 4));
  if ( !v6 )
  {
LABEL_59:
    debug_printf(dword_10D03C, a1[2], a1[4]);
    return tx_process_jump(a1);
  }
  if ( !*((uint32_t *)off_10CF78 + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_10D040 = 1;
    }
    v46 = (int *)off_10D044;
    ++*(uint32_t *)off_10D044;
    ((void (*)(void))rf_is_idle)();
    if ( *v46 )
    {
      v48 = *v46 - 1;
      v47 = *(uint32_t *)off_10D040;
      *v46 = v48;
      if ( !v48 )
      {
        if ( v47 )
          __enable_irq();
      }
    }
    v51 = list_length(dword_10D048, v47);
    v50 = list_length(dword_10D04C, v49);
    debug_printf(dword_10D050, v51, v50);
    return tx_process_jump(a1);
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10CF80 = 1;
  }
  v37 = (int *)off_10CF84;
  v38 = dword_10CF94;
  ++*(uint32_t *)off_10CF84;
  v7 = list_pop(v38);
  if ( *v37 )
  {
    v39 = *v37 - 1;
    v40 = *(uint32_t *)off_10CF80;
    *v37 = v39;
    if ( !v39 )
    {
      if ( v40 )
        __enable_irq();
    }
  }
  *(uint16_t *)v6 = a1[5] + 12;
  *(uint8_t *)(v6 + 2) = 17;
  *(uint8_t *)(v6 + 3) = 0;
  v5 = v6 + 4;
LABEL_6:
  v8 = a1[5];
  *(uint16_t *)v5 = a1[2];
  *(uint16_t *)(v5 + 6) = v8;
  if ( v8 )
  {
    if ( **(int16_t **)off_10CF68 < 0 && v8 > 0x400 )
    {
      irq_disable_mmio_write(dword_10CF9C, dword_10CF98, 1671);
      v8 = a1[5];
    }
    memcpy(v5 + 12, a1 + 6, v8);
    v9 = **v1;
    if ( v9 != 3 )
    {
LABEL_8:
      if ( v9 != 2 )
        goto LABEL_9;
LABEL_16:
      v12 = a1[5];
      if ( (v12 & 3) != 0 )
      {
        v14 = (uint8_t)(4 - (v12 & 3));
        v13 = (uint8_t)(4 - (v12 & 3));
      }
      else
      {
        v13 = 0;
        v14 = 0;
      }
      v15 = off_10CF78;
      v16 = *((uint16_t *)off_10CF78 + 4122);
      if ( v16 > 0x186 )
      {
        v18 = 0;
        LOWORD(v16) = 0;
        v17 = 1;
      }
      else
      {
        v17 = v16 + 1;
        v18 = 8 * v16;
      }
      v19 = (int *)off_10CF7C;
      *(uint16_t *)(v7 + 12) = v16;
      v20 = *v19;
      v21 = v12 + 16;
      v22 = v20 + v18;
      *(uint32_t *)(v22 + 4) = v6;
      *(uint16_t *)(v20 + v18) = v14 + v21;
      *(uint8_t *)(v22 + 3) = *(uint8_t *)(v20 + v18 + 3) & 0x31 | 4;
      v23 = v15[3074];
      *((uint16_t *)v15 + 4122) = v17;
      v15[3074] = v23 + 1;
      *(uint32_t *)(v7 + 4) = v20 + v18;
      *(uint32_t *)(v7 + 8) = v21 + v13;
      *(uint8_t *)(v7 + 14) = 1;
      *(uint32_t *)v7 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_10CF80 = 1;
      }
      v24 = (int *)off_10CF84;
      v25 = dword_10CF88;
      ++*(uint32_t *)off_10CF84;
      v26 = wlan_ioctl_handler_1(v25);
      rf_is_idle(v26);
      if ( *v24 )
      {
        v27 = *v24 - 1;
        v28 = *(uint32_t *)off_10CF80;
        *v24 = v27;
        if ( !v27 )
        {
          if ( v28 )
            __enable_irq();
        }
      }
      if ( **v1 != 1 )
        return tx_process_jump(a1);
      goto LABEL_27;
    }
  }
  else
  {
    v9 = **v1;
    if ( v9 != 3 )
      goto LABEL_8;
  }
  v10 = off_10CF6C;
  while ( !*(uint32_t *)off_10CF6C )
    ;
  wlan_ioctl_handler_1(*(uint32_t *)off_10CF70 + 524);
  v11 = off_10CF74;
  *v10 = 1;
  *v11 = 2;
  v9 = **v1;
  if ( v9 == 2 )
    goto LABEL_16;
LABEL_9:
  if ( v9 != 1 )
    return tx_process_jump(a1);
LABEL_27:
  v29 = (int *)mmio_read_0();
  if ( !v29 )
  {
    debug_printf(dword_10D054, v30, v31);
    return tx_process_jump(a1);
  }
  *(uint16_t *)v6 = a1[5] + 12;
  *(uint8_t *)(v6 + 2) = 17;
  *(uint8_t *)(v6 + 3) = 0;
  v32 = a1[5];
  v29[1] = 0;
  *v29 = v6;
  v29[2] = (uint16_t)(v32 + 16) | 0x80000000;
  memcpy();
  return tx_process_jump(a1);
}

