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

// sub_133704 @ 0x133704, size 54 bytes
int  sub_133704(int a1, int a2, int16_t a3, int16_t a4)
{
  int v5; // r0
  int16_t v6; // r1
  int16_t v7; // r2
  int16_t v10; // [sp+0h] [bp-8h]
  int16_t v12; // [sp+4h] [bp-4h]

  v5 = sub_12CD48(6u);
  v6 = a4;
  v7 = a3;
  if ( v5 == 6 )
  {
    v10 = a3;
    v12 = v6;
    sub_1357F0(*(uint16_t *)(a2 + 2));
    v7 = v10;
    v6 = v12;
  }
  sub_12C8D0(6156, v6, v7);
  return 0;
}

