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

extern uint32_t off_1101A0;
extern uint32_t dword_1101A4;
extern uint32_t dword_1101A8;

// sub_11016C @ 0x11016c, size 52 bytes
// Doc: sub_121016C [unknown]: Initialize engine context and read state register
// sub_121016C [unknown]: Initialize engine context and read state register
int sub_11016C()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_1101A0;
  result = sub_11E71C(dword_1101A4);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 4) )
  {
    v2 = dword_1101A8;
    v3 = dword_1101A4;
    v4 = 0;
    do
    {
      log_pool_alloc2_a18(v2, 0x7Cu);
      result = list_push_tail(v3);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v0 + 4) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}

