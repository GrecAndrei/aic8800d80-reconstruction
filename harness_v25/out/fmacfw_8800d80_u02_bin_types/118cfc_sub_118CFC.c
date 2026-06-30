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

extern uint32_t dword_118D24;

// sub_118CFC @ 0x118cfc, size 40 bytes
// Doc: sub_1218CFC [unknown]: Unknown helper at 0x1218cfc in fmacfw
// sub_1218CFC [unknown]: Unknown helper at 0x1218cfc in fmacfw
int  sub_118CFC(int result, int a2)
{
  int v2; // r4
  int ( *v4)(uint32_t, uint32_t); // r3

  v2 = result;
  if ( !*(uint8_t *)(result + 96) )
    result = list_push_tail(dword_118D24);
  if ( a2 )
  {
    v4 = *(int ( **)(uint32_t, uint32_t))(v2 + 88);
    if ( v4 )
      return v4(*(uint32_t *)(v2 + 92), 0);
  }
  return result;
}

