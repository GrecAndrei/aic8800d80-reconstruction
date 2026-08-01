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

extern uint32_t dword_1101DC;

// get_link_channel @ 0x11018c, size 72 bytes
// Doc: log_free_dispatch_n19c [util]: Allocate log dispatch context and free log resources
// log_free_dispatch_n19c [util]: Allocate log dispatch context and free log resources
int get_link_channel()
{
  void *v0; // r8
  int result; // r0
  uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = log_free_pool_dispatch2_n500_01e0;
  result = zero_8_bytes(log_free_pool_dispatch2_n4f4);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 6) )
  {
    v2 = log_free_dispatch_n1d0;
    v3 = dword_1101DC;
    v4 = log_free_pool_dispatch2_n4f4;
    v5 = 0;
    do
    {
      rx_packet_handler(v3, 0x63Cu);
      result = cmd_handler_a(v4);
      v6 = *(uint16_t *)(*(uint32_t *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v6 > (uint16_t)v5 );
  }
  return result;
}

