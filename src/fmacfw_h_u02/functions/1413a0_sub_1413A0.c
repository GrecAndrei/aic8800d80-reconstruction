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

extern uint32_t off_141498;
extern uint32_t dword_141494;
extern uint32_t dword_1414A8;
extern uint32_t dword_1414A0;
extern uint32_t dword_1414A4;
extern uint32_t dword_14149C;

// sub_1413A0 @ 0x1413a0, size 244 bytes
void sub_1413A0()
{
  int16_t **v0; // r6
  int v1; // r3
  int v2; // r5
  unsigned int v3; // r3
  int v4; // r4
  int v5; // r6
  uint32_t *v6; // r1
  int v7; // r4
  unsigned int v8; // r3
  unsigned int v9; // r3

  v0 = (int16_t **)off_141498;
  v1 = 136 * *(uint32_t *)(dword_141494 + 6480);
  v2 = v1 + 6336 + dword_141494;
  if ( **(int16_t **)off_141498 >= 0 )
  {
    v3 = *(uint8_t *)(v1 + dword_141494 + 6339);
    if ( v3 > 1 )
    {
      if ( v3 != 2 )
        return;
      goto LABEL_4;
    }
LABEL_12:
    sub_140AAC(v2, 1);
    return;
  }
  v7 = dword_141494 + v1;
  if ( *(uint8_t *)(dword_141494 + v1 + 6338) == 5 )
  {
    v9 = *(uint8_t *)(v7 + 6339);
    if ( v9 <= 1 )
      goto LABEL_12;
    if ( v9 != 2 )
    {
LABEL_18:
      sub_12F32C(dword_1414A8, dword_1414A0, 1726);
      return;
    }
  }
  else
  {
    sub_12F32C(dword_1414A4, dword_1414A0, 1714);
    v8 = *(uint8_t *)(v7 + 6339);
    if ( v8 <= 1 )
      goto LABEL_12;
    if ( v8 != 2 )
    {
      if ( **v0 >= 0 )
        return;
      goto LABEL_18;
    }
  }
LABEL_4:
  v4 = dword_141494;
  sub_12CBF4(0xBu, 2);
  v5 = v4 + 6336;
  sub_12D100((uint32_t *)dword_14149C);
  do
  {
    while ( *(uint16_t *)(v4 + 4) != 1 || !sub_140A38((uint16_t *)(v4 + 6), v4 + 28, v2) )
    {
      v4 += 528;
      if ( v4 == v5 )
        goto LABEL_9;
    }
    v6 = (uint32_t *)v4;
    *(uint16_t *)(v4 + 24) = 0;
    *(uint8_t *)(v4 + 22) = 0;
    *(uint16_t *)(v4 + 4) = 2;
    v4 += 528;
    sub_12D108(v5 + 136, v6);
  }
  while ( v4 != v5 );
LABEL_9:
  sub_1409A4(v2, 0);
}

