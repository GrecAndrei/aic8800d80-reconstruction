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

extern uint32_t off_100ED8;
extern uint32_t off_100EDC;
extern uint32_t off_100EE0;
extern uint32_t off_100ED4;
extern uint32_t off_100EE4;

// rf_config_read_a @ 0x100e24, size 174 bytes
int  rf_config_read_a(int result)
{
  unsigned int *v1; // r3
  uint32_t *v2; // r1
  unsigned int v3; // r5
  uint32_t *v4; // r4
  uint32_t *v5; // r3

  v1 = (unsigned int *)off_100ED8;
  v2 = off_100EDC;
  v3 = *(uint32_t *)off_100ED8;
  v4 = off_100EE0;
  *(uint32_t *)off_100EDC = (*(uint8_t *)off_100ED4 << 10) & 0x1FC00 | *(uint32_t *)off_100EDC & 0xFFFE03FF;
  *v1 |= 0x18u;
  *v1 = *v1 & 0xFFFFFFF8 | 4;
  *v2 |= 0x80000u;
  *v2 |= 0x40000u;
  *v1 = *v1 & 0xFFFFFC1F | 0xE0;
  *v4 &= ~2u;
  *v4 |= 1u;
  if ( !result && ((v3 >> 5) & 0x1F) != 7 )
  {
    v5 = off_100EE4;
    *(uint32_t *)off_100EE4 |= 0x80u;
    *v5 &= ~0x40u;
    *v5 |= 0x40u;
    *v5 &= ~0x80u;
  }
  return result;
}

