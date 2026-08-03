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

extern uint32_t off_103110;
extern uint32_t off_103168;
extern uint32_t off_103114;
extern uint32_t off_103118;
extern uint32_t off_103120;
extern uint32_t off_10311C;
extern uint32_t off_103128;
extern uint32_t off_10317C;
extern uint32_t off_103124;
extern uint32_t off_10312C;
extern uint32_t off_103130;
extern uint32_t off_103134;
extern uint32_t off_103138;
extern uint32_t off_10313C;
extern uint32_t off_103140;
extern uint32_t off_103144;
extern uint32_t off_103148;
extern uint32_t off_10314C;
extern uint32_t off_103170;
extern uint32_t off_103150;
extern uint32_t off_103174;
extern uint32_t off_103178;
extern uint32_t off_103154;
extern uint32_t off_103158;
extern uint32_t off_10315C;
extern uint32_t off_103164;
extern uint32_t off_103160;
extern uint32_t off_10316C;

// sub_102ED0 @ 0x102ed0, size 576 bytes
int sub_102ED0()
{
  uint8_t *v0; // r3
  uint32_t *v1; // r2
  uint32_t *v2; // r1
  unsigned int *v3; // r2
  unsigned int *v4; // r0
  uint32_t *v5; // r5
  unsigned int *v6; // r4
  uint32_t *v7; // r6
  uint32_t *v8; // r3
  uint32_t *v9; // r0
  uint32_t *v10; // r2
  uint8_t *v11; // r4
  uint32_t *v12; // r3
  uint32_t *v13; // r4
  unsigned int *v14; // r2
  uint8_t *v15; // r0
  uint32_t *v16; // r1
  int result; // r0
  unsigned int *v18; // r2
  uint32_t *v19; // r3
  uint32_t *v20; // r3
  uint32_t *v21; // r2
  unsigned int *v22; // r0
  uint32_t *v23; // r2

  if ( *((uint8_t *)off_103110 + 2) )
  {
    *(uint32_t *)off_103168 = *(uint32_t *)off_103168 & 0xFFFFF3FF | 0x800;
  }
  else
  {
    v0 = off_103114;
    v1 = off_103118;
    *(uint8_t *)off_103114 = 80;
    v0[1] = 78;
    while ( !*v1 )
      ;
    v2 = off_103120;
    *(uint32_t *)off_10311C &= ~2u;
    if ( (*v2 & 1) == 0 )
    {
      sub_100E24(1);
      v23 = off_103128;
      *(uint32_t *)off_10317C = *(uint32_t *)off_10317C & 0xFFFFFFF0 | 4;
      *v23 |= 2u;
    }
    v3 = (unsigned int *)off_103124;
    v4 = (unsigned int *)off_103128;
    v5 = off_10312C;
    v6 = (unsigned int *)off_103130;
    v7 = off_103134;
    *(uint32_t *)off_103118 = 1;
    *v3 = *v3 & 0xC3FFFFFF | 0x30000000;
    *v4 = *v4 & 0xFE3FFFFF | 0x400000;
    *v5 |= 0x78000u;
    *v4 &= ~2u;
    v8 = off_103138;
    *v3 = *v3 & 0xFF0FFFFF | 0xC00000;
    *v3 = *v3 & 0xFFFFFF0F | 0x60;
    v9 = off_10313C;
    v5 -= 463846;
    *v6 &= ~1u;
    *v5 = *v5 & 0xFFFFE0FF | 0x1000;
    *v8 |= 8u;
    *v8 &= 0xFFFFFFFC;
    *v7 &= ~0x40000u;
    *v8 &= ~4u;
    v10 = off_103140;
    *v6 = *v6 & 0xFFFFF3FF | 0x800;
    v11 = (uint8_t *)off_103144;
    v5 -= 1999;
    *v9 &= 0xFFFF3FFF;
    *v5 = *v5 & 0xFFFFFF | 0x10000000;
    v9 -= 2043;
    *v10 = *v10 & 0xFFFC00FF | (*v11 << 8);
    v12 = off_103148;
    v5 -= 73;
    *v9 |= 0x80000000;
    *v5 |= 0x1000u;
    *v10 &= ~0x40000u;
    *v9 &= ~0x40000000u;
    v13 = off_10314C;
    *v12 &= ~2u;
    *v12 |= 1u;
    v10 += 2062;
    v5[2083] = 20058;
    *v10 = *v10 & 0x3FFFFFF | 0x7C000000;
    *v10 = *v10 & 0xFC07FFFF | 0x3D00000;
    if ( (*v13 & 0x20) != 0 )
    {
      v20 = off_103170;
      *((uint8_t *)off_103150 + 1) = 1;
      v21 = off_103174;
      v22 = (unsigned int *)off_103178;
      *v20 &= 0xFFF0FFFF;
      *v20 &= 0xFF0FFFFF;
      *v21 &= ~0x8000u;
      *v22 = *v22 & 0xFFFFFC7F | 0x200;
    }
    else
    {
      *((uint8_t *)off_103150 + 1) = 0;
    }
    v14 = (unsigned int *)off_103154;
    v15 = (uint8_t *)off_103158;
    v16 = off_10315C;
    *(uint32_t *)off_103154 = *(uint32_t *)off_103154 & 0x3FFFFFF | 0xA0000000;
    result = v15[362];
    *v14 = *v14 & 0xFC0FFFFF | 0x1800000;
    *v16 |= 0x10u;
    if ( result )
      *(v14 - 8824) = *(v14 - 8824) & 0xFFFFFFC0 | 0x2C;
    v18 = (unsigned int *)off_103164;
    *(uint32_t *)off_103160 &= 0xFFFFFFC7;
    *v18 = *v18 & 0xFFFFFFFC | 2;
  }
  v19 = off_10316C;
  *(uint32_t *)off_10316C |= 0xC000u;
  *v19 |= 0x30000u;
  return result;
}

