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

extern uint32_t off_116940;
extern uint32_t off_116978;
extern uint32_t off_116948;
extern uint32_t off_116968;
extern uint32_t dword_116994;
extern uint32_t dword_116980;
extern uint32_t off_11696C;
extern uint32_t dword_116990;
extern uint32_t off_116970;
extern uint32_t dword_11698C;
extern uint32_t off_116974;
extern uint32_t dword_116988;
extern uint32_t off_11697C;
extern uint32_t dword_116984;
extern uint32_t off_116944;
extern uint32_t dword_116998;
extern uint32_t dword_11699C;
extern uint32_t off_116958;
extern uint32_t dword_116954;
extern uint32_t off_116950;
extern uint32_t dword_11694C;
extern uint32_t off_11695C;
extern uint32_t off_116960;
extern uint32_t off_116964;

// radio_band_validate @ 0x1166b4, size 652 bytes
int  radio_band_validate(int a1, int a2, int a3, int a4)
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
      if ( ((*(uint32_t *)off_116940 >> 4) & 3) != 2 )
        goto LABEL_12;
      while ( ((*(uint32_t *)off_116940 >> 4) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116978 >= 0 || ((*(uint32_t *)off_116940 >> 4) & 3) != 2 )
      {
LABEL_12:
        v16 = off_116948;
        *(uint32_t *)off_116968 = a1;
        *v16 = 512;
        goto LABEL_4;
      }
      result = bad_func_0x12f408(dword_116994, dword_116980, 1919, a4);
      break;
    case 1:
      if ( ((*(uint32_t *)off_116940 >> 8) & 3) != 2 )
        goto LABEL_14;
      while ( ((*(uint32_t *)off_116940 >> 8) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116978 >= 0 || ((*(uint32_t *)off_116940 >> 8) & 3) != 2 )
      {
LABEL_14:
        v17 = off_116948;
        *(uint32_t *)off_11696C = a1;
        *v17 = 1024;
        goto LABEL_4;
      }
      result = bad_func_0x12f408(dword_116990, dword_116980, 1907, a4);
      break;
    case 2:
      if ( ((*(uint32_t *)off_116940 >> 12) & 3) != 2 )
        goto LABEL_16;
      while ( ((*(uint32_t *)off_116940 >> 12) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116978 >= 0 || ((*(uint32_t *)off_116940 >> 12) & 3) != 2 )
      {
LABEL_16:
        v18 = off_116948;
        *(uint32_t *)off_116970 = a1;
        *v18 = 2048;
        goto LABEL_4;
      }
      result = bad_func_0x12f408(dword_11698C, dword_116980, 1895, a4);
      break;
    case 3:
      if ( (HIWORD(*(uint32_t *)off_116940) & 3) != 2 )
        goto LABEL_18;
      while ( (HIWORD(*(uint32_t *)off_116940) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116978 >= 0 || (HIWORD(*(uint32_t *)off_116940) & 3) != 2 )
      {
LABEL_18:
        v19 = off_116948;
        *(uint32_t *)off_116974 = a1;
        *v19 = 4096;
        goto LABEL_4;
      }
      result = bad_func_0x12f408(dword_116988, dword_116980, 1883, a4);
      break;
    case 4:
      if ( **(int16_t **)off_116978 >= 0 || (*(uint32_t *)off_116940 & 3) != 2 )
      {
        v20 = off_116948;
        *(uint32_t *)off_11697C = a1;
        *v20 = 256;
        goto LABEL_4;
      }
      result = bad_func_0x12f408(dword_116984, dword_116980, 1871, a4);
      break;
    case 5:
      if ( (HIBYTE(*(uint32_t *)off_116940) & 3) != 2 )
        goto LABEL_3;
      while ( (HIBYTE(*(uint32_t *)off_116940) & 3) == 2 )
        ;
      if ( **(int16_t **)off_116978 >= 0 || (HIBYTE(*(uint32_t *)off_116940) & 3) != 2 )
      {
LABEL_3:
        v5 = off_116948;
        *(uint32_t *)off_116944 = a1;
        *v5 = 0x4000;
        goto LABEL_4;
      }
      result = bad_func_0x12f408(dword_116998, dword_116980, 1931, a4);
      break;
    default:
      if ( **(int16_t **)off_116978 < 0 )
        mmio_clear_register(dword_11699C, dword_116980, 1937);
LABEL_4:
      v6 = (int *)off_116958;
      v7 = (int *)(4 * (dword_116954 + a2));
      v8 = *(uint32_t *)off_116950 + *(uint32_t *)(dword_11694C + 4 * a2);
      v9 = 1 << a2;
      *v7 = v8;
      *v6 = v9;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_11695C = 1;
      }
      v10 = (int *)off_116960;
      v11 = (int *)off_116964;
      result = *(uint32_t *)off_116960;
      v13 = *(uint32_t *)off_116960 + 1;
      v14 = v9 | *(uint32_t *)off_116964;
      *(uint32_t *)off_116960 = v13;
      *v11 = v14;
      if ( v13 )
      {
        v15 = off_11695C;
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

