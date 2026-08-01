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

extern uint32_t off_113A84;
extern uint32_t off_113A8C;
extern uint32_t off_113A90;
extern uint32_t off_113A88;
extern uint32_t off_113A94;
extern uint32_t off_113A9C;
extern uint32_t off_113AA0;
extern uint32_t off_113A98;
extern uint32_t off_113AA4;
extern uint32_t off_113AA8;
extern uint32_t dword_113ADC;
extern uint32_t dword_113AD8;
extern uint32_t off_113AAC;
extern uint32_t dword_113AB4;
extern uint32_t off_113AB8;
extern uint32_t off_113ABC;
extern uint32_t off_113AB0;
extern uint32_t off_113AC0;
extern uint32_t off_113AC4;
extern uint32_t off_113AC8;
extern uint32_t off_113ACC;
extern uint32_t off_113AD0;
extern uint32_t dword_113AD4;

// rf_save_regs @ 0x11397c, size 264 bytes
int  rf_save_regs(int a1)
{
  void *v1; // r5
  uint32_t *v2; // r1
  int *v3; // r2
  uint32_t *v4; // r3
  uint16_t *v5; // r6
  int *v6; // r0
  uint32_t *v7; // r2
  uint32_t *v8; // r3
  uint32_t *v9; // r4
  uint8_t *v10; // r3
  int v11; // r5
  int v12; // r0
  int v13; // r1
  uint32_t *v14; // r6
  int *v15; // r2
  uint8_t *v16; // r4
  int v17; // r1
  uint8_t *v18; // r5
  int v19; // cc
  char v20; // r0
  int v21; // r3
  void *v22; // r2
  int v23; // r0
  int v25; // r0

  v1 = off_113A84;
  v2 = off_113A8C;
  v3 = *(int **)(*(uint32_t *)off_113A84 + 16);
  v4 = off_113A90;
  *(uint32_t *)off_113A88 = v3;
  *v2 = v3 + 16;
  v5 = off_113A94;
  v4[2] = a1;
  *v4 = 0;
  v4[1] = 0;
  v4[4] = 0;
  v4[5] = 0;
  v4[3] = 0;
  v5[6] = 0;
  sub_100200(v3, 0, 0x140u);
  v6 = *(int **)(*(uint32_t *)v1 + 20);
  v7 = off_113A9C;
  v8 = off_113AA0;
  *(uint32_t *)off_113A98 = v6;
  *v7 = v6 + 2;
  *v8 = v6 + 4;
  v8[1] = v6 + 6;
  v8[2] = v6 + 8;
  v8[3] = v6 + 10;
  v9 = off_113AA4;
  v8[4] = v6 + 12;
  *v9 = v6 + 14;
  sub_100200(v6, 0, 0xCB8u);
  if ( **(int16_t **)off_113AA8 < 0 && *(uint32_t *)(*(uint32_t *)v1 + 24) <= 0xCB7u )
    irq_disable_mmio_write(dword_113ADC, dword_113AD8, 758);
  v10 = off_113AAC;
  v11 = *((uint16_t *)off_113AAC + 164);
  v12 = *((uint16_t *)off_113AAC + 154);
  v13 = dword_113AB4;
  v14 = off_113AB8;
  *(uint32_t *)off_113ABC = *((uint16_t *)off_113AAC + 153) - *(uint32_t *)off_113AB0 - 4;
  v15 = (int *)off_113AC0;
  v16 = off_113AC4;
  v17 = v13 * v11;
  v18 = off_113AC8;
  *v14 = v12 - 4;
  v19 = v17 <= (int)v15;
  if ( v17 > (int)v15 )
    v17 = (int)off_113ACC;
  else
    v15 = (int *)off_113ACC;
  *v18 = v10[320];
  v20 = v10[321];
  v21 = (uint8_t)v10[368];
  *v16 = v20;
  if ( v19 )
    *v15 = v17;
  else
    *(uint32_t *)v17 = v15;
  if ( v21 )
  {
    v22 = off_113AD0;
    v23 = dword_113AD4;
    *(uint8_t *)off_113AD0 = v21;
    alloc_tx_event(v23, v21, v22);
  }
  else
  {
    v25 = dword_113AD4;
    *(uint8_t *)off_113AD0 = 10;
    alloc_tx_event(v25, 10, v15);
  }
  return 1;
}

