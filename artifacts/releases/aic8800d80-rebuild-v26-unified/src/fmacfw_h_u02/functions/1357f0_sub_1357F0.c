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

extern uint32_t dword_135820;

// sub_1357F0 @ 0x1357f0, size 46 bytes
void  sub_1357F0(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v14; // r1
  int v15; // r2
  int v16; // r3

  sub_12C5FC(6154, 6);
  if ( a1 )
  {
    sub_12EB90(256, dword_135820, a1);
    sub_134CC4(a1, v14, v15, v16, a5, a6, a7, a8, a9, a10, a11, a12, a13);
  }
  else
  {
    sub_135224();
  }
}

