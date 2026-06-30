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

extern uint32_t off_124170;
extern uint32_t dword_124174;

// sub_124150 @ 0x124150, size 30 bytes
// Doc: sub_1224150 [util]: Packs a value into a global word using shifts and ORs
// sub_1224150 [util]: Packs a value into a global word using shifts and ORs
int  sub_124150(int a1)
{
  int v1; // r1
  int v2; // r0

  v1 = (HIWORD(*(uint32_t *)off_124170) << 16) | (a1 << 8) | a1;
  v2 = dword_124174;
  *(uint32_t *)off_124170 = v1;
  msg_parse(v2);
  return 0;
}

