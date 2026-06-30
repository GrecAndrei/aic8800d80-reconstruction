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

extern uint32_t off_11F648;
extern uint32_t dword_11F64C;
extern uint32_t dword_11F650;

// sub_11F5E4 @ 0x11f5e4, size 98 bytes
int sub_11F5E4()
{
  uint8_t *v0; // r8
  int v1; // r4
  int v2; // r7
  int v3; // r6
  int result; // r0

  v0 = off_11F648;
  sub_100200((int *)off_11F648, 0, 0x18u);
  sub_12D100(v0);
  v1 = dword_11F64C;
  v2 = dword_11F650;
  sub_12D100(v0 + 8);
  v3 = v1 + 5280;
  do
  {
    sub_100200((int *)v1, 0, 0x528u);
    *(uint32_t *)(v1 + 52) = v2;
    *(uint32_t *)(v1 + 56) = v1;
    *(uint8_t *)(v1 + 106) = 5;
    *(uint8_t *)(v1 + 109) = 127;
    *(uint8_t *)(v1 + 110) = 127;
    v1 += 1320;
    result = sub_12D108(v0);
  }
  while ( v1 != v3 );
  v0[16] = -1;
  return result;
}

