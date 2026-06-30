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

extern uint32_t off_103C5C;
extern uint32_t off_103C60;
extern uint32_t off_103C64;
extern uint32_t off_103C58;
extern uint32_t dword_103C68;

// sub_103C14 @ 0x103c14, size 66 bytes
int sub_103C14()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r1
  uint32_t *v2; // r2

  v0 = off_103C5C;
  v1 = off_103C60;
  v2 = off_103C64;
  *(uint32_t *)off_103C58 &= 0xFFFFFA53;
  *v0 &= ~0x20000u;
  *v1 &= ~0x1000000u;
  *v2 &= 0xFFE7FFFF;
  delay_us_0644(10);
  return feature_guard_check(0x2000, dword_103C68);
}

