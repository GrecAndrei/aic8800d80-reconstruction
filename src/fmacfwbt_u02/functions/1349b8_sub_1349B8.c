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

extern uint32_t dword_1349D4;
extern uint32_t off_1349D0;

// phy_channel_index_lookup @ 0x1349b8, size 24 bytes
int  phy_channel_index_lookup(uint8_t *a1)
{
  return find_free_conn(
           (uint8_t *)(dword_1349D4 + 1320 * *(uint8_t *)(*((uint32_t *)off_1349D0 + 4) + 61)),
           a1);
}

