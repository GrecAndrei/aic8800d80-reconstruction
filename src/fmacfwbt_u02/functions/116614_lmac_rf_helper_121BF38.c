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

extern uint32_t dword_1166E8;
extern uint32_t dword_1166F8;
extern uint32_t dword_1166EC;
extern uint32_t off_1166F0;
extern uint32_t dword_1166F4;

// hw_init_magic @ 0x116614, size 210 bytes
// Doc: hw_init_magic [rf]: LMAC RF helper/calibration routine
// hw_init_magic [rf]: LMAC RF helper/calibration routine
int hw_init_magic()
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

  v0 = (int *)dword_1166E8;
  v1 = dword_1166F8;
  v2 = dword_1166EC;
  v3 = off_1166F0;
  v4 = dword_1166E8 + 2048;
  do
  {
    *v0 = v1;
    v0[1] = sub_101954() << 14;
    v5 = get_hw_flash_size();
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
  v7 = (int *)dword_1166F4;
  v8 = dword_1166F8;
  v9 = dword_1166EC;
  v10 = (int *)off_1166F0;
  v11 = dword_1166F4 + 256;
  do
  {
    *v7 = v8;
    v7[1] = sub_101954() << 14;
    result = get_hw_flash_size();
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

