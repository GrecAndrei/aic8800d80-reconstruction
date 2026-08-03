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
extern uint32_t dword_122724;
extern uint32_t dword_122718;
extern uint32_t dword_122720;
extern uint32_t dword_12271C;
extern uint32_t dword_122714;

// sub_122688 @ 0x122688, size 134 bytes
int  sub_122688(int result, int a2)
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
        msg_parse(dword_122724);
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
        rf_setup_param_n5ac((int)v4);
        msg_parse(dword_122718, a2);
        return a2;
      }
    }
    else
    {
      msg_parse(dword_122720);
      return -21;
    }
  }
  else if ( !v2 )
  {
    *(uint32_t *)v4 = 0;
    if ( sub_1145A0((int)v4) )
    {
      msg_parse(dword_12271C);
      return 0;
    }
    else
    {
      msg_parse(dword_122714, v4[0]);
      return v4[0];
    }
  }
  return result;
}

