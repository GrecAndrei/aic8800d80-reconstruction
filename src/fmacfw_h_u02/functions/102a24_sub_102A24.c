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

extern uint32_t off_102A54;
extern uint32_t off_102A58;

// rf_read_cal_values @ 0x102a24, size 48 bytes
int rf_read_cal_values()
{
  int result; // r0
  int *i; // r4

  result = sdio_irq_enable(*((uint8_t *)off_102A54 + 36), *((uint16_t *)off_102A54 + 20));
  for ( i = *((int **)off_102A58 + 2); i; i = (int *)*i )
  {
    while ( !*((uint8_t *)i + 108) )
    {
      i = (int *)*i;
      if ( !i )
        return result;
    }
    result = compute_byte_delta(i);
  }
  return result;
}

