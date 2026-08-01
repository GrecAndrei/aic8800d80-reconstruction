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

// rf_reg_write_c @ 0x111be8, size 40 bytes
// Doc: rf_bus_setup_n_15a [rf]: Configure RF bus interface
// rf_bus_setup_n_15a [rf]: Configure RF bus interface
int * rf_reg_write_c(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rx_desc_hw_config(a2, 0x8000000, 0x200000);
  }
  else if ( a2 <= 5 )
  {
    return tx_desc_hw_config(a2, 0x8000000, 0x200000);
  }
  return result;
}

