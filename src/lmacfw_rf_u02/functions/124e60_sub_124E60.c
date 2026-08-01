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

extern uint32_t dword_124F1C;
extern uint32_t off_124F08;
extern uint32_t off_124F0C;
extern uint32_t off_124F10;
extern uint32_t off_124F14;
extern uint32_t dword_124F18;

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
  int v12; // r3
  int *v13; // r1
  int *v14; // r2
  int v16; // [sp+0h] [bp-14h] BYREF
  int v17; // [sp+4h] [bp-10h] BYREF
  int v18; // [sp+8h] [bp-Ch] BYREF
  uint32_t v19[2]; // [sp+Ch] [bp-8h] BYREF

  if ( a1 <= 2 )
  {
    dispatch_event_handler(dword_124F1C);
    return -1;
  }
  else
  {
    v3 = (int *)off_124F08;
    v4 = parse_number(*(uint8_t **)(a2 + 4), 0, 0xAu);
    v5 = *(uint8_t **)(a2 + 8);
    v6 = v4;
    v7 = parse_number(v5, 0, 0xAu);
    v8 = *(uint32_t *)off_124F0C;
    v9 = *v3;
    v10 = *(uint32_t *)off_124F10;
    v11 = *(uint32_t *)off_124F14;
    LOWORD(v16) = *(uint32_t *)off_124F0C;
    BYTE2(v16) = BYTE2(v8);
    LOWORD(v17) = v9;
    BYTE2(v17) = BYTE2(v9);
    LOWORD(v18) = v10;
    BYTE2(v18) = BYTE2(v10);
    LOWORD(v19[0]) = v11;
    BYTE2(v19[0]) = BYTE2(v11);
    if ( v6 )
    {
      if ( v7 )
      {
        gpio_set_pin(0);
        v13 = &v18;
      }
      else
      {
        gpio_set_pin(1);
        v13 = v19;
      }
      v14 = &v16;
    }
    else
    {
      if ( v7 )
      {
        gpio_clear_pin(0);
        v13 = &v18;
      }
      else
      {
        gpio_clear_pin(1);
        v13 = v19;
      }
      v14 = &v17;
    }
    dispatch_event_handler(dword_124F18, v13, v14, v12, v16, v17, v18, v19[0]);
    return 0;
  }
}

