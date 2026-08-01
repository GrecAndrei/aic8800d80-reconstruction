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

extern uint32_t off_103264;
extern uint32_t off_1032BC;
extern uint32_t off_103268;
extern uint32_t off_10326C;
extern uint32_t off_103274;
extern uint32_t off_103270;
extern uint32_t off_1032D0;
extern uint32_t off_1032D8;
extern uint32_t off_103278;
extern uint32_t off_1032D4;
extern uint32_t off_10327C;
extern uint32_t off_103280;
extern uint32_t off_103284;
extern uint32_t off_103288;
extern uint32_t off_10328C;
extern uint32_t off_103290;
extern uint32_t off_103294;
extern uint32_t off_103298;
extern uint32_t off_10329C;
extern uint32_t off_1032A0;
extern uint32_t off_1032C4;
extern uint32_t off_1032C8;
extern uint32_t off_1032CC;
extern uint32_t off_1032A4;
extern uint32_t off_1032A8;
extern uint32_t off_1032AC;
extern uint32_t off_1032B0;
extern uint32_t off_1032B8;
extern uint32_t off_1032B4;
extern uint32_t off_1032C0;

// check_chip_flag @ 0x10300c, size 600 bytes
void check_chip_flag()
{
  uint8_t *v0; // r3
  uint32_t *v1; // r2
  uint32_t *v2; // r1
  uint8_t *v3; // r3
  int v4; // r2
  unsigned int *v5; // r4
  unsigned int *v6; // r0
  uint32_t *v7; // r5
  uint32_t *v8; // r3
  uint32_t *v9; // r6
  uint32_t *v10; // r1
  uint8_t *v11; // r0
  uint32_t *v12; // r3
  int *v13; // r0
  unsigned int v14; // r3
  int v15; // r3
  unsigned int *v16; // r2
  uint8_t *v17; // r0
  uint32_t *v18; // r1
  int v19; // r0
  unsigned int *v20; // r2
  uint32_t *v21; // r3
  uint32_t *v22; // r3
  uint32_t *v23; // r2
  unsigned int *v24; // r0
  unsigned int *v25; // r1
  uint32_t *v26; // r0
  uint32_t *v27; // r2

  if ( *((uint8_t *)off_103264 + 2) )
  {
    *(uint32_t *)off_1032BC = *(uint32_t *)off_1032BC & 0xFFFFF3FF | 0x800;
  }
  else
  {
    v0 = off_103268;
    v1 = off_10326C;
    *(uint8_t *)off_103268 = 80;
    v0[1] = 78;
    while ( !*v1 )
      ;
    v2 = off_103274;
    *(uint32_t *)off_103270 &= ~2u;
    if ( (*v2 & 1) == 0 )
    {
      rf_cal_read_0(1);
      v27 = off_1032D0;
      *(uint32_t *)off_1032D8 = *(uint32_t *)off_1032D8 & 0xFFFFFFF0 | 4;
      *v27 |= 2u;
    }
    v3 = off_103278;
    *(uint32_t *)off_10326C = 1;
    v4 = *v3 & 0xC0;
    if ( v4 == 192 )
    {
      v25 = (unsigned int *)off_1032D0;
      v26 = off_1032D4;
      *(uint32_t *)off_10327C = *(uint32_t *)off_10327C & 0xC3FFFFFF | 0x30000000;
      *v25 = *v25 & 0xFE3FFFFF | 0x400000;
      *v26 |= 0x78000u;
      *v25 &= ~2u;
    }
    v5 = (unsigned int *)off_10327C;
    v6 = (unsigned int *)off_103280;
    v7 = off_103284;
    v8 = off_103288;
    v9 = off_10328C;
    *(uint32_t *)off_10327C = *(uint32_t *)off_10327C & 0xFF0FFFFF | 0xC00000;
    *v5 = *v5 & 0xFFFFFF0F | 0x60;
    *v6 &= ~1u;
    *v7 = *v7 & 0xFFFFE0FF | 0x1000;
    *v8 |= 8u;
    *v8 &= 0xFFFFFFFC;
    *(unsigned int *)((char *)v5 + 0xFFFFFFB8) &= ~0x40000u;
    *v8 &= ~4u;
    v10 = off_103290;
    *v6 = *v6 & 0xFFFFF3FF | 0x800;
    v11 = (uint8_t *)off_103294;
    v7 -= 1999;
    *v9 &= 0xFFFF3FFF;
    v5 -= 2068;
    *v7 = *v7 & 0xFFFFFF | 0x10000000;
    *v5 = *v5 & 0xFFFC00FF | (*v11 << 8);
    v12 = off_103298;
    v7 -= 73;
    *v10 |= 0x80000000;
    *v7 |= 0x1000u;
    *v5 &= ~0x40000u;
    v13 = (int *)off_10329C;
    *v10 &= ~0x40000000u;
    *v12 &= ~2u;
    *v12 |= 1u;
    v7[2083] = 20058;
    *v13 = *v13 & 0x3FFFFFF | 0x7C000000;
    v14 = *v13 & 0xFC07FFFF;
    if ( v4 == 192 )
      v15 = v14 | 0x3D00000;
    else
      v15 = v14 | 0x3E00000;
    *v13 = v15;
    if ( (*(uint32_t *)off_1032A0 & 0x20) != 0 )
    {
      v22 = off_1032C4;
      v23 = off_1032C8;
      v24 = (unsigned int *)off_1032CC;
      *((uint8_t *)off_1032A4 + 1) = 1;
      *v22 &= 0xFFF0FFFF;
      *v22 &= 0xFF0FFFFF;
      *v23 &= ~0x8000u;
      *v24 = *v24 & 0xFFFFFC7F | 0x200;
    }
    else
    {
      *((uint8_t *)off_1032A4 + 1) = 0;
    }
    v16 = (unsigned int *)off_1032A8;
    v17 = (uint8_t *)off_1032AC;
    v18 = off_1032B0;
    *(uint32_t *)off_1032A8 = *(uint32_t *)off_1032A8 & 0x3FFFFFF | 0xA0000000;
    v19 = v17[362];
    *v16 = *v16 & 0xFC0FFFFF | 0x1800000;
    *v18 |= 0x10u;
    if ( v19 )
      *(v16 - 8824) = *(v16 - 8824) & 0xFFFFFFC0 | 0x2C;
    v20 = (unsigned int *)off_1032B8;
    *(uint32_t *)off_1032B4 &= 0xFFFFFFC7;
    *v20 = *v20 & 0xFFFFFFFC | 2;
  }
  v21 = off_1032C0;
  *(uint32_t *)off_1032C0 |= 0xC000u;
  *v21 |= 0x30000u;
}

