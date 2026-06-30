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

extern uint32_t dword_13F6E8;
extern uint32_t off_13F6E4;
extern uint32_t dword_13F6F0;
extern uint32_t dword_13F6EC;

// sub_13F654 @ 0x13f654, size 142 bytes
int  sub_13F654(int a1)
{
  int v1; // r4
  int v2; // r3
  int result; // r0
  char v4; // r3

  v1 = *(uint32_t *)(dword_13F6E8 + 696 * a1 + 340);
  if ( **(int16_t **)off_13F6E4 < 0 && !v1 )
    sub_12F32C(dword_13F6F0, dword_13F6EC, 2194);
  sub_13E1E8(v1);
  v2 = *(uint16_t *)(v1 + 184);
  *(uint16_t *)(v1 + 136) = (v2 - 1) & ~(uint16_t)((v2 - 1) >> 31);
  *(uint16_t *)(v1 + 138) = (v2 - 2) & ~(uint16_t)((v2 - 2) >> 31);
  *(uint16_t *)(v1 + 140) = (v2 - 3) & ~(uint16_t)((v2 - 3) >> 31);
  *(uint32_t *)(v1 + 148) = 0x10000;
  *(uint16_t *)(v1 + 190) = -1;
  *(uint16_t *)(v1 + 142) = 0;
  *(uint8_t *)(v1 + 166) = 0;
  result = sub_13F490(v1, 1);
  v4 = *(uint8_t *)(v1 + 184);
  *(uint8_t *)(v1 + 154) = 0;
  *(uint8_t *)(v1 + 164) = v4 - 4;
  *(uint16_t *)(v1 + 152) = 5;
  return result;
}

