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

// rf_cmd_send_n_374 @ 0x112c9c, size 6 bytes
// Doc: rf_cmd_send_n_374 [rf]: Sends an RF command by reading descriptor pointer
// rf_cmd_send_n_374 [rf]: Sends an RF command by reading descriptor pointer
int rf_cmd_send_n_374()
{
  return *(uint8_t *)rf_bus_mark_n476;
}

