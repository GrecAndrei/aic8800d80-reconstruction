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

extern uint32_t off_117CBC;
extern uint32_t dword_117CC0;
extern uint32_t dword_117CB4;
extern uint32_t dword_117CB8;

// sub_117BBC @ 0x117bbc, size 246 bytes
uint64_t sub_117BBC()
{
  uint8_t *v0; // r8
  int v1; // r10
  char *v2; // r5
  uint8_t *v3; // r4
  char *v4; // r9
  uint8_t *v5; // r7
  int v6; // r6
  int v7; // r11
  int v8; // r9
  int v9; // r0
  int v10; // r0
  int v11; // r0
  int16_t v12; // r7
  char *v13; // r0
  int i; // r6
  int v15; // r2
  uint64_t result; // r0
  uint32_t *v17; // r3
  uint8_t v18[44]; // [sp+0h] [bp-2Ch] BYREF

  v0 = off_117CBC;
  v1 = dword_117CC0;
  sub_12D14C(126976);
  v2 = v0 + 12;
  v3 = v18;
  v0[510] = 1;
  v4 = v0 + 12;
  v5 = v18;
  v6 = 0;
  do
  {
    v7 = (uint8_t)v6;
    sub_12D240(v5);
    sub_118940((uint8_t)v6++, v1, v5);
    sub_118940(v7, v4, v5);
    v1 += 8;
    v5 += 8;
    v4 += 84;
  }
  while ( v6 != 5 );
  v8 = dword_117CB4;
  v9 = sub_1189F8(5);
  v10 = sub_119E74(v9);
  v11 = sub_117EDC(v10);
  sub_11BEE0(v11);
  v12 = *((uint16_t *)v0 + 254);
  sub_100200((int *)(v8 - 432), 0, 0x204u);
  *((uint16_t *)v0 + 254) = v12;
  do
  {
    sub_12D240(v2);
    *((uint32_t *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((uint32_t *)v2 + 6) = 0;
    *((uint32_t *)v2 + 7) = 0;
    v13 = v2 + 16;
    v2 += 84;
    sub_12D240(v13);
  }
  while ( v2 != (char *)v8 );
  for ( i = 0; i != 5; ++i )
  {
    if ( sub_12D2D0(v3) )
    {
      do
        sub_13AF24();
      while ( sub_12D2D0(v3) );
      sub_11A7E8((uint8_t)i);
    }
    v3 += 8;
  }
  v15 = dword_117CB8;
  result = (unsigned int)(dword_117CB8 + 1152);
  do
  {
    v17 = (uint32_t *)(v15 - 36);
    do
      *v17++ = 0;
    while ( (uint32_t *)v15 != v17 );
    v15 += 36;
  }
  while ( (uint32_t)result != v15 );
  return result;
}

