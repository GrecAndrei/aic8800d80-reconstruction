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

extern uint32_t dword_105990;
extern uint32_t dword_105994;
extern uint32_t dword_10599C;
extern uint32_t dword_1059A0;
extern uint32_t dword_105998;

// dma_chan_init @ 0x1058d0, size 190 bytes
int  dma_chan_init(unsigned int a1, uint32_t *a2)
{
  int v4; // r1
  int result; // r0
  int v6; // r7
  int v7; // r9
  int v8; // r8
  int v9; // r5
  int v10; // r2
  unsigned int v11; // r0
  int v12; // r3
  int v13; // r2

  a2[14] = 0;
  a2[15] = 15;
  v4 = dword_105990;
  a2[16] = 8;
  result = check_feature_flag(1, v4);
  if ( a1 )
  {
    v6 = dword_105994;
    v7 = dword_10599C;
    v8 = dword_1059A0;
    v9 = 20;
    while ( 1 )
    {
      while ( ((1 << v9) & a1) >> v9 != 1 )
      {
LABEL_3:
        if ( ++v9 == 28 )
          return result;
      }
      a2[a2[14] + 10] = v9 - 12;
      check_feature_flag(1, v6);
      v10 = a2[a2[14] + 10];
      if ( v10 <= 7 )
      {
        result = check_feature_flag(((1 << v9) & a1) >> v9, v7);
        if ( !a2[14] )
          a2[16] = a2[10];
        goto LABEL_3;
      }
      v11 = ((1 << v9) & a1) >> v9;
      if ( v10 > 15 )
      {
        result = check_feature_flag(v11, v7);
        if ( !a2[14] )
          a2[15] = a2[10];
        goto LABEL_3;
      }
      result = check_feature_flag(v11, v8);
      v12 = a2[14];
      ++v9;
      v13 = a2[v12 + 10];
      a2[14] = v12 + 1;
      a2[15] = v13;
      if ( v9 == 28 )
        return result;
    }
  }
  return check_feature_flag(1, dword_105998);
}

