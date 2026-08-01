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

extern uint32_t off_11E268;
extern uint32_t dword_11E26C;
extern uint32_t dword_11E264;

// mem_is_null @ 0x11e1d0, size 148 bytes
int  mem_is_null(int result, int a2, int a3, int a4)
{
  int v4; // r7
  int16_t **v5; // r10
  int v6; // r11
  int v7; // r1
  unsigned int v9; // r8
  int16_t v10; // r3
  uint64_t v11; // r4
  int v12; // r6
  int v13; // r4
  int v14; // r3
  uint32_t *v15; // r2
  uint32_t *v16; // r5
  int v17; // r3

  if ( a2 )
  {
    v4 = result;
    v5 = (int16_t **)off_11E268;
    v6 = dword_11E26C;
    result = a2;
    v7 = dword_11E264;
    v9 = 0;
    while ( 1 )
    {
      v11 = *(uint64_t *)(v4 + 8);
      v10 = WORD2(v11) + 1;
      HIDWORD(v11) = (uint16_t)(WORD2(v11) + 1 - v11) - a3;
      if ( result < SHIDWORD(v11) )
      {
        v12 = 0;
      }
      else
      {
        v12 = (uint16_t)(v11 - v10 + a3 + result);
        result = WORD2(v11);
      }
      v13 = v11 + a3;
      v14 = a4 + 4 * (v9 >> 2);
      if ( (unsigned int)(result + 3) >> 2 )
      {
        v15 = (uint32_t *)(a4 + 4 * (v9 >> 2));
        v16 = (uint32_t *)(v14 + 4 * ((unsigned int)(result + 3) >> 2));
        v17 = v13 - v14;
        do
        {
          *v15 = *(uint32_t *)((char *)v15 + v17);
          ++v15;
        }
        while ( v15 != v16 );
      }
      if ( !v12 )
        break;
      v4 = *(uint32_t *)(v4 + 4);
      v9 = (uint16_t)(v9 + result);
      if ( **v5 < 0 && !v4 )
      {
        mmio_clear_register(v6, v7, 1189);
        v7 = dword_11E264;
      }
      result = v12;
      a3 = 0;
    }
  }
  return result;
}

