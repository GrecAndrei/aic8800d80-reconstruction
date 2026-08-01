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

// rf_set_cal_u32_dc @ 0x13144c, size 40 bytes
// Doc: rf_set_cal_u32_dc [rf]: Checks RF state and updates control register pair
// rf_set_cal_u32_dc [rf]: Checks RF state and updates control register pair
uint8_t * rf_set_cal_u32_dc(uint8_t *a1, int a2, int a3)
{
  uint8_t *result; // r0
  char v5; // [sp+7h] [bp-1h] BYREF

  result = parse_dollar_u16(a1, a2, &v5);
  if ( result )
    *(uint32_t *)(a3 + 220) = *(uint32_t *)(result + 3);
  else
    *(uint32_t *)(a3 + 220) = 0x80000000;
  return result;
}

