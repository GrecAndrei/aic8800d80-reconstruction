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

extern uint32_t off_1260FC;
extern uint32_t dword_126100;

// pkt_buf_clear @ 0x126064, size 152 bytes
int  pkt_buf_clear(int a1, uint8_t **a2)
{
  uint16_t v3; // r6
  uint16_t v4; // r7
  uint16_t v5; // r8
  uint16_t v6; // r3
  uint8_t *v7; // r0
  uint16_t v8; // r4
  uint8_t v9; // r5
  int v10; // r3
  int v12; // [sp+Ch] [bp-Ch] BYREF
  uint16_t v13; // [sp+10h] [bp-8h]
  uint16_t v14; // [sp+12h] [bp-6h]
  uint8_t v15; // [sp+14h] [bp-4h]

  v3 = parse_number(a2[1], 0, 0x10u);
  v4 = parse_number(a2[2], 0, 0x10u);
  v5 = parse_number(a2[3], 0, 0x10u);
  v6 = parse_number(a2[4], 0, 0x10u);
  v7 = a2[5];
  v8 = v6;
  v9 = parse_number(v7, 0, 0x10u);
  sub_100200(&v12, 0, 0xAu);
  v15 = v9;
  v10 = *(uint32_t *)off_1260FC;
  LOWORD(v12) = v3;
  HIWORD(v12) = v4;
  v13 = v5;
  v14 = v8;
  if ( (v10 & 0x2000000) == 0 )
  {
    send_cmd_short((int)&v12);
    dispatch_event_handler(dword_126100, v3, v4, v5, v8, v9);
  }
  return 0;
}

