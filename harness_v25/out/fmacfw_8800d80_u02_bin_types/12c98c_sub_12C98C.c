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

extern uint32_t off_12C9F8;
extern uint32_t dword_12C9FC;
extern uint32_t dword_12CA04;
extern uint32_t dword_12CA00;
extern uint32_t dword_12CA08;
extern uint32_t off_12CA0C;

// sub_12C98C @ 0x12c98c, size 106 bytes
int  sub_12C98C(int a1)
{
  int16_t v1; // r3
  uint16_t *v4; // r0

  v1 = *(uint16_t *)(a1 - 6);
  if ( **(int16_t **)off_12C9F8 >= 0 || (uint8_t)v1 <= 0xEu )
  {
    if ( (uint8_t)v1 <= 0xCu )
    {
      sub_12D248(dword_12C9FC);
      return sub_12D104(0x4000000);
    }
  }
  else
  {
    sub_12F46C(dword_12CA04, dword_12CA00, 183);
  }
  sub_12EA88(dword_12CA08, *(uint16_t *)(a1 - 8), *(uint16_t *)(a1 - 4));
  v4 = (uint16_t *)(a1 - 12);
  if ( *(uint8_t *)off_12CA0C )
    return sub_12CBC8(v4);
  else
    return sub_12F52C(v4);
}

