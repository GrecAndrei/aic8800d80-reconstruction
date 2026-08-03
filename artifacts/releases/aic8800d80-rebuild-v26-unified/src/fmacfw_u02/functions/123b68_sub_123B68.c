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

extern uint32_t off_123BE0;
extern uint32_t dword_123BE8;
extern uint32_t dword_123BE4;
extern uint32_t off_123BEC;
extern uint32_t dword_123BF0;

// sub_123B68 @ 0x123b68, size 118 bytes
// Doc: sub_1223B68 [util]: Helper: reads flag from 0x182B60, dispatches to handler with r0/r1/r2 args
// sub_1223B68 [util]: Helper: reads flag from 0x182B60, dispatches to handler with r0/r1/r2 args
int  sub_123B68(int a1, void ( **a2)(int), int a3)
{
  int16_t **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (int16_t **)off_123BE0;
  if ( **(int16_t **)off_123BE0 < 0 && msg_get_value(a3) == 4 )
    sub_12F46C(dword_123BE8, dword_123BE4, 1587);
  result = msg_get_value(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      sub_12B804(result);
      sub_12CD34(a3);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(uint32_t *)off_123BEC << 28 )
      sub_12F46C(dword_123BF0, dword_123BE4, 1594);
    v7 = sub_12CD34(a3);
    (*a2)(v7);
    return 0;
  }
  return result;
}

