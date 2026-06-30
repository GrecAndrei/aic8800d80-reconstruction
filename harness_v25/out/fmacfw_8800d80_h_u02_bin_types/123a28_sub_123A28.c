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

extern uint32_t off_123AA0;
extern uint32_t dword_123AA8;
extern uint32_t dword_123AA4;
extern uint32_t off_123AAC;
extern uint32_t dword_123AB0;

// sub_123A28 @ 0x123a28, size 118 bytes
int  sub_123A28(int a1, void ( **a2)(int), int a3)
{
  int16_t **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (int16_t **)off_123AA0;
  if ( **(int16_t **)off_123AA0 < 0 && sub_12CD48(a3) == 4 )
    sub_12F32C(dword_123AA8, dword_123AA4, 1587);
  result = sub_12CD48(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      sub_12B6C4(result);
      sub_12CBF4(a3);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(uint32_t *)off_123AAC << 28 )
      sub_12F32C(dword_123AB0, dword_123AA4, 1594);
    v7 = sub_12CBF4(a3);
    (*a2)(v7);
    return 0;
  }
  return result;
}

