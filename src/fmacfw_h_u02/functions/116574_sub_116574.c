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


extern uint32_t dword_11680C;
extern uint32_t dword_116814;
extern uint32_t off_116800;
extern uint32_t off_116804;
extern uint32_t off_116808;
extern uint32_t off_116818;
extern uint32_t off_11681C;
extern uint32_t off_116820;
extern uint32_t off_116824;
extern uint32_t off_116828;
extern uint32_t off_11682C;
extern uint32_t off_116830;
extern uint32_t off_116834;
extern uint32_t off_116838;
extern uint32_t off_11683C;
extern uint32_t off_11685C;

// rf_switch_case @ 0x116574, size 652 bytes
int  rf_switch_case(int a1, int a2)
{
  uint32_t *v3; // r3
  volatile unsigned int v4; // r2
  int *v5; // r0
  unsigned int *v6; // r3
  unsigned int v7; // r2
  int v8; // r4
  uint32_t *v9; // r3
  int *v10; // r1
  int result; // r0
  int v12; // r2
  int v13; // r4
  uint32_t *v14; // r2
  uint32_t *v15; // r3
  uint32_t *v16; // r3
  uint32_t *v17; // r3
  uint32_t *v18; // r3
  uint32_t *v19; // r3
  volatile unsigned int v20; // r5
  unsigned int v21; // r5
  int v22; // r3
  volatile unsigned int v23; // r5
  unsigned int v24; // r5
  int v25; // r3
  volatile unsigned int v26; // r5
  unsigned int v27; // r5
  int v28; // r3
  volatile unsigned int v29; // r5
  unsigned int v30; // r5
  int v31; // r3
  volatile unsigned int v32; // r5
  unsigned int v33; // r5
  int v34; // r3

  switch ( a2 )
  {
    case 0:
      if ( ((*(uint32_t *)off_116800 >> 4) & 3) != 2 )
        goto LABEL_12;
      v29 = REG_4032_0120;
      v30 = v29 + 2;
      do
      {
        if ( ((*(uint32_t *)off_116800 >> 4) & 3) != 2 )
          break;
        v31 = REG_4032_0120 - v30;
      }
      while ( v31 < 0 );
      if ( **(uint16_t **)off_116838 >= 0 || ((*(uint32_t *)off_116800 >> 4) & 3) != 2 )
      {
LABEL_12:
        v15 = off_116808;
        *(uint32_t *)off_116828 = a1;
        *v15 = 512;
        goto LABEL_4;
      }
      result = unknown_12f2c8((int)aNxmacTxAc0Stat, (int)aTxlCntrlNewhea, 1919);
      break;
    case 1:
      if ( ((*(uint32_t *)off_116800 >> 8) & 3) != 2 )
        goto LABEL_14;
      v26 = REG_4032_0120;
      v27 = v26 + 2;
      do
      {
        if ( ((*(uint32_t *)off_116800 >> 8) & 3) != 2 )
          break;
        v28 = REG_4032_0120 - v27;
      }
      while ( v28 < 0 );
      if ( **(uint16_t **)off_116838 >= 0 || ((*(uint32_t *)off_116800 >> 8) & 3) != 2 )
      {
LABEL_14:
        v16 = off_116808;
        *(uint32_t *)off_11682C = a1;
        *v16 = 1024;
        goto LABEL_4;
      }
      result = unknown_12f2c8((int)aNxmacTxAc1Stat, (int)aTxlCntrlNewhea, 1907);
      break;
    case 2:
      if ( ((*(uint32_t *)off_116800 >> 12) & 3) != 2 )
        goto LABEL_16;
      v23 = REG_4032_0120;
      v24 = v23 + 2;
      do
      {
        if ( ((*(uint32_t *)off_116800 >> 12) & 3) != 2 )
          break;
        v25 = REG_4032_0120 - v24;
      }
      while ( v25 < 0 );
      if ( **(uint16_t **)off_116838 >= 0 || ((*(uint32_t *)off_116800 >> 12) & 3) != 2 )
      {
LABEL_16:
        v17 = off_116808;
        *(uint32_t *)off_116830 = a1;
        *v17 = 2048;
        goto LABEL_4;
      }
      result = unknown_12f2c8((int)aNxmacTxAc2Stat, (int)aTxlCntrlNewhea, 1895);
      break;
    case 3:
      if ( (HIWORD(*(uint32_t *)off_116800) & 3) != 2 )
        goto LABEL_18;
      v20 = REG_4032_0120;
      v21 = v20 + 2;
      do
      {
        if ( (HIWORD(*(uint32_t *)off_116800) & 3) != 2 )
          break;
        v22 = REG_4032_0120 - v21;
      }
      while ( v22 < 0 );
      if ( **(uint16_t **)off_116838 >= 0 || (HIWORD(*(uint32_t *)off_116800) & 3) != 2 )
      {
LABEL_18:
        v18 = off_116808;
        *(uint32_t *)off_116834 = a1;
        *v18 = 4096;
        goto LABEL_4;
      }
      result = unknown_12f2c8((int)aNxmacTxAc3Stat, (int)aTxlCntrlNewhea, 1883);
      break;
    case 4:
      if ( **(uint16_t **)off_116838 >= 0 || (*(uint32_t *)off_116800 & 3) != 2 )
      {
        v19 = off_116808;
        *(uint32_t *)off_11683C = a1;
        *v19 = 256;
        goto LABEL_4;
      }
      result = unknown_12f2c8((int)aNxmacTxBcnStat, (int)aTxlCntrlNewhea, 1871);
      break;
    case 5:
      if ( (HIBYTE(*(uint32_t *)off_116800) & 3) != 2 )
        goto LABEL_3;
      v32 = REG_4032_0120;
      v33 = v32 + 2;
      do
      {
        if ( (HIBYTE(*(uint32_t *)off_116800) & 3) != 2 )
          break;
        v34 = REG_4032_0120 - v33;
      }
      while ( v34 < 0 );
      if ( **(uint16_t **)off_116838 >= 0 || (HIBYTE(*(uint32_t *)off_116800) & 3) != 2 )
      {
LABEL_3:
        v3 = off_116808;
        *(uint32_t *)off_116804 = a1;
        *v3 = 0x4000;
        goto LABEL_4;
      }
      result = unknown_12f2c8((int)aNxmacTxHiState, (int)aTxlCntrlNewhea, 1931);
      break;
    default:
      if ( **(uint16_t **)off_116838 < 0 )
        irq_disable_mmio_write(off_11685C, (int)aTxlCntrlNewhea, 1937);
LABEL_4:
      v4 = REG_4032_0120;
      v5 = (int *)off_116818;
      v6 = (unsigned int *)(4 * (dword_116814 + a2));
      v7 = v4 + *(uint32_t *)(dword_11680C + 4 * a2);
      v8 = 1 << a2;
      *v6 = v7;
      *v5 = v8;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_11681C = 1;
      }
      v9 = off_116820;
      v10 = (int *)off_116824;
      result = *(uint32_t *)off_116820;
      v12 = *(uint32_t *)off_116820 + 1;
      v13 = v8 | *(uint32_t *)off_116824;
      *(uint32_t *)off_116820 = v12;
      *v10 = v13;
      if ( v12 )
      {
        v14 = off_11681C;
        *v9 = result;
        if ( !result )
        {
          if ( *v14 )
            __enable_irq();
        }
      }
      break;
  }
  return result;
}
