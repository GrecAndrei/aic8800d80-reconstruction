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

// call_copy_packet_data @ 0x1225c4, size 44 bytes
int  call_copy_packet_data(int a1)
{
  int v1; // r1
  float v3; // r0

  if ( a1 <= 1 )
  {
    v3 = COERCE_FLOAT(gpio_port_init());
    dispatch_event_handler_1("Temp      : %d C\n", (int)v3);
    rf_param_build();
  }
  else
  {
    copy_packet_data(a1, v1);
  }
  return 0;
}
