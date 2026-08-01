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

extern uint32_t dword_105A80;
extern uint32_t dword_105A84;
extern uint32_t dword_105A74;
extern uint32_t dword_105A7C;
extern uint32_t dword_105A78;

// dma_rx_init @ 0x1059a4, size 206 bytes
int  dma_rx_init(unsigned int a1, int a2, int a3)
{
  int v5; // r5
  int v6; // r8
  int v7; // r10
  int v8; // r7
  int v9; // r9
  int result; // r0
  int v11; // r1
  int v12; // r2
  unsigned int v13; // r0
  int v14; // r2
  int v15; // r2
  int v16; // r1

  v5 = 0;
  *(uint64_t *)(a2 + 628) = 0x40000000FLL;
  *(uint32_t *)(a2 + 624) = 0;
  v6 = dword_105A80;
  v7 = dword_105A84;
  if ( a3 )
    v8 = 7;
  else
    v8 = 4;
  if ( a3 )
    v9 = 15;
  else
    v9 = 13;
  result = check_feature_flag(1, dword_105A74);
  do
  {
    if ( a1 )
    {
      if ( ((1 << v5) & a1) >> v5 == 1 )
      {
        *(uint32_t *)(a2 + 4 * (*(uint32_t *)(a2 + 624) + 148)) = v5;
        check_feature_flag(1, v6);
        v13 = ((1 << v5) & a1) >> v5;
        v14 = *(uint32_t *)(a2 + 4 * (*(uint32_t *)(a2 + 624) + 148));
        if ( v14 < v8 )
        {
          result = check_feature_flag(v13, v7);
          v12 = *(uint32_t *)(a2 + 624);
          if ( !v12 )
          {
            v12 = *(uint32_t *)(a2 + 592);
            *(uint32_t *)(a2 + 632) = v12;
          }
        }
        else if ( v14 > v9 )
        {
          result = check_feature_flag(v13, v7);
          v12 = *(uint32_t *)(a2 + 624);
          if ( !v12 )
          {
            v12 = *(uint32_t *)(a2 + 592);
            *(uint32_t *)(a2 + 628) = v12;
          }
        }
        else
        {
          result = check_feature_flag(v13, dword_105A7C);
          v15 = *(uint32_t *)(a2 + 624);
          v16 = v15 + 148;
          v12 = v15 + 1;
          v11 = *(uint32_t *)(a2 + 4 * v16);
          *(uint32_t *)(a2 + 624) = v12;
          *(uint32_t *)(a2 + 628) = v11;
        }
      }
    }
    else
    {
      result = alloc_tx_event(dword_105A78, v11, v12);
    }
    ++v5;
  }
  while ( v5 != 16 );
  return result;
}

