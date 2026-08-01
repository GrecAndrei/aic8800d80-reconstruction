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

extern uint32_t off_12FEB8;
extern uint32_t off_12FEBC;
extern uint32_t dword_12FEC0;
extern uint32_t dword_12FEC4;
extern uint32_t dword_12FEC8;
extern uint32_t dword_12FECC;
extern uint32_t dword_12FED0;
extern uint32_t dword_12FED4;

// debug_assert @ 0x12fe58, size 94 bytes
int debug_assert()
{
  int *v0; // r4
  uint32_t *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  system_ready_check();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12FEB8 = 1;
  }
  v0 = (int *)off_12FEBC;
  v1 = (uint32_t *)dword_12FEC0;
  ++*(uint32_t *)off_12FEBC;
  clear_stats_buf(v1);
  clear_stats_buf((uint32_t *)dword_12FEC4);
  wlan_ioctl_handler_1(dword_12FEC0, (uint32_t *)dword_12FEC8);
  wlan_ioctl_handler_1(dword_12FEC0, (uint32_t *)dword_12FECC);
  wlan_ioctl_handler_1(dword_12FEC0, (uint32_t *)dword_12FED0);
  result = wlan_ioctl_handler_1(dword_12FEC0, (uint32_t *)dword_12FED4);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_12FEB8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

