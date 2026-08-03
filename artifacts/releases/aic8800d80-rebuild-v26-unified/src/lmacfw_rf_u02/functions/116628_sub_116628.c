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

extern uint32_t dword_116650;

// sub_116628 @ 0x116628, size 40 bytes
int  sub_116628(int result, int a2)
{
  int v2; // r4
  int ( *v4)(uint32_t, uint32_t); // r3

  v2 = result;
  if ( !*(uint8_t *)(result + 52) )
    result = list_push_tail(dword_116650);
  if ( a2 )
  {
    v4 = *(int ( **)(uint32_t, uint32_t))(v2 + 44);
    if ( v4 )
      return v4(*(uint32_t *)(v2 + 48), 0);
  }
  return result;
}

