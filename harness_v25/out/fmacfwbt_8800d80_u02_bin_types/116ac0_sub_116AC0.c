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

extern uint32_t dword_116AF0;

// sub_116AC0 @ 0x116ac0, size 48 bytes
int  sub_116AC0(uint8_t *a1, char a2)
{
  int v2; // r6
  int v4; // r5

  v2 = dword_116AF0;
  v4 = 696 * (uint8_t)a1[29];
  a1[27] = a2;
  a1[97] = 1;
  sub_12D470(v4 + 572 + v2);
  return sub_136C94(a1, v2 + v4);
}

