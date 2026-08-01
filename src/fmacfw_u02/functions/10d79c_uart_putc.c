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

extern uint32_t off_10D7AC;
extern uint32_t off_10D7B0;

// gpio_write @ 0x10d79c, size 14 bytes
// Doc: gpio_write [util]: Write one character to UART data register
// gpio_write [util]: Write one character to UART data register
int  gpio_write(int result)
{
  while ( (*(uint32_t *)off_10D7AC & 0x80000) != 0 )
    ;
  *(uint32_t *)off_10D7B0 = result;
  return result;
}

