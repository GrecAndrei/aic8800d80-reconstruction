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

extern uint32_t dword_138AA4;

// sub_138A74 @ 0x138a74, size 46 bytes
// Doc: sub_1238A74 [util]: Helper that calls sub-function with arg 4 and returns result
// sub_1238A74 [util]: Helper that calls sub-function with arg 4 and returns result
uint32_t ** sub_138A74(uint32_t *a1)
{
  int v1; // r5

  v1 = dword_138AA4;
  sub_1389D0(0, 4, a1[5]);
  sub_12D2E8(v1, a1);
  list_push_tail(v1 - 8, a1);
  return sub_12F554((uint32_t **)(v1 - 32));
}

