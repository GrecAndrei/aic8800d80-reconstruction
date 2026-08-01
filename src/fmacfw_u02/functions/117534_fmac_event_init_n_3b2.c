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

// dma_rx_setup @ 0x117534, size 48 bytes
// Doc: dma_rx_setup [util]: Initialize fmac event/state object with cleared slot at offset 0x4f8
// dma_rx_setup [util]: Initialize fmac event/state object with cleared slot at offset 0x4f8
int  dma_rx_setup(int a1)
{
  int v1; // r4
  int v2; // r5
  int v3; // r0
  int result; // r0
  int v5; // [sp+4h] [bp-8h]

  v1 = a1 + 1272;
  v2 = 0;
  do
  {
    v3 = (uint8_t)v2;
    v5 = (uint8_t)v2++;
    rf_tx_setup(v3, v1, 0);
    result = rf_tx_setup(v5, v1 - 40, 0);
    v1 += 8;
  }
  while ( v2 != 5 );
  return result;
}

