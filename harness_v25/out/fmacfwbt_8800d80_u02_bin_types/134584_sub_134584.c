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

extern uint32_t dword_1345A0;

// sub_134584 @ 0x134584, size 26 bytes
int sub_134584()
{
  int result; // r0

  sub_12ECB0(dword_1345A0);
  result = sub_12C964(6155, 6);
  *(uint8_t *)(loc_1345A4 + 0xF) = 0;
  return result;
}

