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

extern uint32_t off_102A30;
extern uint32_t off_102A34;

// rf_power_set @ 0x1029f8, size 56 bytes
// Doc: rf_power_set [rf]: Set RF power level via register field
// rf_power_set [rf]: Set RF power level via register field
unsigned int  rf_power_set(uint8_t a1)
{
  unsigned int *v1; // r1
  unsigned int *v2; // r2
  uint8_t v3; // r0
  unsigned int result; // r0

  v1 = (unsigned int *)off_102A30;
  v2 = (unsigned int *)off_102A34;
  *(uint32_t *)off_102A30 = *(uint32_t *)off_102A30 & 0xFFFFFF00 | a1;
  *v2 = *v2 & 0xFFFFFF00 | a1;
  v3 = a1 - 3;
  *v1 = *v1 & 0xFFF00FFF | (v3 << 12);
  result = *v2 & 0xFFF00FFF | (v3 << 12);
  *v2 = result;
  return result;
}

