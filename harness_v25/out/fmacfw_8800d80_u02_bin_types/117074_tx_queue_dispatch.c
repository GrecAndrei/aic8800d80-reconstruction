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

extern uint32_t dword_117484;
extern uint32_t off_11733C;
extern uint32_t off_117344;
extern uint32_t off_117370;
extern uint32_t dword_117340;
extern uint32_t dword_117348;
extern uint32_t off_11746C;
extern uint32_t dword_117474;
extern uint32_t dword_117470;
extern uint32_t dword_117368;
extern uint32_t off_117498;
extern uint32_t dword_11734C;
extern uint32_t off_117358;
extern uint32_t off_11735C;
extern uint32_t off_117360;
extern uint32_t off_117364;
extern uint32_t off_11736C;
extern uint32_t dword_117480;
extern uint32_t off_11747C;
extern uint32_t dword_117478;
extern uint32_t dword_117350;
extern uint32_t off_117354;
extern uint32_t off_117488;
extern uint32_t off_11748C;
extern uint32_t off_117490;
extern uint32_t off_117494;

// tx_queue_dispatch @ 0x117074, size 1016 bytes
// Doc: tx_queue_dispatch [tx]: Dispatch handler selecting among 5 queue/state cases
// tx_queue_dispatch [tx]: Dispatch handler selecting among 5 queue/state cases
int  tx_queue_dispatch(int result)
{
  int v1; // r6
  char *v2; // r4
  int *v3; // r7
  uint32_t *v4; // r9
  int v5; // r3
  uint32_t *v6; // r8
  int v7; // r5
  int v8; // r3
  int v9; // r2
  int v10; // r3
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
  int v21; // r3
  int v22; // r10
  int v23; // r3
  int *v24; // r2
  int *v25; // r5
  int v26; // r1
  int *v27; // r3
  int v28; // r3
  int v29; // r10
  int *v30; // r3
  int v31; // r3
  int *v32; // r2
  int *v33; // r4
  int v34; // r1
  int *v35; // r3
  int v36; // r3
  int v37; // [sp+0h] [bp-14h]
  int v38; // [sp+4h] [bp-10h]
  int v39; // [sp+8h] [bp-Ch]
  int v40; // [sp+Ch] [bp-8h]

  v1 = result;
  if ( result == 5 )
    v2 = (char *)dword_117484;
  else
    v2 = (char *)off_11733C + 84 * result;
  v3 = (int *)off_117344;
  v4 = off_117370;
  v37 = 1 << result;
  v5 = (uint8_t)v2[26];
  v39 = result + dword_117340;
  v6 = (uint32_t *)(4 * (result + dword_117340));
  v38 = ~(1 << result);
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !v5 )
        goto LABEL_14;
      v7 = *((uint32_t *)v2 + 9);
      v8 = *(uint8_t *)(*v3 + 1);
      v9 = *(uint32_t *)(v7 + 144);
      if ( *(uint8_t *)(*v3 + 1) )
      {
        if ( v9 >= 0 )
          return result;
        if ( *(uint32_t *)(v7 + 88) || v2[80] != 1 )
        {
          *v6 = *v4 + *(uint32_t *)(dword_117348 + 4 * v1);
LABEL_9:
          if ( (v9 & 0x800000) != 0 )
          {
            LOWORD(v10) = *(uint16_t *)(v7 + 8);
            if ( (v10 & 0x20) == 0 )
            {
              sub_11EBFC(result);
              v29 = 4;
              while ( 1 )
              {
                v10 = *(uint16_t *)(v7 + 8);
                if ( (v10 & 0x20) != 0 )
                  break;
                sub_11EBFC(v10 << 26);
                if ( !--v29 )
                {
                  v10 = *(uint16_t *)(v7 + 8);
                  if ( **(int16_t **)off_11746C < 0 && (v10 & 0x20) == 0 )
                    return fmac_phy_op_handler(dword_117474, dword_117470, 1262, v10);
                  goto LABEL_11;
                }
              }
            }
          }
          else
          {
LABEL_36:
            rf_bus_mark_n100_d2d0(v2 + 28);
            LOWORD(v10) = *(uint16_t *)(v7 + 8);
          }
          goto LABEL_11;
        }
      }
      else
      {
        if ( *(int *)(v7 + 76) >= 0 )
          return result;
        if ( *(uint32_t *)(v7 + 20) || v2[80] != 1 )
        {
          *v6 = *v4 + *(uint32_t *)(dword_117348 + 4 * v1);
          goto LABEL_31;
        }
      }
      if ( *((uint32_t *)v2 + 11)
        && !*(uint32_t *)(dword_117368 + 8 * (165 * *(uint8_t *)(*((uint32_t *)v2 + 12) + 28) + v1 + 154))
        && !*((uint8_t *)off_117498 + 511) )
      {
        v40 = *(uint32_t *)(v7 + 144);
        sub_119EC8(v1);
        v9 = v40;
        v8 = *(uint8_t *)(*v3 + 1);
      }
      result = *(uint32_t *)(dword_117348 + 4 * v1);
      *v6 = *v4 + result;
      if ( v8 )
        goto LABEL_9;
LABEL_31:
      LOWORD(v10) = *(uint16_t *)(v7 + 8);
      if ( (v10 & 0x20) == 0 )
      {
        ((void (*)(void))sub_11EBFC)();
        v22 = 4;
        while ( 1 )
        {
          v10 = *(uint16_t *)(v7 + 8);
          if ( (v10 & 0x20) != 0 )
            break;
          sub_11EBFC(v10 << 26);
          if ( !--v22 )
          {
            LOWORD(v10) = *(uint16_t *)(v7 + 8);
            if ( (v10 & 0x20) != 0 )
              break;
            goto LABEL_36;
          }
        }
      }
LABEL_11:
      v11 = *(uint32_t *)(dword_11734C + 4 * v1);
      *(uint16_t *)(v7 + 8) = v10 | 0x10;
      result = irq_nesting_or_d104(v11);
      v12 = *v3;
      --v2[80];
      v2[26] = 0;
      *((uint32_t *)v2 + 9) = 0;
      if ( *(uint8_t *)(v12 + 1) )
        break;
      v13 = *(uint32_t *)(v7 + 20);
      if ( v13 )
        goto LABEL_13;
LABEL_38:
      *(uint32_t *)v2 = v13;
      v23 = *(uint32_t *)off_117358;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_11735C = 1;
      }
      v24 = (int *)off_117360;
      result = *(uint32_t *)off_117360;
      v25 = (int *)off_117358;
      v26 = *(uint32_t *)off_117360 + 1;
      *(uint32_t *)off_117360 = v26;
      *v25 = v23 & v38;
      if ( v26 )
      {
        v27 = (int *)off_11735C;
        *v24 = result;
        v28 = *v27;
        if ( !result )
        {
          if ( v28 )
            __enable_irq();
        }
      }
      *(uint32_t *)off_117364 = v37;
      v5 = (uint8_t)v2[26];
    }
    v13 = *(uint32_t *)(v7 + 88);
    if ( !v13 )
      goto LABEL_38;
LABEL_13:
    *((uint32_t *)v2 + 10) = v7;
    ++*(uint8_t *)(v7 + 14);
LABEL_14:
    v14 = *((uint32_t *)v2 + 3);
    if ( !v14 )
      break;
    v15 = *(uint32_t **)(v14 + 76);
    v16 = v15[18];
    if ( v16 >= 0 )
    {
      if ( (*(uint32_t *)(v14 + 36) & 0x380000) == 0x280000 )
        return sub_11A8B0(*(uint32_t *)(v14 + 68) + 16, v1);
      return result;
    }
    v15[1] = v16;
    fmac_txpwr_table_lookup(v1);
    v17 = *(uint32_t *)(v14 + 36) & 0x200000;
    if ( !v17 )
    {
      v18 = v15[4];
      if ( v18 )
      {
        v19 = v15[4];
        if ( (*(uint32_t *)(v18 + 56) & 0x380000) == 0x200000 )
        {
          if ( **(int16_t **)off_11736C < 0 && !*(uint32_t *)(v18 + 8) )
          {
            sub_12F46C(dword_117480, dword_117470, 1077);
            __und(0xFFu);
          }
          v17 = v15[4];
          v19 = *(uint32_t *)(v18 + 8);
        }
        if ( *(int *)(v19 + 60) >= 0 )
        {
          result = v17;
          if ( v17 )
            result = sub_11A8B0(v17, v1);
          *(uint32_t *)(4 * v39) = *(uint32_t *)off_11747C + *(uint32_t *)(dword_117478 + 4 * v1);
          return result;
        }
      }
      else
      {
        *(uint32_t *)v2 = 0;
        rf_set_bit_flag(v1);
        if ( v2[80] == 1
          && *((uint32_t *)v2 + 11)
          && !*(uint32_t *)(dword_117368 + 8 * (165 * *(uint8_t *)(*((uint32_t *)v2 + 12) + 28) + v1 + 154))
          && !*((uint8_t *)off_11733C + 511) )
        {
          sub_119EC8(v1);
        }
      }
    }
    if ( (v16 & 0x800000) != 0 )
    {
      v20 = *(uint8_t *)(v14 + 29);
      if ( v20 <= 0x23 )
        *(uint32_t *)(dword_117350 + 696 * v20 + 664) = *((uint32_t *)off_117354 + 4);
    }
    rf_bus_mark_n100_d2d0(v2 + 12);
    if ( *(uint16_t *)(v14 + 4) )
      sub_117F18(v14, v16, v1);
    else
      sub_118CE0(v14);
    v21 = *(uint32_t *)(v14 + 36);
    result = v21 << 10;
    if ( (v21 & 0x200000) != 0 )
    {
      if ( (v21 & 0x380000) == 0x380000 )
      {
        *((uint32_t *)v2 + 9) = *(uint32_t *)(v14 + 68);
        v2[26] = 1;
        result = irq_nesting_or_d104(512);
      }
    }
    else
    {
      --v2[80];
    }
    *v6 = *v4 + *(uint32_t *)(dword_117348 + 4 * v1);
    v5 = (uint8_t)v2[26];
  }
  v30 = (int *)off_117488;
  *(uint32_t *)v2 = 0;
  v31 = *v30;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11748C = 1;
  }
  v32 = (int *)off_117490;
  result = *(uint32_t *)off_117490;
  v33 = (int *)off_117488;
  v34 = *(uint32_t *)off_117490 + 1;
  *(uint32_t *)off_117490 = v34;
  *v33 = v31 & v38;
  if ( v34 )
  {
    v35 = (int *)off_11748C;
    *v32 = result;
    v36 = *v35;
    if ( !result )
    {
      if ( v36 )
        __enable_irq();
    }
  }
  *(uint32_t *)off_117494 = v37;
  return result;
}

