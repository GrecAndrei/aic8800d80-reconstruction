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

// sub_12F954 @ 0x12f954, size 12 bytes
int sub_12F954()
{
  int v0; // r5
  int v1; // r6
  char v2; // r7

  *(uint32_t *)(v1 + 20) = v1;
  *(uint8_t *)(v0 + 9) = v2;
  return 45;
}

