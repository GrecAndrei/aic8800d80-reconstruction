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

// sub_12D908 @ 0x12d908, size 26 bytes
unsigned int  sub_12D908(unsigned int a1)
{
  unsigned int v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0

  v1 = sub_12D7CC(a1);
  v2 = sub_142A94(v1);
  v3 = sub_142B44(v2, *(uint64_t *)&dword_12D928);
  return sub_143108(v3);
}
