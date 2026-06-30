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

extern uint32_t dword_12A5CC;

// sub_12A564 @ 0x12a564, size 102 bytes
char * sub_12A564(int a1)
{
  int v1; // r7
  int v2; // r4
  uint8_t *v3; // r6
  int v4; // r3
  int v5; // r4
  char v6; // r1

  v1 = dword_12A5CC;
  v2 = *(uint8_t *)(a1 + 1225);
  v3 = (uint8_t *)(dword_12A5CC + 140 * v2);
  v4 = v3[114];
  v3[115] = 0;
  if ( v4 )
  {
    sub_124E34(140 * v2 + 96 + v1);
    v3[114] = 0;
  }
  sub_129804(v3);
  v5 = v1 + 140 * v2;
  if ( *(uint8_t *)(v5 + 121) )
    v6 = 3;
  else
    v6 = 2;
  return sub_125CD8(*(uint8_t *)(v5 + 113), v6);
}

