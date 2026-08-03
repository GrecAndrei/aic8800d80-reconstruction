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

extern uint32_t off_112594;
extern uint32_t dword_1125A0;
extern uint32_t dword_112598;
extern uint32_t off_11259C;

// sub_11256C @ 0x11256c, size 40 bytes
uint8_t * sub_11256C(int a1, int a2)
{
  uint8_t *result; // r0

  if ( (*((uint16_t *)off_112594 + 89) & 0x4000) != 0 )
    result = sub_10D654((uint8_t *)dword_1125A0);
  else
    result = (uint8_t *)sub_11F504(dword_112598, a2);
  *(uint8_t *)off_11259C = 1;
  return result;
}

