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

extern uint32_t off_129138;
extern uint32_t dword_12913C;

// sub_12911C @ 0x12911c, size 28 bytes
int sub_12911C()
{
  uint32_t *v0; // r4
  int *v1; // r0
  int result; // r0

  v0 = off_129138;
  v1 = sub_100200((int *)off_129138, 0, 0x28u);
  result = sub_14213C(v1);
  v0[4] = dword_12913C;
  *((uint8_t *)v0 + 28) = 1;
  return result;
}

