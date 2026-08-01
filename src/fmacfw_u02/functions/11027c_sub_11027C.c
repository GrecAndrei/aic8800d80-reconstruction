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

extern uint32_t dword_1102B8;

// get_link_tx_power @ 0x11027c, size 52 bytes
// Doc: log_free_dispatch_n286 [util]: Free log entry then dispatch to logging sink
// log_free_dispatch_n286 [util]: Free log entry then dispatch to logging sink
int get_link_tx_power()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = log_free_dispatch_n2a8;
  result = zero_8_bytes(log_free_dispatch_n2ac_02b4);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 4) )
  {
    v2 = dword_1102B8;
    v3 = log_free_dispatch_n2ac_02b4;
    v4 = 0;
    do
    {
      rx_packet_handler(v2, 0x7Cu);
      result = cmd_handler_a(v3);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v0 + 4) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}

