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

extern uint32_t off_108228;
extern uint32_t off_108224;
extern uint32_t dword_10822C;
extern uint32_t off_108234;
extern uint32_t dword_108230;

// read_status_high @ 0x1081e8, size 60 bytes
int read_status_high()
{
  unsigned int *v0; // r5
  unsigned int v1; // r4
  int v2; // r6
  int result; // r0
  uint32_t *v4; // r2

  v0 = (unsigned int *)off_108228;
  v1 = *(uint32_t *)off_108228;
  v2 = *(uint32_t *)off_108224 >> 20;
  result = check_status_bits(1, dword_10822C);
  v4 = off_108234;
  *v0 = dword_108230 & (((HIWORD(v1) & 0xFFF) + v2) << 16) | *v0 & 0xF000FFFF;
  *v4 |= 0x800000u;
  return result;
}

