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

extern uint32_t off_115D24;

// sub_115D04 @ 0x115d04, size 32 bytes
int sub_115D04()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0

  *((uint8_t *)off_115D24 + 1) = 0;
  v0 = sub_12F710();
  v1 = sub_1323E4(v0);
  v2 = sub_120A58(v1);
  v3 = sub_12D438(v2);
  return sub_12F730(v3);
}

