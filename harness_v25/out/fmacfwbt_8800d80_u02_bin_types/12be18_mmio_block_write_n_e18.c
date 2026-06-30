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

extern uint32_t off_12BE4C;
extern uint32_t off_12BE50;
extern uint32_t off_12BE48;

// mmio_block_write_n_e18 @ 0x12be18, size 48 bytes
// Doc: mmio_block_write_n_e18 [mmio]: Writes a contiguous block to MMIO register space
// mmio_block_write_n_e18 [mmio]: Writes a contiguous block to MMIO register space
int  mmio_block_write_n_e18(int *a1)
{
  uint32_t *v1; // r2
  int *v2; // r3
  int v3; // r4
  int v4; // r0
  int v5; // r0

  v1 = off_12BE4C;
  v2 = (int *)off_12BE50;
  v3 = *a1;
  v4 = *((uint16_t *)a1 + 2);
  *(uint32_t *)off_12BE48 = v3;
  *v1 = v4;
  *v2 = 0x20000000;
  do
    v5 = *v2;
  while ( (*v2 & 0x20000000) != 0 );
  if ( (v5 & 0x10000000) != 0 )
    return 255;
  else
    return (uint8_t)(BYTE2(v5) - 16);
}

