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

// check_address_alignment @ 0x122f3c, size 86 bytes
int  check_address_alignment(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r5
  unsigned int v7; // r5

  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( !(a2 << 28) || (a2 & 0xFFFFFFF0) != 0 )
      {
        dispatch_event_handler_1("invalid cfg: %x\n", a2);
        return -11;
      }
      else
      {
        v5 = mmio_rmw_field((uint8_t)a2);
        dispatch_event_handler_1("set ef_sdio_cfg=%x, cur=%x\n", a2, v5);
      }
    }
    else
    {
      dispatch_event_handler_1(aWrongFunc_0, a2, a3);
      return -21;
    }
    return v5;
  }
  else
  {
    v7 = rf_get_reg1_bits13_16();
    dispatch_event_handler_1("get ef_sdio_cfg=%x\n", v7);
    return v7;
  }
}
