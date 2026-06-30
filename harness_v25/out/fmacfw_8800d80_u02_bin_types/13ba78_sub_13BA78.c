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

extern uint32_t off_13BAC0;
extern uint32_t dword_13BAC4;

// sub_13BA78 @ 0x13ba78, size 72 bytes
// Doc: sub_123BA78 [util]: Utility helper using linked-list style structure traversal
// sub_123BA78 [util]: Utility helper using linked-list style structure traversal
int  sub_13BA78(int **a1)
{
  int *v1; // r6
  int result; // r0
  unsigned int v3; // r4
  int **v4; // r3
  int *v5; // r1
  unsigned int v6; // r2
  int v7; // r3

  v1 = *a1;
  if ( !*a1 )
    return 33;
  result = 0;
  v3 = 0;
  v4 = (int **)v1;
  do
  {
    v5 = v4[2];
    v6 = *((uint32_t *)off_13BAC0 + 4) - (uint32_t)v5;
    if ( v6 > v3 )
      result = *((uint8_t *)v4 + 26);
    v4 = (int **)*v4;
    if ( v6 > v3 )
      v3 = *((uint32_t *)off_13BAC0 + 4) - (uint32_t)v5;
  }
  while ( v4 );
  v7 = dword_13BAC4 + 32 * result;
  if ( v3 <= *(uint16_t *)(v7 + 14) << 10 || *(uint32_t *)(v7 + 4) )
    return *((uint8_t *)v1 + 26);
  else
    return (uint16_t)result;
}

