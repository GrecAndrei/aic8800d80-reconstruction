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


extern uint32_t dword_10E3E8;
extern uint32_t dword_10E3F0;
extern uint32_t dword_10E3F8;
extern uint32_t dword_10E400;
extern uint32_t dword_10E40C;
extern uint32_t dword_10E410;
extern uint32_t dword_10E414;
extern uint32_t dword_10E418;
extern uint32_t off_10E408;

// sub_10E2E8 @ 0x10e2e8, size 252 bytes
int sub_10E2E8()
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

  v0 = off_10E408;
  sub_10DBF4(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_12752C(v0[4]);
  v2 = sub_127620(v1, *(uint64_t *)&dword_10E3E8);
  v3 = sub_127874(v2, *(uint64_t *)&dword_10E3F0);
  v4 = sub_1272B0(v3, *(uint64_t *)&dword_10E3E8);
  v5 = sub_127BE4(v4);
  sub_10DBF4(2);
  v6 = off_10E408;
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  sub_10DBF4(3);
  v8 = sub_12752C(v7);
  v9 = sub_127620(v8, *(uint64_t *)&dword_10E3E8);
  v10 = sub_127874(v9, *(uint64_t *)&dword_10E3F0);
  v11 = sub_1272B0(v10, *(uint64_t *)&dword_10E3E8);
  v12 = sub_127BE4(v11);
  v13 = sub_127570(v12);
  v14 = sub_127874(v13, *(uint64_t *)&dword_10E3F8);
  HIDWORD(v15) = dword_10E40C;
  LODWORD(v15) = 0;
  v16 = sub_127620(v14, v15);
  v17 = sub_127570(v5);
  v18 = sub_127874(v17, *(uint64_t *)&dword_10E3F8);
  HIDWORD(v19) = dword_10E410;
  LODWORD(v19) = 0;
  v20 = sub_127620(v18, v19);
  v21 = sub_1272B4(v16, v20);
  HIDWORD(v22) = dword_10E414;
  LODWORD(v22) = 0;
  v23 = sub_127620(v21, v22);
  v24 = sub_127620(v23, *(uint64_t *)&dword_10E400);
  HIDWORD(v25) = dword_10E418;
  LODWORD(v25) = 0;
  v26 = sub_127874(v24, v25);
  return (int)COERCE_FLOAT(sub_127BE4(v26));
}
