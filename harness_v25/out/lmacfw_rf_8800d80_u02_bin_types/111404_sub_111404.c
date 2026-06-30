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

extern uint32_t off_111460;
extern uint32_t off_11145C;
extern uint32_t off_111464;
extern uint32_t off_111468;

// sub_111404 @ 0x111404, size 88 bytes
int  sub_111404(int result, int a2)
{
  int *v2; // r4
  int v3; // r5
  int v4; // r3
  char v5; // r2
  uint32_t *v6; // r2

  v2 = (int *)off_111460;
  v3 = *(uint32_t *)off_11145C;
  v4 = *(uint32_t *)off_111460;
  *((uint16_t *)off_111464 + 5) = a2;
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
    result = sub_1282E8(v3, result, a2);
    v4 = *v2;
  }
  v6 = off_111468;
  *(uint8_t *)(v4 + 3) &= 0x3Fu;
  v6[578] = v6[578];
  v6[581] = v4;
  v6[576] |= 0x84000000;
  return result;
}

