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

extern uint32_t off_113AC8;
extern uint32_t off_113ACC;

// mmio_read32 @ 0x113a44, size 130 bytes
int  mmio_read32(unsigned int a1)
{
  int v1; // r8
  uint32_t *v3; // r3
  unsigned int v4; // r6
  uint32_t *v5; // r5
  int v6; // r4
  unsigned int v7; // r2
  uint32_t *v8; // r3

  while ( !*(uint32_t *)off_113AC8 )
    ;
  if ( a1 <= 0x1F )
  {
    v3 = off_113ACC;
    v1 = 0;
    *((uint32_t *)off_113ACC + 16) = 1;
    v4 = a1 + 512;
    v5 = v3;
    v3[19] = 34816;
    v6 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v5[21] = (v6 << 12) | 0x27D;
        __dsb(0xFu);
        v7 = v5[v4];
        if ( v7 <= 0x29 )
          break;
        v1 |= 1 << v6;
LABEL_7:
        if ( ++v6 == 32 )
          goto LABEL_11;
      }
      if ( v7 <= 0x26 )
        goto LABEL_7;
      ++v6;
      uart_tx_byte(101);
      if ( v6 == 32 )
      {
LABEL_11:
        v8 = off_113ACC;
        *((uint32_t *)off_113ACC + 16) = 0;
        v8[19] = 0;
        v8[21] &= ~4u;
        goto LABEL_4;
      }
    }
  }
  v1 = 0;
LABEL_4:
  *(uint32_t *)off_113AC8 = 1;
  return v1;
}

