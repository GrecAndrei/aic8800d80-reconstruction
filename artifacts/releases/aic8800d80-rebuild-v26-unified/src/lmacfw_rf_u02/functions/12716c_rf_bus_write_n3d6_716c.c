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

extern uint32_t off_127190;

// rf_bus_write_n3d6_716c @ 0x12716c, size 36 bytes
// Doc: rf_level_apply_n3a6 [rf]: Apply RF TX power level adjustment
// rf_level_apply_n3a6 [rf]: Apply RF TX power level adjustment
int rf_bus_write_n3d6_716c()
{
  int result; // r0

  *((uint8_t *)off_127190 + 1) = 0;
  result = sub_11DDCC(1070, 1);
  if ( result )
    return event_queue_push(1070, 1);
  return result;
}

