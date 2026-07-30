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

extern uint32_t dword_12ACF8;
extern uint32_t off_12ACFC;

// sub_12ACC4 @ 0x12acc4, size 52 bytes
int * sub_12ACC4(int a1)
{
  int v1; // r4
  int v2; // r6
  char v3; // r5
  int v4; // r7
  int *result; // r0
  int v6; // r3
  void *v7; // r1

  v1 = dword_12ACF8;
  v2 = dword_12ACF8 + 32 * a1;
  v3 = a1;
  v4 = 32 * a1;
  if ( *(uint8_t *)(v2 + 30) )
    sub_124CF4(dword_12ACF8 + 32 * a1);
  result = sub_100200((int *)v2, 0, 0x20u);
  v6 = v1 + v4;
  v7 = off_12ACFC;
  *(uint32_t *)(v6 + 8) = v2;
  *(uint8_t *)(v6 + 28) = v3;
  *(uint32_t *)(v6 + 4) = v7;
  *(uint32_t *)(v6 + 24) = 3;
  return result;
}

