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

extern uint32_t off_11C408;
extern uint32_t off_11C404;
extern uint32_t dword_11C40C;

// sub_11C3E8 @ 0x11c3e8, size 26 bytes
int  sub_11C3E8(int a1)
{
  uint32_t *v1; // r3
  int v2; // r1

  v1 = off_11C408;
  v2 = *((uint32_t *)off_11C404 + 4);
  *((uint32_t *)off_11C408 + 1) = dword_11C40C;
  v1[2] = a1;
  return sub_124BFC(v1, v2 + 5000);
}

