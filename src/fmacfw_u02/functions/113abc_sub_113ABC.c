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


extern uint32_t dword_113BF4;
extern uint32_t off_113BC4;
extern uint32_t off_113BC8;
extern uint32_t off_113BCC;
extern uint32_t off_113BD0;
extern uint32_t off_113BD4;
extern uint32_t off_113BD8;
extern uint32_t off_113BDC;
extern uint32_t off_113BE0;
extern uint32_t off_113BE4;
extern uint32_t off_113BE8;
extern uint32_t off_113BEC;
extern uint32_t off_113BF0;
extern uint32_t off_113BF8;
extern uint32_t off_113BFC;
extern uint32_t off_113C00;
extern uint32_t off_113C04;
extern uint32_t off_113C08;
extern uint32_t off_113C0C;
extern uint32_t off_113C10;

// save_task_ptr @ 0x113abc, size 264 bytes
int  save_task_ptr(int a1)
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
  int *v10; // r3
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

  v1 = off_113BC4;
  v2 = off_113BCC;
  v3 = *(int **)(*(uint32_t *)off_113BC4 + 16);
  v4 = off_113BD0;
  *(uint32_t *)off_113BC8 = v3;
  *v2 = v3 + 16;
  v5 = off_113BD4;
  v4[2] = a1;
  *v4 = 0;
  v4[1] = 0;
  v4[4] = 0;
  v4[5] = 0;
  v4[3] = 0;
  v5[6] = 0;
  memset(v3, 0, 0x140u);
  v6 = *(int **)(*(uint32_t *)v1 + 20);
  v7 = off_113BDC;
  v8 = off_113BE0;
  *(uint32_t *)off_113BD8 = v6;
  *v7 = v6 + 2;
  *v8 = v6 + 4;
  v8[1] = v6 + 6;
  v8[2] = v6 + 8;
  v8[3] = v6 + 10;
  v9 = off_113BE4;
  v8[4] = v6 + 12;
  *v9 = v6 + 14;
  memset(v6, 0, 0xCB8u);
  if ( **(uint16_t **)off_113BE8 < 0 && *(uint32_t *)(*(uint32_t *)v1 + 24) <= 0xCB7u )
    mmio_clear_register((int)aIndexHostIfPar, (int)aHostUsbWlanIni, 758);
  v10 = (int *)off_113BEC;
  v11 = LOWORD(((uint32_t *)(uintptr_t)off_113BEC)[82]);
  v12 = LOWORD(((uint32_t *)(uintptr_t)off_113BEC)[77]);
  v13 = dword_113BF4;
  v14 = off_113BF8;
  *(uint32_t *)off_113BFC = HIWORD(((uint32_t *)(uintptr_t)off_113BEC)[76]) - *off_113BF0 - 4;
  v15 = (int *)off_113C00;
  v16 = off_113C04;
  v17 = v13 * v11;
  v18 = off_113C08;
  *v14 = v12 - 4;
  v19 = v17 <= (int)v15;
  if ( v17 > (int)v15 )
    v17 = (int)off_113C0C;
  else
    v15 = (int *)off_113C0C;
  *v18 = *((uint8_t *)v10 + 320);
  v20 = *((uint8_t *)v10 + 321);
  v21 = *((uint8_t *)v10 + 368);
  *v16 = v20;
  if ( v19 )
    *v15 = v17;
  else
    *(uint32_t *)v17 = v15;
  if ( v21 )
  {
    *(uint8_t *)off_113C10 = v21;
    event_dispatch("usb in agg cnt %d\n", v21);
  }
  else
  {
    *(uint8_t *)off_113C10 = 10;
    event_dispatch("usb in agg cnt %d\n", 10);
  }
  return 1;
}
