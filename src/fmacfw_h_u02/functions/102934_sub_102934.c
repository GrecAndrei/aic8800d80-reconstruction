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


extern uint32_t dword_10296C;
extern uint32_t off_102968;

// set_rf_channel @ 0x102934, size 52 bytes
void  set_rf_channel(int *a1)
{
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  uint32_t *v6; // r6
  int v7; // r7
  int *v8; // r5
  int v9; // r1
  int v10; // r2
  int v11; // r3

  pll_enable();
  sdio_irq_enable(0, 2412);
  pll_clock_config();
  v2 = *a1;
  v3 = a1[1];
  v4 = a1[2];
  v5 = a1[3];
  a1 += 4;
  v6 = off_102968;
  v7 = dword_10296C;
  v8 = (int *)off_102968;
  *(uint32_t *)off_102968 = v2;
  v8[1] = v3;
  v8[2] = v4;
  v8[3] = v5;
  v8 += 4;
  v9 = a1[1];
  v10 = a1[2];
  v11 = a1[3];
  *v8 = *a1;
  v8[1] = v9;
  v8[2] = v10;
  v8[3] = v11;
  v8[4] = a1[4];
  v6[9] = v7;
  v6[10] = 16711935;
}
