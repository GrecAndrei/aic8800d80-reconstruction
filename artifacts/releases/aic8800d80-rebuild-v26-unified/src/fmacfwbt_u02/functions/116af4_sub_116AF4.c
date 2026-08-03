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

extern uint32_t off_116D80;
extern uint32_t off_116DB8;
extern uint32_t off_116D88;
extern uint32_t off_116DA8;
extern uint32_t dword_116DD4;
extern uint32_t dword_116DC0;
extern uint32_t off_116DAC;
extern uint32_t dword_116DD0;
extern uint32_t off_116DB0;
extern uint32_t dword_116DCC;
extern uint32_t off_116DB4;
extern uint32_t dword_116DC8;
extern uint32_t off_116DBC;
extern uint32_t dword_116DC4;
extern uint32_t off_116D84;
extern uint32_t dword_116DD8;
extern uint32_t dword_116DDC;
extern uint32_t off_116D98;
extern uint32_t dword_116D94;
extern uint32_t off_116D90;
extern uint32_t dword_116D8C;
extern uint32_t off_116D9C;
extern uint32_t off_116DA0;
extern uint32_t off_116DA4;

// sub_116AF4 @ 0x116af4, size 652 bytes
int  sub_116AF4(int a1, int a2, int a3, int a4)
{
  uint32_t *v5; // r3
  int *v6; // r0
  int *v7; // r3
  int v8; // r2
  int v9; // r4
  int *v10; // r3
  int *v11; // r1
  int result; // r0
  int v13; // r2
  int v14; // r4
  uint32_t *v15; // r2
  uint32_t *v16; // r3
  uint32_t *v17; // r3
  uint32_t *v18; // r3
  uint32_t *v19; // r3
  uint32_t *v20; // r3

  switch ( a2 )
  {
    case 0:
      if ( ((*(uint32_t *)off_116D80 >> 4) & 3) != 2 )
        goto LABEL_12;
      while ( ((*(uint32_t *)off_116D80 >> 4) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116DB8 >= 0 || ((*(uint32_t *)off_116D80 >> 4) & 3) != 2 )
      {
LABEL_12:
        v16 = off_116D88;
        *(uint32_t *)off_116DA8 = a1;
        *v16 = 512;
        goto LABEL_4;
      }
      result = sub_12F630(dword_116DD4, dword_116DC0, 1919, a4);
      break;
    case 1:
      if ( ((*(uint32_t *)off_116D80 >> 8) & 3) != 2 )
        goto LABEL_14;
      while ( ((*(uint32_t *)off_116D80 >> 8) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116DB8 >= 0 || ((*(uint32_t *)off_116D80 >> 8) & 3) != 2 )
      {
LABEL_14:
        v17 = off_116D88;
        *(uint32_t *)off_116DAC = a1;
        *v17 = 1024;
        goto LABEL_4;
      }
      result = sub_12F630(dword_116DD0, dword_116DC0, 1907, a4);
      break;
    case 2:
      if ( ((*(uint32_t *)off_116D80 >> 12) & 3) != 2 )
        goto LABEL_16;
      while ( ((*(uint32_t *)off_116D80 >> 12) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116DB8 >= 0 || ((*(uint32_t *)off_116D80 >> 12) & 3) != 2 )
      {
LABEL_16:
        v18 = off_116D88;
        *(uint32_t *)off_116DB0 = a1;
        *v18 = 2048;
        goto LABEL_4;
      }
      result = sub_12F630(dword_116DCC, dword_116DC0, 1895, a4);
      break;
    case 3:
      if ( (HIWORD(*(uint32_t *)off_116D80) & 3) != 2 )
        goto LABEL_18;
      while ( (HIWORD(*(uint32_t *)off_116D80) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116DB8 >= 0 || (HIWORD(*(uint32_t *)off_116D80) & 3) != 2 )
      {
LABEL_18:
        v19 = off_116D88;
        *(uint32_t *)off_116DB4 = a1;
        *v19 = 4096;
        goto LABEL_4;
      }
      result = sub_12F630(dword_116DC8, dword_116DC0, 1883, a4);
      break;
    case 4:
      if ( **(int16_t **)off_116DB8 >= 0 || (*(uint32_t *)off_116D80 & 3) != 2 )
      {
        v20 = off_116D88;
        *(uint32_t *)off_116DBC = a1;
        *v20 = 256;
        goto LABEL_4;
      }
      result = sub_12F630(dword_116DC4, dword_116DC0, 1871, a4);
      break;
    case 5:
      if ( (HIBYTE(*(uint32_t *)off_116D80) & 3) != 2 )
        goto LABEL_3;
      while ( (HIBYTE(*(uint32_t *)off_116D80) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116DB8 >= 0 || (HIBYTE(*(uint32_t *)off_116D80) & 3) != 2 )
      {
LABEL_3:
        v5 = off_116D88;
        *(uint32_t *)off_116D84 = a1;
        *v5 = 0x4000;
        goto LABEL_4;
      }
      result = sub_12F630(dword_116DD8, dword_116DC0, 1931, a4);
      break;
    default:
      if ( **(int16_t **)off_116DB8 < 0 )
        sub_12F694(dword_116DDC, dword_116DC0, 1937);
LABEL_4:
      v6 = (int *)off_116D98;
      v7 = (int *)(4 * (dword_116D94 + a2));
      v8 = *(uint32_t *)off_116D90 + *(uint32_t *)(dword_116D8C + 4 * a2);
      v9 = 1 << a2;
      *v7 = v8;
      *v6 = v9;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_116D9C = 1;
      }
      v10 = (int *)off_116DA0;
      v11 = (int *)off_116DA4;
      result = *(uint32_t *)off_116DA0;
      v13 = *(uint32_t *)off_116DA0 + 1;
      v14 = v9 | *(uint32_t *)off_116DA4;
      *(uint32_t *)off_116DA0 = v13;
      *v11 = v14;
      if ( v13 )
      {
        v15 = off_116D9C;
        *v10 = result;
        if ( !result )
        {
          if ( *v15 )
            __enable_irq();
        }
      }
      break;
  }
  return result;
}

