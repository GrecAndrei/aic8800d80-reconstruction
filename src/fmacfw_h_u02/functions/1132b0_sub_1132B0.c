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

extern uint32_t off_113354;
extern uint32_t off_113358;
extern uint32_t dword_11336C;
extern uint32_t dword_113368;
extern uint32_t off_11335C;
extern uint32_t off_113360;
extern uint32_t dword_113370;
extern uint32_t off_113364;

// sub_1132B0 @ 0x1132b0, size 164 bytes
int  sub_1132B0(int a1, unsigned int a2)
{
  uint8_t *v2; // r4
  uint8_t *v3; // r5
  int v4; // r3
  uint32_t *v5; // r2
  int v6; // r0
  int v7; // r2

  v2 = off_113354;
  if ( *(uint8_t *)off_113354 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_113358;
  if ( *(uint8_t *)off_113358 )
  {
    sub_10DAE4(dword_11336C, dword_113368, *(uint8_t *)off_113358);
    return -3;
  }
  else
  {
    v4 = *(char *)off_11335C;
    *(uint8_t *)off_113358 = 1;
    v5 = off_113360;
    if ( v4 )
    {
      *((uint32_t *)off_113360 + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((uint32_t *)off_113360 + 713) |= 1u;
    }
    v6 = sub_111FDC(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      sub_10DAE4(dword_113370, dword_113368, v6);
      return -1;
    }
    else
    {
      *(uint8_t *)off_113364 = 1;
      if ( *v2 )
      {
        sub_111C74(0, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}

