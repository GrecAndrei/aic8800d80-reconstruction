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

extern uint32_t off_12CD0C;
extern uint32_t dword_12CD34;
extern uint32_t dword_12CD28;
extern uint32_t dword_12CD10;
extern uint32_t dword_12CD3C;
extern uint32_t dword_12CD38;
extern uint32_t dword_12CD40;
extern uint32_t dword_12CD30;
extern uint32_t dword_12CD2C;
extern uint32_t dword_12CD14;
extern uint32_t dword_12CD44;
extern uint32_t dword_12CD18;
extern uint32_t off_12CD1C;
extern uint32_t off_12CD20;
extern uint32_t dword_12CD24;

// sub_12CBF4 @ 0x12cbf4, size 278 bytes
uint32_t * sub_12CBF4(unsigned int a1, int a2)
{
  int16_t **v2; // r7
  unsigned int v5; // r9
  int v6; // r6
  uint16_t *v7; // r9
  uint32_t *result; // r0
  int ( *v9)(uint32_t *, int); // r8
  int v10; // r7
  int *v11; // r6
  int *v12; // r5
  int v13; // r0
  int v14; // r3
  int v15; // r2
  int v16; // r6

  v2 = (int16_t **)off_12CD0C;
  v5 = a1 >> 8;
  v6 = (uint8_t)a1;
  if ( **(int16_t **)off_12CD0C >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 > 0xDu )
  {
    sub_12F32C(dword_12CD34, dword_12CD28, 173);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v7 = (uint16_t *)(*(uint32_t *)(dword_12CD10 + 16 * v6 + 8) + 2 * v5);
      goto LABEL_3;
    }
    if ( v6 != 14 )
      sub_12F32C(dword_12CD3C, dword_12CD38, 183);
  }
  else if ( (uint8_t)a1 != 13 )
  {
    goto LABEL_16;
  }
  sub_12F32C(dword_12CD40, dword_12CD28, 174);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_16:
  v16 = dword_12CD10 + 16 * v6;
  if ( *(uint16_t *)(v16 + 14) > v5 )
  {
    v7 = (uint16_t *)(*(uint32_t *)(v16 + 8) + 2 * v5);
    if ( v7 )
      goto LABEL_3;
    goto LABEL_18;
  }
  sub_12F32C(dword_12CD30, dword_12CD28, 175);
  v7 = (uint16_t *)(*(uint32_t *)(v16 + 8) + 2 * v5);
  if ( **v2 < 0 && !v7 )
LABEL_18:
    sub_12F32C(dword_12CD2C, dword_12CD28, 180);
LABEL_3:
  result = (uint32_t *)sub_12E948(dword_12CD14, a1, a2);
  if ( (uint16_t)*v7 != a2 )
  {
    v9 = (int ( *)(uint32_t *, int))dword_12CD44;
    v10 = dword_12CD18;
    v11 = (int *)off_12CD1C;
    *v7 = a2;
    while ( 1 )
    {
      result = sub_12C8FC(v10, v9, a1);
      if ( !result )
        break;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v11 = 1;
      }
      v12 = (int *)off_12CD20;
      v13 = dword_12CD24;
      ++*(uint32_t *)off_12CD20;
      sub_12D108(v13);
      v14 = *v12 - 1;
      if ( *v12 )
      {
        v15 = *v11;
        *v12 = v14;
        if ( !v14 )
        {
          if ( v15 )
            __enable_irq();
        }
      }
      sub_12CFC4(0x4000000);
    }
  }
  return result;
}

