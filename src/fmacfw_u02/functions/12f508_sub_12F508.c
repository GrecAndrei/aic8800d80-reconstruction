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

extern uint32_t dword_12F524;

// init_global_0x1922d4 @ 0x12f508, size 26 bytes
// Doc: sub_122F508 [util]: Init/clear 16-byte table and link next node (sentinel setup)
// sub_122F508 [util]: Init/clear 16-byte table and link next node (sentinel setup)
int init_global_0x1922d4()
{
  int v0; // r4

  v0 = dword_12F524;
  memset((int *)dword_12F524, 0, 0x10u);
  zero_8_bytes((uint32_t *)(v0 + 8));
  return 0;
}

