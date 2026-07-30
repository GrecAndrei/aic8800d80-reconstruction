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

extern uint32_t off_100728;

// sub_1006D8 @ 0x1006d8, size 78 bytes
void __noreturn sub_1006D8()
{
  int v1; // [sp+0h] [bp-Ch]

  *(uint32_t *)off_100728 = 17;
  while ( 1 )
  {
    v1 = 32;
    while ( v1-- )
      ;
  }
}

