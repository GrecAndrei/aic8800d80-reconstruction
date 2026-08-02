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


extern uint32_t dword_1355BC;
extern uint32_t off_1355B8;
extern uint32_t off_1355C0;
extern uint32_t off_1355C4;

// sub_135528 @ 0x135528, size 144 bytes
int  sub_135528(int a1)
{
  int v2; // r6
  int v3; // r2
  int result; // r0
  int v5; // r6
  int v6; // r4

  v2 = *(uint8_t *)(a1 + 8);
  if ( sub_12CD48(6) == 10 || sub_12CD48(6) == 9 )
    return 2;
  if ( sub_12CD48(6) )
  {
    v3 = *(uint8_t *)(*((uint32_t *)off_1355B8 + 4) + 61);
    if ( v3 != *(uint8_t *)(a1 + 8) )
      return 2;
    sub_12EB90(256, off_1355C4, v3);
    if ( sub_12C774(6154, 6) )
      sub_12C5FC(6154, 6);
    sub_134CC4(1);
    return 0;
  }
  else
  {
    v5 = dword_1355BC + 1320 * v2;
    result = *(uint8_t *)(v5 + 108);
    if ( *(uint8_t *)(v5 + 108) )
    {
      v6 = *(uint16_t *)(a1 + 12);
      sub_12EB90(256, off_1355C0[0], v6);
      sub_134C4C(v5, v6, 0);
      return 0;
    }
  }
  return result;
}
