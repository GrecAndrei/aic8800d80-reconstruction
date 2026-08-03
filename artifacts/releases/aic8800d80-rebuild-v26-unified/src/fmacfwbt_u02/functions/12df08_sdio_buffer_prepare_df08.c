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

extern uint32_t dword_12DF2C;

// sdio_buffer_prepare_df08 @ 0x12df08, size 36 bytes
// Doc: rf_bus_reset2_n_3b2_df0a [rf]: Reset RF bus and reinitialize channel registers
// rf_bus_reset2_n_3b2_df0a [rf]: Reset RF bus and reinitialize channel registers
uint8_t * sdio_buffer_prepare_df08(uint8_t *a1, int a2)
{
  uint8_t *result; // r0
  uint16_t v3[3]; // [sp+Eh] [bp-6h] BYREF

  result = sub_12D9B0(a1, a2, (uint8_t *)dword_12DF2C, 5, v3);
  if ( result )
  {
    if ( v3[0] != 26 )
      return 0;
  }
  return result;
}

