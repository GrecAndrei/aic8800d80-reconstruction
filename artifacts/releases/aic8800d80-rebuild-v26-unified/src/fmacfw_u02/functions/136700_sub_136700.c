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

extern uint32_t off_13672C;
extern uint32_t dword_136730;

// sub_136700 @ 0x136700, size 42 bytes
uint32_t *sub_136700()
{
  uint8_t *v0; // r4
  int v1; // r3

  v0 = off_13672C;
  sub_100200((int *)off_13672C, 0, 0x24u);
  v1 = dword_136730;
  v0[15] = 3;
  *((uint32_t *)v0 + 4) = 20000;
  *((uint32_t *)v0 + 6) = v1;
  v0[12] = 0;
  return sub_12CD34(7u, 0);
}

