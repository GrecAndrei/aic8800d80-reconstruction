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

extern uint32_t off_118904;

// write_bb_control @ 0x1188f4, size 14 bytes
// Doc: write_bb_control [mmio]: Writes 0x30 to MMIO 0x40320038 to configure clock gate/control
// write_bb_control [mmio]: Writes 0x30 to MMIO 0x40320038 to configure clock gate/control
int write_bb_control()
{
  *(uint32_t *)off_118904 = 48;
  return flash_erase_sector(0);
}

