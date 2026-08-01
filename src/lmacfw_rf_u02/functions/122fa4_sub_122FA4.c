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

extern uint32_t dword_123010;
extern uint32_t dword_12301C;
extern uint32_t dword_123018;
extern uint32_t dword_123014;
extern uint32_t dword_12300C;

// lookup_entry @ 0x122fa4, size 104 bytes
unsigned int  lookup_entry(int a1, int a2)
{
  unsigned int v4; // r0
  unsigned int v5; // r4

  v4 = rf_get_reg1_bit9();
  v5 = v4;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( v4 )
      {
        dispatch_event_handler(dword_123010);
      }
      else
      {
        dispatch_event_handler(dword_12301C, a2);
        mmio_write_reg2(__ROR4__(a2, 16));
        rf_set_reg1_bit9();
      }
      return __ROR4__(rf_get_reg2(), 16);
    }
    else
    {
      dispatch_event_handler(dword_123018);
      return 0;
    }
  }
  else
  {
    if ( v4 )
    {
      v5 = __ROR4__(rf_get_reg2(), 16);
      dispatch_event_handler(dword_123014, v5);
    }
    else
    {
      dispatch_event_handler(dword_12300C);
    }
    return v5;
  }
}

