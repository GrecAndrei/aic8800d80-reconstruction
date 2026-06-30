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

extern uint32_t off_114E40;
extern uint32_t dword_114E48;
extern uint32_t off_114E44;
extern uint32_t off_114E4C;
extern uint32_t off_114E50;
extern uint32_t off_114E5C;
extern uint32_t off_114E54;
extern uint32_t off_114E58;

// sub_114E60 @ 0x114e60, size 12 bytes
int  sub_114E60(int a1, int a2)
{
  int v2; // r1
  int v3; // r4
  int v4; // r0
  int *v5; // r4
  int v6; // r5
  int *v7; // r2
  int *v8; // r3
  uint8_t *v9; // r2
  int v10; // r0
  uint32_t *v12; // r3

  if ( !*(uint8_t *)off_114E40 )
    return 3;
  v2 = dword_114E48;
  *(uint32_t *)off_114E44 = 0x20000;
  v3 = v2 + 120;
  while ( 1 )
  {
    v4 = *(uint8_t *)(v2 + 16);
    if ( !*(uint8_t *)(v2 + 16) )
      break;
    v2 += 20;
    if ( v2 == v3 )
      return -1;
  }
  v5 = (int *)off_114E4C;
  *(uint32_t *)v2 = v4;
  v6 = *v5;
  *(uint8_t *)(v2 + 4) = v4;
  *(uint32_t *)(v2 + 8) = a2;
  *(uint32_t *)(v2 + 12) = a1;
  *(uint8_t *)(v2 + 16) = 1;
  if ( v6 )
  {
    v7 = (int *)off_114E50;
    v8 = *(int **)off_114E50;
    if ( *(uint32_t *)off_114E50 )
    {
      do
      {
        v7 = v8;
        v8 = (int *)*v8;
      }
      while ( v8 );
    }
    *v7 = v2;
  }
  else
  {
    v12 = off_114E5C;
    *v5 = v2;
    *v12 = 0x10000;
  }
  if ( *(uint8_t *)off_114E54 != 1 )
  {
    v9 = off_114E58;
    v10 = *(uint8_t *)off_114E58;
    *(uint8_t *)off_114E54 = 1;
    if ( v10 != 1 )
      *v9 = 1;
  }
  return 0;
}

