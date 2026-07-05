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

#define off_100588 ((uint32_t)0x40501000u)
// delay_us @ 0x100560, size 40 bytes
// Doc: delay_us [util]: Microsecond delay loop using 0x40501000 timer base
// delay_us [util]: Microsecond delay loop using 0x40501000 timer base
int  delay_us(int a1)
{
  int result; // r0
  int v3; // [sp+4h] [bp-8h]

  result = a1 + *((uint32_t *)off_100588 + 4);
  do
  {
    v3 = 32;
    while ( v3-- )
      ;
  }
  while ( *((uint32_t *)off_100588 + 4) - result < 0 );
  return result;
}

