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

extern uint32_t off_13025C;

// rf_power_adjust @ 0x130234, size 38 bytes
int rf_power_adjust()
{
  if ( *((uint8_t *)off_13025C + 1) )
    return *((char *)off_13025C + 3);
  hw_block_reset();
  return (int)COERCE_FLOAT(hw_poll_status());
}

