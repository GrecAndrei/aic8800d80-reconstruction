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

extern uint32_t dword_13B6D0;
extern uint32_t dword_13B6CC;
extern uint32_t dword_13B6C8;

// rx_measure_rssi @ 0x13b69c, size 42 bytes
int  rx_measure_rssi(int a1, int a2, unsigned int a3)
{
  int v4; // r0

  if ( hci_cmd_send_short(a3) == 1 )
  {
    if ( a3 < 0x1000 )
      v4 = dword_13B6D0;
    else
      v4 = dword_13B6CC;
    check_abort_flag(v4, (uint32_t *)(dword_13B6C8 + 32 * (a3 >> 8)));
  }
  return 0;
}

