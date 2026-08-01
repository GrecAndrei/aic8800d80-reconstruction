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

extern uint32_t off_1018E0;

// sys_status_get_bit30 @ 0x1018d4, size 10 bytes
// Doc: sys_status_get_bit30 [mmio]: Returns bit 30 of chip ID register at 0x40330000
// sys_status_get_bit30 [mmio]: Returns bit 30 of chip ID register at 0x40330000
int sys_status_get_bit30()
{
  return (*(uint32_t *)off_1018E0 >> 30) & 1;
}

