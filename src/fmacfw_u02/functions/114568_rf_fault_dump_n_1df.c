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

// get_global_167204 @ 0x114568, size 6 bytes
// Doc: get_global_167204 [rf]: Dump RF fault state from shared trace buffer
// get_global_167204 [rf]: Dump RF fault state from shared trace buffer
int  get_global_167204(int a1, int a2, int a3)
{
  return event_dispatch(rf_fault_dump_n_1d8, a2, a3);
}

