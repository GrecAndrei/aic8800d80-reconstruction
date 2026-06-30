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

extern uint32_t off_116800;
extern uint32_t off_116838;
extern uint32_t off_116808;
extern uint32_t off_116828;
extern uint32_t dword_116854;
extern uint32_t dword_116840;
extern uint32_t off_11682C;
extern uint32_t dword_116850;
extern uint32_t off_116830;
extern uint32_t dword_11684C;
extern uint32_t off_116834;
extern uint32_t dword_116848;
extern uint32_t off_11683C;
extern uint32_t dword_116844;
extern uint32_t off_116804;
extern uint32_t dword_116858;
extern uint32_t dword_11685C;
extern uint32_t off_116818;
extern uint32_t dword_116814;
extern uint32_t off_116810;
extern uint32_t dword_11680C;
extern uint32_t off_11681C;
extern uint32_t off_116820;
extern uint32_t off_116824;

// sub_116574 @ 0x116574, size 652 bytes
int  sub_116574(int a1, int a2, int a3, int a4)
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
      if ( ((*(uint32_t *)off_116800 >> 4) & 3) != 2 )
        goto LABEL_12;
      while ( ((*(uint32_t *)off_116800 >> 4) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116838 >= 0 || ((*(uint32_t *)off_116800 >> 4) & 3) != 2 )
      {
LABEL_12:
        v16 = off_116808;
        *(uint32_t *)off_116828 = a1;
        *v16 = 512;
        goto LABEL_4;
      }
      result = sub_12F2C8(dword_116854, dword_116840, 1919, a4);
      break;
    case 1:
      if ( ((*(uint32_t *)off_116800 >> 8) & 3) != 2 )
        goto LABEL_14;
      while ( ((*(uint32_t *)off_116800 >> 8) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116838 >= 0 || ((*(uint32_t *)off_116800 >> 8) & 3) != 2 )
      {
LABEL_14:
        v17 = off_116808;
        *(uint32_t *)off_11682C = a1;
        *v17 = 1024;
        goto LABEL_4;
      }
      result = sub_12F2C8(dword_116850, dword_116840, 1907, a4);
      break;
    case 2:
      if ( ((*(uint32_t *)off_116800 >> 12) & 3) != 2 )
        goto LABEL_16;
      while ( ((*(uint32_t *)off_116800 >> 12) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116838 >= 0 || ((*(uint32_t *)off_116800 >> 12) & 3) != 2 )
      {
LABEL_16:
        v18 = off_116808;
        *(uint32_t *)off_116830 = a1;
        *v18 = 2048;
        goto LABEL_4;
      }
      result = sub_12F2C8(dword_11684C, dword_116840, 1895, a4);
      break;
    case 3:
      if ( (HIWORD(*(uint32_t *)off_116800) & 3) != 2 )
        goto LABEL_18;
      while ( (HIWORD(*(uint32_t *)off_116800) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116838 >= 0 || (HIWORD(*(uint32_t *)off_116800) & 3) != 2 )
      {
LABEL_18:
        v19 = off_116808;
        *(uint32_t *)off_116834 = a1;
        *v19 = 4096;
        goto LABEL_4;
      }
      result = sub_12F2C8(dword_116848, dword_116840, 1883, a4);
      break;
    case 4:
      if ( **(int16_t **)off_116838 >= 0 || (*(uint32_t *)off_116800 & 3) != 2 )
      {
        v20 = off_116808;
        *(uint32_t *)off_11683C = a1;
        *v20 = 256;
        goto LABEL_4;
      }
      result = sub_12F2C8(dword_116844, dword_116840, 1871, a4);
      break;
    case 5:
      if ( (HIBYTE(*(uint32_t *)off_116800) & 3) != 2 )
        goto LABEL_3;
      while ( (HIBYTE(*(uint32_t *)off_116800) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116838 >= 0 || (HIBYTE(*(uint32_t *)off_116800) & 3) != 2 )
      {
LABEL_3:
        v5 = off_116808;
        *(uint32_t *)off_116804 = a1;
        *v5 = 0x4000;
        goto LABEL_4;
      }
      result = sub_12F2C8(dword_116858, dword_116840, 1931, a4);
      break;
    default:
      if ( **(int16_t **)off_116838 < 0 )
        sub_12F32C(dword_11685C, dword_116840, 1937);
LABEL_4:
      v6 = (int *)off_116818;
      v7 = (int *)(4 * (dword_116814 + a2));
      v8 = *(uint32_t *)off_116810 + *(uint32_t *)(dword_11680C + 4 * a2);
      v9 = 1 << a2;
      *v7 = v8;
      *v6 = v9;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_11681C = 1;
      }
      v10 = (int *)off_116820;
      v11 = (int *)off_116824;
      result = *(uint32_t *)off_116820;
      v13 = *(uint32_t *)off_116820 + 1;
      v14 = v9 | *(uint32_t *)off_116824;
      *(uint32_t *)off_116820 = v13;
      *v11 = v14;
      if ( v13 )
      {
        v15 = off_11681C;
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

