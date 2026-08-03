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

extern uint32_t dword_11CABC;
extern uint32_t off_11CAC0;
extern uint32_t dword_11CAC4;

// sub_11CA94 @ 0x11ca94, size 40 bytes
int sub_11CA94()
{
  int result; // r0
  uint32_t *v1; // r3

  sub_100200((int *)dword_11CABC, 0, 0xCu);
  result = sub_11E1E4(2);
  v1 = off_11CAC0;
  *(uint32_t *)off_11CAC0 = dword_11CAC4;
  v1[2] = v1 + 5;
  v1[4] = 0;
  v1[1] = 0;
  return result;
}

