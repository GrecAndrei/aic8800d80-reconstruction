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

extern uint32_t off_11347C;
extern uint32_t off_113484;
extern uint32_t off_113488;
extern uint32_t off_113480;
extern uint32_t off_11348C;
extern uint32_t off_113494;
extern uint32_t off_113498;
extern uint32_t off_113490;
extern uint32_t off_11349C;
extern uint32_t off_1134A0;
extern uint32_t dword_1134D4;
extern uint32_t dword_1134D0;
extern uint32_t off_1134A4;
extern uint32_t dword_1134AC;
extern uint32_t off_1134B0;
extern uint32_t off_1134B4;
extern uint32_t off_1134A8;
extern uint32_t off_1134B8;
extern uint32_t off_1134BC;
extern uint32_t off_1134C0;
extern uint32_t off_1134C4;
extern uint32_t dword_1134CC;
extern uint32_t off_1134C8;

// update_hw_config @ 0x113374, size 264 bytes
int  update_hw_config(int a1)
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
  int v22; // r0

  v1 = off_11347C;
  v2 = off_113484;
  v3 = *(int **)(*(uint32_t *)off_11347C + 16);
  v4 = off_113488;
  *(uint32_t *)off_113480 = v3;
  *v2 = v3 + 16;
  v5 = off_11348C;
  v4[2] = a1;
  *v4 = 0;
  v4[1] = 0;
  v4[4] = 0;
  v4[5] = 0;
  v4[3] = 0;
  v5[6] = 0;
  sub_100200(v3, 0, 0x140u);
  v6 = *(int **)(*(uint32_t *)v1 + 20);
  v7 = off_113494;
  v8 = off_113498;
  *(uint32_t *)off_113490 = v6;
  *v7 = v6 + 2;
  *v8 = v6 + 4;
  v8[1] = v6 + 6;
  v8[2] = v6 + 8;
  v8[3] = v6 + 10;
  v9 = off_11349C;
  v8[4] = v6 + 12;
  *v9 = v6 + 14;
  sub_100200(v6, 0, 0xCB8u);
  if ( **(int16_t **)off_1134A0 < 0 && *(uint32_t *)(*(uint32_t *)v1 + 24) <= 0xCB7u )
    flash_ctrl_init(dword_1134D4, dword_1134D0, 758);
  v10 = off_1134A4;
  v11 = *((uint16_t *)off_1134A4 + 164);
  v12 = *((uint16_t *)off_1134A4 + 154);
  v13 = dword_1134AC;
  v14 = off_1134B0;
  *(uint32_t *)off_1134B4 = *((uint16_t *)off_1134A4 + 153) - *(uint32_t *)off_1134A8 - 4;
  v15 = (int *)off_1134B8;
  v16 = off_1134BC;
  v17 = v13 * v11;
  v18 = off_1134C0;
  *v14 = v12 - 4;
  v19 = v17 <= (int)v15;
  if ( v17 > (int)v15 )
    v17 = (int)off_1134C4;
  else
    v15 = (int *)off_1134C4;
  *v18 = v10[320];
  v20 = v10[321];
  v21 = (uint8_t)v10[368];
  *v16 = v20;
  if ( v19 )
    *v15 = v17;
  else
    *(uint32_t *)v17 = v15;
  v22 = dword_1134CC;
  if ( v21 )
  {
    *(uint8_t *)off_1134C8 = v21;
    dispatch_event_handler(v22, v21);
  }
  else
  {
    *(uint8_t *)off_1134C8 = 10;
    dispatch_event_handler(v22, 10);
  }
  return 1;
}

