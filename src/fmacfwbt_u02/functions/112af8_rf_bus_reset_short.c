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

// get_global_state @ 0x112af8, size 6 bytes
// Doc: rf_msg_handler_n_466 [rf]: Handle incoming RF control message and dispatch
// rf_msg_handler_n_466 [rf]: Handle incoming RF control message and dispatch
int get_global_state()
{
  return *(uint8_t *)rf_bus_reset_n2bc;
}

