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

extern uint32_t off_108D2C;
extern uint32_t off_108D30;

// sub_108CB8 @ 0x108cb8, size 114 bytes
uint32_t * sub_108CB8(uint32_t *result, unsigned int *a2)
{
  int v2; // r3
  int v3; // r3
  int v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r3

  LOWORD(v2) = 50;
  do
    v2 = (uint16_t)(v2 - 1);
  while ( v2 );
  *(uint32_t *)off_108D2C = 2;
  LOWORD(v3) = 50;
  do
    v3 = (uint16_t)(v3 - 1);
  while ( v3 );
  if ( (*(uint32_t *)off_108D30 & 1) == 0 )
  {
    while ( 1 )
    {
      LOWORD(v4) = 50;
      do
        v4 = (uint16_t)(v4 - 1);
      while ( v4 );
      if ( (*(uint32_t *)off_108D30 & 1) != 0 )
      {
        LOWORD(v5) = 50;
        do
          v5 = (uint16_t)(v5 - 1);
        while ( v5 );
        if ( (*(uint32_t *)off_108D30 & 1) != 0 )
          break;
      }
    }
  }
  v6 = *(uint32_t *)off_108D30;
  v7 = *(uint32_t *)off_108D30 >> 17;
  if ( *(int *)off_108D30 < 0 )
    v7 = ~((unsigned int)~(v7 << 17) >> 17);
  *result = v7;
  v8 = (uint16_t)v6 >> 1;
  if ( (v6 & 0x8000) != 0 )
    v8 = ~(~(v8 << 17) >> 17);
  *a2 = v8;
  return result;
}

