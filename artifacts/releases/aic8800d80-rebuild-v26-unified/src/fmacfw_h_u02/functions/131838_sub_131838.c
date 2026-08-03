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

extern uint32_t off_131880;
extern uint32_t dword_13188C;
extern uint32_t dword_131888;
extern uint32_t off_131884;

// sub_131838 @ 0x131838, size 70 bytes
int  sub_131838(int a1, int a2, unsigned int a3)
{
  int v4; // r1

  if ( **(int16_t **)off_131880 < 0 && sub_12CD48(a3) != 1 )
    sub_12F32C(dword_13188C, dword_131888, 670);
  v4 = *((uint16_t *)off_131884 + 4);
  if ( v4 != 255 )
    sub_12C8D0(5144, v4, a3);
  sub_12CBF4(a3, 0);
  return 0;
}

