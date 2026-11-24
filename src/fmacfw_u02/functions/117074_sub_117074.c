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


extern uint32_t dword_11733C;
extern uint32_t dword_117340;
extern uint32_t dword_117344;
extern uint32_t dword_117348;
extern uint32_t dword_11734C;
extern uint32_t dword_117350;
extern uint32_t dword_117358;
extern uint32_t dword_11735C;
extern uint32_t dword_117360;
extern uint32_t dword_117364;
extern uint32_t dword_117368;
extern uint32_t dword_11736C;
extern uint32_t dword_11746C;
extern uint32_t dword_117478;
extern uint32_t dword_117484;
extern uint32_t dword_117488;
extern uint32_t dword_11748C;
extern uint32_t dword_117490;
extern uint32_t dword_117494;
extern uint32_t dword_117498;

// phy_radio_switch @ 0x117074, size 1016 bytes
int  phy_radio_switch(int result)
{
  int v1; // r6
  unsigned int v2; // r4
  unsigned int v3; // r7
  int v4; // r3
  unsigned int *v5; // r8
  int v6; // r5
  int v7; // r3
  int v8; // r2
  unsigned int v9; // r3
  uint16_t v10; // r3
  int v11; // r0
  int v12; // r2
  int v13; // r3
  int v14; // r5
  uint32_t *v15; // r11
  int v16; // r10
  int v17; // r3
  int v18; // r1
  int v19; // r0
  unsigned int v20; // r3
  volatile unsigned int v21; // r2
  int v22; // r3
  unsigned int v23; // r3
  int v24; // r10
  int v25; // r3
  uint32_t *v26; // r2
  uint32_t *v27; // r5
  int v28; // r1
  int *v29; // r3
  int v30; // r3
  unsigned int v31; // r1
  int v32; // r10
  volatile unsigned int v33; // r2
  int *v34; // r3
  int v35; // r3
  uint32_t *v36; // r2
  uint32_t *v37; // r4
  int v38; // r1
  int *v39; // r3
  int v40; // r3
  int v41; // [sp+0h] [bp-14h]
  int v42; // [sp+4h] [bp-10h]
  unsigned int v43; // [sp+8h] [bp-Ch]
  int v44; // [sp+Ch] [bp-8h]

  v1 = result;
  if ( result == 5 )
    v2 = dword_117484;
  else
    v2 = dword_11733C + 84 * result;
  v3 = dword_117344;
  v41 = 1 << result;
  v4 = *(uint8_t *)(v2 + 26);
  v43 = result + dword_117340;
  v5 = (unsigned int *)(4 * (result + dword_117340));
  v42 = ~(1 << result);
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !v4 )
        goto LABEL_14;
      v6 = *(uint32_t *)(v2 + 36);
      v7 = *(uint8_t *)(*(uint32_t *)v3 + 1);
      v8 = *(uint32_t *)(v6 + 144);
      if ( *(uint8_t *)(*(uint32_t *)v3 + 1) )
      {
        if ( v8 >= 0 )
          return result;
        if ( *(uint32_t *)(v6 + 88) || *(uint8_t *)(v2 + 80) != 1 )
        {
          v9 = REG_4032_0120 + *(uint32_t *)(dword_117348 + 4 * v1);
          *v5 = v9;
LABEL_9:
          if ( (v8 & 0x800000) != 0 )
          {
            v10 = *(uint16_t *)(v6 + 8);
            if ( (v10 & 0x20) == 0 )
            {
              rf_irq_status_check();
              v32 = 4;
              while ( 1 )
              {
                v10 = *(uint16_t *)(v6 + 8);
                if ( (v10 & 0x20) != 0 )
                  break;
                rf_irq_status_check();
                if ( !--v32 )
                {
                  v10 = *(uint16_t *)(v6 + 8);
                  if ( **(uint16_t **)dword_11746C < 0 && (v10 & 0x20) == 0 )
                    return bad_func_0x12f408((int)aAggDescStatusA, (int)aTxlFrameExchan_0, 1262);
                  goto LABEL_11;
                }
              }
            }
          }
          else
          {
LABEL_36:
            mem_word_load(v2 + 28);
            v10 = *(uint16_t *)(v6 + 8);
          }
          goto LABEL_11;
        }
      }
      else
      {
        if ( *(int *)(v6 + 76) >= 0 )
          return result;
        if ( *(uint32_t *)(v6 + 20) || *(uint8_t *)(v2 + 80) != 1 )
        {
          v23 = REG_4032_0120 + *(uint32_t *)(dword_117348 + 4 * v1);
          *v5 = v23;
          goto LABEL_31;
        }
      }
      if ( *(uint32_t *)(v2 + 44)
        && !*(uint32_t *)(dword_117368 + 8 * (165 * *(uint8_t *)(*(uint32_t *)(v2 + 48) + 28) + v1 + 154))
        && !*(uint8_t *)(dword_117498 + 0x1FF) )
      {
        v44 = *(uint32_t *)(v6 + 144);
        rate_get_config(v1);
        v8 = v44;
        v7 = *(uint8_t *)(*(uint32_t *)v3 + 1);
      }
      v31 = REG_4032_0120 + *(uint32_t *)(dword_117348 + 4 * v1);
      *v5 = v31;
      if ( v7 )
        goto LABEL_9;
LABEL_31:
      v10 = *(uint16_t *)(v6 + 8);
      if ( (v10 & 0x20) == 0 )
      {
        rf_irq_status_check();
        v24 = 4;
        while ( 1 )
        {
          v10 = *(uint16_t *)(v6 + 8);
          if ( (v10 & 0x20) != 0 )
            break;
          rf_irq_status_check();
          if ( !--v24 )
          {
            v10 = *(uint16_t *)(v6 + 8);
            if ( (v10 & 0x20) != 0 )
              break;
            goto LABEL_36;
          }
        }
      }
LABEL_11:
      v11 = *(uint32_t *)(dword_11734C + 4 * v1);
      *(uint16_t *)(v6 + 8) = v10 | 0x10;
      result = unknown_func_12d104(v11);
      v12 = *(uint32_t *)v3;
      --*(uint8_t *)(v2 + 80);
      *(uint8_t *)(v2 + 26) = 0;
      *(uint32_t *)(v2 + 36) = 0;
      if ( *(uint8_t *)(v12 + 1) )
        break;
      v13 = *(uint32_t *)(v6 + 20);
      if ( v13 )
        goto LABEL_13;
LABEL_38:
      *(uint32_t *)v2 = v13;
      v25 = *(uint32_t *)dword_117358;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)dword_11735C = 1;
      }
      v26 = (uint32_t *)dword_117360;
      result = *(uint32_t *)dword_117360;
      v27 = (uint32_t *)dword_117358;
      v28 = *(uint32_t *)dword_117360 + 1;
      *(uint32_t *)dword_117360 = v28;
      *v27 = v25 & v42;
      if ( v28 )
      {
        v29 = (int *)dword_11735C;
        *v26 = result;
        v30 = *v29;
        if ( !result )
        {
          if ( v30 )
            __enable_irq();
        }
      }
      *(uint32_t *)dword_117364 = v41;
      v4 = *(uint8_t *)(v2 + 26);
    }
    v13 = *(uint32_t *)(v6 + 88);
    if ( !v13 )
      goto LABEL_38;
LABEL_13:
    *(uint32_t *)(v2 + 40) = v6;
    ++*(uint8_t *)(v6 + 14);
LABEL_14:
    v14 = *(uint32_t *)(v2 + 12);
    if ( !v14 )
      break;
    v15 = *(uint32_t **)(v14 + 76);
    v16 = v15[18];
    if ( v16 >= 0 )
    {
      if ( (*(uint32_t *)(v14 + 36) & 0x380000) == 0x280000 )
        return get_hw_state(*(uint32_t *)(v14 + 68) + 16, v1);
      return result;
    }
    v15[1] = v16;
    get_channel_by_handle(v1);
    v17 = *(uint32_t *)(v14 + 36) & 0x200000;
    if ( !v17 )
    {
      v18 = v15[4];
      if ( v18 )
      {
        v19 = v15[4];
        if ( (*(uint32_t *)(v18 + 56) & 0x380000) == 0x200000 )
        {
          if ( **(uint16_t **)dword_11736C < 0 && !*(uint32_t *)(v18 + 8) )
          {
            mmio_clear_register((int)aNextdescNull, (int)aTxlFrameExchan_0, 1077);
            __und(0xFFu);
          }
          v17 = v15[4];
          v19 = *(uint32_t *)(v18 + 8);
        }
        if ( *(int *)(v19 + 60) >= 0 )
        {
          result = v17;
          if ( v17 )
            result = get_hw_state(v17, v1);
          v33 = REG_4032_0120;
          *(uint32_t *)(4 * v43) = v33 + *(uint32_t *)(dword_117478 + 4 * v1);
          return result;
        }
      }
      else
      {
        *(uint32_t *)v2 = 0;
        mmio_set_bit_1(v1);
        if ( *(uint8_t *)(v2 + 80) == 1
          && *(uint32_t *)(v2 + 44)
          && !*(uint32_t *)(dword_117368 + 8 * (165 * *(uint8_t *)(*(uint32_t *)(v2 + 48) + 28) + v1 + 154))
          && !*(uint8_t *)(dword_11733C + 0x1FF) )
        {
          rate_get_config(v1);
        }
      }
    }
    if ( (v16 & 0x800000) != 0 )
    {
      v20 = *(uint8_t *)(v14 + 29);
      if ( v20 <= 0x23 )
      {
        v21 = (*(volatile uint32_t *)0x40501010u);
        *(uint32_t *)(dword_117350 + 696 * v20 + 664) = v21;
      }
    }
    mem_word_load(v2 + 12);
    if ( *(uint16_t *)(v14 + 4) )
      ipc_handler_register((uint32_t *)v14, v16, v1);
    else
      free_buf_1882c0((uint32_t *)v14);
    v22 = *(uint32_t *)(v14 + 36);
    result = v22 << 10;
    if ( (v22 & 0x200000) != 0 )
    {
      if ( (v22 & 0x380000) == 0x380000 )
      {
        *(uint32_t *)(v2 + 36) = *(uint32_t *)(v14 + 68);
        *(uint8_t *)(v2 + 26) = 1;
        result = unknown_func_12d104(512);
      }
    }
    else
    {
      --*(uint8_t *)(v2 + 80);
    }
    *v5 = REG_4032_0120 + *(uint32_t *)(dword_117348 + 4 * v1);
    v4 = *(uint8_t *)(v2 + 26);
  }
  v34 = (int *)dword_117488;
  *(uint32_t *)v2 = 0;
  v35 = *v34;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)dword_11748C = 1;
  }
  v36 = (uint32_t *)dword_117490;
  result = *(uint32_t *)dword_117490;
  v37 = (uint32_t *)dword_117488;
  v38 = *(uint32_t *)dword_117490 + 1;
  *(uint32_t *)dword_117490 = v38;
  *v37 = v35 & v42;
  if ( v38 )
  {
    v39 = (int *)dword_11748C;
    *v36 = result;
    v40 = *v39;
    if ( !result )
    {
      if ( v40 )
        __enable_irq();
    }
  }
  *(uint32_t *)dword_117494 = v41;
  return result;
}
