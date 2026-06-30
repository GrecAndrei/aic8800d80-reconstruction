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

extern uint32_t off_11C1CC;

// sub_11C1B4 @ 0x11c1b4, size 24 bytes
void  sub_11C1B4(int a1)
{
  uint8_t *v1; // r4

  v1 = off_11C1CC;
  *(uint8_t *)off_11C1CC = 1;
  sub_11EABC(a1);
  *v1 = 0;
  sub_11B898();
}

