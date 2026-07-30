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

extern uint32_t off_121668;
extern uint32_t off_121640;
extern uint32_t dword_121660;
extern uint32_t off_12163C;
extern uint32_t off_121630;
extern uint32_t dword_121648;
extern uint32_t dword_121644;
extern uint32_t dword_121634;
extern uint32_t dword_121638;
extern uint32_t off_12164C;
extern uint32_t off_121650;
extern uint32_t off_121654;
extern uint32_t off_121658;
extern uint32_t off_121664;
extern uint32_t dword_121670;
extern uint32_t dword_12166C;
extern uint32_t off_12165C;

// sub_121418 @ 0x121418, size 534 bytes
int  sub_121418(uint8_t *a1)
{
  unsigned int v1; // r7
  int v2; // r5
  int v4; // r6
  uint32_t *v5; // r2
  uint16_t *v6; // r7
  uint32_t *v7; // r3
  uint8_t *v8; // r3
  uint32_t *v9; // r3
  int v10; // r0
  int v11; // r1
  uint32_t *v12; // r3
  uint32_t *v13; // r2
  uint8_t v15; // r6
  uint32_t *v16; // r2
  int v17; // r1
  uint32_t *v18; // r3
  uint32_t *v19; // r3
  uint32_t *v20; // r3
  uint32_t *v21; // r3
  uint32_t *v22; // r3
  int v23; // r5

  v1 = a1[1];
  v2 = a1[41];
  if ( v1 == 255 )
  {
    if ( a1[40] == 5 )
    {
      v23 = HIBYTE(*(uint32_t *)off_121668) - 3 + *a1 + 2 * v2;
      v4 = (uint8_t)v23;
      fmac_init_struct(a1, v23);
      return v4;
    }
    v15 = *a1;
    v16 = off_121640;
    v17 = dword_121660;
    *(uint32_t *)off_12163C = -1;
    *v16 = -1;
    v4 = (uint8_t)(v15 + 4 * v2);
    feature_guard_check(256, v17);
    fmac_init_struct(a1, v4);
  }
  else
  {
    if ( **(int16_t **)off_121630 < 0 && v1 > 0x23 )
      sub_12F46C(dword_121648, dword_121644, 1424);
    v4 = (uint8_t)(v1 + 16);
    feature_guard_check(256, dword_121634);
    sub_11F298((int)a1, v1 + 16);
    v5 = off_121640;
    v6 = (uint16_t *)(dword_121638 + 696 * v1);
    *(uint32_t *)off_12163C = v6[19] | (v6[20] << 16);
    *v5 = v6[21];
  }
  switch ( a1[40] )
  {
    case 0u:
      v18 = off_12164C;
      *(uint32_t *)off_12164C = *((uint32_t *)a1 + 2);
      v18[1] = *((uint32_t *)a1 + 3);
      v18[2] = *((uint32_t *)a1 + 4);
      v18[3] = *((uint32_t *)a1 + 5);
      v10 = 256;
      v11 = 0;
      break;
    case 1u:
      v7 = off_12164C;
      *(uint32_t *)off_12164C = *((uint32_t *)a1 + 2);
      v7[1] = *((uint32_t *)a1 + 3);
      v7[2] = *((uint32_t *)a1 + 4);
      v8 = *(uint8_t **)off_121650;
      *(uint32_t *)off_121654 = *((uint32_t *)a1 + 5);
      if ( (*v8 & 1) != 0 )
      {
        v9 = off_121658;
        *(uint32_t *)off_121658 = *((uint32_t *)a1 + 6);
        v9[1] = *((uint32_t *)a1 + 7);
        v9[2] = *((uint32_t *)a1 + 8);
        v9[3] = *((uint32_t *)a1 + 9);
      }
      else
      {
        *(uint32_t *)off_121664 &= ~1u;
      }
      v10 = 512;
      v11 = 4096;
      break;
    case 2u:
      v12 = off_12164C;
      *(uint32_t *)off_12164C = *((uint32_t *)a1 + 2);
      v12[1] = *((uint32_t *)a1 + 3);
      v12[2] = *((uint32_t *)a1 + 4);
      v12[3] = *((uint32_t *)a1 + 5);
      v10 = 768;
      v11 = 0;
      break;
    case 3u:
      v10 = 256;
      v11 = 4096;
      goto LABEL_22;
    case 4u:
      v22 = off_12164C;
      *(uint32_t *)off_12164C = *((uint32_t *)a1 + 2);
      v22[1] = *((uint32_t *)a1 + 3);
      v22[2] = *((uint32_t *)a1 + 4);
      v22[3] = *((uint32_t *)a1 + 5);
      v10 = 1024;
      v11 = 4096;
      goto LABEL_20;
    case 6u:
      v10 = 1280;
      v11 = 0;
      goto LABEL_22;
    case 7u:
      v10 = 1280;
      goto LABEL_19;
    case 8u:
      v10 = 768;
LABEL_19:
      v19 = off_12164C;
      *(uint32_t *)off_12164C = *((uint32_t *)a1 + 2);
      v19[1] = *((uint32_t *)a1 + 3);
      v19[2] = *((uint32_t *)a1 + 4);
      v19[3] = *((uint32_t *)a1 + 5);
      v11 = 0x2000;
LABEL_20:
      v20 = off_121658;
      *(uint32_t *)off_121658 = *((uint32_t *)a1 + 6);
      v20[1] = *((uint32_t *)a1 + 7);
      v20[2] = *((uint32_t *)a1 + 8);
      v20[3] = *((uint32_t *)a1 + 9);
      break;
    default:
      if ( **(int16_t **)off_121630 < 0 )
        sub_12F46C(dword_121670, dword_12166C, 159);
      v10 = 0;
      v11 = 4096;
LABEL_22:
      v21 = off_12164C;
      *(uint32_t *)off_12164C = *((uint32_t *)a1 + 2);
      v21[1] = *((uint32_t *)a1 + 3);
      v21[2] = *((uint32_t *)a1 + 4);
      v21[3] = *((uint32_t *)a1 + 5);
      break;
  }
  v13 = off_12165C;
  *(uint32_t *)off_12165C = (16 * v2) | (4 * a1[42]) | v10 | (v4 << 16) | v11 | 0x40000000;
  while ( (*v13 & 0x40000000) != 0 )
    ;
  return v4;
}

