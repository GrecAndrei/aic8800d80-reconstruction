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

extern uint32_t dword_10FB9C;
extern uint32_t dword_10FB8C;
extern uint32_t off_10FB74;
extern uint32_t off_10FB78;
extern uint32_t off_10FB7C;
extern uint32_t off_10FB80;
extern uint32_t dword_10FB84;
extern uint32_t dword_10FB90;
extern uint32_t dword_10FB94;
extern uint32_t dword_10FB88;
extern uint32_t dword_10FB98;

// sub_10F9E8 @ 0x10f9e8, size 396 bytes
uint32_t * sub_10F9E8(int a1, unsigned int a2)
{
  unsigned int v2; // r6
  uint32_t *v3; // r5
  uint16_t *v4; // r4
  unsigned int v5; // r3
  int *v6; // r6
  int v7; // r3
  int v8; // r2
  unsigned int *v9; // r7
  unsigned int v10; // r2
  int v11; // r1
  int v12; // r3
  int v13; // r2
  uint16_t v14; // r3
  int v15; // cc
  unsigned int v16; // r3
  int *v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r2

  v2 = *(uint8_t *)(a1 + 8);
  if ( !*(uint8_t *)(a1 + 8) )
  {
LABEL_57:
    sub_10DAE4(dword_10FB9C);
    return 0;
  }
  v3 = *(uint32_t **)(a1 + 12);
  if ( !v3 )
  {
    sub_10DAE4(dword_10FB8C);
    return v3;
  }
  v4 = *(uint16_t **)(a1 + 12);
  v5 = 1;
  while ( v4[2] < a2 )
  {
    if ( v2 <= v5 )
      goto LABEL_11;
    v4 = (uint16_t *)&v3[3 * v5];
LABEL_7:
    v5 = (uint8_t)(v5 + 1);
  }
  if ( *v4 )
    goto LABEL_12;
  if ( v2 > v5 )
  {
    v4 = (uint16_t *)&v3[3 * v5];
    goto LABEL_7;
  }
LABEL_11:
  if ( v2 == v5 )
    goto LABEL_57;
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10FB74 = 1;
  }
  v6 = (int *)off_10FB78;
  v7 = *v4;
  v3 = *(uint32_t **)off_10FB78;
  v8 = *(uint32_t *)off_10FB78 + 1;
  *(uint32_t *)off_10FB78 = v8;
  if ( !v7 )
  {
    if ( v8 )
    {
      v18 = (int *)off_10FB74;
      *v6 = (int)v3;
      v19 = *v18;
      if ( !v3 )
      {
        if ( v19 )
          goto LABEL_43;
      }
    }
    return 0;
  }
  v9 = (unsigned int *)off_10FB7C;
  v3 = *((uint32_t **)v4 + 2);
  v10 = *(uint32_t *)off_10FB7C;
  if ( *(uint32_t *)off_10FB7C <= (unsigned int)v3 && (unsigned int)v3 <= *((uint32_t *)off_10FB7C + 1) + v10
    || (unsigned int)v3 >= *(uint32_t *)off_10FB80
    && (unsigned int)v3 <= *(uint32_t *)off_10FB80 + *((uint32_t *)off_10FB80 + 1) )
  {
    *((uint32_t *)v4 + 2) = *v3;
    *v4 = v7 - 1;
    if ( v10 <= (unsigned int)v3 )
      goto LABEL_18;
  }
  else
  {
    sub_10DAE4(dword_10FB84, *((uint32_t *)v4 + 2));
    v10 = *v9;
    v14 = *v4 - 1;
    v15 = *v9 > (unsigned int)v3;
    *((uint32_t *)v4 + 2) = 0;
    *v4 = v14;
    if ( !v15 )
    {
LABEL_18:
      if ( v9[1] + v10 >= (unsigned int)v3 )
      {
        v11 = *((uint8_t *)v3 - 3);
        if ( v11 == 85 )
          goto LABEL_20;
        goto LABEL_45;
      }
    }
  }
  v16 = *(uint32_t *)off_10FB80;
  if ( *(uint32_t *)off_10FB80 > (unsigned int)v3 || *((uint32_t *)off_10FB80 + 1) + v16 < (unsigned int)v3 )
  {
    sub_10DAE4(dword_10FB90, v3);
    v11 = 0;
    goto LABEL_45;
  }
  v11 = *((uint8_t *)v3 - 3);
  if ( v11 != 85 )
  {
LABEL_45:
    if ( *v6 )
    {
      v20 = *v6 - 1;
      v21 = *(uint32_t *)off_10FB74;
      *v6 = v20;
      if ( !v20 )
      {
        if ( v21 )
          __enable_irq();
      }
    }
    sub_10DAE4(dword_10FB94, v11, v3);
    return 0;
  }
  if ( v10 > (unsigned int)v3 )
    goto LABEL_36;
  if ( (unsigned int)v3 <= v10 + v9[1] )
    goto LABEL_20;
  if ( (unsigned int)v3 < v16 )
  {
LABEL_37:
    sub_10DAE4(dword_10FB88, v3);
  }
  else
  {
LABEL_36:
    if ( (unsigned int)v3 > v16 + *((uint32_t *)off_10FB80 + 1) )
      goto LABEL_37;
LABEL_20:
    *((uint8_t *)v3 - 3) = -86;
  }
  if ( (unsigned int)v3 >= *v9 && (unsigned int)v3 <= *v9 + v9[1]
    || (unsigned int)v3 >= *(uint32_t *)off_10FB80
    && (unsigned int)v3 <= *(uint32_t *)off_10FB80 + *((uint32_t *)off_10FB80 + 1) )
  {
    *((uint8_t *)v3 - 2) = 1;
  }
  else
  {
    sub_10DAE4(dword_10FB98, v3);
  }
  if ( *v6 )
  {
    v12 = *v6 - 1;
    v13 = *(uint32_t *)off_10FB74;
    *v6 = v12;
    if ( !v12 )
    {
      if ( v13 )
LABEL_43:
        __enable_irq();
    }
  }
  return v3;
}

