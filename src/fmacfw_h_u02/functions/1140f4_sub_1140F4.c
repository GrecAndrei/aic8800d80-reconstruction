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

extern uint32_t off_11413C;
extern uint32_t off_114140;
extern uint32_t dword_114144;

// rf_power_down @ 0x1140f4, size 72 bytes
int rf_power_down()
{
  uint32_t *v0; // r5
  void *v1; // r7
  int result; // r0
  int v3; // r6
  int v4; // r4

  v0 = off_11413C;
  v1 = off_114140;
  clear_stats_buf(*(uint32_t *)off_11413C + 628);
  result = clear_stats_buf(*v0 + 636);
  if ( *(uint16_t *)(*(uint32_t *)v1 + 8) )
  {
    v3 = dword_114144;
    v4 = 0;
    do
    {
      tx_irq_handler(v3, 0x6B8u);
      result = wlan_ioctl_handler_1(*v0 + 628);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v1 + 8) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}

