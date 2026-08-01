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

extern uint32_t dword_121F0C;

// buffer_flush @ 0x121ee8, size 32 bytes
// Doc: rf_cmd_dispatch_n_4b [rf]: Dispatches completed RF command response
// rf_cmd_dispatch_n_4b [rf]: Dispatches completed RF command response
int buffer_flush()
{
  uint32_t *v0; // r4
  int v1; // r6
  int v2; // r5

  v0 = (uint32_t *)rf_mem_write_n_123;
  v1 = dword_121F0C;
  v2 = rf_mem_write_n_123 + 880;
  do
  {
    if ( v0[1] )
      log_printf(v1, *v0);
    v0 += 4;
  }
  while ( v0 != (uint32_t *)v2 );
  return 0;
}

