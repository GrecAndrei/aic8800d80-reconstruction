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

extern uint32_t off_12FEE8;
extern uint32_t dword_12FEEC;
extern uint32_t dword_12FEE4;
extern uint32_t dword_12FEFC;
extern uint32_t dword_12FEF8;
extern uint32_t dword_12FEF0;
extern uint32_t dword_12FEF4;

// sub_12FE54 @ 0x12fe54, size 144 bytes
// Doc: sub_122FE54 [util]: Allocate/initialize object with 10-byte memset call
// sub_122FE54 [util]: Allocate/initialize object with 10-byte memset call
int  sub_12FE54(int a1, int a2)
{
  int v4; // r0
  uint16_t v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = sub_12FB74(*(uint8_t **)(a2 + 4), 0, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = sub_12FB74(*(uint8_t **)(a2 + 8), 0, 0x10u);
      **(uint16_t **)off_12FEE8 = v6;
      sub_12ECB0(dword_12FEEC, v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        sub_12ECB0(dword_12FEE4);
        return 0;
      }
      v8 = sub_12FB74(*(uint8_t **)(a2 + 8), 0, 0x10u);
      sub_12ECB0(dword_12FEFC, v8);
      sub_12EC54(v8);
      return 0;
    }
    else
    {
      sub_12ECB0(dword_12FEF8, v4);
      return 0;
    }
  }
  else
  {
    sub_12ECB0(dword_12FEF0, **(uint16_t **)off_12FEE8);
    v7 = rf_cmd_process_n4e();
    sub_12ECB0(dword_12FEF4, v7);
    return 0;
  }
}

