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

extern uint32_t dword_128B44;
extern uint32_t off_128B4C;
extern uint32_t off_128B48;
extern uint32_t off_128B50;
extern uint32_t off_128B58;
extern uint32_t off_128B54;
extern uint32_t dword_128B5C;

// sub_128AF8 @ 0x128af8, size 76 bytes
int  sub_128AF8(int a1, int a2)
{
  int result; // r0
  uint8_t *v4; // r3
  int v5; // r2
  int v6; // r2
  int v7; // r1
  int v8; // r0

  result = sub_1289EC(a1, a2, dword_128B44);
  if ( result )
  {
    v4 = off_128B4C;
    v5 = *((uint8_t *)off_128B48 + 2);
    *((uint8_t *)off_128B4C + 28) = 1;
    if ( v5 )
      *(uint32_t *)off_128B50 &= ~0x80000000;
    if ( v4[8] )
      --v4[8];
    v6 = *((uint32_t *)off_128B58 + 4);
    v7 = *(uint16_t *)(*(uint32_t *)off_128B54 + 54);
    v8 = dword_128B5C;
    *((uint32_t *)v4 + 5) = a1;
    v4[29] = 4;
    result = sub_124BFC(v8, v7 + v6);
    *(uint32_t *)(a1 + 4) |= 0x200u;
  }
  return result;
}

