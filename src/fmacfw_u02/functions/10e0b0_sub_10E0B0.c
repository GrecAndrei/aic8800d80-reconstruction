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


extern uint32_t dword_10E1B0;
extern uint32_t dword_10E1B8;
extern uint32_t dword_10E1C0;
extern uint32_t dword_10E1C8;
extern uint32_t dword_10E1D4;
extern uint32_t dword_10E1D8;
extern uint32_t dword_10E1DC;
extern uint32_t dword_10E1E0;
extern uint32_t off_10E1D0;

// sub_10E0B0 @ 0x10e0b0, size 252 bytes
int sub_10E0B0()
{
  uint32_t *v0; // r5
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  uint64_t v4; // r0
  unsigned int v5; // r6
  uint32_t *v6; // r2
  unsigned int v7; // r4
  uint64_t v8; // r0
  uint64_t v9; // r0
  uint64_t v10; // r0
  uint64_t v11; // r0
  unsigned int v12; // r0
  uint64_t v13; // r0
  uint64_t v14; // r0
  uint64_t v15; // r2
  uint64_t v16; // r4
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r2
  uint64_t v20; // r0
  uint64_t v21; // r0
  uint64_t v22; // r2
  uint64_t v23; // r0
  uint64_t v24; // r0
  uint64_t v25; // r2
  uint64_t v26; // r0

  v0 = off_10E1D0;
  sub_10DF18(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_1429B4(v0[4]);
  v2 = sub_142AA8(v1, *(uint64_t *)&dword_10E1B0);
  v3 = sub_142CFC(v2, *(uint64_t *)&dword_10E1B8);
  v4 = sub_142738(v3, *(uint64_t *)&dword_10E1B0);
  v5 = sub_14306C(v4);
  sub_10DF18(2);
  v6 = off_10E1D0;
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  sub_10DF18(3);
  v8 = sub_1429B4(v7);
  v9 = sub_142AA8(v8, *(uint64_t *)&dword_10E1B0);
  v10 = sub_142CFC(v9, *(uint64_t *)&dword_10E1B8);
  v11 = sub_142738(v10, *(uint64_t *)&dword_10E1B0);
  v12 = sub_14306C(v11);
  v13 = sub_1429F8(v12);
  v14 = sub_142CFC(v13, *(uint64_t *)&dword_10E1C0);
  HIDWORD(v15) = dword_10E1D4;
  LODWORD(v15) = 0;
  v16 = sub_142AA8(v14, v15);
  v17 = sub_1429F8(v5);
  v18 = sub_142CFC(v17, *(uint64_t *)&dword_10E1C0);
  HIDWORD(v19) = dword_10E1D8;
  LODWORD(v19) = 0;
  v20 = sub_142AA8(v18, v19);
  v21 = sub_14273C(v16, v20);
  HIDWORD(v22) = dword_10E1DC;
  LODWORD(v22) = 0;
  v23 = sub_142AA8(v21, v22);
  v24 = sub_142AA8(v23, *(uint64_t *)&dword_10E1C8);
  HIDWORD(v25) = dword_10E1E0;
  LODWORD(v25) = 0;
  v26 = sub_142CFC(v24, v25);
  return (int)COERCE_FLOAT(sub_14306C(v26));
}
