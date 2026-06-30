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

extern uint32_t off_1111E4;
extern uint32_t dword_1111E8;

// sub_111168 @ 0x111168, size 124 bytes
int  sub_111168(int a1)
{
  int *v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r1

  v1 = (int *)off_1111E4;
  v2 = a1 & 0x3FFFFF;
  v3 = *(uint32_t *)off_1111E4 & 0x3FFFFF;
  if ( (a1 & 0x400000) != 0 )
  {
    *(uint32_t *)off_1111E4 = v3 | 0x800000;
    *v1 = v3;
    *v1 = v2;
    v4 = v2 | 0x800000;
  }
  else
  {
    *(uint32_t *)off_1111E4 = v3 | 0x400000;
    v4 = v2 | 0x400000;
  }
  *v1 = v4;
  *v1 = v2 | 0xC00000;
  return sub_10DA7C(dword_1111E8, *(uint32_t *)off_1111E4 & 0x3FFFFF);
}

