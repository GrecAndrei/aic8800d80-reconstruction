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


extern uint32_t dword_127AA4;
extern uint32_t dword_127AAC;
extern uint32_t dword_127AB0;
extern uint32_t dword_127AC4;
extern uint32_t dword_127AD0;
extern uint32_t dword_127AE0;
extern uint32_t off_127A9C;
extern uint32_t off_127AA0;
extern uint32_t off_127AA8;
extern uint32_t off_127AB4;
extern uint32_t off_127ABC;
extern uint32_t off_127AC8;
extern uint32_t off_127ACC;
extern uint32_t off_127AE4;

// scan_process @ 0x12788c, size 526 bytes
int  scan_process(uint32_t *a1)
{
  uint16_t **v1; // r7
  uint8_t *v2; // r6
  uint32_t *v4; // r0
  uint32_t *v5; // r5
  int v6; // r3
  uint32_t *v7; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2
  char *v12; // r0
  int v13; // r0
  int result; // r0
  int *v15; // r5
  int v16; // r1
  volatile unsigned int v17; // r3
  int v18; // r6
  int v19; // r2
  int *v20; // r3
  int v21; // r3
  int v22; // r1
  int v23; // r3
  int v24; // r7
  int v25; // r3
  int v26; // r3
  unsigned int v27; // r8
  uint32_t *v28; // r2
  uint32_t *v29; // r7
  int v30; // r1
  int v31; // r0
  int v32; // r3
  int *v33; // r3
  int v34; // r3
  uint32_t *v35; // r2
  int v36; // r3
  int v37; // r2

  v1 = (uint16_t **)off_127A9C;
  v2 = off_127AA0;
  v4 = list_pop_front(dword_127AA4);
  v5 = v4;
  if ( **v1 >= 0 )
  {
    v6 = (uint8_t)*v2;
    if ( *v2 )
    {
LABEL_3:
      v7 = off_127AA8;
      goto LABEL_4;
    }
    goto LABEL_25;
  }
  if ( a1 == v4 )
  {
    v6 = (uint8_t)*v2;
    if ( *v2 )
      goto LABEL_3;
  }
  else
  {
    mmio_irq_clear((int)aVoidChSwitchEn, (int)aChanTmrSwitchC, 1958);
    v6 = (uint8_t)*v2;
    if ( *v2 )
      goto LABEL_3;
    if ( **v1 >= 0 )
    {
LABEL_25:
      v7 = off_127AA8;
      goto LABEL_5;
    }
  }
  v7 = off_127AA8;
  v8 = *((uint32_t *)off_127AA8 + 10);
  if ( v8 )
    goto LABEL_6;
  mmio_irq_clear((int)aChanEnvCurrent, (int)aChanTmrSwitchC, 1960);
  v6 = (uint8_t)*v2;
LABEL_4:
  if ( v6 != 1 )
  {
LABEL_5:
    v8 = v7[10];
    goto LABEL_6;
  }
  ke_event_schedule_1("cb:%x,%x\n", *((uint8_t *)v7 + 88), v7[11]);
  v23 = *((uint8_t *)v7 + 88);
  if ( (v23 & 8) != 0 )
  {
    v24 = dword_127AE0;
  }
  else
  {
    v22 = v23 << 29;
    if ( (v23 & 4) == 0 )
    {
      v24 = v7[11];
      if ( !v24 )
        goto LABEL_5;
      goto LABEL_32;
    }
    v24 = dword_127AC4;
  }
  v25 = v7[11];
  if ( v25 != v24 && v25 )
    *(uint8_t *)(v25 + 16) = 1;
LABEL_32:
  v26 = v7[10];
  if ( v26 )
    *(uint8_t *)(v26 + 16) = 1;
  v7[10] = v24;
  v7[11] = 0;
  v27 = *(uint8_t *)(v24 + 24);
  *(uint8_t *)(v24 + 16) = 4;
  if ( v27 == 3 )
  {
    ke_event_schedule_1(aCbSetState, v22);
    hci_cmd_send(2u, 3);
    v27 = *(uint8_t *)(v24 + 24);
  }
  if ( v27 <= 2 )
    goto LABEL_5;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_127AB4 = 1;
  }
  v28 = off_127ABC;
  v29 = off_127AC8;
  v30 = *(uint32_t *)off_127ABC;
  v31 = *(uint32_t *)off_127ABC + 1;
  v32 = *((uint32_t *)off_127AC8 + 1) | 2;
  *(uint32_t *)off_127ABC = v31;
  v29[1] = v32;
  if ( v31 )
  {
    v33 = (int *)off_127AB4;
    *v28 = v30;
    v34 = *v33;
    if ( !v30 )
    {
      if ( v34 )
        __enable_irq();
    }
  }
  v35 = off_127ACC;
  v8 = v7[10];
  *((uint8_t *)v7 + 92) = (*(uint32_t *)off_127ACC & 4) != 0;
  *v35 &= ~4u;
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
      v5[2] = 0;
      goto LABEL_14;
    }
    if ( v11 == 1 || (v10 = v7[4]) == 0 )
    {
      v12 = (char *)off_127AE4;
      if ( *((uint8_t *)off_127AE4 + 24) == 255 )
      {
        if ( *((uint8_t *)off_127AE4 + 52) == 255 )
        {
          if ( *((uint8_t *)off_127AE4 + 80) == 255 )
          {
            v5[2] = v10;
            goto LABEL_14;
          }
          v12 = (char *)off_127AE4 + 56;
        }
        else
        {
          v12 = (char *)off_127AE4 + 28;
        }
      }
    }
    else
    {
      v12 = *(char **)(dword_127AAC + 1320 * *(uint8_t *)(v10 + 8) + 72);
    }
    v5[2] = v12;
  }
  else
  {
    v12 = (char *)v5[2];
  }
  if ( v12 )
    set_tx_buffer(v12);
LABEL_14:
  check_abort_flag(dword_127AB0, v5);
  v13 = v7[10];
  if ( *(uint8_t *)(v13 + 24) > 2u )
    rf_reset(v13, 0);
  result = v7[8];
  v7[18] = result;
  if ( result )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_127AB4 = 1;
    }
    v15 = (int *)off_127ABC;
    v16 = *(uint32_t *)(result + 4);
    v17 = (*(volatile uint32_t *)0x40501010u);
    v18 = *(uint32_t *)off_127ABC;
    v19 = *(uint32_t *)off_127ABC + 1;
    *(uint32_t *)off_127ABC = v19;
    if ( (int)(v16 - v17 - 64) >= 0 )
    {
      result = ke_event_lock((uint32_t *)dword_127AD0, v16);
      if ( *v15 )
      {
        v36 = *v15 - 1;
        v37 = *(uint32_t *)off_127AB4;
        *v15 = v36;
        if ( !v36 )
        {
          if ( v37 )
            __enable_irq();
        }
      }
    }
    else
    {
      if ( v19 )
      {
        v20 = (int *)off_127AB4;
        *v15 = v18;
        v21 = *v20;
        if ( !v18 )
        {
          if ( v21 )
            __enable_irq();
        }
      }
      return ((int (*)(void))v7[17])();
    }
  }
  return result;
}
