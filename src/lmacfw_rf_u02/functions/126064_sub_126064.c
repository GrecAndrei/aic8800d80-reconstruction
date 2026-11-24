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

// pkt_buf_clear @ 0x126064, size 152 bytes
int  pkt_buf_clear(int a1, uint32_t *a2)
{
  uint16_t v3; // r6
  uint16_t v4; // r7
  uint16_t v5; // r8
  uint16_t v6; // r3
  uint8_t *v7; // r0
  uint16_t v8; // r4
  uint8_t v9; // r5
  int v10; // r3
  int result; // [sp+Ch] [bp-Ch] BYREF
  uint16_t v13; // [sp+10h] [bp-8h]
  uint16_t v14; // [sp+12h] [bp-6h]
  uint8_t v15; // [sp+14h] [bp-4h]

  v3 = parse_number((uint8_t *)a2[1], nullptr, 0x10u);
  v4 = parse_number((uint8_t *)a2[2], nullptr, 0x10u);
  v5 = parse_number((uint8_t *)a2[3], nullptr, 0x10u);
  v6 = parse_number((uint8_t *)a2[4], nullptr, 0x10u);
  v7 = (uint8_t *)a2[5];
  v8 = v6;
  v9 = parse_number(v7, nullptr, 0x10u);
  memset_thunk(&result, 0, 0xAu);
  v15 = v9;
  v10 = *(uint32_t *)off_1260FC;
  LOWORD(result) = v3;
  HIWORD(result) = v4;
  v13 = v5;
  v14 = v8;
  if ( (v10 & 0x2000000) == 0 )
  {
    send_cmd_short((int)&result);
    dispatch_event_handler_1("set vid 0x%x, did 0x%x, subsys_vid 0x%x, subsys_id 0x%x, rev_id 0x%x\n", v3, v4, v5, v8, v9);
  }
  return 0;
}
