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

extern uint32_t off_101A44;

// rf_get_status_bit26 @ 0x101a38, size 10 bytes
// Doc: rf_get_status_bit26 [mmio]: Read flag bit 0x1a from MMIO register 0x40330000
// rf_get_status_bit26 [mmio]: Read flag bit 0x1a from MMIO register 0x40330000
int rf_get_status_bit26()
{
  return (*(uint32_t *)off_101A44 >> 26) & 1;
}

