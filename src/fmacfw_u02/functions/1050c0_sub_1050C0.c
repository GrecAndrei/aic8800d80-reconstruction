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


extern uint32_t dword_105170;
extern uint32_t off_10516C;
extern uint32_t off_105174;
extern uint32_t off_105180;
extern uint32_t off_105184;

// mac_reset_disable @ 0x1050c0, size 172 bytes
int  mac_reset_disable(int a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r4
  int *v5; // r9
  int v6; // r5
  uint32_t *v7; // r11
  uint32_t *v12; // r2
  unsigned int v13; // r5
  unsigned int v14; // r0
  int result; // r0

  v4 = (unsigned int *)off_10516C;
  v5 = (int *)off_105180;
  v6 = dword_105170;
  v7 = off_105184;
  *(uint32_t *)off_10516C &= ~0x20000000u;
  *v5 = *v5 & v6 | 0x80;
  timer_delay(300);
  *v5 = v6 & *v5 | a1 & 0xFFF;
  *v7 = 0;
  timer_delay(2);
  *v7 = 8;
  timer_delay(300);
  v12 = off_105174;
  *v4 |= 0x40000000u;
  v13 = HIWORD(*v12) & 0x3FFF;
  v14 = *v4 & 0xBFFFFFFF;
  *(uint16_t *)(a2 + 2 * (a3 + 16 * a4)) = v13;
  *v4 = v14;
  result = check_status_bits(1, "amp=%x pwr_amp_back[%d][%x]=%6d\n", a1, a4, a3, v13);
  if ( v13 > 0x3E80 )
    return event_dispatch(aWarningDataSat_0);
  return result;
}
