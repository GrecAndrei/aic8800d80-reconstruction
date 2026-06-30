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

extern uint32_t dword_12EE98;
extern uint32_t off_12EE9C;

// sub_12EE6C @ 0x12ee6c, size 42 bytes
int  sub_12EE6C(int a1, uint32_t *a2, int16_t a3, int16_t a4)
{
  sub_12E948(dword_12EE98, *a2);
  *(uint32_t *)off_12EE9C = *a2;
  sub_12C8D0(1029, a4, a3);
  return 0;
}

