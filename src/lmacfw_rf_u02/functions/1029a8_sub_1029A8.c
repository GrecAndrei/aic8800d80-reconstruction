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

extern uint32_t off_1029B8;

// rf_get_rssi @ 0x1029a8, size 16 bytes
uint8_t * rf_get_rssi(uint8_t *result, uint8_t *a2)
{
  uint8_t *v2; // r3

  v2 = off_1029B8;
  *result = *((uint8_t *)off_1029B8 + 294);
  *a2 = v2[295];
  return result;
}

