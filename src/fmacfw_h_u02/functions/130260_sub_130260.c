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

extern uint32_t off_1302D8;
extern uint32_t dword_1302DC;
extern uint32_t dword_1302E0;
extern uint32_t dword_1302E4;
extern uint32_t off_1302E8;
extern uint32_t dword_1302EC;

// sub_130260 @ 0x130260, size 118 bytes
int sub_130260()
{
  uint8_t *v0; // r4
  int v1; // r4
  int v2; // r0
  int v4; // [sp+14h] [bp-4h]

  v0 = (uint8_t *)off_1302D8;
  sub_12E948(
    dword_1302DC,
    *(char *)off_1302D8,
    *((char *)off_1302D8 + 1),
    *((char *)off_1302D8 + 2),
    *((char *)off_1302D8 + 3));
  sub_12E948(dword_1302E0, v0[4], v0[5], v0[6]);
  sub_12E948(dword_1302E4, (char)v0[8], (char)v0[9], (char)v0[10], (char)v0[11], (char)v0[12], (char)v0[13]);
  v1 = *((uint8_t *)off_1302E8 + 363);
  v4 = *((uint32_t *)off_1302E8 + 91);
  v2 = sub_12C774(1070, 1);
  return sub_12E948(dword_1302EC, v1, v4, v2);
}

