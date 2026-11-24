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


extern uint32_t dword_110338;
extern uint32_t off_110330;
extern uint32_t off_110334;
extern uint32_t off_11033C;

// mmio_write_2 @ 0x1102f0, size 62 bytes
int  mmio_write_2(uint32_t *a1)
{
  int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110330 = 1;
  }
  v2 = (int *)off_110334;
  v3 = dword_110338;
  ++*(uint32_t *)off_110334;
  result = wlan_ioctl_handler_1(v3, a1);
  v5 = *v2;
  ++*(uint32_t *)off_11033C;
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(uint32_t *)off_110330;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}
