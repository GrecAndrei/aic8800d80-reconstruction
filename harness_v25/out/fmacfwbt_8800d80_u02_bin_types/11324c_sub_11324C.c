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

extern uint32_t off_1132F0;
extern uint32_t off_1132F4;
extern uint32_t dword_113308;
extern uint32_t dword_113304;
extern uint32_t off_1132F8;
extern uint32_t off_1132FC;
extern uint32_t dword_11330C;
extern uint32_t off_113300;

// sub_11324C @ 0x11324c, size 164 bytes
int  sub_11324C(int a1, unsigned int a2)
{
  uint8_t *v2; // r4
  uint8_t *v3; // r5
  int v4; // r3
  uint32_t *v5; // r2
  int v6; // r0
  int v7; // r2

  v2 = off_1132F0;
  if ( *(uint8_t *)off_1132F0 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_1132F4;
  if ( *(uint8_t *)off_1132F4 )
  {
    sub_10DA7C(dword_113308, dword_113304, *(uint8_t *)off_1132F4);
    return -3;
  }
  else
  {
    v4 = *(char *)off_1132F8;
    *(uint8_t *)off_1132F4 = 1;
    v5 = off_1132FC;
    if ( v4 )
    {
      *((uint32_t *)off_1132FC + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((uint32_t *)off_1132FC + 713) |= 1u;
    }
    v6 = sub_111F78(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      sub_10DA7C(dword_11330C, dword_113304, v6);
      return -1;
    }
    else
    {
      *(uint8_t *)off_113300 = 1;
      if ( *v2 )
      {
        sub_111C10(0, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}

