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


extern uint32_t dword_127740;
extern uint32_t dword_127748;
extern uint32_t dword_12774C;
extern uint32_t dword_127760;
extern uint32_t dword_12776C;
extern uint32_t dword_12777C;
extern uint32_t off_127738;
extern uint32_t off_12773C;
extern uint32_t off_127744;
extern uint32_t off_127750;
extern uint32_t off_127758;
extern uint32_t off_127764;
extern uint32_t off_127768;
extern uint32_t off_127780;

// llc_version_read @ 0x127528, size 526 bytes
int  llc_version_read(uint32_t *a1)
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

  v1 = (uint16_t **)off_127738;
  v2 = off_12773C;
  v4 = list_pop(dword_127740);
  v5 = v4;
  if ( **v1 >= 0 )
  {
    v6 = (uint8_t)*v2;
    if ( *v2 )
    {
LABEL_3:
      v7 = off_127744;
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
    irq_disable_mmio_write((int)aVoidChSwitchEn, (int)aChanTmrSwitchC, 1958);
    v6 = (uint8_t)*v2;
    if ( *v2 )
      goto LABEL_3;
    if ( **v1 >= 0 )
    {
LABEL_25:
      v7 = off_127744;
      goto LABEL_5;
    }
  }
  v7 = off_127744;
  v8 = *((uint32_t *)off_127744 + 10);
  if ( v8 )
    goto LABEL_6;
  irq_disable_mmio_write((int)aChanEnvCurrent, (int)aChanTmrSwitchC, 1960);
  v6 = (uint8_t)*v2;
LABEL_4:
  if ( v6 != 1 )
  {
LABEL_5:
    v8 = v7[10];
    goto LABEL_6;
  }
  alloc_tx_event("cb:%x,%x\n", *((uint8_t *)v7 + 88), v7[11]);
  v23 = *((uint8_t *)v7 + 88);
  if ( (v23 & 8) != 0 )
  {
    v24 = dword_12777C;
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
    v24 = dword_127760;
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
    alloc_tx_event(aCbSetState, v22);
    hci_cmd_preprocess(2u, 3);
    v27 = *(uint8_t *)(v24 + 24);
  }
  if ( v27 <= 2 )
    goto LABEL_5;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_127750 = 1;
  }
  v28 = off_127758;
  v29 = off_127764;
  v30 = *(uint32_t *)off_127758;
  v31 = *(uint32_t *)off_127758 + 1;
  v32 = *((uint32_t *)off_127764 + 1) | 2;
  *(uint32_t *)off_127758 = v31;
  v29[1] = v32;
  if ( v31 )
  {
    v33 = (int *)off_127750;
    *v28 = v30;
    v34 = *v33;
    if ( !v30 )
    {
      if ( v34 )
        __enable_irq();
    }
  }
  v35 = off_127768;
  v8 = v7[10];
  *((uint8_t *)v7 + 92) = (*(uint32_t *)off_127768 & 4) != 0;
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
      v12 = (char *)off_127780;
      if ( *((uint8_t *)off_127780 + 24) == 255 )
      {
        if ( *((uint8_t *)off_127780 + 52) == 255 )
        {
          if ( *((uint8_t *)off_127780 + 80) == 255 )
          {
            v5[2] = v10;
            goto LABEL_14;
          }
          v12 = (char *)off_127780 + 56;
        }
        else
        {
          v12 = (char *)off_127780 + 28;
        }
      }
    }
    else
    {
      v12 = *(char **)(dword_127748 + 1320 * *(uint8_t *)(v10 + 8) + 72);
    }
    v5[2] = v12;
  }
  else
  {
    v12 = (char *)v5[2];
  }
  if ( v12 )
    llc_conn_command(v12);
LABEL_14:
  wlan_ioctl_handler_1(dword_12774C, v5);
  v13 = v7[10];
  if ( *(uint8_t *)(v13 + 24) > 2u )
    llc_state_reset(v13, 0);
  result = v7[8];
  v7[18] = result;
  if ( result )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_127750 = 1;
    }
    v15 = (int *)off_127758;
    v16 = *(uint32_t *)(result + 4);
    v17 = (*(volatile uint32_t *)0x40501010u);
    v18 = *(uint32_t *)off_127758;
    v19 = *(uint32_t *)off_127758 + 1;
    *(uint32_t *)off_127758 = v19;
    if ( (int)(v16 - v17 - 64) >= 0 )
    {
      result = mem_copy_util((uint32_t *)dword_12776C, v16);
      if ( *v15 )
      {
        v36 = *v15 - 1;
        v37 = *(uint32_t *)off_127750;
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
        v20 = (int *)off_127750;
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
