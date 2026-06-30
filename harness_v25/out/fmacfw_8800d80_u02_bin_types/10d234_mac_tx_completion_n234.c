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

extern uint32_t off_10D240;

// mac_tx_completion_n234 @ 0x10d234, size 10 bytes
// Doc: mac_tx_completion_n234 [tx]: Handle TX frame completion event
// mac_tx_completion_n234 [tx]: Handle TX frame completion event
void mac_tx_completion_n234()
{
  *(uint32_t *)off_10D240 = 0x4000000;
}

