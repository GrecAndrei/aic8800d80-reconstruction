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

extern uint32_t dword_116088;

// sub_116050 @ 0x116050, size 56 bytes
int  sub_116050(int a1)
{
  int v1; // r1
  int v2; // r3
  int result; // r0

  v1 = dword_116088;
  v2 = dword_116088 + 36 * a1;
  *(uint32_t *)v2 = 0;
  result = v1 + 8 * (a1 + 22);
  *(uint32_t *)(v2 + 8) = 4978;
  *(uint32_t *)(v2 + 12) = -1;
  *(uint32_t *)(result + 4) = 0;
  *(uint32_t *)(result + 8) = 0;
  *(uint32_t *)(v2 + 4) = 0;
  *(uint8_t *)(v2 + 32) = 0;
  *(uint32_t *)(v2 + 20) = 0;
  *(uint32_t *)(v2 + 16) = -1;
  return result;
}

