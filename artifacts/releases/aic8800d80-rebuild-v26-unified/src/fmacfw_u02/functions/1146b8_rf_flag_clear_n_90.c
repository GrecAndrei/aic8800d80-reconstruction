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

// rf_flag_clear_n_90 @ 0x1146b8, size 10 bytes
// Doc: rf_flag_clear_n_90 [rf]: Clear a global RF status flag by zeroing word
// rf_flag_clear_n_90 [rf]: Clear a global RF status flag by zeroing word
void rf_flag_clear_n_90()
{
  **(uint32_t **)rf_fault_dump_n_84 = **(uint32_t **)rf_fault_dump_n_84;
}

