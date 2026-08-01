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

// rf_get_cal_bytes @ 0x131364, size 60 bytes
uint8_t * rf_get_cal_bytes(uint8_t *a1, int a2, int a3)
{
  uint8_t *result; // r0
  int16_t v5; // r1
  int16_t v6; // r6
  int16_t v7; // r5
  int16_t v8; // r2
  int v9; // r7
  int16_t v10; // r3
  int16_t v11; // r0

  result = parse_data_7(a1, a2);
  if ( result )
  {
    v5 = result[10];
    v6 = result[11];
    v7 = result[6] | (result[7] << 8);
    v8 = result[8] | (result[9] << 8);
    v9 = *(uint32_t *)(result + 2);
    v10 = result[12];
    v11 = result[13];
    *(uint32_t *)a3 = v9;
    *(uint16_t *)(a3 + 4) = v7;
    *(uint16_t *)(a3 + 8) = v5 | (v6 << 8);
    *(uint16_t *)(a3 + 6) = v8;
    *(uint16_t *)(a3 + 10) = v10 | (v11 << 8);
    return (uint8_t *)1;
  }
  return result;
}

