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

extern uint32_t off_12FCCC;
extern uint32_t dword_12FCD0;
extern uint32_t dword_12FCC8;
extern uint32_t dword_12FCE0;
extern uint32_t dword_12FCDC;
extern uint32_t dword_12FCD4;
extern uint32_t dword_12FCD8;

// sub_12FC38 @ 0x12fc38, size 144 bytes
// Doc: sub_122FC38 [util]: Calls helper with args from struct, sets up state
// sub_122FC38 [util]: Calls helper with args from struct, sets up state
int  sub_12FC38(int a1, int a2)
{
  int v4; // r0
  uint16_t v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = sub_12F958(*(uint8_t **)(a2 + 4), 0, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = sub_12F958(*(uint8_t **)(a2 + 8), 0, 0x10u);
      **(uint16_t **)off_12FCCC = v6;
      msg_parse(dword_12FCD0, v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        msg_parse(dword_12FCC8);
        return 0;
      }
      v8 = sub_12F958(*(uint8_t **)(a2 + 8), 0, 0x10u);
      msg_parse(dword_12FCE0, v8);
      sub_12EA2C(v8);
      return 0;
    }
    else
    {
      msg_parse(dword_12FCDC, v4);
      return 0;
    }
  }
  else
  {
    msg_parse(dword_12FCD4, **(uint16_t **)off_12FCCC);
    v7 = fmacfw_version_get();
    msg_parse(dword_12FCD8, v7);
    return 0;
  }
}

