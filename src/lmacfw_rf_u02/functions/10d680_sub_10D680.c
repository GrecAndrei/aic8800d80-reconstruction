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

extern uint32_t off_10D690;
extern uint32_t off_10D694;

// uart_rx_byte @ 0x10d680, size 16 bytes
int uart_rx_byte()
{
  while ( (*(uint32_t *)off_10D690 & 1) == 0 )
    ;
  return (uint8_t)*(uint32_t *)off_10D694;
}

