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

extern uint32_t off_1073A0;
extern uint32_t off_1073A4;
extern uint32_t off_1073A8;
extern uint32_t dword_1073B8;
extern uint32_t dword_1073AC;
extern uint32_t dword_1073B0;
extern uint32_t off_1073B4;

// rf_core_irq_clear @ 0x1072cc, size 212 bytes
int  rf_core_irq_clear(int a1, uint32_t *a2, int a3)
{
  uint32_t *v3; // r5
  unsigned int *v4; // r4
  int *v5; // r6
  int v6; // r8
  int v7; // r7
  uint64_t v8; // kr00_8
  int v9; // r3
  int *v10; // r0
  int v11; // r0
  unsigned int v12; // r3
  int result; // r0

  v3 = off_1073A0;
  v4 = (unsigned int *)off_1073A4;
  v5 = (int *)off_1073A8;
  v6 = dword_1073B8;
  v7 = dword_1073AC;
  v8 = *(uint64_t *)(a1 + 8);
  clk_set_divider();
  *v3 &= ~1u;
  write_timer_reg(20);
  v9 = dword_1073B0;
  *v3 |= 4u;
  *v3 |= 8u;
  *v4 |= 0x100000u;
  *v4 |= 0x200000u;
  *v5 = v9 & (HIDWORD(v8) << 16) | *v5 & v6;
  *v5 = *v5 & v7 | v8 & 0xFFF;
  write_timer_reg(40);
  v10 = (int *)off_1073B4;
  *v4 |= 0x4000000u;
  v11 = *v10;
  *v4 &= ~0x4000000u;
  *v4 &= ~0x100000u;
  v12 = *v4 & 0xFFDFFFFF;
  *v4 = v12;
  result = rf_core_cmd_post(v11 & 0x7FFF, a2, a3, v12);
  *v3 &= ~4u;
  *v3 &= ~8u;
  *v5 &= v6;
  *v5 &= v7;
  *v4 &= ~0x1000000u;
  *v4 &= ~0x2000000u;
  return result;
}

