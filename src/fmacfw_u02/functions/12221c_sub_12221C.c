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

extern uint32_t dword_122294;
extern uint32_t dword_122298;
extern uint32_t dword_12229C;
extern uint32_t off_122290;
extern uint32_t off_1222A0;
extern uint32_t off_1222A4;
extern uint32_t off_1222AC;
extern uint32_t off_1222B0;
extern uint32_t off_1222A8;
extern uint32_t off_1222B4;
extern uint32_t off_1222B8;
extern uint32_t dword_1222BC;

// mmio_masked_write @ 0x12221c, size 114 bytes
int  mmio_masked_write(int a1)
{
  int v1; // r4
  int *v2; // r2
  int v3; // r5
  int v4; // r6
  int *v5; // r0
  int *v6; // r1
  int v7; // t1
  int v8; // zf
  int v9; // r3
  uint8_t *v10; // r4
  uint32_t *v11; // r5
  uint8_t *v12; // r0
  uint8_t *v13; // r1
  int *v14; // r2
  int v15; // r1
  uint32_t *v16; // r2
  int v17; // r0

  v2 = (int *)dword_122294;
  v3 = dword_122298;
  v4 = dword_12229C;
  v5 = (int *)(a1 + 444);
  v6 = (int *)(*(uint32_t *)off_122290 + 4);
  do
  {
    v7 = *v6++;
    v9 = v7 & v3;
    v8 = (v7 & v3) == 0;
    if ( (v7 & v3) != 0 )
      v1 = *v5;
    else
      v9 = *v5;
    if ( !v8 )
    {
      v1 &= 0xFFFu;
      v9 |= v1;
    }
    *v2++ = v9;
    ++v5;
  }
  while ( v2 != (int *)v4 );
  v10 = off_1222A0;
  v11 = off_1222A4;
  write_phy_config(*((uint8_t *)off_1222A0 + 410));
  v12 = off_1222AC;
  v13 = off_1222B0;
  *((uint8_t *)off_1222A8 + 9) = v10[410];
  v14 = (int *)off_1222B4;
  *v12 = 1;
  *v13 = 1;
  v15 = *v14;
  v16 = off_1222B8;
  v17 = dword_1222BC;
  v15 += 15000;
  *v11 = v15;
  *v16 = 15000;
  v16[1] = 15000;
  v16[2] = 15000;
  v16[3] = 15000;
  v16[4] = 15000;
  v16[5] = 15000;
  return event_dispatch(v17, v15, v16);
}

