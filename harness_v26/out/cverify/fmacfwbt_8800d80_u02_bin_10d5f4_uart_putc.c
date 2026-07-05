#include <stdint.h>
#define BYTE1(x) ((uint8_t)(((uint32_t)(x) >> 8) & 0xFFu))
#define BYTE2(x) ((uint8_t)(((uint32_t)(x) >> 16) & 0xFFu))
#define BYTE3(x) ((uint8_t)(((uint32_t)(x) >> 24) & 0xFFu))
#define __noreturn
#define _VF 0
#define _CF 0
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

#define off_10D604 ((uint32_t)0x40032020u)
#define off_10D608 ((uint32_t)0x40032000u)
// uart_putc @ 0x10d5f4, size 14 bytes
// Doc: uart_putc [util]: Write one character to UART data register at 0x40032000
// uart_putc [util]: Write one character to UART data register at 0x40032000
int  uart_putc(int result)
{
  while ( (*(uint32_t *)off_10D604 & 0x80000) != 0 )
    ;
  *(uint32_t *)off_10D608 = result;
  return result;
}

