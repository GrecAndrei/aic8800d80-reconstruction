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

extern uint32_t off_141ED4;
extern uint32_t dword_141ED8;
extern uint32_t off_141EE0;
extern uint32_t dword_141EDC;

// sub_141E6C @ 0x141e6c, size 102 bytes
int  sub_141E6C(int a1)
{
  int v1; // r2
  int v3; // r3
  uint64_t v4; // r0
  int v5; // r5
  uint8_t *v6; // r2
  int v7; // r3
  int16_t v8; // r1
  int result; // r0
  int v10; // r1

  v1 = *(uint32_t *)(a1 + 12);
  v3 = *((uint32_t *)off_141ED4 + 4) + 100;
  v4 = *(uint64_t *)(a1 + 24) + *(unsigned int *)(a1 + 16);
  *(uint32_t *)(a1 + 56) = dword_141ED8;
  *(uint64_t *)(a1 + 24) = v4;
  v5 = *(uint8_t *)(a1 + 47);
  sub_124F60(a1 + 52, v3 + v1);
  v6 = off_141EE0;
  v7 = dword_141EDC + 1320 * v5;
  v8 = *(uint16_t *)a1 | 8;
  result = *(uint32_t *)(v7 + 4) | 0x100;
  *(uint32_t *)(v7 + 4) = result;
  *(uint16_t *)a1 = v8;
  v10 = *(uint8_t *)(a1 + 4);
  ++v6[1];
  if ( !v10 )
  {
    result = *(uint8_t *)(a1 + 47);
    v6[2] |= 1 << result;
  }
  return result;
}

