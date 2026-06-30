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

extern uint32_t dword_136714;
extern uint32_t off_136718;
extern uint32_t dword_136720;
extern uint32_t dword_13671C;

// sub_1366E0 @ 0x1366e0, size 50 bytes
int sub_1366E0()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r4

  v0 = sub_12D190(dword_136714);
  v1 = v0;
  if ( **(int16_t **)off_136718 < 0 && !v0 )
    sub_12F32C(dword_136720, dword_13671C, 210);
  return sub_12C84C((int)(v1 + 3));
}

