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

extern uint32_t off_124ABC;
extern uint32_t off_124AC0;
extern uint32_t off_124AC4;
extern uint32_t off_124AC8;
extern uint32_t off_124ACC;
extern uint32_t dword_124AD0;

// sub_1249FC @ 0x1249fc, size 192 bytes
int  sub_1249FC(uint8_t *a1)
{
  int v1; // r1
  int v3; // r3
  unsigned int *v4; // r0
  int v5; // r1
  unsigned int *v6; // r0
  unsigned int v7; // r1
  unsigned int *v8; // r0
  int v9; // r2

  v1 = *a1;
  v3 = (uint8_t)*(uint32_t *)off_124ABC;
  if ( *a1 )
  {
    v4 = (unsigned int *)off_124AC0;
    *(uint32_t *)off_124AC0 = *(uint32_t *)off_124AC0 & 0xFFFFFF00 | v1;
    *v4 = *v4 & 0xFF0000FF | ((v3 * v1) << 8);
  }
  v5 = a1[1];
  if ( a1[1] )
  {
    v6 = (unsigned int *)off_124AC4;
    *(uint32_t *)off_124AC4 = *(uint32_t *)off_124AC4 & 0xFFFFFF00 | v5;
    *v6 = *v6 & 0xFF0000FF | ((v3 * v5) << 8);
  }
  v7 = a1[2];
  if ( a1[2] )
  {
    v8 = (unsigned int *)off_124AC8;
    *(uint32_t *)off_124AC8 = *(uint32_t *)off_124AC8 & 0xFFFFFF00 | v7;
    *v8 = *v8 & 0xFF0000FF | ((v3 * v7) << 8);
  }
  if ( a1[3] )
  {
    v7 = (unsigned int)off_124ACC;
    *(uint32_t *)off_124ACC = *(uint32_t *)off_124ACC & 0xFFFFFF00 | a1[3];
  }
  if ( a1[4] )
  {
    v7 = (unsigned int)off_124ACC;
    *(uint32_t *)off_124ACC = *(uint32_t *)off_124ACC & 0xFFFF00FF | (a1[4] << 8);
  }
  v9 = a1[5];
  if ( a1[5] )
  {
    v7 = (unsigned int)off_124ACC;
    *(uint32_t *)off_124ACC = *(uint32_t *)off_124ACC & 0xFF00FFFF | (v9 << 16);
  }
  sub_12E948(dword_124AD0, v7, v9);
  return sub_12E9D8(a1, 6, 1, 0);
}

