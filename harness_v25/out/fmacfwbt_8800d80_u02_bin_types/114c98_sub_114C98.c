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

extern uint32_t off_114DB8;
extern uint32_t off_114D74;
extern uint32_t off_114D98;
extern uint32_t off_114DA8;
extern uint32_t dword_114DAC;
extern uint32_t off_114DA4;
extern uint32_t off_114DB0;
extern uint32_t dword_114DB4;
extern uint32_t dword_114D7C;
extern uint32_t off_114D78;
extern uint32_t off_114D84;
extern uint32_t off_114D80;
extern uint32_t off_114D88;
extern uint32_t off_114D8C;
extern uint32_t off_114D94;
extern uint32_t off_114D9C;
extern uint32_t off_114D90;
extern uint32_t off_114DA0;

// sub_114C98 @ 0x114c98, size 218 bytes
// Doc: sub_1214C98 [util]: stack-saving helper with argument byte fetch and null check
// sub_1214C98 [util]: stack-saving helper with argument byte fetch and null check
int  sub_114C98(int a1, int a2, int a3, int a4, char a5)
{
  uint8_t *v5; // r8
  uint32_t *v8; // r7
  int v9; // r0
  uint32_t *v10; // r2
  uint8_t *v11; // r3
  unsigned int *v12; // r2
  uint32_t *v13; // r6
  uint32_t *v14; // r5
  uint32_t *v15; // r4
  unsigned int v17; // r3
  unsigned int v18; // r1
  unsigned int v19; // r1
  uint8_t *v20; // r3
  uint32_t *v21; // r4
  uint32_t *v22; // r3
  uint8_t *v23; // r2

  if ( a1 )
    return 1;
  if ( a2 )
    return 2;
  v5 = off_114DB8;
  if ( *(uint8_t *)off_114DB8 )
  {
    v8 = off_114D74;
  }
  else
  {
    v22 = off_114D98;
    v8 = off_114D74;
    *(uint32_t *)off_114DA8 = off_114D74;
    *v22 = 196608;
    sub_12ECB0(dword_114DAC, 38, 196608);
    v23 = off_114DA4;
    *(uint32_t *)(*((uint32_t *)off_114DB0 + 2) + 216) = dword_114DB4;
    v23[806] = -4;
    *v5 = 1;
  }
  v9 = dword_114D7C;
  *(uint32_t *)off_114D78 = 196608;
  sub_12ECB0(v9, 38, 196608);
  v10 = off_114D84;
  *(uint32_t *)off_114D80 = a3;
  v11 = off_114D88;
  *v10 = a4;
  v12 = (unsigned int *)off_114D8C;
  *v11 = a5;
  v13 = off_114D94;
  v14 = off_114D98;
  v15 = off_114D9C;
  v17 = *v12 & 0xFFFFFFFC;
  *(uint32_t *)off_114D90 = 0;
  *v8 = 0;
  *v12 = v17;
  v18 = *v12;
  v13[3] = 0;
  *v12 = v18 & 0xFFFFFFF3;
  *v14 = 4980736;
  *v15 = 0x10000;
  *v14 = 0x4000000;
  *v15 = 0x4000000;
  v19 = *v12;
  v20 = off_114DA0;
  v21 = off_114DA4;
  *((uint8_t *)off_114DA0 + 16) = 0;
  *v12 = v19 & 0xFFCFFFFF;
  v20[36] = 0;
  v20[56] = 0;
  v20[76] = 0;
  v20[96] = 0;
  v20[116] = 0;
  v21[1] = 64;
  return 0;
}

