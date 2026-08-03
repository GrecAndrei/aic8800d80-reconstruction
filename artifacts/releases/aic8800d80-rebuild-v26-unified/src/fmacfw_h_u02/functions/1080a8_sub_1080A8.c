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

extern uint32_t off_1080E8;
extern uint32_t off_1080E4;
extern uint32_t dword_1080EC;
extern uint32_t off_1080F4;
extern uint32_t dword_1080F0;

// sub_1080A8 @ 0x1080a8, size 60 bytes
int sub_1080A8()
{
  unsigned int *v0; // r5
  unsigned int v1; // r4
  int v2; // r6
  int result; // r0
  uint32_t *v4; // r2

  v0 = (unsigned int *)off_1080E8;
  v1 = *(uint32_t *)off_1080E8;
  v2 = *(uint32_t *)off_1080E4 >> 20;
  result = sub_12EB90(1, dword_1080EC);
  v4 = off_1080F4;
  *v0 = dword_1080F0 & (((HIWORD(v1) & 0xFFF) + v2) << 16) | *v0 & 0xF000FFFF;
  *v4 |= 0x800000u;
  return result;
}

