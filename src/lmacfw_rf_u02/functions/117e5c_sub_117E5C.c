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

extern uint32_t off_118064;
extern uint32_t dword_11806C;
extern uint32_t dword_118070;
extern uint32_t dword_118078;
extern uint32_t dword_118074;
extern uint32_t dword_1180B0;
extern uint32_t dword_1180B4;
extern uint32_t off_118080;
extern uint32_t off_11807C;
extern uint32_t off_1180A0;
extern uint32_t dword_1180A8;
extern uint32_t dword_1180A4;
extern uint32_t off_118084;
extern uint32_t off_11809C;
extern uint32_t dword_118088;
extern uint32_t off_11808C;
extern uint32_t dword_118090;
extern uint32_t dword_118094;
extern uint32_t off_118098;

// process_pending_events @ 0x117e5c, size 520 bytes
int  process_pending_events(int a1, int a2, int a3, uint8_t *a4)
{
  uint8_t *v4; // r5
  int v8; // r7
  int v9; // r0
  int v10; // r4
  char v11; // r1
  int v12; // r3
  uint8_t v13; // r1
  int v14; // r2
  int v15; // r3
  uint32_t *v16; // r7
  int v17; // r1
  int v18; // r2
  int v19; // r3
  uint32_t *v20; // r3
  int v21; // zf
  int result; // r0
  uint8_t v23; // r2
  uint8_t v24; // r3
  int v25; // r3
  int v26; // r3

  v4 = (uint8_t *)off_118064;
  if ( !*(uint32_t *)off_118064 )
    return 1;
  if ( !*((uint32_t *)off_118064 + 2) )
    rf_read_status();
  v8 = dword_11806C;
  v9 = list_pop_front(off_118064);
  *(uint8_t *)(v9 + 94) = a2;
  v10 = v9;
  *(uint32_t *)(v9 + 88) = *(uint32_t *)a1;
  v11 = dword_118070;
  *(uint16_t *)(v9 + 92) = *(uint16_t *)(a1 + 4);
  *(uint32_t *)(v9 + 8) = 2631;
  *(uint32_t *)(v9 + 12) = 2627;
  v12 = dword_118078;
  *(uint32_t *)(v9 + 16) = dword_118074;
  v13 = v11 * ((v9 - v8) >> 5);
  *(uint32_t *)(v9 + 20) = v12;
  *(uint8_t *)(v9 + 97) = 127;
  *(uint32_t *)(v9 + 72) = 0;
  *(uint8_t *)(v9 + 95) = v13;
  *(uint8_t *)(v9 + 84) = v13;
  if ( a2 == 2 )
  {
    v23 = v4[18];
    if ( !v23 )
    {
      rf_enable();
      v23 = v4[18];
    }
    v14 = (uint8_t)(v23 + 1);
    v15 = v4[17] + v14;
    v4[18] = v14;
    if ( v15 > 1 )
      goto LABEL_8;
    goto LABEL_19;
  }
  if ( a2 != 4 )
  {
    if ( a2 )
    {
      v14 = v4[18];
      v15 = v4[17] + v14;
      if ( v15 > 1 )
        goto LABEL_8;
    }
    else
    {
      v24 = v4[17];
      *(uint32_t *)(v9 + 28) = dword_1180B0;
      *(uint16_t *)(v9 + 100) = 100;
      *(uint32_t *)(v9 + 128) = dword_1180B4;
      v14 = v4[18];
      *(uint32_t *)(v9 + 32) = v9;
      v25 = (uint8_t)(v24 + 1);
      v4[17] = v25;
      v15 = v25 + v14;
      *(uint32_t *)(v9 + 132) = v9;
      *(uint8_t *)(v9 + 102) = -1;
      if ( v15 > 1 )
        goto LABEL_8;
    }
    goto LABEL_19;
  }
  if ( v4[16] != 255 )
    return 1;
  v14 = v4[18];
  v26 = v4[17];
  v4[16] = v13;
  v15 = v26 + v14;
  if ( v15 > 1 )
    goto LABEL_8;
LABEL_19:
  if ( v14 )
  {
LABEL_8:
    v16 = off_118080;
    v17 = **(int16_t **)off_11807C;
    v18 = *((uint32_t *)off_118080 + 1) | 0x100;
    *((uint32_t *)off_118080 + 1) = v18;
    if ( v17 < 0 && *(uint32_t *)off_1180A0 << 28 )
    {
      flash_cmd_exec(dword_1180A8, dword_1180A4, 472);
      v18 = v16[1];
      v15 = v4[17] + v4[18];
    }
    *(uint32_t *)off_118084 = v18 | *v16;
  }
  if ( v15 == 1 )
    *(uint32_t *)off_11809C |= 1u;
  *a4 = *(uint8_t *)(v10 + 95);
  check_kernel_state(dword_118088);
  list_init(v10 + 148);
  list_init(v10 + 180);
  list_init(v10 + 156);
  list_init(v10 + 188);
  list_init(v10 + 164);
  list_init(v10 + 196);
  list_init(v10 + 172);
  list_init(v10 + 204);
  list_init(v10 + 212);
  v19 = v4[17] + v4[18];
  *(uint32_t *)off_11808C = 0;
  if ( v19 <= 1 )
  {
    btcoex_check_state();
    v19 = v4[17] + v4[18];
  }
  check_interrupt_flag(256, dword_118090, dword_118094, v19);
  v20 = (uint32_t *)(v4[18] + v4[17]);
  v21 = v20 == (uint32_t *)1;
  if ( v20 == (uint32_t *)1 )
    v20 = off_118098;
  result = 0;
  if ( v21 )
    *v20 = 0;
  return result;
}

