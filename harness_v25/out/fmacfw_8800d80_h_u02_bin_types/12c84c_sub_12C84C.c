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

extern uint32_t off_12C8B8;
extern uint32_t dword_12C8BC;
extern uint32_t dword_12C8C4;
extern uint32_t dword_12C8C0;
extern uint32_t dword_12C8C8;
extern uint32_t off_12C8CC;

// sub_12C84C @ 0x12c84c, size 106 bytes
int  sub_12C84C(int a1)
{
  int16_t v1; // r3
  uint16_t *v4; // r0

  v1 = *(uint16_t *)(a1 - 6);
  if ( **(int16_t **)off_12C8B8 >= 0 || (uint8_t)v1 <= 0xEu )
  {
    if ( (uint8_t)v1 <= 0xCu )
    {
      sub_12D108(dword_12C8BC);
      return sub_12CFC4(0x4000000);
    }
  }
  else
  {
    sub_12F32C(dword_12C8C4, dword_12C8C0, 183);
  }
  sub_12E948(dword_12C8C8, *(uint16_t *)(a1 - 8), *(uint16_t *)(a1 - 4));
  v4 = (uint16_t *)(a1 - 12);
  if ( *(uint8_t *)off_12C8CC )
    return sub_12CA88(v4);
  else
    return sub_12F3EC(v4);
}

