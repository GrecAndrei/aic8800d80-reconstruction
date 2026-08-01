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

extern uint32_t dword_11EB70;

// crc32_update_lsb @ 0x11eb48, size 38 bytes
// Doc: sdio_buffer_prepare_n_66 [mmio]: Prepares SDIO DMA buffer for host transfer
// sdio_buffer_prepare_n_66 [mmio]: Prepares SDIO DMA buffer for host transfer
unsigned int  crc32_update_lsb(uint8_t *a1, int a2, unsigned int a3)
{
  uint8_t *v3; // r4
  int v4; // t1

  if ( !a2 )
    return a3;
  v3 = &a1[a2];
  do
  {
    v4 = *a1++;
    a3 = *(uint32_t *)(dword_11EB70 + 4 * ((uint8_t)a3 ^ v4)) ^ (a3 >> 8);
  }
  while ( a1 != v3 );
  return a3;
}

