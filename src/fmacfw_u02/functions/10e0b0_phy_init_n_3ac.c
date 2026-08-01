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

extern uint32_t off_10E1D0;
extern uint32_t dword_10E1B0;
extern uint32_t dword_10E1B4;
extern uint32_t dword_10E1B8;
extern uint32_t dword_10E1BC;
extern uint32_t dword_10E1C0;
extern uint32_t dword_10E1C4;
extern uint32_t dword_10E1D4;
extern uint32_t dword_10E1D8;
extern uint32_t dword_10E1DC;
extern uint32_t dword_10E1C8;
extern uint32_t dword_10E1CC;
extern uint32_t dword_10E1E0;

// rf_core_enable @ 0x10e0b0, size 252 bytes
// Doc: rf_core_enable [mmio]: Initialize PHY/MMIO block at 0x4010d000 with enable
// rf_core_enable [mmio]: Initialize PHY/MMIO block at 0x4010d000 with enable
int rf_core_enable()
{
  uint32_t *v0; // r5
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  int v4; // r0
  int v5; // r6
  uint32_t *v6; // r2
  int v7; // r4
  uint64_t v8; // r0
  uint64_t v9; // r0
  uint64_t v10; // r0
  int v11; // r0
  int v12; // r0
  uint64_t v13; // r0
  uint64_t v14; // r0
  uint64_t v15; // r4
  uint64_t v16; // r0
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r0
  uint64_t v20; // r0
  uint64_t v21; // r0
  int v22; // r0

  v0 = off_10E1D0;
  rf_ctrl_config_set(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = uint_to_double(v0[4]);
  v2 = double_add(v1, HIDWORD(v1), dword_10E1B0, dword_10E1B4);
  v3 = double_subtract(v2, HIDWORD(v2), dword_10E1B8, dword_10E1BC);
  v4 = double_compare_wrapper(v3, HIDWORD(v3), dword_10E1B0, dword_10E1B4);
  v5 = ((int ( *)(int))double_to_uint)(v4);
  rf_ctrl_config_set(2);
  v6 = off_10E1D0;
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  rf_ctrl_config_set(3);
  v8 = uint_to_double(v7);
  v9 = double_add(v8, HIDWORD(v8), dword_10E1B0, dword_10E1B4);
  v10 = double_subtract(v9, HIDWORD(v9), dword_10E1B8, dword_10E1BC);
  v11 = double_compare_wrapper(v10, HIDWORD(v10), dword_10E1B0, dword_10E1B4);
  v12 = ((int ( *)(int))double_to_uint)(v11);
  v13 = float_to_double(v12);
  v14 = double_subtract(v13, HIDWORD(v13), dword_10E1C0, dword_10E1C4);
  v15 = double_add(v14, HIDWORD(v14), 0, dword_10E1D4);
  v16 = float_to_double(v5);
  v17 = double_subtract(v16, HIDWORD(v16), dword_10E1C0, dword_10E1C4);
  v18 = double_add(v17, HIDWORD(v17), 0, dword_10E1D8);
  v19 = double_compare(v15, HIDWORD(v15), v18, HIDWORD(v18));
  v20 = double_add(v19, HIDWORD(v19), 0, dword_10E1DC);
  v21 = double_add(v20, HIDWORD(v20), dword_10E1C8, dword_10E1CC);
  v22 = double_subtract(v21, HIDWORD(v21), 0, dword_10E1E0);
  return (int)double_to_uint(v22);
}

