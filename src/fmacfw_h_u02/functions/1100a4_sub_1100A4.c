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

extern uint32_t off_1100D8;
extern uint32_t dword_1100DC;
extern uint32_t dword_1100E0;

// get_current_channel @ 0x1100a4, size 52 bytes
int get_current_channel()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_1100D8;
  result = clear_stats_buf(dword_1100DC);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 2) )
  {
    v2 = dword_1100E0;
    v3 = dword_1100DC;
    v4 = 0;
    do
    {
      tx_irq_handler(v2, 0xCu);
      result = wlan_ioctl_handler_1(v3);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v0 + 2) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}

