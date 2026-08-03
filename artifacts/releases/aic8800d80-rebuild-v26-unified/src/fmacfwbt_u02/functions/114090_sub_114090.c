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

extern uint32_t off_1140D8;
extern uint32_t off_1140DC;
extern uint32_t dword_1140E0;

// sub_114090 @ 0x114090, size 72 bytes
int sub_114090()
{
  uint32_t *v0; // r5
  void *v1; // r7
  int result; // r0
  int v3; // r6
  int v4; // r4

  v0 = off_1140D8;
  v1 = off_1140DC;
  sub_12D468(*(uint32_t *)off_1140D8 + 564);
  result = sub_12D468(*v0 + 572);
  if ( *(uint16_t *)(*(uint32_t *)v1 + 8) )
  {
    v3 = dword_1140E0;
    v4 = 0;
    do
    {
      sub_10F980(v3, 0x6B8u);
      result = sub_12D470(*v0 + 564);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v1 + 8) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}

