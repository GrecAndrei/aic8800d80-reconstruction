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

extern uint32_t off_101A74;

// sys_status_bit28_get @ 0x101a68, size 10 bytes
// Doc: sys_status_bit28_get [mac]: Read PHY status bit 28 from 0x40330000 register
// sys_status_bit28_get [mac]: Read PHY status bit 28 from 0x40330000 register
int sys_status_bit28_get()
{
  return (*(uint32_t *)off_101A74 >> 28) & 1;
}

