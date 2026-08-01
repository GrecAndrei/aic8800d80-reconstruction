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

extern uint32_t off_10F194;

// rf_save_rssi @ 0x10f180, size 18 bytes
unsigned int rf_save_rssi()
{
  unsigned int result; // r0

  result = write_phy_config(0xC2u);
  *((uint8_t *)off_10F194 + 7) = -62;
  return result;
}

