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


extern uint32_t off_122710;

// check_system_flag @ 0x122688, size 134 bytes
int  check_system_flag(int result, int a2)
{
  int v2; // r4
  uint8_t v4[8]; // [sp+4h] [bp-8h] BYREF

  v2 = HIBYTE(*(uint32_t *)off_122710) & 2;
  if ( result )
  {
    if ( result == 1 )
    {
      if ( (unsigned int)(a2 - 1) > 6 )
      {
        dispatch_event_handler_1("wrong ibit:%x\r\n", a2);
        return -12;
      }
      else if ( v2 )
      {
        return 0;
      }
      else
      {
        v4[0] = a2;
        *(uint16_t *)&v4[1] = 0;
        v4[3] = 0;
        mmio_write_8((int)v4);
        dispatch_event_handler_1("set flash txgain 2.4g pa_drv_ibit=%x\n", a2);
        return a2;
      }
    }
    else
    {
      dispatch_event_handler_1(aWrongFunc, a2);
      return -21;
    }
  }
  else if ( !v2 )
  {
    *(uint32_t *)v4 = 0;
    if ( mmio_read_8((int)v4) )
    {
      dispatch_event_handler_1(aUnset);
      return 0;
    }
    else
    {
      dispatch_event_handler_1("flash txgain 2.4g pa_drv_ibit=%x\n", v4[0]);
      return v4[0];
    }
  }
  return result;
}
