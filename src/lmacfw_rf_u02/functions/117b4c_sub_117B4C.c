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


extern uint32_t dword_117C94;
extern uint32_t dword_117C98;
extern uint32_t dword_117C9C;
extern uint32_t dword_117CA8;
extern uint32_t off_117CAC;
extern uint32_t off_117CB0;

// btcoex_update_bt_info @ 0x117b4c, size 328 bytes
int  btcoex_update_bt_info(int *a1, uint8_t *a2)
{
  int v3; // r6
  uint32_t *v5; // r0
  uint32_t *v6; // r4
  int v7; // r1
  char *v8; // r2
  int v9; // r0
  int v10; // r3
  unsigned int v11; // r0
  char v12; // r3
  int v13; // r3
  int v14; // r6
  int v15; // r3
  uint32_t *v16; // r3
  int v17; // r0
  int v18; // r2
  int v19; // r1
  uint32_t *v20; // r1
  uint32_t *v22; // r0
  char v23; // r1
  uint16_t v24; // lr
  int v25; // r3
  uint16_t v26; // r12
  int v27; // r12

  v3 = *((uint8_t *)a1 + 25);
  v5 = list_pop_front(dword_117C94);
  if ( !v5 )
    return 1;
  v6 = v5;
  if ( *((uint8_t *)a1 + 29) )
  {
    v22 = list_pop_front(dword_117C94);
    if ( !v22 )
    {
      check_kernel_state(dword_117C94, v6);
      return 1;
    }
    v6[11] = v22;
    v22[11] = v6;
    v23 = *((uint8_t *)a1 + 30);
    v8 = (char *)a1 + 18;
    v24 = *((uint8_t *)a1 + 29);
    v22[9] = *(int *)((char *)a1 + 18);
    *((uint16_t *)v22 + 20) = *((uint16_t *)a1 + 11);
    v25 = (1 << v23) - 1;
    v7 = dword_117C98;
    LOWORD(v25) = (uint16_t)v25 << 8;
    v26 = v22[10] & ~(uint16_t)v25;
    *((uint16_t *)v22 + 20) = v26;
    LOWORD(v25) = v26 | v25 & (*((uint16_t *)a1 + 11) - (v24 << 8));
    v27 = dword_117C9C * (((int)v22 - v7) >> 3);
    *((uint16_t *)v22 + 20) = v25;
    *((uint8_t *)v22 + 33) = v27;
    *((uint16_t *)v22 + 15) = -1;
  }
  else
  {
    v7 = dword_117C98;
    v8 = (char *)a1 + 18;
  }
  v9 = *(uint32_t *)v8;
  v10 = *a1;
  *((uint16_t *)v6 + 20) = *((uint16_t *)v8 + 2);
  v6[1] = v10;
  v6[9] = v9;
  v11 = *((uint8_t *)a1 + 24);
  v12 = dword_117C9C;
  if ( v11 < 0x10 )
    LOBYTE(v11) = 16;
  *((uint8_t *)v6 + 28) = v11;
  *((uint16_t *)v6 + 10) = *((uint16_t *)a1 + 8);
  v6[4] = a1[2];
  v6[3] = a1[1];
  v6[6] = a1[3];
  v13 = (uint8_t)(v12 * (((int)v6 - v7) >> 3));
  *((uint8_t *)v6 + 32) = *((uint8_t *)a1 + 25);
  *a2 = v13;
  *((uint8_t *)v6 + 33) = v13;
  check_interrupt_flag(256, "%s: sta_idx=%d\n", aStaMgmtRegiste, v13);
  v14 = dword_117CA8 + 224 * v3;
  if ( *(uint8_t *)(v14 + 94) )
    v15 = 102400;
  else
    v15 = *(uint16_t *)(v14 + 100) << 10;
  v6[2] = v15;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_117CAC = 1;
  }
  v16 = off_117CB0;
  v17 = v6[11];
  v18 = *(uint32_t *)off_117CB0;
  v19 = *(uint32_t *)off_117CB0 + 1;
  *(uint32_t *)off_117CB0 = v19;
  *((uint8_t *)v6 + 35) = 1;
  if ( v17 )
    *(uint8_t *)(v17 + 35) = 1;
  if ( v19 )
  {
    v20 = off_117CAC;
    *v16 = v18;
    if ( !v18 )
    {
      if ( *v20 )
        __enable_irq();
    }
  }
  *((uint8_t *)v6 + 124) = 0;
  return 0;
}
