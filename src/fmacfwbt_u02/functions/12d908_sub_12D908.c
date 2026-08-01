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

extern uint32_t dword_12D928;
extern uint32_t dword_12D92C;

// system_init_sequence @ 0x12d908, size 26 bytes
float  system_init_sequence(unsigned int a1)
{
  float v1; // r0
  uint64_t v2; // r0
  int v3; // r0

  v1 = float32_decompose(a1);
  v2 = __aeabi_f2d(LODWORD(v1));
  v3 = __aeabi_dmul(v2, HIDWORD(v2), dword_12D928, dword_12D92C);
  return double_to_float(v3);
}

