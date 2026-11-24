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


extern uint32_t dword_11026C;
extern uint32_t dword_110274;
extern uint32_t off_110270;
extern uint32_t off_110278;

// get_modulation_type @ 0x110224, size 72 bytes
uint32_t *get_modulation_type()
{
  void *v0; // r8
  uint32_t *result; // r0
  uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  uint32_t *v6; // r0
  unsigned int v7; // r1

  v0 = off_110278;
  result = zero_8_bytes((uint32_t *)dword_11026C);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
  {
    v2 = off_110270;
    v3 = dword_110274;
    v4 = dword_11026C;
    v5 = 0;
    do
    {
      v6 = rx_packet_handler_1(v3, 0x6B8u);
      result = (uint32_t *)cmd_handler_a(v4, v6);
      v7 = *(uint16_t *)(*(uint32_t *)v0 + 8);
      ++v5;
      ++*v2;
    }
    while ( v7 > (uint16_t)v5 );
  }
  return result;
}
