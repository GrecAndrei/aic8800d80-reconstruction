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

extern uint32_t dword_126428;
extern uint32_t off_126424;
extern uint32_t off_12642C;
extern uint32_t off_126450;
extern uint32_t dword_126454;
extern uint32_t off_126434;
extern uint32_t off_126430;
extern uint32_t off_126458;
extern uint32_t off_126438;
extern uint32_t off_12643C;
extern uint32_t off_126440;
extern uint32_t off_126444;
extern uint32_t off_126448;
extern uint32_t off_12644C;

// sub_12632C @ 0x12632c, size 248 bytes
int sub_12632C()
{
  int v0; // r0
  int v1; // r4
  uint8_t *v2; // r8
  uint16_t *v3; // r5
  int v4; // r9
  int v5; // r1
  uint8_t *v6; // r5
  uint16_t *v7; // r4
  uint32_t *v8; // r0
  uint32_t *v9; // r2
  uint32_t *v10; // r2
  unsigned int *v11; // r4
  int v12; // r1
  int result; // r0
  unsigned int v14; // r3
  int *v15; // r3
  int v16; // r3
  uint32_t *v17; // r3

  v0 = dword_126428;
  *(uint8_t *)off_126424 = 0;
  sub_11F504(v0);
  v1 = *(uint8_t *)off_12642C;
  if ( v1 == 1 )
  {
    v17 = off_126450;
    *(uint32_t *)off_126450 &= ~0x100u;
    *v17 &= ~0x200u;
    *v17 &= ~0x400u;
    goto LABEL_15;
  }
  if ( *(uint8_t *)off_12642C )
  {
LABEL_15:
    sub_11F504(
      dword_126454,
      *(uint8_t *)off_126434,
      *(uint16_t *)off_126430,
      *((uint8_t *)off_126430 + 2),
      *((char *)off_126430 + 3),
      *((char *)off_126430 + 4),
      *((char *)off_126430 + 5));
    goto LABEL_7;
  }
  v2 = off_126458;
  if ( *(uint8_t *)off_126458 )
  {
    v3 = (uint16_t *)off_126430;
    v4 = dword_126454;
    v5 = *(uint8_t *)off_12642C;
    do
    {
      sub_11F504(
        v4,
        v5 + 1,
        v3[4 * v5],
        LOBYTE(v3[4 * v5 + 1]),
        SHIBYTE(v3[4 * v5 + 1]),
        SLOBYTE(v3[4 * v5 + 2]),
        SHIBYTE(v3[4 * v5 + 2]));
      v5 = (uint8_t)++v1;
    }
    while ( (uint8_t)*v2 > (unsigned int)(uint8_t)v1 );
  }
  v6 = off_126434;
  v7 = off_126438;
  sub_100200((int *)off_126430, 0, 8u);
  v8 = off_12643C;
  v9 = off_126440;
  *v6 = 1;
  *v2 = 1;
  *v7 = 0;
  *v8 = 0;
  *v9 = 0;
LABEL_7:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_126444 = 1;
  }
  v10 = off_126448;
  v11 = (unsigned int *)off_12644C;
  v12 = *(uint32_t *)off_126448;
  result = *(uint32_t *)off_126448 + 1;
  v14 = *(uint32_t *)off_12644C & 0xFFFFFBFF;
  *(uint32_t *)off_126448 = result;
  *v11 = v14;
  if ( result )
  {
    v15 = (int *)off_126444;
    *v10 = v12;
    v16 = *v15;
    if ( !v12 )
    {
      if ( v16 )
        __enable_irq();
    }
  }
  return result;
}

