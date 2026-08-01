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

extern uint32_t dword_12D700;
extern uint32_t dword_12D704;

// free_msg @ 0x12d6e0, size 26 bytes
float  free_msg(unsigned int a1)
{
  float v1; // r0
  uint64_t v2; // r0
  int v3; // r0

  v1 = extract_msg_type(a1);
  v2 = float_to_double(LODWORD(v1));
  v3 = double_add(v2, HIDWORD(v2), dword_12D700, dword_12D704);
  return double_to_uint(v3);
}

