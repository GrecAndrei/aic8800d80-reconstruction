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

extern uint32_t off_12BC24;
extern uint32_t off_12BC28;
extern uint32_t off_12BC20;

// mmio_block_write_3reg @ 0x12bbf0, size 48 bytes
// Doc: mmio_block_write_3reg [mmio]: Writes 3 MMIO registers at 0x403200bc/c0/c4 from a struct
// mmio_block_write_3reg [mmio]: Writes 3 MMIO registers at 0x403200bc/c0/c4 from a struct
int  mmio_block_write_3reg(int *a1)
{
  uint32_t *v1; // r2
  int *v2; // r3
  int v3; // r4
  int v4; // r0
  int v5; // r0

  v1 = off_12BC24;
  v2 = (int *)off_12BC28;
  v3 = *a1;
  v4 = *((uint16_t *)a1 + 2);
  *(uint32_t *)off_12BC20 = v3;
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

