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

extern uint32_t dword_1225F0;

// call_copy_packet_data @ 0x1225c4, size 44 bytes
int  call_copy_packet_data(int a1, int a2)
{
  float v3; // r0
  int v4; // r0

  if ( a1 <= 1 )
  {
    v3 = COERCE_FLOAT(gpio_port_init());
    v4 = dispatch_event_handler(dword_1225F0, (int)v3);
    rf_param_build(v4);
  }
  else
  {
    copy_packet_data(a1, a2);
  }
  return 0;
}

