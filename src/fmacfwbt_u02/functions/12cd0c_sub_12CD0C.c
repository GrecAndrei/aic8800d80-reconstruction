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

extern uint32_t off_12CDD4;
extern uint32_t dword_12CDEC;
extern uint32_t dword_12CDE4;
extern uint32_t off_12CDD8;
extern uint32_t off_12CDDC;
extern uint32_t off_12CDE0;
extern uint32_t dword_12CDE8;

// sub_12CD0C @ 0x12cd0c, size 200 bytes
int  sub_12CD0C(int a1)
{
  int16_t **v1; // r7
  unsigned int v2; // r4
  unsigned int v3; // r6
  uint32_t *v4; // r3
  int *v5; // r5
  int v6; // r12
  uint32_t *v7; // r1
  unsigned int v8; // r2
  uint32_t *v9; // r2
  unsigned int v10; // r3
  int result; // r0
  int v12; // r2

  v1 = (int16_t **)off_12CDD4;
  v2 = (a1 + 3) & 0xFFFFFFFC;
  v3 = v2 + 4;
  if ( **(int16_t **)off_12CDD4 < 0 && v3 <= 7 )
    sub_12F694(dword_12CDEC, dword_12CDE4, 132);
  v4 = *((uint32_t **)off_12CDD8 + 7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12CDDC = 1;
  }
  v5 = (int *)off_12CDE0;
  v6 = *(uint32_t *)off_12CDE0 + 1;
  *(uint32_t *)off_12CDE0 = v6;
  if ( v4 )
  {
    v7 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v8 = v4[1];
        if ( v8 >= v2 + 12 )
          break;
LABEL_8:
        v4 = (uint32_t *)*v4;
        if ( !v4 )
          goto LABEL_12;
      }
      if ( v7 )
      {
        if ( v8 < v7[1] )
          v7 = v4;
        goto LABEL_8;
      }
      v7 = v4;
      v4 = (uint32_t *)*v4;
      if ( !v4 )
      {
LABEL_12:
        if ( **v1 < 0 && !v7 )
          goto LABEL_20;
        v9 = v7;
        goto LABEL_14;
      }
    }
  }
  if ( **v1 >= 0 )
    __und(0xFFu);
LABEL_20:
  sub_12F694(dword_12CDE8, dword_12CDE4, 160);
  v9 = 0;
  v6 = *v5;
  v7 = 0;
LABEL_14:
  v10 = v7[1] - v3;
  v7[1] = v10;
  result = (int)v9 + v10 + 4;
  *(uint32_t *)((char *)v9 + v10) = v3;
  if ( v6 )
  {
    v12 = *(uint32_t *)off_12CDDC;
    *v5 = v6 - 1;
    if ( v6 == 1 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}

