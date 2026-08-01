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

// set_global_flag_2 @ 0x1146dc, size 14 bytes
// Doc: set_global_flag_2 [rf]: RF bus reset byte readback
// set_global_flag_2 [rf]: RF bus reset byte readback
void set_global_flag_2()
{
  *(uint32_t *)(*(uint32_t *)rf_fault_dump_n_5b + 8) |= 2u;
}

