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

// set_global_ptr @ 0x11f4a8, size 6 bytes
// Doc: set_global_ptr [rf]: Read RF memory and store to shared pointer
// set_global_ptr [rf]: Read RF memory and store to shared pointer
int  set_global_ptr(int result)
{
  *(uint32_t *)rf_mem_read_n_e4 = result;
  return result;
}

