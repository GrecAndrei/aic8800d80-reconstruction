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

extern uint32_t off_11E05C;
extern uint32_t dword_11E074;
extern uint32_t dword_11E06C;
extern uint32_t off_11E060;
extern uint32_t off_11E064;
extern uint32_t off_11E068;
extern uint32_t dword_11E070;

// sub_11DF94 @ 0x11df94, size 200 bytes
// Doc: sub_121DF94 [util]: Allocates and aligns buffer from heap pool
// sub_121DF94 [util]: Allocates and aligns buffer from heap pool
int  sub_11DF94(int a1)
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

  v1 = (int16_t **)off_11E05C;
  v2 = (a1 + 3) & 0xFFFFFFFC;
  v3 = v2 + 4;
  if ( **(int16_t **)off_11E05C < 0 && v3 <= 7 )
    rf_cmd_send_n264(dword_11E074, dword_11E06C, 132);
  v4 = *((uint32_t **)off_11E060 + 7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11E064 = 1;
  }
  v5 = (int *)off_11E068;
  v6 = *(uint32_t *)off_11E068 + 1;
  *(uint32_t *)off_11E068 = v6;
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
  rf_cmd_send_n264(dword_11E070, dword_11E06C, 160);
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
    v12 = *(uint32_t *)off_11E064;
    *v5 = v6 - 1;
    if ( v6 == 1 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}

