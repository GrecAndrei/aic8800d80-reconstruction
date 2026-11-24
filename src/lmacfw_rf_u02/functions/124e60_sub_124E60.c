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


extern uint32_t off_124F08;
extern uint32_t off_124F0C;
extern uint32_t off_124F10;
extern uint32_t off_124F14;

// set_scan_params @ 0x124e60, size 166 bytes
int  set_scan_params(int a1, int a2)
{
  int *v3; // r5
  int v4; // r3
  uint8_t *v5; // r0
  int v6; // r4
  int v7; // r0
  int v8; // r3
  int v9; // r5
  int v10; // r1
  int v11; // r2
  const char *v12; // r1
  const char *v13; // r2
  uint16_t v15; // [sp+0h] [bp-14h] BYREF
  char v16; // [sp+2h] [bp-12h]
  uint16_t v17; // [sp+4h] [bp-10h] BYREF
  char v18; // [sp+6h] [bp-Eh]
  uint16_t v19; // [sp+8h] [bp-Ch] BYREF
  char v20; // [sp+Ah] [bp-Ah]
  uint16_t v21; // [sp+Ch] [bp-8h] BYREF
  char v22; // [sp+Eh] [bp-6h]

  if ( a1 <= 2 )
  {
    dispatch_event_handler_1(asc_130254, a2);
    return -1;
  }
  else
  {
    v3 = off_124F08[0];
    v4 = parse_number(*(uint8_t **)(a2 + 4), nullptr, 0xAu);
    v5 = *(uint8_t **)(a2 + 8);
    v6 = v4;
    v7 = parse_number(v5, nullptr, 0xAu);
    v8 = *off_124F0C;
    v9 = *v3;
    v10 = *(uint32_t *)off_124F10;
    v11 = *(uint32_t *)off_124F14;
    v15 = *off_124F0C;
    v16 = BYTE2(v8);
    v17 = v9;
    v18 = BYTE2(v9);
    v19 = v10;
    v20 = BYTE2(v10);
    v21 = v11;
    v22 = BYTE2(v11);
    if ( v6 )
    {
      if ( v7 )
      {
        gpio_set_pin(0);
        v12 = (const char *)&v19;
      }
      else
      {
        gpio_set_pin(1);
        v12 = (const char *)&v21;
      }
      v13 = (const char *)&v15;
    }
    else
    {
      if ( v7 )
      {
        gpio_clear_pin(0);
        v12 = (const char *)&v19;
      }
      else
      {
        gpio_clear_pin(1);
        v12 = (const char *)&v21;
      }
      v13 = (const char *)&v17;
    }
    dispatch_event_handler_1("%s table in %s mode\n", v12, v13);
    return 0;
  }
}
