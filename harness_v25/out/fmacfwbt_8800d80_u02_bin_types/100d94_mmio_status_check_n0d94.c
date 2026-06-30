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

extern uint32_t off_100E44;
extern uint32_t off_100E48;
extern uint32_t off_100E4C;
extern uint32_t off_100E40;
extern uint32_t off_100E50;

// mmio_status_check_n0d94 @ 0x100d94, size 172 bytes
// Doc: mmio_status_check_n0d94 [mmio]: Reads and checks status from MMIO registers
// mmio_status_check_n0d94 [mmio]: Reads and checks status from MMIO registers
uint32_t *mmio_status_check_n0d94()
{
  unsigned int *v0; // r3
  uint32_t *v1; // r1
  unsigned int v2; // r4
  uint32_t *result; // r0
  uint32_t *v4; // r3

  v0 = (unsigned int *)off_100E44;
  v1 = off_100E48;
  v2 = *(uint32_t *)off_100E44;
  result = off_100E4C;
  *(uint32_t *)off_100E48 = (*((uint8_t *)off_100E40 + 1) << 10) & 0x1FC00 | *(uint32_t *)off_100E48 & 0xFFFE03FF;
  *v0 = *v0 & 0xFFFFFFE7 | 8;
  *v0 |= 7u;
  *v1 &= ~0x80000u;
  *v1 &= ~0x40000u;
  *v0 = *v0 & 0xFFFFFC1F | 0x80;
  *result |= 2u;
  *result &= ~1u;
  if ( ((v2 >> 5) & 0x1F) != 4 )
  {
    v4 = off_100E50;
    *(uint32_t *)off_100E50 |= 0x80u;
    *v4 &= ~0x40u;
    *v4 |= 0x40u;
    *v4 &= ~0x80u;
  }
  return result;
}

