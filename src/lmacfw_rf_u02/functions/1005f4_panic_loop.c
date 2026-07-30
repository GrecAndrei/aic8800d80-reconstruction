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

extern uint32_t off_100644;

// panic_loop @ 0x1005f4, size 78 bytes
// Doc: panic_loop [util]: CPU panic infinite loop / fatal halt
// panic_loop [util]: CPU panic infinite loop / fatal halt
void __noreturn panic_loop()
{
  int v1; // [sp+0h] [bp-Ch]

  *(uint32_t *)off_100644 = 17;
  while ( 1 )
  {
    v1 = 32;
    while ( v1-- )
      ;
  }
}

