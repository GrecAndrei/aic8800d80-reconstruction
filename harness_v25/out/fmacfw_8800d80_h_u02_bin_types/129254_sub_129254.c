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

extern uint32_t off_129384;
extern uint32_t off_129358;
extern uint32_t off_12935C;
extern uint32_t off_129360;
extern uint32_t off_129364;
extern uint32_t off_129368;
extern uint32_t off_129354;
extern uint32_t dword_129370;
extern uint32_t off_129374;
extern uint32_t off_129378;
extern uint32_t off_129380;
extern uint32_t off_12937C;

// sub_129254 @ 0x129254, size 254 bytes
int sub_129254()
{
  unsigned int *v0; // r12
  int *v1; // r1
  uint8_t *v2; // r7
  uint32_t *v3; // r4
  unsigned int v4; // r0
  unsigned int *v5; // r5
  uint8_t **v6; // r6
  int result; // r0
  uint8_t *v8; // r2
  int v9; // r3
  uint32_t *v10; // r1
  uint32_t *v11; // r4
  uint32_t *v12; // r2
  uint32_t *v13; // r6
  uint32_t *v14; // r5

  v0 = (unsigned int *)off_129384;
  v1 = (int *)off_129358;
  v2 = off_12935C;
  v3 = off_129360;
  v4 = *((uint16_t *)off_12935C + 93);
  v5 = (unsigned int *)off_129364;
  v6 = (uint8_t **)off_129368;
  *(uint32_t *)off_129354 |= 0x40000000u;
  *v3 |= 0x10000000u;
  *v0 &= 0xFFF0FFFF;
  *v0 = *v0 & 0xFFFFFF00 | 0x10;
  *v5 = *v5 & 0xFFFFFF03 | 0x10;
  *v1 = *v1 & 0x3FFFFF | (((v4 >> 5) + 32) << 22);
  result = sub_12EB90(2, dword_129370);
  v8 = *v6;
  v9 = **v6;
  if ( v9 == 1 )
  {
    if ( v2[189] )
    {
      result = (int)off_129374;
      *(uint32_t *)off_129378 &= ~0x2000000u;
      *v5 |= 0x200000u;
      *(uint32_t *)result = 36;
      if ( *v8 != 2 )
        goto LABEL_3;
      goto LABEL_6;
    }
    result = (int)off_129378;
    v13 = off_129374;
    v14 = off_129380;
    *(uint32_t *)off_129378 |= 0x2000000u;
    *v13 = 4;
    *v14 = 1;
    *v3 &= 0xFFFBFFFE;
    v9 = (uint8_t)*v8;
  }
  if ( v9 != 2 )
  {
LABEL_3:
    *(uint32_t *)off_129374 &= ~0x20u;
    return result;
  }
LABEL_6:
  v10 = off_129378;
  v11 = off_129374;
  v12 = off_129364;
  *(uint32_t *)off_12937C |= 0x10000u;
  *v10 &= ~0x2000000u;
  *v11 = 63;
  *v12 &= ~1u;
  return 63;
}

