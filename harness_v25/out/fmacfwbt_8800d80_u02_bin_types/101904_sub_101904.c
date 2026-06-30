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

extern uint32_t dword_101934;
extern uint32_t off_101938;
extern uint32_t off_10193C;
extern uint32_t off_101930;

// sub_101904 @ 0x101904, size 44 bytes
int  sub_101904(int16_t a1)
{
  int v1; // r4
  uint32_t *v2; // r1
  int *v3; // r2
  int result; // r0

  v1 = dword_101934;
  v2 = off_101938;
  v3 = (int *)off_10193C;
  result = a1 & 0x7FF;
  *(uint32_t *)off_101930 = *(uint32_t *)off_101930 & dword_101934 | result;
  *v2 &= v1;
  *v3 = ~(~((unsigned int)*v3 >> 11) << 11);
  return result;
}

