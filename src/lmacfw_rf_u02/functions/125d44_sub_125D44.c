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

extern uint32_t off_125D9C;
extern uint32_t dword_125DA0;

// parse_bt_name_field @ 0x125d44, size 88 bytes
int  parse_bt_name_field(int a1, int a2)
{
  uint16_t v3; // r3
  uint8_t *v4; // r0
  uint16_t v5; // r4
  uint16_t v6; // r5
  int v7; // r3
  int v9[2]; // [sp+4h] [bp-8h] BYREF

  v3 = parse_number(*(uint8_t **)(a2 + 4), 0, 0x10u);
  v4 = *(uint8_t **)(a2 + 8);
  v5 = v3;
  v6 = parse_number(v4, 0, 0x10u);
  sub_100200(v9, 0, 4u);
  LOWORD(v9[0]) = v5;
  v7 = *(uint32_t *)off_125D9C;
  HIWORD(v9[0]) = v6;
  if ( (v7 & 0x2000000) == 0 )
  {
    mmio_write_400000_4_alt((int)v9);
    dispatch_event_handler(dword_125DA0, v5, v6);
  }
  return 0;
}

