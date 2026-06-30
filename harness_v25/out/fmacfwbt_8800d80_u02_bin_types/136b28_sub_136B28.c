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

extern uint32_t dword_136C28;
extern uint32_t dword_136C2C;
extern uint32_t off_136C30;

// sub_136B28 @ 0x136b28, size 256 bytes
uint32_t * sub_136B28(int a1)
{
  uint8_t *v2; // r6
  int v3; // r0
  uint8_t *v4; // r5
  int v5; // r1
  unsigned int v6; // r2
  int *v7; // r3
  uint8_t *v8; // r0
  int v9; // r0
  int v11; // r0

  v2 = (uint8_t *)sub_12CB54(5145, 5, 7, 2u);
  v3 = sub_12CB54(5143, 5, 7, 2u);
  *(uint8_t *)(dword_136C28 + 696 * (*(uint8_t *)(a1 + 107) + 32) + 37) = 0;
  v4 = (uint8_t *)v3;
  sub_136828();
  *v2 = 0;
  v2[1] = *(uint8_t *)(a1 + 107);
  sub_12D470(dword_136C2C, (uint32_t *)v2 - 3);
  v7 = *((int **)off_136C30 + 2);
  if ( v7 )
  {
    v5 = 4999;
    while ( 1 )
    {
      if ( (int *)a1 != v7 )
      {
        v6 = *((uint8_t *)v7 + 108);
        if ( *((uint8_t *)v7 + 108) )
        {
          v6 = *((uint16_t *)v7 + 208);
          if ( v6 <= 0x1387 )
            break;
        }
      }
      v7 = (int *)*v7;
      if ( !v7 )
        goto LABEL_7;
    }
    sub_10D054(v6 | (*((uint8_t *)v7 + 413) << 16) | 0x80000000, 4999, v6);
  }
  else
  {
LABEL_7:
    sub_10D054(0, v5, v6);
  }
  sub_120AB4((int *)a1, 0, 0);
  if ( *(uint8_t *)(a1 + 108) )
  {
    v11 = sub_12CB54(30, 0, 7, 4u);
    *(uint8_t *)(v11 + 2) = 0;
    *(uint8_t *)(v11 + 3) = *(uint8_t *)(a1 + 107);
    sub_12D470(dword_136C2C, (uint32_t *)(v11 - 12));
  }
  if ( *(uint32_t *)(a1 + 72) )
  {
    v8 = (uint8_t *)sub_12CB54(57, 0, 7, 1u);
    *v8 = *(uint8_t *)(a1 + 107);
    sub_12D470(dword_136C2C, (uint32_t *)v8 - 3);
  }
  *v4 = 0;
  v9 = dword_136C2C;
  v4[1] = *(uint8_t *)(a1 + 107);
  sub_12D470(v9, (uint32_t *)v4 - 3);
  sub_13697C();
  return sub_12CF5C(7u, 3);
}

