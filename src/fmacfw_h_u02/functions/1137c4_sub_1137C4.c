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


extern uint32_t dword_113868;
extern uint32_t off_113860;
extern uint32_t off_113864;
extern uint32_t off_11386C;
extern uint32_t off_113870;
extern uint32_t off_113874;
extern uint32_t off_113878;
extern uint32_t off_11387C;
extern uint32_t off_113884;

// util_call_raw @ 0x1137c4, size 156 bytes
int  util_call_raw(uint32_t *a1)
{
  int *v2; // r4
  int v3; // r0
  uint8_t *v4; // r1
  int result; // r0
  uint16_t v6; // r3
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_113860 = 1;
  }
  v2 = (int *)off_113864;
  v3 = dword_113868;
  ++*(uint32_t *)off_113864;
  wlan_ioctl_handler_1(v3, a1);
  v4 = off_113870;
  result = *(uint8_t *)off_113870;
  v6 = *(uint16_t *)off_11386C + 1;
  *(uint16_t *)off_11386C = v6;
  if ( result && *(uint8_t *)off_113874 <= (unsigned int)v6 )
  {
    v9 = *(uint8_t *)off_113878;
    *v4 = 0;
    if ( v9 )
      *((uint32_t *)off_11387C + 512) &= ~0x2000u;
    else
      *((uint32_t *)off_11387C + 713) &= ~1u;
    wlan_wait_ready_alt(1);
    invalid_handler_12c5fc((char *)0x42D, 1);
    result = check_feature_flag(512, aWfr);
    if ( !*(uint8_t *)off_113884 )
      rf_get_flag(result, v10, v11, *(uint8_t *)off_113884);
  }
  if ( *v2 )
  {
    v7 = *v2 - 1;
    v8 = *(uint32_t *)off_113860;
    *v2 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}
