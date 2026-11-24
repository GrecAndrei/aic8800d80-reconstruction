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


extern uint32_t dword_102A14;
extern uint32_t off_102A08;
extern uint32_t off_102A0C;
extern uint32_t off_102A10;

// sub_102970 @ 0x102970, size 152 bytes
int  sub_102970(uint16_t *a1, int a2)
{
  uint8_t *v3; // r0
  int v4; // r1
  unsigned int v5; // r1
  unsigned int v6; // r2
  int a5; // r3
  int result; // r0
  int v9; // r1
  int v10; // r3

  if ( a2 )
    return sub_12E948("\x9B\x87%s: radio %d does not exist\n", aPhySetChannel, a2);
  if ( *(uint8_t *)off_102A08 )
    goto LABEL_4;
  v3 = (uint8_t *)off_102A10;
  v4 = *((uint16_t *)off_102A10 + 18);
  *(uint32_t *)off_102A0C &= ~0x200u;
  if ( v4 != *a1 )
    goto LABEL_4;
  a5 = *((uint8_t *)a1 + 9);
  v5 = a1[1];
  if ( v3[45] != a5 )
  {
    v6 = a1[2];
    goto LABEL_5;
  }
  v6 = a1[2];
  if ( *((uint16_t *)v3 + 19) != v5
    || *((uint16_t *)v3 + 20) != v6
    || *((uint16_t *)v3 + 21) != a1[3] )
  {
    goto LABEL_5;
  }
  if ( sub_12CD48(7u) == 1 || sub_12CD48(6u) == 3 )
  {
LABEL_4:
    v5 = a1[1];
    v6 = a1[2];
    LOBYTE(a5) = *((uint8_t *)a1 + 9);
LABEL_5:
    sub_101EC0(*(uint8_t *)a1, v5, v6, *((uint8_t *)a1 + 1), a5, 0);
    result = *(uint32_t *)a1;
    v9 = *((uint32_t *)a1 + 1);
    v10 = dword_102A14;
    *(uint32_t *)dword_102A14 = *(uint32_t *)a1;
    *(uint32_t *)(v10 + 4) = v9;
    *(uint16_t *)(v10 + 8) = a1[4];
    return result;
  }
  return sub_12E948("\x9D\x87%s: Setting same channel, do nothing\n", aPhySetChannel);
}
