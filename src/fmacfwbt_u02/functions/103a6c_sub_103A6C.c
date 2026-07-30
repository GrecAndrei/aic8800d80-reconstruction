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

extern uint32_t off_103AB4;
extern uint32_t off_103AB8;
extern uint32_t off_103ABC;
extern uint32_t off_103AB0;
extern uint32_t dword_103AC0;

// sub_103A6C @ 0x103a6c, size 66 bytes
int sub_103A6C()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r1
  uint32_t *v2; // r2

  v0 = off_103AB4;
  v1 = off_103AB8;
  v2 = off_103ABC;
  *(uint32_t *)off_103AB0 &= 0xFFFFFA53;
  *v0 &= ~0x20000u;
  *v1 &= ~0x1000000u;
  *v2 &= 0xFFE7FFFF;
  sub_100644(10);
  return sub_12EEF8(0x2000, dword_103AC0);
}

