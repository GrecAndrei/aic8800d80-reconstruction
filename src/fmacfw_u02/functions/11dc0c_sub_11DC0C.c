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

extern uint32_t off_11DD24;
extern uint32_t off_11DD38;
extern uint32_t off_11DD3C;
extern uint32_t off_11DD40;
extern uint32_t off_11DD28;
extern uint32_t off_11DD2C;
extern uint32_t dword_11DD34;
extern uint32_t dword_11DD30;

// sub_11DC0C @ 0x11dc0c, size 278 bytes
int  sub_11DC0C(int *a1, int a2, uint16_t *a3)
{
  uint8_t *v3; // r7
  int v4; // r6
  int v5; // r5
  int *v6; // r9
  uint16_t *v7; // r10
  int *v8; // r11
  int16_t v9; // r8
  int v10; // r4
  int v11; // r3
  int v12; // r12
  int v13; // r0
  char v14; // r2
  char v15; // r3
  int *v16; // r3
  int v17; // r3
  int v18; // r3
  int16_t v19; // r0
  int16_t v20; // r3
  int v21; // r2
  int *v22; // r3
  int v23; // r3
  int v25; // [sp+0h] [bp-14h]
  int v26; // [sp+4h] [bp-10h]

  v3 = off_11DD24;
  v4 = *a1;
  v5 = (uint16_t)*a3;
  v6 = (int *)off_11DD38;
  v7 = off_11DD3C;
  v8 = (int *)off_11DD40;
  v9 = 0;
  *((uint8_t *)off_11DD24 + 2) = 0;
  v26 = 0;
  while ( 1 )
  {
    v19 = *(uint16_t *)(v4 + 8);
    v20 = *(uint32_t *)(v4 + 12) + 1;
    v21 = (uint16_t)(v20 - v19);
    if ( a2 + v5 >= v21 )
    {
      LOWORD(v10) = v19 - v20 + v5 + a2;
      a2 = (uint16_t)(v21 - v5);
      v10 = (uint16_t)v10;
      v5 = 0;
    }
    else
    {
      v10 = 0;
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11DD28 = 1;
    }
    v11 = (uint16_t)*v7;
    v12 = *v6;
    v25 = *v8;
    v13 = *v8 + 8 * v11;
    *(uint32_t *)(v13 + 4) = *(uint32_t *)(v4 + 8);
    *v6 = v12 + 1;
    *(uint32_t *)(v25 + 8 * v11) = a2;
    v14 = v3[3] + 1;
    v9 += a2;
    *v7 = v11 + 1;
    v3[3] = v14;
    if ( v10 )
    {
      if ( v12 == -1 )
        goto LABEL_10;
      v22 = (int *)off_11DD28;
      *v6 = v12;
      v23 = *v22;
      if ( v12 || !v23 )
        goto LABEL_10;
      goto LABEL_9;
    }
    v15 = *(uint8_t *)(v13 + 3);
    *(uint16_t *)v3 = v9;
    *(uint8_t *)(v13 + 3) = v15 | 4;
    v3[2] = 1;
    *((uint32_t *)v3 + 2) = v13;
    if ( v12 == -1 )
      break;
    v16 = (int *)off_11DD28;
    *v6 = v12;
    v17 = *v16;
    if ( v12 || !v17 )
      break;
LABEL_9:
    __enable_irq();
    if ( !v10 )
      break;
LABEL_10:
    v18 = *(uint32_t *)(v4 + 4);
    if ( **(int16_t **)off_11DD2C < 0 && !v18 )
    {
      sub_12F46C(dword_11DD34, dword_11DD30, 615);
      v18 = 0;
    }
    v26 = v4;
    a2 = v10;
    v4 = v18;
  }
  *a1 = v4;
  *a3 = v5;
  return v26;
}

