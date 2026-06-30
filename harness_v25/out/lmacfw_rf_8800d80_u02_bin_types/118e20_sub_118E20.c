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

extern uint32_t off_118E48;
extern uint32_t off_118E50;
extern uint32_t off_118E4C;
extern uint32_t dword_118E54;

// sub_118E20 @ 0x118e20, size 40 bytes
unsigned int sub_118E20()
{
  unsigned int result; // r0
  uint32_t *v1; // r2

  *(uint32_t *)off_118E48 &= ~2u;
  result = sub_1174B8(0);
  v1 = off_118E50;
  *(uint32_t *)off_118E4C = dword_118E54;
  *v1 &= 0xFFFBFFFE;
  return result;
}

