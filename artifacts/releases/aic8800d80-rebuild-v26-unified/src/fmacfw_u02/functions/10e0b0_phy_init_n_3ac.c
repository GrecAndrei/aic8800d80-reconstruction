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

// phy_init_n_3ac @ 0x10e0b0, size 252 bytes
// Doc: phy_init_n_3ac [mmio]: Initialize PHY/MMIO block at 0x4010d000 with enable
// phy_init_n_3ac [mmio]: Initialize PHY/MMIO block at 0x4010d000 with enable
int phy_init_n_3ac()
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
  mmio_field_update(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_1429B4(v0[4]);
  v2 = sub_142AA8(v1, HIDWORD(v1), dword_10E1B0, dword_10E1B4);
  v3 = sub_142CFC(v2, HIDWORD(v2), dword_10E1B8, dword_10E1BC);
  v4 = sub_142738(v3, HIDWORD(v3), dword_10E1B0, dword_10E1B4);
  v5 = ((int ( *)(int))sub_14306C)(v4);
  mmio_field_update(2);
  v6 = off_10E1D0;
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  mmio_field_update(3);
  v8 = sub_1429B4(v7);
  v9 = sub_142AA8(v8, HIDWORD(v8), dword_10E1B0, dword_10E1B4);
  v10 = sub_142CFC(v9, HIDWORD(v9), dword_10E1B8, dword_10E1BC);
  v11 = sub_142738(v10, HIDWORD(v10), dword_10E1B0, dword_10E1B4);
  v12 = ((int ( *)(int))sub_14306C)(v11);
  v13 = sub_1429F8(v12);
  v14 = sub_142CFC(v13, HIDWORD(v13), dword_10E1C0, dword_10E1C4);
  v15 = sub_142AA8(v14, HIDWORD(v14), 0, dword_10E1D4);
  v16 = sub_1429F8(v5);
  v17 = sub_142CFC(v16, HIDWORD(v16), dword_10E1C0, dword_10E1C4);
  v18 = sub_142AA8(v17, HIDWORD(v17), 0, dword_10E1D8);
  v19 = sub_14273C(v15, HIDWORD(v15), v18, HIDWORD(v18));
  v20 = sub_142AA8(v19, HIDWORD(v19), 0, dword_10E1DC);
  v21 = sub_142AA8(v20, HIDWORD(v20), dword_10E1C8, dword_10E1CC);
  v22 = sub_142CFC(v21, HIDWORD(v21), 0, dword_10E1E0);
  return (int)sub_14306C(v22);
}

