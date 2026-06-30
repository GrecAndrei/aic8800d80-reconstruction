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

extern uint32_t off_117988;

// rf_table_lookup_handler @ 0x117954, size 50 bytes
// Doc: rf_table_lookup_handler [rf]: Look up handler from RF table and invoke callback
// rf_table_lookup_handler [rf]: Look up handler from RF table and invoke callback
int  rf_table_lookup_handler(int a1)
{
  void *v2; // r0

  scan_channel_done_n_180(a1, *(uint32_t *)(a1 + 28));
  v2 = off_117988;
  if ( !*(uint32_t *)off_117988 )
    return sub_1174EC(a1);
  *(uint8_t *)(a1 + 16) |= 1u;
  *(uint32_t *)(a1 + 4) = 0;
  return list_push_tail(v2);
}

