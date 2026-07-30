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

// sub_13B0A0 @ 0x13b0a0, size 62 bytes
uint16_t * sub_13B0A0(int a1, uint16_t *a2, int a3)
{
  uint16_t *v6; // r1
  int v8; // r0
  char v9; // r3
  int v10; // [sp+4h] [bp-4h] BYREF

  if ( *(uint8_t *)(a1 + 51) )
  {
    v6 = (uint16_t *)((char *)a2 + a3 + *(uint8_t *)(a1 + 51));
  }
  else
  {
    v8 = sub_13A528(a1, &v10);
    v9 = v10;
    *(uint8_t *)(a1 + 51) = v8;
    v6 = (uint16_t *)((char *)a2 + a3 + v8);
    *(uint8_t *)(a1 + 53) = v9;
  }
  *a2 |= 0x4000u;
  return sub_13A980(a1, v6, 0);
}

