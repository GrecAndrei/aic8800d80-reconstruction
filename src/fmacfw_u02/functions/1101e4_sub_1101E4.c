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

extern uint32_t off_110218;
extern uint32_t dword_11021C;
extern uint32_t dword_110220;

// get_link_rate @ 0x1101e4, size 52 bytes
int get_link_rate()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_110218;
  result = zero_8_bytes(dword_11021C);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 2) )
  {
    v2 = dword_110220;
    v3 = dword_11021C;
    v4 = 0;
    do
    {
      rx_packet_handler(v2, 0xCu);
      result = cmd_handler_a(v3);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v0 + 2) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}

