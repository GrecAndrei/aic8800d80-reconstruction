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

extern uint32_t off_1132B4;
extern uint32_t dword_1132B8;
extern uint32_t dword_1132BC;

// sub_113280 @ 0x113280, size 52 bytes
// Doc: sub_1213280 [unknown]: Unidentified initialization helper in lmacfw_rf
// sub_1213280 [unknown]: Unidentified initialization helper in lmacfw_rf
int sub_113280()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_1132B4;
  result = sub_11E71C(dword_1132B8);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 4) )
  {
    v2 = dword_1132BC;
    v3 = dword_1132B8;
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

