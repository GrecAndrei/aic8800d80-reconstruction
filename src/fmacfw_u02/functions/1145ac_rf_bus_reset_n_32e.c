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

extern uint32_t off_114624;
extern uint32_t off_11462C;
extern uint32_t off_114630;

// rf_bus_reset_n_32e @ 0x1145ac, size 110 bytes
// Doc: rf_fault_dump_n_17c [rf]: Dumps RF fault state from 0x182b64
// rf_fault_dump_n_17c [rf]: Dumps RF fault state from 0x182b64
int  rf_bus_reset_n_32e(int result)
{
  if ( !result )
  {
    if ( *(uint32_t *)rf_fault_dump_n_12c
      && (result = *((uint32_t *)rf_fault_dump_n_128 + 4),
          *(uint32_t *)(*(uint32_t *)rf_fault_dump_n_12c + 12) - result - *((uint16_t *)off_114624 + 92) - 2000 < 0) )
    {
      result = feature_guard_check(2, rf_fault_dump_n_114);
    }
    else
    {
      if ( !*(uint8_t *)rf_fault_dump_628
        || (result = *((uint32_t *)rf_fault_dump_n_128 + 4),
            *((uint32_t *)rf_fault_dump_628 + 1)
          + *((uint32_t *)rf_fault_dump_628 + 2)
          - result
          - *((uint16_t *)off_114624 + 92)
          - *(uint16_t *)(*(uint32_t *)off_11462C + 52) >= 0) )
      {
        *(uint32_t *)off_114630 = 0x40000000;
        return result;
      }
      result = feature_guard_check(2, rf_fault_dump_n_110);
    }
  }
  *(uint32_t *)off_114630 = 0x80000000;
  return result;
}

