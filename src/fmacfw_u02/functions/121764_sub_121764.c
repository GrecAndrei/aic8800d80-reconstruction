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

extern uint32_t off_121784;

// delay_and_clear_flag @ 0x121764, size 32 bytes
int delay_and_clear_flag()
{
  unknown_func_12d14c(0x2000000);
  *((uint32_t *)off_121784 + 1) &= ~4u;
  return rx_phy_status_parse(0);
}

