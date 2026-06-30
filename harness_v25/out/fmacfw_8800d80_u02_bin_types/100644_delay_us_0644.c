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

extern uint32_t off_10066C;

// delay_us_0644 @ 0x100644, size 40 bytes
// Doc: delay_us_0644 [util]: Microsecond busy-wait delay using MMIO timer at 0x40501000
// delay_us_0644 [util]: Microsecond busy-wait delay using MMIO timer at 0x40501000
int  delay_us_0644(int a1)
{
  int result; // r0
  int v3; // [sp+4h] [bp-8h]

  result = a1 + *((uint32_t *)off_10066C + 4);
  do
  {
    v3 = 32;
    while ( v3-- )
      ;
  }
  while ( *((uint32_t *)off_10066C + 4) - result < 0 );
  return result;
}

