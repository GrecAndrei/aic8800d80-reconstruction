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

extern uint32_t off_11D6E0;

// sub_11D6BC @ 0x11d6bc, size 34 bytes
int sub_11D6BC()
{
  uint8_t *v0; // r4
  int v1; // r0
  char v2; // r0

  v0 = off_11D6E0;
  sub_11DEB0();
  v1 = sub_12D100(v0);
  v2 = sub_12F3F0(v1) - 1;
  v0[11] = v2;
  v0[10] = v2;
  return sub_139BB4();
}

