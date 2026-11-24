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


extern uint32_t off_122D94;

// check_radio_status @ 0x122c94, size 256 bytes
int  check_radio_status(int a1, int a2, int a3)
{
  int v3; // r3
  int v4; // r0
  int v7; // r5
  int v8; // r6
  int a1a; // [sp+Ch] [bp-4h] BYREF

  v3 = HIBYTE(*(uint32_t *)off_122D94) & 2;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( (unsigned int)(a2 + 7) > 0xF )
      {
        dispatch_event_handler_1("wrong temp level:%d\n", a2);
        return -12;
      }
      else
      {
        v7 = 10 * a2;
        if ( v3 )
        {
          v8 = rf_reg10_low_check(a2);
          if ( v8 < 0 )
          {
            dispatch_event_handler_1(aNoRoom);
            return -11;
          }
          else
          {
            dispatch_event_handler_1("set efuse calib temp_level=%d (rem:%x), temp_range:%d~%d\n", a2, v8, v7 + 30, v7 + 39);
            return a2 | (v8 << 8);
          }
        }
        else
        {
          *(uint16_t *)((char *)&a1a + 1) = 0;
          HIBYTE(a1a) = 0;
          LOBYTE(a1a) = a2;
          mmio_write_64((int)&a1a);
          dispatch_event_handler_1("set flash calib temp_level=%d, temp_range:%d~%d\n", a2, v7 + 30, v7 + 39);
          return (char)a1a | 0xF00;
        }
      }
    }
    else
    {
      dispatch_event_handler_1(aWrongFunc_0, a2, a3, v3);
      return -21;
    }
  }
  else if ( v3 )
  {
    v4 = rf_reg10_status(&a1a);
    dispatch_event_handler_1(
      "read efuse calib temp_level:%d (rem:%x), temp_range:%d~%d\n",
      a1a,
      v4,
      10 * a1a + 30,
      10 * a1a + 39);
    return (char)a1a;
  }
  else
  {
    a1a = 0;
    if ( mmio_read_64((int)&a1a) )
    {
      dispatch_event_handler_1(aEmpty_0);
      return 3584;
    }
    else
    {
      dispatch_event_handler_1(
        "read flash calib temp_level:%d, temp_range:%d~%d\n",
        (char)a1a,
        10 * (char)a1a + 30,
        10 * (char)a1a + 39);
      return (char)a1a | 0xF00;
    }
  }
}
