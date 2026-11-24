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

// call_tx_function @ 0x10c1b4, size 56 bytes
int  call_tx_function(int a1, int a2, int a3, int a4)
{
  int v7; // r0

  rf_calibrate(a1, a2, a2, 0, 0, 0);
  parse_packet_control((unsigned int *)a3, a4, 1, 0);
  if ( a1 == 1 )
    v7 = 132;
  else
    v7 = 129;
  return periph_wait_status(v7, (uint16_t *)a4);
}
