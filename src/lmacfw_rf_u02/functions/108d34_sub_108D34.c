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


extern uint32_t dword_108F44;
extern uint32_t off_108F20;
extern uint32_t off_108F24;
extern uint32_t off_108F28;
extern uint32_t off_108F2C;
extern uint32_t off_108F30;
extern uint32_t off_108F34;
extern uint32_t off_108F38;
extern uint32_t off_108F3C;
extern uint32_t off_108F40;

// rf_core_init @ 0x108d34, size 492 bytes
uint32_t * rf_core_init(int a1, int a2)
{
  uint32_t *v2; // r2
  unsigned int *v3; // r3
  uint32_t *v4; // r12
  uint32_t *v5; // r6
  unsigned int *v6; // r7
  unsigned int *v7; // r4
  uint32_t *v8; // lr
  int v9; // r11
  int v10; // r6
  int *v11; // r5
  int v14; // r9
  int i; // r4
  int v16; // lr
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r12
  unsigned int *v21; // r3
  uint32_t *result; // r0
  uint32_t *v23; // r2
  int v24; // [sp+0h] [bp-Ch] BYREF
  unsigned int a2a; // [sp+4h] [bp-8h] BYREF

  v2 = off_108F20;
  v3 = (unsigned int *)off_108F24;
  v4 = off_108F40;
  v5 = off_108F28;
  v6 = (unsigned int *)off_108F2C;
  v7 = (unsigned int *)off_108F30;
  v8 = off_108F38;
  v9 = dword_108F44;
  *(uint32_t *)off_108F20 &= ~4u;
  *v5 &= 0xFFFF0FFF;
  v10 = 0;
  *v6 = 0;
  *v3 |= 0x80u;
  *v7 |= 0x80000000;
  *v2 |= 4u;
  v6 -= 6154;
  *v4 = HIWORD(*v4) << 16;
  *v6 = *v6 & 0xCFFFFFFF | 0x10000000;
  *v2 &= ~4u;
  *v7 &= ~0x80000000;
  *v3 &= ~0x80u;
  *v2 |= 4u;
  v11 = (int *)off_108F34;
  *v8 |= 2u;
  *v3 = *v3 & 0xFFFF8FFF | 0x4000;
  *v3 = *v3 & 0xF8FFFFFF | 0x6000000;
  *v3 = *v3 & 0xFFFFF8FF | 0x100;
  *v3 &= ~4u;
  *v3 |= 1u;
  *v3 |= 8u;
  *v7 = ((unsigned int)v6 + 1059082178) | *v7 & 0x80000000;
  v14 = ((v4[8208] >> 3) & 7) << 6;
  for ( i = 0; i != 16; ++i )
  {
    while ( ((a1 >> i) & 1) == 0 )
    {
      if ( ++i == 16 )
        goto LABEL_7;
    }
    *v11 = *v11 & v9 | ((uint16_t)(v14 | (4 * i)) << 8);
    *v11 |= 0x20000u;
    *v11 |= 0x40000u;
    write_timer_reg(1);
    rf_wait_for_command(&v24, &a2a);
    v16 = (int)a2a / 8;
    v17 = i;
    v18 = v24 / 8;
    v19 = (int)a2a / 8;
    if ( a2 )
    {
      *(uint16_t *)(a2 + 4 * v10) = v24 / 8;
      v20 = a2 + 4 * v10++;
      *(uint16_t *)(v20 + 2) = v16;
    }
    dispatch_event_handler_1(aDc0xXIDQD, v17, v18, v19);
  }
LABEL_7:
  v21 = (unsigned int *)off_108F24;
  result = off_108F3C;
  v23 = off_108F34;
  *(uint32_t *)off_108F38 &= ~2u;
  *v21 |= 4u;
  *v21 = *v21 & 0xFFFF8FFF | 0x3000;
  *v21 = *v21 & 0xFFFFF8FF | 0x600;
  *v21 &= ~8u;
  *v21 &= ~1u;
  *result &= 0xCFFFFFFF;
  *v23 &= 0xFFFE00FF;
  *v23 &= ~0x20000u;
  *v23 |= 0x40000u;
  return result;
}
