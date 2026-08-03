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

// rf_mem_read_f4c0 @ 0x11f4c0, size 6 bytes
// Doc: rf_mem_read_n_d2 [rf]: Reads value from RF memory region
// rf_mem_read_n_d2 [rf]: Reads value from RF memory region
int rf_mem_read_f4c0()
{
  return *(uint32_t *)rf_mem_write_short;
}

