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

extern uint32_t off_101A84;

// sys_status_bit30_get @ 0x101a78, size 10 bytes
// Doc: sys_status_bit30_get [mmio]: Reads MMIO register 0x40330000 and returns bit 30
// sys_status_bit30_get [mmio]: Reads MMIO register 0x40330000 and returns bit 30
int sys_status_bit30_get()
{
  return (*(uint32_t *)off_101A84 >> 30) & 1;
}

