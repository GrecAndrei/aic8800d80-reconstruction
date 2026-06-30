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

extern uint32_t off_108080;
extern uint32_t off_10807C;
extern uint32_t dword_108084;
extern uint32_t off_10808C;
extern uint32_t dword_108088;

// sub_108040 @ 0x108040, size 60 bytes
int sub_108040()
{
  unsigned int *v0; // r5
  unsigned int v1; // r4
  int v2; // r6
  int result; // r0
  uint32_t *v4; // r2

  v0 = (unsigned int *)off_108080;
  v1 = *(uint32_t *)off_108080;
  v2 = *(uint32_t *)off_10807C >> 20;
  result = sub_12EEF8(1, dword_108084);
  v4 = off_10808C;
  *v0 = dword_108088 & (((HIWORD(v1) & 0xFFF) + v2) << 16) | *v0 & 0xF000FFFF;
  *v4 |= 0x800000u;
  return result;
}

