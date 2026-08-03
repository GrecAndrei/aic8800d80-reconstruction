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

extern uint32_t dword_142034;
extern uint32_t dword_142030;

// sub_141FE0 @ 0x141fe0, size 80 bytes
int  sub_141FE0(int a1, int a2, char a3)
{
  int result; // r0
  uint16_t v5; // r3
  int v6; // r0
  int v7; // r1
  uint64_t v8; // r2
  int v9; // [sp+Ch] [bp-4h] BYREF

  result = sub_141B70((int)&v9, dword_142034 + 1320 * a1, dword_142030 + 696 * a2, 7, 0);
  if ( result )
  {
    v5 = result + 1;
    *(uint8_t *)(*(uint32_t *)(v9 + 72) + result + 108) = a3;
    v6 = v9;
    v7 = *(uint32_t *)(v9 + 76);
    LODWORD(v8) = *(uint32_t *)(v7 + 28) - 1 + v5;
    HIDWORD(v8) = v5 + 4;
    *(uint64_t *)(v7 + 32) = v8;
    return rf_param_get_status(v6, 3);
  }
  return result;
}

