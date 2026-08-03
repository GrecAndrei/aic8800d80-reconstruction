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

extern uint32_t dword_128C14;
extern uint32_t dword_128C18;
extern uint32_t off_128C1C;
extern uint32_t off_128C20;

// sub_128BB0 @ 0x128bb0, size 96 bytes
uint16_t * sub_128BB0(int a1, int a2)
{
  uint16_t *result; // r0
  int *i; // r3
  int v6; // r3

  sub_12EB90(2, dword_128C14);
  result = (uint16_t *)sub_1289EC(a1, a2, dword_128C18);
  if ( result )
  {
    result = (uint16_t *)off_128C1C;
    if ( !*((uint8_t *)off_128C1C + 8)
      || (v6 = (uint8_t)(*((uint8_t *)off_128C1C + 8) - 1), *((uint8_t *)off_128C1C + 8) = v6, !v6) )
    {
      for ( i = *((int **)off_128C20 + 2); i; i = (int *)*i )
      {
        if ( !*((uint8_t *)i + 106) )
        {
          if ( *((uint8_t *)i + 108) )
            i[1] &= 0xFFFFFFF1;
        }
      }
      *(uint8_t *)result = 0;
      return (uint16_t *)sub_12C8D0(50, result[1], 0);
    }
  }
  return result;
}

