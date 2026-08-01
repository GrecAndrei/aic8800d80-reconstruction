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

// rf_reg_write @ 0x111ba0, size 36 bytes
// Doc: rf_bus_write2_n12e [rf]: RF bus write variant dispatch on parameter
// rf_bus_write2_n12e [rf]: RF bus write variant dispatch on parameter
int * rf_reg_write(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rx_desc_hw_config(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return tx_desc_hw_config(a2, 0x8000000, 0);
  }
  return result;
}

