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

extern uint32_t off_101AC0;

// chip_info_nibble0_get @ 0x101ab0, size 14 bytes
// Doc: chip_info_nibble0_get [util]: Read chip revision register and extract (val & 0xf) - 1
// chip_info_nibble0_get [util]: Read chip revision register and extract (val & 0xf) - 1
int chip_info_nibble0_get()
{
  return (uint8_t)((*(uint8_t *)off_101AC0 & 0xF) - 1);
}

