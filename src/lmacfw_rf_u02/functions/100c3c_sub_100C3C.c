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

extern uint32_t off_100D04;
extern uint32_t off_100D0C;
extern uint32_t off_100D08;
extern uint32_t off_100D00;
extern uint32_t off_100D10;
extern uint32_t off_100D14;

// rf_cal_read_0 @ 0x100c3c, size 194 bytes
// Doc: sub_1200C3C [util]: Read linked state from globals and initialize context struct
// sub_1200C3C [util]: Read linked state from globals and initialize context struct
int  rf_cal_read_0(int result)
{
  int *v1; // r2
  unsigned int v2; // r1
  uint8_t *v3; // r6
  unsigned int *v4; // r5
  unsigned int v5; // r3
  int v6; // r3
  uint32_t *v7; // r3
  uint32_t *v8; // r2
  uint32_t *v9; // r3

  v1 = (int *)off_100D04;
  v2 = *(uint32_t *)off_100D04;
  v3 = off_100D0C;
  *(uint32_t *)off_100D08 = (*(uint8_t *)off_100D00 << 10) & 0x1FC00 | *(uint32_t *)off_100D08 & 0xFFFE03FF;
  v4 = (unsigned int *)off_100D04;
  *v1 |= 0x18u;
  v5 = *v1 & 0xFFFFFFF8;
  if ( (*v3 & 0xC0) == 0xC0 )
    v6 = v5 | 4;
  else
    v6 = v5 | 3;
  *v1 = v6;
  v7 = off_100D08;
  v8 = off_100D10;
  *(uint32_t *)off_100D08 |= 0x80000u;
  *v7 |= 0x40000u;
  *v4 = *v4 & 0xFFFFFC1F | 0xE0;
  *v8 &= ~2u;
  *v8 |= 1u;
  if ( !result && ((v2 >> 5) & 0x1F) != 7 )
  {
    v9 = off_100D14;
    *(uint32_t *)off_100D14 |= 0x80u;
    *v9 &= ~0x40u;
    *v9 |= 0x40u;
    *v9 &= ~0x80u;
  }
  return result;
}

