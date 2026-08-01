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

extern uint32_t off_10761C;
extern uint32_t off_107620;
extern uint32_t off_107624;
extern uint32_t dword_107628;
extern uint32_t off_107634;
extern uint32_t dword_10762C;
extern uint32_t dword_107630;

// rf_core_irq_poll @ 0x10747c, size 414 bytes
int  rf_core_irq_poll(int a1)
{
  int *v1; // r4
  uint32_t *v2; // r6
  int *v3; // r5
  int v4; // r7
  uint32_t *v5; // r11
  int v7; // r1
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // cc
  int v12; // r2
  int v13; // r9
  int v14; // r1
  int result; // r0
  unsigned int v16; // [sp+20h] [bp-14h] BYREF
  unsigned int v17; // [sp+24h] [bp-10h]
  int v18; // [sp+28h] [bp-Ch]
  int v19; // [sp+2Ch] [bp-8h]

  v1 = (int *)off_10761C;
  v2 = off_107620;
  v3 = (int *)off_107624;
  v4 = dword_107628;
  v5 = off_107634;
  load_patch_bundle(a1);
  v7 = dword_10762C;
  *v1 |= 0x1000000u;
  v8 = *v1 | 0x2000000;
  *v1 = v8;
  check_interrupt_flag(1, v7, v9, v8);
  clk_set_divider();
  *v2 &= ~1u;
  write_timer_reg(20);
  *v2 |= 4u;
  *v2 |= 8u;
  write_timer_reg(20);
  *v1 |= 0x800000u;
  *v3 = *v3 & v4 | 0xC000000;
  write_timer_reg(20);
  *v1 |= 0x4000000u;
  v10 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v16 = v10;
  *v3 = *v3 & v4 | 0x4000000;
  write_timer_reg(20);
  *v1 |= 0x4000000u;
  v17 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v11 = v16 > v17;
  if ( v16 <= v17 )
    v12 = 234881024;
  else
    v12 = 100663296;
  *v3 = *v3 & v4 | v12;
  if ( v11 )
    v13 = 0x2000000;
  else
    v13 = 167772160;
  write_timer_reg(20);
  *v1 |= 0x4000000u;
  v18 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  *v3 = *v3 & v4 | v13;
  write_timer_reg(20);
  v14 = dword_107630;
  *v1 |= 0x4000000u;
  v19 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  *v1 &= ~0x800000u;
  check_interrupt_flag(1, v14, 3072, v16);
  result = timer_delta_compare(&v16, a1);
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 &= v4;
  *v1 &= ~0x1000000u;
  *v1 &= ~0x2000000u;
  return result;
}

