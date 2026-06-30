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

extern uint32_t off_130418;
extern uint32_t dword_13041C;
extern uint32_t dword_130420;
extern uint32_t dword_130424;
extern uint32_t off_130428;
extern uint32_t dword_13042C;

// sub_1303A0 @ 0x1303a0, size 118 bytes
int sub_1303A0()
{
  uint8_t *v0; // r4
  int v1; // r4
  int v2; // r0
  int v4; // [sp+14h] [bp-4h]

  v0 = (uint8_t *)off_130418;
  msg_parse(
    dword_13041C,
    *(char *)off_130418,
    *((char *)off_130418 + 1),
    *((char *)off_130418 + 2),
    *((char *)off_130418 + 3));
  msg_parse(dword_130420, v0[4], v0[5], v0[6]);
  msg_parse(dword_130424, (char)v0[8], (char)v0[9], (char)v0[10], (char)v0[11], (char)v0[12], (char)v0[13]);
  v1 = *((uint8_t *)off_130428 + 363);
  v4 = *((uint32_t *)off_130428 + 91);
  v2 = message_dispatch_c8b4(1070, 1);
  return msg_parse(dword_13042C, v1, v4, v2);
}

