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

extern uint32_t off_103AF8;

// rf_lo_cal_clear @ 0x103ac4, size 50 bytes
int rf_lo_cal_clear()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_103AF8;
  *(uint32_t *)off_103AF8 &= ~0x400000u;
  *v0 &= ~0x200000u;
  timer_set(2);
  *v0 |= 0x200000u;
  result = timer_set(2);
  *v0 |= 0x400000u;
  return result;
}

