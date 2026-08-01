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

// setup_packet_buffer @ 0x118324, size 26 bytes
// Doc: setup_packet_buffer [rf]: Initializes/resets an RF channel context structure
// setup_packet_buffer [rf]: Initializes/resets an RF channel context structure
int  setup_packet_buffer(int a1)
{
  int result; // r0

  result = ke_exit_critical(a1 + 48);
  if ( *(uint32_t *)(a1 + 72) )
    return bt_link_rx_check(a1);
  return result;
}

