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

extern uint32_t off_123E14;
extern uint32_t dword_123E1C;
extern uint32_t dword_123E18;
extern uint32_t off_123E20;
extern uint32_t dword_123E24;

// sub_123D9C @ 0x123d9c, size 118 bytes
int  sub_123D9C(int a1, void ( **a2)(int), int a3)
{
  int16_t **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (int16_t **)off_123E14;
  if ( **(int16_t **)off_123E14 < 0 && sub_12D0B0(a3) == 4 )
    sub_12F694(dword_123E1C, dword_123E18, 1587);
  result = sub_12D0B0(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      sub_12BA2C(result);
      sub_12CF5C(a3);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(uint32_t *)off_123E20 << 28 )
      sub_12F694(dword_123E24, dword_123E18, 1594);
    v7 = sub_12CF5C(a3);
    (*a2)(v7);
    return 0;
  }
  return result;
}

