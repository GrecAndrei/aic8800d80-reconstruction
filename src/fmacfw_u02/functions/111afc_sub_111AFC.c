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

extern uint32_t off_111B58;
extern uint32_t off_111B54;
extern uint32_t off_111B5C;
extern uint32_t off_111B60;

// sub_111AFC @ 0x111afc, size 88 bytes
int  sub_111AFC(int result, int a2)
{
  int *v2; // r4
  int v3; // r5
  int v4; // r3
  char v5; // r2
  uint32_t *v6; // r2

  v2 = (int *)off_111B58;
  v3 = *(uint32_t *)off_111B54;
  v4 = *(uint32_t *)off_111B58;
  *((uint16_t *)off_111B5C + 5) = a2;
  if ( a2 == 64 )
    v5 = -54;
  else
    v5 = -50;
  *(uint32_t *)v4 = -1073741824;
  *(uint32_t *)(v4 + 4) = v3;
  *(uint8_t *)(v4 + 3) = v5;
  *(uint16_t *)v4 = a2;
  if ( result && a2 )
  {
    result = sub_143770(v3, result, a2);
    v4 = *v2;
  }
  v6 = off_111B60;
  *(uint8_t *)(v4 + 3) &= 0x3Fu;
  v6[578] = v6[578];
  v6[581] = v4;
  v6[576] |= 0x84000000;
  return result;
}

