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

extern uint32_t off_100DEC;
extern uint32_t off_100DF4;
extern uint32_t off_100DF0;
extern uint32_t off_100DE8;
extern uint32_t off_100DF8;
extern uint32_t off_100DFC;

// rf_cal_read_1 @ 0x100d18, size 208 bytes
unsigned int rf_cal_read_1()
{
  unsigned int *v0; // r2
  unsigned int v1; // r1
  uint8_t *v2; // r5
  int v3; // r1
  unsigned int v4; // r3
  unsigned int *v5; // r3
  unsigned int *v6; // r4
  uint32_t *v7; // r2
  unsigned int result; // r0
  uint32_t *v9; // r3

  v0 = (unsigned int *)off_100DEC;
  v1 = *(uint32_t *)off_100DEC;
  v2 = off_100DF4;
  *(uint32_t *)off_100DF0 = (*((uint8_t *)off_100DE8 + 1) << 10) & 0x1FC00 | *(uint32_t *)off_100DF0 & 0xFFFE03FF;
  v3 = (v1 >> 5) & 0x1F;
  v4 = *v0 & 0xFFFFFFE7;
  if ( (*v2 & 0xC0) == 0xC0 )
  {
    *v0 = v4 | 0x10;
    *v0 = *v0 & 0xFFFFFFF8 | 1;
  }
  else
  {
    *v0 = v4 | 8;
    *v0 |= 7u;
  }
  v5 = (unsigned int *)off_100DF0;
  v6 = (unsigned int *)off_100DEC;
  v7 = off_100DF8;
  *(uint32_t *)off_100DF0 &= ~0x80000u;
  result = *v5 & 0xFFFBFFFF;
  *v5 = result;
  *v6 = *v6 & 0xFFFFFC1F | 0x80;
  *v7 |= 2u;
  *v7 &= ~1u;
  if ( v3 != 4 )
  {
    v9 = off_100DFC;
    *(uint32_t *)off_100DFC |= 0x80u;
    *v9 &= ~0x40u;
    *v9 |= 0x40u;
    *v9 &= ~0x80u;
  }
  return result;
}

