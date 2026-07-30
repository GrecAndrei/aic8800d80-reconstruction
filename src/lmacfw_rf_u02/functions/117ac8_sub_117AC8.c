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

// sub_117AC8 @ 0x117ac8, size 48 bytes
// Doc: sub_1217AC8 [unknown]: Unknown internal function (lmacfw)
// sub_1217AC8 [unknown]: Unknown internal function (lmacfw)
int * sub_117AC8(int a1)
{
  int v2; // r5
  int v3; // r0
  int *result; // r0

  v2 = a1 + 48;
  while ( *(uint32_t *)(a1 + 48) )
  {
    v3 = sub_11E7AC(v2);
    sub_116628(v3, 1);
  }
  result = sub_100200((int *)a1, 0, 0x98u);
  *(uint8_t *)(a1 + 32) = -1;
  return result;
}

