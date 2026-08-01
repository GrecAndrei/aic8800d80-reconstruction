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

extern uint32_t off_126524;
extern uint32_t off_126528;
extern uint32_t off_12652C;
extern uint32_t off_126530;
extern uint32_t off_126534;

// mmio_write_register @ 0x1264dc, size 70 bytes
// Doc: mmio_write_register [mmio]: Writes value to MMIO register 0x40320150
// mmio_write_register [mmio]: Writes value to MMIO register 0x40320150
int  mmio_write_register(int a1)
{
  uint32_t *v1; // r3
  int *v2; // r4
  int v3; // r1
  int v4; // r2
  int result; // r0
  int v6; // nf
  uint32_t *v7; // r2

  *(uint32_t *)off_126524 = a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_126528 = 1;
  }
  v1 = off_12652C;
  v2 = (int *)off_126530;
  v3 = *(uint32_t *)off_12652C;
  v4 = *(uint32_t *)off_126530;
  result = *(uint32_t *)off_12652C + 1;
  v6 = (*(uint32_t *)off_126530 & 0x400) != 0;
  *(uint32_t *)off_12652C = result;
  if ( !v6 )
  {
    *(uint32_t *)off_126534 = 1024;
    *v2 = v4 | 0x400;
  }
  if ( result )
  {
    v7 = off_126528;
    *v1 = v3;
    if ( !v3 )
    {
      if ( *v7 )
        __enable_irq();
    }
  }
  return result;
}

