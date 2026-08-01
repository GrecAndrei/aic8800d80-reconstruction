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

// set_global_variable @ 0x11f4b4, size 6 bytes
// Doc: set_global_variable [rf]: Writes to RF bus with shifted index
// set_global_variable [rf]: Writes to RF bus with shifted index
int  set_global_variable(int result)
{
  *((uint32_t *)rf_mem_read_n_d8 + 1) = result;
  return result;
}

