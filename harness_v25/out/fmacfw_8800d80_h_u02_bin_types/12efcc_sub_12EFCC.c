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

// sub_12EFCC @ 0x12efcc, size 116 bytes
int  sub_12EFCC(int a1, int *a2, int16_t a3, int16_t a4)
{
  int v5; // r0
  int v6; // r3
  uint32_t *v7; // r4
  int v9; // r5

  v5 = sub_12C7EC(1038, a4, a3, 4u);
  v6 = a2[1];
  v7 = (uint32_t *)v5;
  switch ( v6 )
  {
    case 1:
      sub_12E948(loc_12F04C, *(uint32_t *)(*a2 + 4));
      break;
    case 2:
      sub_12E948(loc_12F050, *a2);
      break;
    case 3:
      v9 = *a2;
      sub_12E948(loc_12F048, v9);
      if ( !v9 )
        sub_12EF88();
      sub_12C4A4(1068, 1, v9 << 10);
      break;
    default:
      sub_12E948(sub_12F040);
      break;
  }
  *v7 = (uint8_t)sub_114700();
  sub_12E948(loc_12F044);
  sub_12C84C((int)v7);
  return 0;
}

