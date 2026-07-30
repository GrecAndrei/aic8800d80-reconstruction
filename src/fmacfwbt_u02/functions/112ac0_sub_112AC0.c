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

extern uint32_t off_112AE8;
extern uint32_t dword_112AF4;
extern uint32_t dword_112AEC;
extern uint32_t off_112AF0;

// sub_112AC0 @ 0x112ac0, size 40 bytes
uint8_t * sub_112AC0(int a1, int a2, int a3)
{
  uint8_t *result; // r0

  if ( (*((uint16_t *)off_112AE8 + 89) & 0x4000) != 0 )
    result = sub_10D60C((uint8_t *)dword_112AF4);
  else
    result = (uint8_t *)sub_12ECB0(dword_112AEC, a2, a3);
  *(uint8_t *)off_112AF0 = 1;
  return result;
}

