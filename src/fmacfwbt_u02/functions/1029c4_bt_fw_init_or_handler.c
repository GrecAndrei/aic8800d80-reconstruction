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

extern uint32_t off_1029D4;

// read_calibration_offsets @ 0x1029c4, size 16 bytes
// Doc: read_calibration_offsets [bt]: Bluetooth firmware init/handler routine
// read_calibration_offsets [bt]: Bluetooth firmware init/handler routine
uint8_t * read_calibration_offsets(uint8_t *result, uint8_t *a2)
{
  uint8_t *v2; // r3

  v2 = off_1029D4;
  *result = *((uint8_t *)off_1029D4 + 294);
  *a2 = v2[295];
  return result;
}

