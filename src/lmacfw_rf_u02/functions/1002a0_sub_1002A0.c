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


extern uint32_t dword_100390;
extern uint32_t dword_100398;
extern uint32_t dword_1003AC;
extern uint32_t dword_1003B4;
extern uint32_t dword_1003C0;
extern uint32_t off_10038C;
extern uint32_t off_100394;
extern uint32_t off_10039C;
extern uint32_t off_1003A0;
extern uint32_t off_1003A8;
extern uint32_t off_1003B0;
extern uint32_t off_1003BC;

// process_state_update @ 0x1002a0, size 234 bytes
int process_state_update()
{
  uint8_t **v0; // r5
  int v1; // r0
  unsigned int v2; // r7
  uint64_t v3; // kr00_8
  uint64_t v4; // kr08_8
  int v5; // r2
  uint32_t *v6; // r3
  unsigned int v7; // r4
  uint16_t **v8; // r6
  uint32_t *v9; // r2
  int v10; // r1
  int v11; // r4
  int v12; // r3
  unsigned int v13; // r4
  unsigned int v14; // r3
  unsigned int v15; // r3
  unsigned int v16; // r7
  int result; // r0
  uint8_t *v18; // r3
  int v19; // r2
  unsigned int v20; // r2

  v0 = (uint8_t **)off_10038C;
  v1 = dword_100390;
  v2 = dword_100398;
  v3 = *(uint64_t *)(*(uint32_t *)off_10038C + 36);
  v4 = *(uint64_t *)(*(uint32_t *)off_10038C + 44);
  v5 = 44 * *(uint16_t *)(*(uint32_t *)off_10038C + 8) + 44;
  v6 = off_10039C;
  *(uint32_t *)off_100394 = dword_100390;
  v7 = v5 + v1;
  v8 = (uint16_t **)off_1003A0;
  *(uint64_t *)v6 = v3;
  v6[2] = v4;
  v6[3] = HIDWORD(v4);
  log_printf("stk_start=%x, ptr_bss=%x\n", v2, v5 + v1);
  if ( **v8 < 0 && v7 >= v2 )
    flash_ctrl_init((int)aPtrBssStartSta, (int)aPostponedArray, 120);
  v9 = *(uint32_t **)off_1003A8;
  v10 = dword_1003AC;
  v11 = 76 * *((uint16_t *)*v0 + 4) + 76;
  v12 = **(uint32_t **)off_1003A8;
  *(uint32_t *)off_1003B0 = dword_1003AC;
  v13 = v11 + v10;
  if ( !v12 )
  {
    v14 = (v9[1] + 4) & 0xFFFFFFFC;
    *v9 = v13 + 4;
    v13 += v14;
  }
  if ( !v9[2] )
  {
    v15 = (v9[3] + 4) & 0xFFFFFFFC;
    v9[2] = v13 + 4;
    v13 += v15;
  }
  v16 = dword_1003B4;
  result = log_printf("emacsh=%x, lmacsh=%x, ptr_macsh=%x\n", dword_1003AC, dword_1003B4, v13);
  if ( **v8 < 0 && v13 >= v16 )
    result = flash_ctrl_init((int)aPtrMacshLmacsh, (int)aPostponedArray, 156);
  v18 = *v0;
  *(uint32_t *)off_1003BC = *((uint32_t *)*v0 + 3);
  v19 = *v18;
  if ( v19 == 2 )
  {
    v20 = *((uint32_t *)v18 + 4);
  }
  else
  {
    if ( v19 != 1 )
      return result;
    v20 = *((uint32_t *)v18 + 5);
  }
  if ( v20 )
  {
    if ( dword_1003C0 > v20 )
      return log_printf("mem overlaps: stk_end=%x, host_base=%x\r\n", dword_1003C0, v20);
  }
  return result;
}
