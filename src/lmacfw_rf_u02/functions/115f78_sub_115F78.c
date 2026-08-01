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

extern uint32_t off_115FB4;
extern uint32_t off_115FB8;

// rf_wait_timeout @ 0x115f78, size 58 bytes
int  rf_wait_timeout(int a1)
{
  uint32_t *v1; // r6
  uint32_t *v2; // r7
  int v3; // r2
  uint32_t *v4; // r4
  int result; // r0
  int *v6; // r1
  int v7; // r3
  int v8; // t1

  v1 = off_115FB4;
  v2 = off_115FB8;
  v3 = a1 - 4;
  v4 = off_115FB4;
  result = a1 + 12;
  v6 = (int *)off_115FB8;
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
  v1[4] = 1000 * v2[4];
  return result;
}

