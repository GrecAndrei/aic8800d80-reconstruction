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

// dma_tx_reset @ 0x1204c4, size 136 bytes
int  dma_tx_reset(int result, int a2)
{
  int v2; // r4
  int v3; // r3
  int v4; // r1
  int v5; // r3
  int v6; // r3
  int v7; // r3

  v2 = *(uint32_t *)(result + 1200);
  v3 = result + 120 * a2;
  v4 = v3 + 480;
  *(uint8_t *)(v3 + 579) = 0;
  if ( v2 == v3 + 480 )
  {
    v5 = *(uint8_t *)(result + 579);
    *(uint32_t *)(result + 1200) = 0;
    v4 = result + 480;
    if ( v5
      || (v4 = result + 600, *(uint8_t *)(result + 699))
      || (v4 = result + 720, *(uint8_t *)(result + 819))
      || (v4 = result + 840, *(uint8_t *)(result + 939)) )
    {
      *(uint32_t *)(result + 1200) = v4;
      return result;
    }
  }
  if ( *(uint32_t *)(result + 1204) == v4 )
  {
    v6 = *(uint8_t *)(result + 1059);
    *(uint32_t *)(result + 1204) = 0;
    if ( v6 )
    {
      v7 = result + 960;
    }
    else
    {
      if ( !*(uint8_t *)(result + 1179) )
        return result;
      v7 = result + 1080;
    }
    *(uint32_t *)(result + 1204) = v7;
  }
  return result;
}

