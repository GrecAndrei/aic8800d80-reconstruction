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


extern uint32_t dword_127880;
extern uint32_t dword_127888;
extern uint32_t dword_12788C;
extern uint32_t dword_1278A0;
extern uint32_t dword_1278AC;
extern uint32_t dword_1278BC;
extern uint32_t off_127878;
extern uint32_t off_12787C;
extern uint32_t off_127884;
extern uint32_t off_127890;
extern uint32_t off_127898;
extern uint32_t off_1278A4;
extern uint32_t off_1278A8;
extern uint32_t off_1278C0;

// rf_perform_calibration @ 0x127668, size 526 bytes
int  rf_perform_calibration(uint32_t *a1)
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

  v1 = (uint16_t **)off_127878;
  v2 = off_12787C;
  v4 = mem_word_load(dword_127880);
  v5 = v4;
  if ( **v1 >= 0 )
  {
    v6 = (uint8_t)*v2;
    if ( *v2 )
    {
LABEL_3:
      v7 = off_127884;
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
    mmio_clear_register((int)aVoidChSwitchEn, (int)aChanTmrSwitchC, 1958);
    v6 = (uint8_t)*v2;
    if ( *v2 )
      goto LABEL_3;
    if ( **v1 >= 0 )
    {
LABEL_25:
      v7 = off_127884;
      goto LABEL_5;
    }
  }
  v7 = off_127884;
  v8 = *((uint32_t *)off_127884 + 10);
  if ( v8 )
    goto LABEL_6;
  mmio_clear_register((int)aChanEnvCurrent, (int)aChanTmrSwitchC, 1960);
  v6 = (uint8_t)*v2;
LABEL_4:
  if ( v6 != 1 )
  {
LABEL_5:
    v8 = v7[10];
    goto LABEL_6;
  }
  event_dispatch("cb:%x,%x\n", *((uint8_t *)v7 + 88), v7[11]);
  v23 = *((uint8_t *)v7 + 88);
  if ( (v23 & 8) != 0 )
  {
    v24 = dword_1278BC;
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
    v24 = dword_1278A0;
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
    event_dispatch(aCbSetState, v22);
    rx_phy_status_parse(2u, 3);
    v27 = *(uint8_t *)(v24 + 24);
  }
  if ( v27 <= 2 )
    goto LABEL_5;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_127890 = 1;
  }
  v28 = off_127898;
  v29 = off_1278A4;
  v30 = *(uint32_t *)off_127898;
  v31 = *(uint32_t *)off_127898 + 1;
  v32 = *((uint32_t *)off_1278A4 + 1) | 2;
  *(uint32_t *)off_127898 = v31;
  v29[1] = v32;
  if ( v31 )
  {
    v33 = (int *)off_127890;
    *v28 = v30;
    v34 = *v33;
    if ( !v30 )
    {
      if ( v34 )
        __enable_irq();
    }
  }
  v35 = off_1278A8;
  v8 = v7[10];
  *((uint8_t *)v7 + 92) = (*(uint32_t *)off_1278A8 & 4) != 0;
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
      v12 = (char *)off_1278C0;
      if ( *((uint8_t *)off_1278C0 + 24) == 255 )
      {
        if ( *((uint8_t *)off_1278C0 + 52) == 255 )
        {
          if ( *((uint8_t *)off_1278C0 + 80) == 255 )
          {
            v5[2] = v10;
            goto LABEL_14;
          }
          v12 = (char *)off_1278C0 + 56;
        }
        else
        {
          v12 = (char *)off_1278C0 + 28;
        }
      }
    }
    else
    {
      v12 = *(char **)(dword_127888 + 1320 * *(uint8_t *)(v10 + 8) + 72);
    }
    v5[2] = v12;
  }
  else
  {
    v12 = (char *)v5[2];
  }
  if ( v12 )
    ctrl_register_handler(v12);
LABEL_14:
  cmd_handler_a(dword_12788C, v5);
  v13 = v7[10];
  if ( *(uint8_t *)(v13 + 24) > 2u )
    ctrl_reset_handler(v13, 0);
  result = v7[8];
  v7[18] = result;
  if ( result )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_127890 = 1;
    }
    v15 = (int *)off_127898;
    v16 = *(uint32_t *)(result + 4);
    v17 = (*(volatile uint32_t *)0x40501010u);
    v18 = *(uint32_t *)off_127898;
    v19 = *(uint32_t *)off_127898 + 1;
    *(uint32_t *)off_127898 = v19;
    if ( (int)(v16 - v17 - 64) >= 0 )
    {
      result = unknown_worker((uint32_t *)dword_1278AC, v16);
      if ( *v15 )
      {
        v36 = *v15 - 1;
        v37 = *(uint32_t *)off_127890;
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
        v20 = (int *)off_127890;
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
