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

extern uint32_t off_10D678;
extern uint32_t off_10D67C;

// uart_puts @ 0x10d654, size 34 bytes
// Doc: uart_puts [util]: Output null-terminated string to UART byte-by-byte
// uart_puts [util]: Output null-terminated string to UART byte-by-byte
uint8_t * uart_puts(uint8_t *result)
{
  int v1; // r1
  uint32_t *v2; // r2
  uint32_t *v3; // r4
  int v4; // t1

  v1 = (uint8_t)*result;
  if ( *result )
  {
    v2 = off_10D678;
    v3 = off_10D67C;
    do
    {
      while ( (*v2 & 0x80000) != 0 )
        ;
      *v3 = v1;
      v4 = (uint8_t)*++result;
      v1 = v4;
    }
    while ( v4 );
  }
  return result;
}

