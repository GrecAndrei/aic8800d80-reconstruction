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

extern uint32_t off_136E08;
extern uint32_t dword_136E0C;

// sub_136DE0 @ 0x136de0, size 40 bytes
int sub_136DE0()
{
  uint16_t *v0; // r4
  int v1; // r0

  v0 = (uint16_t *)off_136E08;
  v1 = sub_12C7EC(4107, *((uint16_t *)off_136E08 + 1924), 4, 1u);
  sub_12C84C(v1);
  sub_12EB90(8, dword_136E0C, v0[1924]);
  return 0;
}

