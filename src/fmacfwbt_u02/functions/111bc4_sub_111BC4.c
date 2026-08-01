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

// rf_reg_write_b @ 0x111bc4, size 36 bytes
// Doc: rf_state_check_n_44c [rf]: Check RF state, conditional return based on flags
// rf_state_check_n_44c [rf]: Check RF state, conditional return based on flags
int * rf_reg_write_b(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rx_desc_hw_config(a2, 0x200000, 0);
  }
  else if ( a2 <= 5 )
  {
    return tx_desc_hw_config(a2, 0x200000, 0);
  }
  return result;
}

