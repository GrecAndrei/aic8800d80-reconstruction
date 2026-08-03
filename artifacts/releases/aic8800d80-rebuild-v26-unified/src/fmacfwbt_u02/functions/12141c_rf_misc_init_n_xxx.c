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

extern uint32_t off_12142C;

// rf_misc_init_n_xxx @ 0x12141c, size 14 bytes
// Doc: rf_misc_init_n_xxx [rf]: Initialize RF misc control register at 0x40320038 with value 0x30
// rf_misc_init_n_xxx [rf]: Initialize RF misc control register at 0x40320038 with value 0x30
int rf_misc_init_n_xxx()
{
  *(uint32_t *)off_12142C = 48;
  return rf_bus_mark_n_3b7(0);
}

