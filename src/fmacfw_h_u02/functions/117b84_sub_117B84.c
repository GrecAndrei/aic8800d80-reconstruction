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

extern uint32_t off_117BC8;
extern uint32_t off_117BCC;

// sub_117B84 @ 0x117b84, size 66 bytes
int  sub_117B84(int a1)
{
  uint64_t *v1; // r6
  uint64_t *v2; // r7
  int v3; // r2
  uint32_t *v4; // r4
  int result; // r0
  int *v6; // r1
  int v7; // r3
  int v8; // t1
  uint64_t v9; // kr00_8
  uint64_t v10; // r2

  v1 = off_117BC8;
  v2 = off_117BCC;
  v3 = a1 - 4;
  v4 = off_117BC8;
  result = a1 + 12;
  v6 = (int *)off_117BCC;
  do
  {
    v8 = *(uint32_t *)(v3 + 4);
    v3 += 4;
    v7 = v8;
    if ( !v8 )
      v7 = *v6;
    *v4++ = 1000 * v7;
    ++v6;
  }
  while ( v3 != result );
  v9 = v2[2];
  LODWORD(v10) = 1000 * v9;
  HIDWORD(v10) = 1000 * HIDWORD(v9);
  v1[2] = v10;
  return result;
}

