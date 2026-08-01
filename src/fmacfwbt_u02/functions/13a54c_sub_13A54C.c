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

extern uint32_t off_13A570;

// rf_save_cal_values @ 0x13a54c, size 36 bytes
uint16_t * rf_save_cal_values(uint16_t *result)
{
  uint16_t *v1; // r3

  v1 = off_13A570;
  if ( !*((uint8_t *)off_13A570 + 115) )
  {
    *((uint16_t *)off_13A570 + 54) = *result;
    v1[55] = result[1];
    v1[56] = result[2];
    v1[57] = 256;
  }
  return result;
}

