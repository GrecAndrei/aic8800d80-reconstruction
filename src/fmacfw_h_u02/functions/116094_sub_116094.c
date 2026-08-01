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

extern uint32_t dword_116168;
extern uint32_t dword_116178;
extern uint32_t dword_11616C;
extern uint32_t off_116170;
extern uint32_t dword_116174;

// patch_enable @ 0x116094, size 210 bytes
int patch_enable()
{
  int *v0; // r4
  int v1; // r8
  int v2; // r7
  uint16_t *v3; // r5
  int v4; // r6
  int v5; // r0
  int v6; // r3
  int *v7; // r4
  int v8; // r7
  int v9; // r6
  int *v10; // r8
  int v11; // r5
  int result; // r0
  int v13; // r2
  int v14; // r1

  v0 = (int *)dword_116168;
  v1 = dword_116178;
  v2 = dword_11616C;
  v3 = off_116170;
  v4 = dword_116168 + 2048;
  do
  {
    *v0 = v1;
    v0[1] = get_rf_field_mid() << 14;
    v5 = get_clock_prescaler();
    v0[3] = 0;
    v0[4] = v2;
    v0[5] = 0;
    v0[6] = 0;
    v0[7] = 0;
    v0[8] = 0;
    v0[2] = v5;
    v0[9] = (uint16_t)(*v3 << 8) | (uint8_t)*(uint32_t *)v3;
    v0[10] = (uint16_t)(*v3 << 8) | (uint8_t)*(uint32_t *)v3;
    v0[11] = (uint16_t)(*v3 << 8) | (uint8_t)*(uint32_t *)v3;
    v6 = (uint16_t)(*v3 << 8) | (uint8_t)*(uint32_t *)v3;
    v0[14] = 4128768;
    v0[12] = v6;
    v0[13] = 8704;
    v0 += 16;
  }
  while ( v0 != (int *)v4 );
  v7 = (int *)dword_116174;
  v8 = dword_116178;
  v9 = dword_11616C;
  v10 = (int *)off_116170;
  v11 = dword_116174 + 256;
  do
  {
    *v7 = v8;
    v7[1] = get_rf_field_mid() << 14;
    result = get_clock_prescaler();
    v7[3] = 0;
    v7[4] = v9;
    v7[5] = 0;
    v7[6] = 0;
    v7[7] = 0;
    v7[8] = 0;
    v7[2] = result;
    v13 = *v10;
    v14 = *v10;
    v7[10] = 0;
    v7[9] = (uint16_t)((uint16_t)v13 << 8) | (uint8_t)v14;
    v7[11] = 0;
    v7[12] = 0;
    v7[13] = 0;
    v7[14] = 4128768;
    v7 += 16;
  }
  while ( v7 != (int *)v11 );
  return result;
}

