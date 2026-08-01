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
extern uint32_t dword_117CA0;
extern uint32_t dword_117CA4;
extern uint32_t dword_117CA8;
extern uint32_t off_117CAC;
extern uint32_t off_117CB0;

// btcoex_update_bt_info @ 0x117b4c, size 328 bytes
int  btcoex_update_bt_info(int *a1, uint8_t *a2)
{
  int v3; // r6
  int v5; // r0
  int v6; // r4
  int v7; // r1
  int *v8; // r2
  int v9; // r0
  int v10; // r3
  unsigned int v11; // r0
  char v12; // r3
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r6
  int v17; // r3
  uint32_t *v18; // r3
  int v19; // r0
  int v20; // r2
  int v21; // r1
  uint32_t *v22; // r1
  int v24; // r0
  char v25; // r1
  int16_t v26; // lr
  int v27; // r3
  int16_t v28; // r12
  int v29; // r12

  v3 = *((uint8_t *)a1 + 25);
  v5 = list_pop_front(dword_117C94);
  if ( !v5 )
    return 1;
  v6 = v5;
  if ( *((uint8_t *)a1 + 29) )
  {
    v24 = list_pop_front(dword_117C94);
    if ( !v24 )
    {
      check_kernel_state(dword_117C94);
      return 1;
    }
    *(uint32_t *)(v6 + 44) = v24;
    *(uint32_t *)(v24 + 44) = v6;
    v25 = *((uint8_t *)a1 + 30);
    v8 = (int *)((char *)a1 + 18);
    v26 = *((uint8_t *)a1 + 29);
    *(uint32_t *)(v24 + 36) = *(int *)((char *)a1 + 18);
    *(uint16_t *)(v24 + 40) = *((uint16_t *)a1 + 11);
    v27 = (1 << v25) - 1;
    v7 = dword_117C98;
    LOWORD(v27) = (uint16_t)v27 << 8;
    v28 = *(uint16_t *)(v24 + 40) & ~(uint16_t)v27;
    *(uint16_t *)(v24 + 40) = v28;
    LOWORD(v27) = v28 | v27 & (*((uint16_t *)a1 + 11) - (v26 << 8));
    v29 = dword_117C9C * ((v24 - v7) >> 3);
    *(uint16_t *)(v24 + 40) = v27;
    *(uint8_t *)(v24 + 33) = v29;
    *(uint16_t *)(v24 + 30) = -1;
  }
  else
  {
    v7 = dword_117C98;
    v8 = (int *)((char *)a1 + 18);
  }
  v9 = *v8;
  v10 = *a1;
  *(uint16_t *)(v6 + 40) = *((uint16_t *)v8 + 2);
  *(uint32_t *)(v6 + 4) = v10;
  *(uint32_t *)(v6 + 36) = v9;
  v11 = *((uint8_t *)a1 + 24);
  v12 = dword_117C9C;
  v13 = dword_117CA0;
  if ( v11 < 0x10 )
    LOBYTE(v11) = 16;
  *(uint8_t *)(v6 + 28) = v11;
  *(uint16_t *)(v6 + 20) = *((uint16_t *)a1 + 8);
  *(uint32_t *)(v6 + 16) = a1[2];
  *(uint32_t *)(v6 + 12) = a1[1];
  *(uint32_t *)(v6 + 24) = a1[3];
  v14 = (uint8_t)(v12 * ((v6 - v7) >> 3));
  *(uint8_t *)(v6 + 32) = *((uint8_t *)a1 + 25);
  *a2 = v14;
  v15 = dword_117CA4;
  *(uint8_t *)(v6 + 33) = v14;
  check_interrupt_flag(256, v15, v13, v14);
  v16 = dword_117CA8 + 224 * v3;
  if ( *(uint8_t *)(v16 + 94) )
    v17 = 102400;
  else
    v17 = *(uint16_t *)(v16 + 100) << 10;
  *(uint32_t *)(v6 + 8) = v17;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_117CAC = 1;
  }
  v18 = off_117CB0;
  v19 = *(uint32_t *)(v6 + 44);
  v20 = *(uint32_t *)off_117CB0;
  v21 = *(uint32_t *)off_117CB0 + 1;
  *(uint32_t *)off_117CB0 = v21;
  *(uint8_t *)(v6 + 35) = 1;
  if ( v19 )
    *(uint8_t *)(v19 + 35) = 1;
  if ( v21 )
  {
    v22 = off_117CAC;
    *v18 = v20;
    if ( !v20 )
    {
      if ( *v22 )
        __enable_irq();
    }
  }
  *(uint8_t *)(v6 + 124) = 0;
  return 0;
}

