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

// dma_rx_init @ 0x1059a4, size 206 bytes
int  dma_rx_init(unsigned int a1, int a2, int a3)
{
  int v5; // r5
  int v6; // r7
  int v7; // r9
  int result; // r0
  unsigned int v9; // r0
  int v10; // r2
  int v11; // r2
  int v12; // r1

  v5 = 0;
  *(uint64_t *)(a2 + 628) = 0x40000000FLL;
  *(uint32_t *)(a2 + 624) = 0;
  if ( a3 )
    v6 = 7;
  else
    v6 = 4;
  if ( a3 )
    v7 = 15;
  else
    v7 = 13;
  result = check_feature_flag(1, aBitMaskX, a1);
  do
  {
    if ( a1 )
    {
      if ( ((1 << v5) & a1) >> v5 == 1 )
      {
        *(uint32_t *)(a2 + 4 * (*(uint32_t *)(a2 + 624) + 148)) = v5;
        check_feature_flag(1, "you want to cal %x index\n", v5);
        v9 = ((1 << v5) & a1) >> v5;
        v10 = *(uint32_t *)(a2 + 4 * (*(uint32_t *)(a2 + 624) + 148));
        if ( v10 < v6 )
        {
          result = check_feature_flag(v9, " %x ana_pwr_index dont need cal\n", v10);
          if ( !*(uint32_t *)(a2 + 624) )
            *(uint32_t *)(a2 + 632) = *(uint32_t *)(a2 + 592);
        }
        else if ( v10 > v7 )
        {
          result = check_feature_flag(v9, " %x ana_pwr_index dont need cal\n", v10);
          if ( !*(uint32_t *)(a2 + 624) )
            *(uint32_t *)(a2 + 628) = *(uint32_t *)(a2 + 592);
        }
        else
        {
          result = check_feature_flag(v9, "need cal %x ana_pwr_index\n", v10);
          v11 = *(uint32_t *)(a2 + 624);
          v12 = *(uint32_t *)(a2 + 4 * (v11 + 148));
          *(uint32_t *)(a2 + 624) = v11 + 1;
          *(uint32_t *)(a2 + 628) = v12;
        }
      }
    }
    else
    {
      result = alloc_tx_event(aDpdDontNeedCal);
    }
    ++v5;
  }
  while ( v5 != 16 );
  return result;
}
