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


extern uint32_t dword_105058;
extern uint32_t off_105054;
extern uint32_t off_10505C;
extern uint32_t off_105068;
extern uint32_t off_10506C;

// rf_path_disable @ 0x104fa8, size 172 bytes
int  rf_path_disable(int a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r4
  int *v5; // r9
  int v6; // r5
  uint32_t *v7; // r11
  uint32_t *v12; // r2
  unsigned int v13; // r5
  unsigned int v14; // r0
  int result; // r0

  v4 = (unsigned int *)off_105054;
  v5 = (int *)off_105068;
  v6 = dword_105058;
  v7 = off_10506C;
  *(uint32_t *)off_105054 &= ~0x20000000u;
  *v5 = *v5 & v6 | 0x80;
  mmio_read32(300);
  *v5 = v6 & *v5 | a1 & 0xFFF;
  *v7 = 0;
  mmio_read32(2);
  *v7 = 8;
  mmio_read32(300);
  v12 = off_10505C;
  *v4 |= 0x40000000u;
  v13 = HIWORD(*v12) & 0x3FFF;
  v14 = *v4 & 0xBFFFFFFF;
  *(uint16_t *)(a2 + 2 * (a3 + 16 * a4)) = v13;
  *v4 = v14;
  result = check_feature_flag(1, "amp=%x pwr_amp_back[%d][%x]=%6d\n", a1, a4, a3, v13);
  if ( v13 > 0x3E80 )
    return alloc_tx_event(aWarningDataSat_0);
  return result;
}
