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

// sub_1073BC @ 0x1073bc, size 174 bytes
int  sub_1073BC(unsigned int *a1, int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r5
  int v5; // r7
  int v6; // s15

  v2 = *a1;
  if ( *a1 < a1[1] )
    v2 = a1[1];
  v3 = a1[3];
  if ( !v2 )
    v2 = 1;
  if ( v2 < a1[2] )
    v2 = a1[2];
  if ( v3 < v2 )
    v3 = v2;
  v5 = *(uint32_t *)(a2 + 8);
  sub_11F74C(1, "pwr_hih=%d\n", v3);
  v6 = (int)(float)(COERCE_FLOAT(sub_11EAA0(COERCE_UNSIGNED_INT(vcvts_n_f32_u32(v3, 0xFu)))) * 10.0);
  sub_11F74C(1, "pwr_db=%d\n", v6);
  if ( v6 >= -1 )
  {
    sub_11F74C(1, "sat> %d \n", -2);
  }
  else if ( v6 < -30 )
  {
    sub_11F74C(1, "sma %d\n", -30);
  }
  *(uint32_t *)(a2 + 8) = (int)COERCE_FLOAT(sub_11EAC8(COERCE_INT((float)(~v6 + v5))));
  return sub_107150(a2);
}
