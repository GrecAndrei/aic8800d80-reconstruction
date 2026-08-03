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

extern uint32_t off_100F9C;
extern uint32_t off_100FA0;
extern uint32_t off_100FA4;
extern uint32_t off_100F98;
extern uint32_t off_100FA8;

// sub_100EE8 @ 0x100ee8, size 176 bytes
uint32_t *sub_100EE8()
{
  unsigned int *v0; // r3
  uint32_t *v1; // r1
  unsigned int v2; // r4
  uint32_t *result; // r0
  uint32_t *v4; // r3

  v0 = (unsigned int *)off_100F9C;
  v1 = off_100FA0;
  v2 = *(uint32_t *)off_100F9C;
  result = off_100FA4;
  *(uint32_t *)off_100FA0 = (*((uint8_t *)off_100F98 + 1) << 10) & 0x1FC00 | *(uint32_t *)off_100FA0 & 0xFFFE03FF;
  *v0 = *v0 & 0xFFFFFFE7 | 0x10;
  *v0 = *v0 & 0xFFFFFFF8 | 1;
  *v1 &= ~0x80000u;
  *v1 &= ~0x40000u;
  *v0 = *v0 & 0xFFFFFC1F | 0x80;
  *result |= 2u;
  *result &= ~1u;
  if ( ((v2 >> 5) & 0x1F) != 4 )
  {
    v4 = off_100FA8;
    *(uint32_t *)off_100FA8 |= 0x80u;
    *v4 &= ~0x40u;
    *v4 |= 0x40u;
    *v4 &= ~0x80u;
  }
  return result;
}

