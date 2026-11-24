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


extern uint32_t dword_102904;
extern uint32_t off_1028FC;
extern uint32_t off_102900;

// wifi_set_channel @ 0x1028b8, size 66 bytes
int  wifi_set_channel(int *a1)
{
  int *v2; // r6
  int v3; // r7
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int result; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3

  rf_band_config();
  rf_ctrl_set(0, 2412);
  pmu_write_ctrl();
  v2 = (int *)off_102900;
  v3 = dword_102904;
  *(uint32_t *)off_1028FC &= 0xFFFFFC00;
  v4 = *a1;
  v5 = a1[1];
  v6 = a1[2];
  v7 = a1[3];
  a1 += 4;
  *v2 = v4;
  v2[1] = v5;
  v2[2] = v6;
  v2[3] = v7;
  result = *a1;
  v9 = a1[1];
  v10 = a1[2];
  v11 = a1[3];
  v2[4] = *a1;
  v2[5] = v9;
  v2[6] = v10;
  v2[7] = v11;
  v2[8] = a1[4];
  v2[9] = v3;
  v2[10] = 16711935;
  return result;
}
