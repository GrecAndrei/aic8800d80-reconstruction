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

extern uint32_t off_101884;

// sys_status_get_bit21 @ 0x101878, size 10 bytes
// Doc: sys_status_get_bit21 [util]: Reads chip revision register and extracts a feature flag bit
// sys_status_get_bit21 [util]: Reads chip revision register and extracts a feature flag bit
int sys_status_get_bit21()
{
  return (*(uint32_t *)off_101884 >> 21) & 1;
}

