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

extern uint32_t off_10D618;
extern uint32_t off_10D620;
extern uint32_t off_10D61C;
extern uint32_t dword_10D624;

// sub_10D5D4 @ 0x10d5d4, size 68 bytes
int sub_10D5D4()
{
  unsigned int *v0; // r2
  unsigned int v1; // r3
  int result; // r0
  uint32_t *v3; // r3

  v0 = (unsigned int *)off_10D618;
  v1 = *(uint32_t *)off_10D618;
  if ( (*(uint32_t *)off_10D618 & 1) == 0 )
  {
    v1 = v1 & 0xFFFFFCFE | 0x101;
    result = 17;
    *((uint32_t *)off_10D618 + 4) = 0;
    v0[5] = 0;
    v0[1] = 17;
    *v0 = v1;
  }
  if ( (v1 & 0x4000) == 0 )
    *(uint32_t *)off_10D618 = v1 | 0x4040;
  v3 = off_10D620;
  *(uint32_t *)(*((uint32_t *)off_10D61C + 2) + 148) = dword_10D624;
  *v3 = 0x200000;
  return result;
}

