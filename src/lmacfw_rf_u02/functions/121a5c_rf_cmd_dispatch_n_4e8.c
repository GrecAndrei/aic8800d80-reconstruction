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

// rf_cmd_dispatch_n_4e8 @ 0x121a5c, size 4 bytes
// Doc: rf_cmd_dispatch_n_4e8 [rf]: Dispatches RF command based on current state (checks state==3)
// rf_cmd_dispatch_n_4e8 [rf]: Dispatches RF command based on current state (checks state==3)
// attributes: thunk
int  rf_cmd_dispatch_n_4e8(uint16_t *a1)
{
  return sub_10D06C(a1);
}

