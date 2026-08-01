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

extern uint32_t off_10F26C;

// tx_store_packet @ 0x10f23c, size 48 bytes
int tx_store_packet()
{
  uint8_t *v0; // r4
  char *v1; // r0

  v0 = off_10F26C;
  v1 = (char *)off_10F26C + 1624;
  *((uint16_t *)off_10F26C + 810) = 80;
  v0[1622] = 81;
  clear_stats_buf(v1);
  *((uint16_t *)v0 + 1216) = 39;
  v0[2434] = 40;
  return clear_stats_buf(v0 + 2436);
}

