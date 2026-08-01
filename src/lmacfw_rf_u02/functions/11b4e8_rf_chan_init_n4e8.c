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

extern uint32_t off_11B6A8;
extern uint32_t off_11B6AC;
extern uint32_t dword_11B6B0;
extern uint32_t off_11B6B4;
extern uint32_t dword_11B6E0;
extern uint32_t dword_11B6DC;
extern uint32_t dword_11B6E4;
extern uint32_t dword_11B6CC;
extern uint32_t dword_11B6E8;
extern uint32_t dword_11B6D4;
extern uint32_t dword_11B6D0;
extern uint32_t off_11B6EC;
extern uint32_t dword_11B6B8;
extern uint32_t dword_11B6BC;
extern uint32_t off_11B6C0;
extern uint32_t off_11B6C8;
extern uint32_t off_11B6C4;
extern uint32_t dword_11B6D8;

// tx_processing @ 0x11b4e8, size 448 bytes
// Doc: tx_processing [rf]: Initialize RF channel context from data tables, call helper, read signed halfword
// tx_processing [rf]: Initialize RF channel context from data tables, call helper, read signed halfword
int  tx_processing(int a1)
{
  int16_t **v1; // r7
  uint8_t *v2; // r6
  int v4; // r0
  int v5; // r5
  int v6; // r3
  uint32_t *v7; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2
  char *v12; // r0
  int v13; // r2
  int v14; // r0
  int result; // r0
  int *v16; // r5
  int v17; // r1
  int v18; // r6
  int v19; // r3
  int v20; // r2
  int *v21; // r3
  int v22; // r3
  int v23; // r3
  int v24; // r1
  int v25; // r3
  int v26; // r2
  int v27; // r2
  int v28; // r7
  int v29; // r3
  int v30; // r2

  v1 = (int16_t **)off_11B6A8;
  v2 = off_11B6AC;
  v4 = list_pop_front(dword_11B6B0);
  v5 = v4;
  if ( **v1 >= 0 )
  {
    v6 = (uint8_t)*v2;
    if ( *v2 )
    {
LABEL_3:
      v7 = off_11B6B4;
      goto LABEL_4;
    }
LABEL_26:
    v7 = off_11B6B4;
    v8 = *((uint32_t *)off_11B6B4 + 10);
    goto LABEL_6;
  }
  if ( a1 == v4 )
  {
    v6 = (uint8_t)*v2;
    if ( *v2 )
      goto LABEL_3;
  }
  else
  {
    flash_ctrl_init(dword_11B6E0, dword_11B6DC, 1958);
    v6 = (uint8_t)*v2;
    if ( *v2 )
      goto LABEL_3;
    if ( **v1 >= 0 )
      goto LABEL_26;
  }
  v7 = off_11B6B4;
  v8 = *((uint32_t *)off_11B6B4 + 10);
  if ( !v8 )
  {
    flash_ctrl_init(dword_11B6E4, dword_11B6DC, 1960);
    v6 = (uint8_t)*v2;
LABEL_4:
    if ( v6 != 1 )
    {
LABEL_5:
      v8 = v7[10];
      goto LABEL_6;
    }
    dispatch_event_handler(dword_11B6CC, *((uint8_t *)v7 + 88));
    v23 = *((uint8_t *)v7 + 88);
    v24 = v23 << 28;
    if ( (v23 & 8) != 0 )
    {
      v25 = dword_11B6E8;
    }
    else
    {
      if ( (v23 & 4) == 0 )
      {
        v25 = v7[11];
        if ( !v25 )
          goto LABEL_5;
LABEL_33:
        v27 = v7[10];
        if ( v27 )
        {
          v24 = 1;
          *(uint8_t *)(v27 + 16) = 1;
        }
        v7[10] = v25;
        v7[11] = 0;
        v28 = *(uint8_t *)(v25 + 24);
        *(uint8_t *)(v25 + 16) = 4;
        if ( v28 == 3 )
        {
          dispatch_event_handler(dword_11B6D4, v24);
          flash_erase_sector(2);
        }
        goto LABEL_5;
      }
      v25 = dword_11B6D0;
    }
    v26 = v7[11];
    if ( v26 != v25 && v26 )
    {
      v24 = 1;
      *(uint8_t *)(v26 + 16) = 1;
    }
    goto LABEL_33;
  }
LABEL_6:
  *(uint8_t *)(v8 + 16) = 1;
  v9 = v7[20];
  v10 = 0;
  *v2 = 0;
  if ( v9 )
  {
    v11 = *((uint8_t *)v7 + 90);
    v7[20] = 0;
    if ( !v11 )
    {
      *(uint32_t *)(v5 + 8) = 0;
      goto LABEL_15;
    }
    if ( v11 == 1 || (v10 = v7[4]) == 0 )
    {
      v12 = (char *)off_11B6EC;
      if ( *((uint8_t *)off_11B6EC + 24) == 255 )
      {
        if ( *((uint8_t *)off_11B6EC + 52) == 255 )
        {
          if ( *((uint8_t *)off_11B6EC + 80) == 255 )
          {
            *(uint32_t *)(v5 + 8) = v10;
            goto LABEL_15;
          }
          v12 = (char *)off_11B6EC + 56;
        }
        else
        {
          v12 = (char *)off_11B6EC + 28;
        }
      }
    }
    else
    {
      v12 = *(char **)(dword_11B6B8 + 224 * *(uint8_t *)(v10 + 8) + 72);
    }
    *(uint32_t *)(v5 + 8) = v12;
  }
  else
  {
    v12 = *(char **)(v5 + 8);
  }
  if ( v12 )
  {
    if ( v7[11] )
      v7[11] = v12;
    else
      list_search((int)v12);
  }
LABEL_15:
  check_kernel_state(dword_11B6BC);
  v14 = v7[10];
  if ( *(uint8_t *)(v14 + 24) > 2u )
    rx_queue_init(v14, 0, v13);
  result = v7[8];
  v7[18] = result;
  if ( result )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11B6C0 = 1;
    }
    v16 = (int *)off_11B6C8;
    v17 = *(uint32_t *)(result + 4);
    v18 = *(uint32_t *)off_11B6C8;
    v19 = v17 - *((uint32_t *)off_11B6C4 + 4);
    v20 = *(uint32_t *)off_11B6C8 + 1;
    *(uint32_t *)off_11B6C8 = v20;
    if ( v19 - 64 >= 0 )
    {
      result = ke_enter_critical(dword_11B6D8, v17);
      if ( *v16 )
      {
        v29 = *v16 - 1;
        v30 = *(uint32_t *)off_11B6C0;
        *v16 = v29;
        if ( !v29 )
        {
          if ( v30 )
            __enable_irq();
        }
      }
    }
    else
    {
      if ( v20 )
      {
        v21 = (int *)off_11B6C0;
        *v16 = v18;
        v22 = *v21;
        if ( !v18 )
        {
          if ( v22 )
            __enable_irq();
        }
      }
      return ((int (*)(void))v7[17])();
    }
  }
  return result;
}

