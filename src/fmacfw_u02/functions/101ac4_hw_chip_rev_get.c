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

extern uint32_t off_101AD4;

// rf_get_field8 @ 0x101ac4, size 14 bytes
// Doc: rf_get_field8 [mmio]: Read chip revision field from HW register
// rf_get_field8 [mmio]: Read chip revision field from HW register
int rf_get_field8()
{
  return (uint8_t)((BYTE1(*(uint32_t *)off_101AD4) & 0xF) - 1);
}

