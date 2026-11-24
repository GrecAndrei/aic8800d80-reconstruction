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


extern uint32_t dword_11806C;
extern uint32_t dword_118070;
extern uint32_t dword_118074;
extern uint32_t dword_118078;
extern uint32_t dword_118088;
extern uint32_t off_118064;
extern uint32_t off_11807C;
extern uint32_t off_118080;
extern uint32_t off_118084;
extern uint32_t off_11808C;
extern uint32_t off_118098;
extern uint32_t off_11809C;
extern uint32_t off_1180A0;
extern uint32_t off_1180B0;
extern uint32_t off_1180B4;

// process_pending_events @ 0x117e5c, size 520 bytes
int  process_pending_events(int a1, int a2, int a3, uint8_t *a4)
{
  uint8_t *v4; // r5
  int v9; // r7
  uint32_t *v10; // r0
  uint32_t *v11; // r4
  char v12; // r1
  int v13; // r3
  uint8_t v14; // r1
  int v15; // r2
  int v16; // r3
  int *v17; // r7
  int v18; // r1
  int v19; // r2
  int v20; // r2
  int v21; // r3
  uint32_t *v22; // r3
  int v23; // zf
  int result; // r0
  uint8_t v25; // r2
  uint8_t v26; // r3
  int v27; // r3
  int v28; // r3

  v4 = (uint8_t *)off_118064;
  if ( !*(uint32_t *)off_118064 )
    return 1;
  if ( !*(uint32_t *)(off_118064 + 8) )
    rf_read_status_1((int *)a1);
  v9 = dword_11806C;
  v10 = list_pop_front(off_118064);
  *((uint8_t *)v10 + 94) = a2;
  v11 = v10;
  v10[22] = *(uint32_t *)a1;
  v12 = dword_118070;
  *((uint16_t *)v10 + 46) = *(uint16_t *)(a1 + 4);
  v10[2] = 2631;
  v10[3] = 2627;
  v13 = dword_118078;
  v10[4] = dword_118074;
  v14 = v12 * (((int)v10 - v9) >> 5);
  v10[5] = v13;
  *((uint8_t *)v10 + 97) = 127;
  v10[18] = 0;
  *((uint8_t *)v10 + 95) = v14;
  *((uint8_t *)v10 + 84) = v14;
  if ( a2 == 2 )
  {
    v25 = v4[18];
    if ( !v25 )
    {
      rf_enable_1();
      v25 = v4[18];
    }
    v15 = (uint8_t)(v25 + 1);
    v16 = v4[17] + v15;
    v4[18] = v15;
    if ( v16 > 1 )
      goto LABEL_8;
    goto LABEL_19;
  }
  if ( a2 != 4 )
  {
    if ( a2 )
    {
      v15 = v4[18];
      v16 = v4[17] + v15;
      if ( v16 > 1 )
        goto LABEL_8;
    }
    else
    {
      v26 = v4[17];
      v10[7] = off_1180B0;
      *((uint16_t *)v10 + 50) = 100;
      v10[32] = off_1180B4;
      v15 = v4[18];
      v10[8] = v10;
      v27 = (uint8_t)(v26 + 1);
      v4[17] = v27;
      v16 = v27 + v15;
      v10[33] = v10;
      *((uint8_t *)v10 + 102) = -1;
      if ( v16 > 1 )
        goto LABEL_8;
    }
    goto LABEL_19;
  }
  if ( v4[16] != 255 )
    return 1;
  v15 = v4[18];
  v28 = v4[17];
  v4[16] = v14;
  v16 = v28 + v15;
  if ( v16 > 1 )
    goto LABEL_8;
LABEL_19:
  if ( v15 )
  {
LABEL_8:
    v17 = off_118080;
    v18 = **(uint16_t **)off_11807C;
    v19 = off_118080[1] | 0x100;
    off_118080[1] = v19;
    if ( v18 < 0 && *(uint32_t *)off_1180A0 << 28 )
    {
      flash_cmd_exec((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
      v19 = v17[1];
      v16 = v4[17] + v4[18];
    }
    *(uint32_t *)off_118084 = v19 | *v17;
  }
  if ( v16 == 1 )
    *(uint32_t *)off_11809C |= 1u;
  *a4 = *((uint8_t *)v11 + 95);
  check_kernel_state(dword_118088, v11);
  list_init_1(v11 + 37);
  list_init_1(v11 + 45);
  list_init_1(v11 + 39);
  list_init_1(v11 + 47);
  list_init_1(v11 + 41);
  list_init_1(v11 + 49);
  list_init_1(v11 + 43);
  list_init_1(v11 + 51);
  list_init_1(v11 + 53);
  v20 = v4[18];
  v21 = v4[17] + v20;
  *(uint32_t *)off_11808C = 0;
  if ( v21 <= 1 )
  {
    btcoex_check_state();
    v20 = v4[18];
    v21 = v4[17] + v20;
  }
  check_interrupt_flag(256, "%s:%d,%d,%d,%d,%d\r\n", aVifMgmtRegiste, v21, v20, a2, a3, *a4);
  v22 = (uint32_t *)(v4[18] + v4[17]);
  v23 = v22 == (uint32_t *)1;
  if ( v22 == (uint32_t *)1 )
    v22 = off_118098;
  result = 0;
  if ( v23 )
    *v22 = 0;
  return result;
}
