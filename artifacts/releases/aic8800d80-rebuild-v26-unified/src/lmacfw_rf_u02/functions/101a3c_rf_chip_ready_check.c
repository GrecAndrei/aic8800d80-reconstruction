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

extern uint32_t off_101A4C;

// rf_chip_ready_check @ 0x101a3c, size 14 bytes
// Doc: rf_chip_ready_check [rf]: Check RF chip ready flag at 0x40341424, return 1 if > 1
// rf_chip_ready_check [rf]: Check RF chip ready flag at 0x40341424, return 1 if > 1
BOOL rf_chip_ready_check()
{
  return *(uint32_t *)off_101A4C > 1u;
}

