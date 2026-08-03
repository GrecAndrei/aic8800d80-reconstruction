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

// rf_bus_reset_n2b4 @ 0x1125a4, size 6 bytes
// Doc: rf_bus_reset_n2b4 [rf]: RF bus reset/read register byte stub
// rf_bus_reset_n2b4 [rf]: RF bus reset/read register byte stub
int rf_bus_reset_n2b4()
{
  return *(uint8_t *)rf_cmd_send_n_36c;
}

