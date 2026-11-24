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


extern uint32_t dword_115654;
extern uint32_t dword_11565C;
extern uint32_t off_115648;
extern uint32_t off_11564C;
extern uint32_t off_115650;
extern uint32_t off_115660;
extern uint32_t off_115664;
extern uint32_t off_115668;
extern uint32_t off_11566C;
extern uint32_t off_115670;
extern uint32_t off_115674;
extern uint32_t off_115678;
extern uint32_t off_11567C;
extern uint32_t off_115680;
extern uint32_t off_115688;

// adv_pdu_type_handler @ 0x1153f4, size 594 bytes
int * adv_pdu_type_handler(int a1, int a2)
{
  uint32_t *v3; // r3
  volatile unsigned int v4; // r2
  int *v5; // r0
  unsigned int *v6; // r3
  unsigned int v7; // r2
  int v8; // r4
  uint32_t *v9; // r3
  int *result; // r0
  int v11; // r2
  int v12; // r1
  int v13; // r4
  uint32_t *v14; // r1
  uint32_t *v15; // r3
  uint32_t *v16; // r3
  uint32_t *v17; // r3
  uint32_t *v18; // r3
  volatile unsigned int v19; // r5
  unsigned int v20; // r5
  int v21; // r3
  volatile unsigned int v22; // r5
  unsigned int v23; // r5
  int v24; // r3
  volatile unsigned int v25; // r5
  unsigned int v26; // r5
  int v27; // r3
  volatile unsigned int v28; // r5
  unsigned int v29; // r5
  int v30; // r3
  volatile unsigned int v31; // r5
  unsigned int v32; // r5
  int v33; // r3

  switch ( a2 )
  {
    case 0:
      if ( ((*(uint32_t *)off_115648 >> 4) & 3) != 2 )
        goto LABEL_12;
      v22 = REG_4032_0120;
      v23 = v22 + 2;
      do
      {
        if ( ((*(uint32_t *)off_115648 >> 4) & 3) != 2 )
          break;
        v24 = REG_4032_0120 - v23;
      }
      while ( v24 < 0 );
      if ( **(uint16_t **)off_115680 >= 0 || ((*(uint32_t *)off_115648 >> 4) & 3) != 2 )
      {
LABEL_12:
        v15 = off_115650;
        *(uint32_t *)off_115670 = a1;
        *v15 = 512;
        goto LABEL_4;
      }
      result = (int *)ke_int_lock_1((int)aNxmacTxAc0Stat, (int)aTxlCntrlNewhea, 1919);
      break;
    case 1:
      if ( ((*(uint32_t *)off_115648 >> 8) & 3) != 2 )
        goto LABEL_16;
      v25 = REG_4032_0120;
      v26 = v25 + 2;
      do
      {
        if ( ((*(uint32_t *)off_115648 >> 8) & 3) != 2 )
          break;
        v27 = REG_4032_0120 - v26;
      }
      while ( v27 < 0 );
      if ( **(uint16_t **)off_115680 >= 0 || ((*(uint32_t *)off_115648 >> 8) & 3) != 2 )
      {
LABEL_16:
        v17 = off_115650;
        *(uint32_t *)off_115678 = a1;
        *v17 = 1024;
        goto LABEL_4;
      }
      result = (int *)ke_int_lock_1((int)aNxmacTxAc1Stat, (int)aTxlCntrlNewhea, 1907);
      break;
    case 2:
      if ( ((*(uint32_t *)off_115648 >> 12) & 3) != 2 )
        goto LABEL_14;
      v28 = REG_4032_0120;
      v29 = v28 + 2;
      do
      {
        if ( ((*(uint32_t *)off_115648 >> 12) & 3) != 2 )
          break;
        v30 = REG_4032_0120 - v29;
      }
      while ( v30 < 0 );
      if ( **(uint16_t **)off_115680 >= 0 || ((*(uint32_t *)off_115648 >> 12) & 3) != 2 )
      {
LABEL_14:
        v16 = off_115650;
        *(uint32_t *)off_115674 = a1;
        *v16 = 2048;
        goto LABEL_4;
      }
      result = (int *)ke_int_lock_1((int)aNxmacTxAc2Stat, (int)aTxlCntrlNewhea, 1895);
      break;
    case 3:
      if ( (HIWORD(*(uint32_t *)off_115648) & 3) != 2 )
        goto LABEL_18;
      v31 = REG_4032_0120;
      v32 = v31 + 2;
      do
      {
        if ( (HIWORD(*(uint32_t *)off_115648) & 3) != 2 )
          break;
        v33 = REG_4032_0120 - v32;
      }
      while ( v33 < 0 );
      if ( **(uint16_t **)off_115680 >= 0 || (HIWORD(*(uint32_t *)off_115648) & 3) != 2 )
      {
LABEL_18:
        v18 = off_115650;
        *(uint32_t *)off_11567C = a1;
        *v18 = 4096;
        goto LABEL_4;
      }
      result = (int *)ke_int_lock_1((int)aNxmacTxAc3Stat, (int)aTxlCntrlNewhea, 1883);
      break;
    case 5:
      if ( (HIBYTE(*(uint32_t *)off_115648) & 3) != 2 )
        goto LABEL_3;
      v19 = REG_4032_0120;
      v20 = v19 + 2;
      do
      {
        if ( (HIBYTE(*(uint32_t *)off_115648) & 3) != 2 )
          break;
        v21 = REG_4032_0120 - v20;
      }
      while ( v21 < 0 );
      if ( **(uint16_t **)off_115680 >= 0 || (HIBYTE(*(uint32_t *)off_115648) & 3) != 2 )
      {
LABEL_3:
        v3 = off_115650;
        *(uint32_t *)off_11564C = a1;
        *v3 = 0x4000;
        goto LABEL_4;
      }
      result = (int *)ke_int_lock_1((int)aNxmacTxHiState, (int)aTxlCntrlNewhea, 1931);
      break;
    default:
      if ( **(uint16_t **)off_115680 < 0 )
        flash_ctrl_init(off_115688, (int)aTxlCntrlNewhea, 1937);
LABEL_4:
      v4 = REG_4032_0120;
      v5 = (int *)off_115660;
      v6 = (unsigned int *)(4 * (dword_11565C + a2));
      v7 = v4 + *(uint32_t *)(dword_115654 + 4 * a2);
      v8 = 1 << a2;
      *v6 = v7;
      *v5 = v8;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_115664 = 1;
      }
      v9 = off_115668;
      result = (int *)off_11566C;
      v11 = *(uint32_t *)off_115668;
      v12 = *(uint32_t *)off_115668 + 1;
      v13 = v8 | *(uint32_t *)off_11566C;
      *(uint32_t *)off_115668 = v12;
      *result = v13;
      if ( v12 )
      {
        v14 = off_115664;
        *v9 = v11;
        if ( !v11 )
        {
          if ( *v14 )
            __enable_irq();
        }
      }
      break;
  }
  return result;
}
