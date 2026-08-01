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

extern uint32_t dword_1182F0;

// check_link_id @ 0x1182c8, size 40 bytes
// Doc: check_link_id [rf]: RF initialization/setup routine
// check_link_id [rf]: RF initialization/setup routine
int  check_link_id(int result)
{
  int v1; // r4
  int v2; // r5
  int v3; // r6

  v1 = dword_1182F0;
  v2 = result;
  v3 = dword_1182F0 + 608;
  do
  {
    if ( *(uint8_t *)(v1 + 32) == *(uint8_t *)(v2 + 95) )
      result = rx_queue_flush(v2, v1, 0);
    v1 += 152;
  }
  while ( v3 != v1 );
  return result;
}

