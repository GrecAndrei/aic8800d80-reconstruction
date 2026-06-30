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

extern uint32_t dword_114EC4;
extern uint32_t off_114EC8;

// sub_114E90 @ 0x114e90, size 50 bytes
void __noreturn sub_114E90()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0

  sub_10DA6C(dword_114EC4);
  if ( *(uint8_t *)(*(uint32_t *)off_114EC8 + 6) == 2 )
  {
    v2 = sub_114B5C();
    sub_10F0B8(v2);
  }
  while ( 1 )
  {
    while ( !sub_10D698() )
      ;
    v0 = sub_10D680();
    v1 = sub_1230E8(v0);
    sub_123240(v1);
  }
}

