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

extern uint32_t dword_12AD30;

// sub_12AD00 @ 0x12ad00, size 48 bytes
int *sub_12AD00()
{
  int *result; // r0
  uint8_t *v1; // r3
  int v2; // r1

  sub_12ACC4(0);
  sub_12ACC4(1);
  sub_12ACC4(2);
  result = sub_12ACC4(3);
  v1 = (uint8_t *)dword_12AD30;
  v2 = dword_12AD30 + 96;
  do
  {
    v1[1] = 0;
    v1[2] = 0;
    *v1 = 0;
    v1 += 3;
  }
  while ( v1 != (uint8_t *)v2 );
  return result;
}

