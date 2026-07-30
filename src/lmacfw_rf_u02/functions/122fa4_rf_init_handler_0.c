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

// rf_init_handler_0 @ 0x122fa4, size 104 bytes
// Doc: rf_init_handler [rf]: RF initialization handler calling chip setup routine
// rf_init_handler [rf]: RF initialization handler calling chip setup routine
unsigned int  rf_init_handler_0(int a1, int a2)
{
  unsigned int v4; // r0
  unsigned int v5; // r4

  v4 = sub_113B30();
  v5 = v4;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( v4 )
      {
        msg_parse(dword_123010);
      }
      else
      {
        msg_parse(dword_12301C, a2);
        rf_fault_dump_n_b2(__ROR4__(a2, 16));
        rf_cmd_status_get_n1c0();
      }
      return __ROR4__(rf_helper_sub_n_3b78(), 16);
    }
    else
    {
      msg_parse(dword_123018);
      return 0;
    }
  }
  else
  {
    if ( v4 )
    {
      v5 = __ROR4__(rf_helper_sub_n_3b78(), 16);
      msg_parse(dword_123014, v5);
    }
    else
    {
      msg_parse(dword_12300C);
    }
    return v5;
  }
}

