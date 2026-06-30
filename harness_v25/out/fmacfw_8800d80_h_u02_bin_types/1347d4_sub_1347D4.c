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

extern uint32_t off_134910;
extern uint32_t dword_134914;
extern uint32_t off_134918;
extern uint32_t off_13491C;
extern uint32_t off_134924;
extern uint32_t off_134920;
extern uint32_t off_134928;

// sub_1347D4 @ 0x1347d4, size 314 bytes
int sub_1347D4()
{
  uint16_t *v0; // r6
  int v1; // r4
  int v2; // r5
  int16_t v3; // r7
  uint32_t *v4; // r1
  int *v5; // r2
  int *v6; // r3
  unsigned int v7; // r2
  int result; // r0
  uint32_t *v9; // r12
  int *v10; // r0
  int v11; // r1

  v0 = off_134910;
  v1 = *((uint32_t *)off_134910 + 2);
  sub_12EB90(256, dword_134914);
  v2 = sub_12C7EC(6149, 13, 6, 6u);
  if ( *((uint8_t *)v0 + 4) )
    v3 = 0;
  else
    v3 = v0[6];
  *(uint8_t *)(v1 + 149) = 0;
  sub_124CF4(v1 + 152);
  v6 = *((int **)off_134918 + 2);
  if ( !v6 )
  {
LABEL_14:
    sub_10D0BC(0, (int)v4, (int)v5);
    goto LABEL_15;
  }
  v4 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !*((uint8_t *)v6 + 106) )
      {
        if ( !*((uint8_t *)v6 + 108) )
          goto LABEL_8;
        v4 = (uint32_t *)((char *)v4 + 1);
        if ( (int *)v1 == v6 )
          goto LABEL_8;
        break;
      }
      if ( (int *)v1 == v6 )
        goto LABEL_8;
      if ( *((uint8_t *)v6 + 108) )
        break;
      v6 = (int *)*v6;
      if ( !v6 )
      {
LABEL_13:
        v5 = *(int **)off_13491C;
        if ( *(int *)off_13491C < 0 && v4 == (uint32_t *)1 )
        {
          v4 = off_134924;
          *((uint8_t *)off_134920 + 2) = (uint8_t)v6;
          v5 = (int *)off_134928;
          *v4 |= 0x80000000;
          *v5 = (HIWORD(*v5) << 16) | 0x5DC;
        }
        goto LABEL_14;
      }
    }
    v7 = *((uint16_t *)v6 + 208);
    if ( v7 <= 0x1387 )
      break;
LABEL_8:
    v6 = (int *)*v6;
    if ( !v6 )
      goto LABEL_13;
  }
  if ( *(int *)off_13491C < 0 && v4 == (uint32_t *)1 )
  {
    v9 = off_134924;
    *((uint8_t *)off_134920 + 2) = 0;
    v10 = (int *)off_134928;
    *v9 |= 0x80000000;
    v11 = (HIWORD(*v10) << 16) | 0x5DC;
    *v10 = v11;
    sub_10D0BC(v7 | (*((uint8_t *)v6 + 413) << 16) | 0x80000000, v11, v7);
  }
  else
  {
    sub_10D0BC(v7 | (*((uint8_t *)v6 + 413) << 16) | 0x80000000, (int)v4, v7);
  }
LABEL_15:
  sub_12063C((int *)v1, 0, 0);
  result = sub_1346C0(v1);
  *(uint16_t *)v2 = v3;
  *(uint8_t *)(v2 + 2) = *(uint8_t *)(v1 + 107);
  *(uint8_t *)(v2 + 4) = *((uint8_t *)v0 + 33);
  *(uint32_t *)v0 = v2 - 12;
  return result;
}

