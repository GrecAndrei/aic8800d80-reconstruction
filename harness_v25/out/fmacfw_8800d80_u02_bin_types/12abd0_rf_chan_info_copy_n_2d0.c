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

extern uint32_t dword_12AC8C;
extern uint32_t off_12AC90;
extern uint32_t off_12AC94;

// rf_chan_info_copy_n_2d0 @ 0x12abd0, size 188 bytes
// Doc: rf_chan_info_copy_n_2d0 [rf]: Copy RF channel/band info from indexed entry to output buffer
// rf_chan_info_copy_n_2d0 [rf]: Copy RF channel/band info from indexed entry to output buffer
int  rf_chan_info_copy_n_2d0(int a1, int a2)
{
  int v2; // r6
  int v3; // r3
  char v4; // r2
  int v5; // r4
  uint32_t *v6; // r9
  uint32_t *v7; // r8
  int v8; // r3
  int v9; // r2
  int16_t v10; // r4
  int result; // r0

  v2 = dword_12AC8C;
  v3 = dword_12AC8C + 140 * a1;
  v4 = *(uint8_t *)(v3 + 120);
  *(uint8_t *)(a2 + 9) = v4;
  v5 = *(uint8_t *)(v3 + 115);
  *(uint8_t *)(v3 + 120) = v4 + 1;
  if ( v5 )
    *(uint8_t *)(a2 + 10) = v5 | 0x80;
  else
    *(uint8_t *)(a2 + 10) = 0;
  v6 = off_12AC90;
  v7 = off_12AC94;
  v8 = v2 + 140 * a1;
  v9 = a2 + 11;
  v10 = 0;
  do
  {
    if ( *(uint8_t *)(v8 + 16) && (!*(uint8_t *)(v2 + 140 * a1 + 135) || !*(uint8_t *)(v8 + 33) || *(uint8_t *)(v8 + 32) != 1) )
    {
      *(uint8_t *)v9 = *(uint8_t *)(v8 + 20);
      *(uint64_t *)(v9 + 1) = *(uint64_t *)(v8 + 24);
      v10 = (uint8_t)(v10 + 1);
      *(uint32_t *)(v9 + 9) = *v6 - v7[4] + *(uint32_t *)(v8 + 36);
    }
    v9 += 13;
    v8 += 48;
  }
  while ( v9 != a2 + 37 );
  result = v2 + 140 * a1;
  *(uint8_t *)(result + 136) = v10;
  *(uint8_t *)(a2 + 1) = 13 * v10 + 9;
  *(uint16_t *)(a2 + 7) = 13 * v10 + 2;
  return result;
}

