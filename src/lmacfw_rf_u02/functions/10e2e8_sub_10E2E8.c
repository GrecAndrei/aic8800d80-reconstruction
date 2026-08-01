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

extern uint32_t off_10E408;
extern uint32_t dword_10E3E8;
extern uint32_t dword_10E3EC;
extern uint32_t dword_10E3F0;
extern uint32_t dword_10E3F4;
extern uint32_t dword_10E3F8;
extern uint32_t dword_10E3FC;
extern uint32_t dword_10E40C;
extern uint32_t dword_10E410;
extern uint32_t dword_10E414;
extern uint32_t dword_10E400;
extern uint32_t dword_10E404;
extern uint32_t dword_10E418;

// sdio_core_enable @ 0x10e2e8, size 252 bytes
int sdio_core_enable()
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

  v0 = off_10E408;
  check_hw_status(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = double_to_float(v0[4]);
  v2 = aeabi_dadd(v1, HIDWORD(v1), dword_10E3E8, dword_10E3EC);
  v3 = aeabi_dsub(v2, HIDWORD(v2), dword_10E3F0, dword_10E3F4);
  v4 = double_subtract(v3, HIDWORD(v3), dword_10E3E8, dword_10E3EC);
  v5 = ((int ( *)(int))aeabi_dmul)(v4);
  check_hw_status(2);
  v6 = off_10E408;
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  check_hw_status(3);
  v8 = double_to_float(v7);
  v9 = aeabi_dadd(v8, HIDWORD(v8), dword_10E3E8, dword_10E3EC);
  v10 = aeabi_dsub(v9, HIDWORD(v9), dword_10E3F0, dword_10E3F4);
  v11 = double_subtract(v10, HIDWORD(v10), dword_10E3E8, dword_10E3EC);
  v12 = ((int ( *)(int))aeabi_dmul)(v11);
  v13 = aeabi_d2f(v12);
  v14 = aeabi_dsub(v13, HIDWORD(v13), dword_10E3F8, dword_10E3FC);
  v15 = aeabi_dadd(v14, HIDWORD(v14), 0, dword_10E40C);
  v16 = aeabi_d2f(v5);
  v17 = aeabi_dsub(v16, HIDWORD(v16), dword_10E3F8, dword_10E3FC);
  v18 = aeabi_dadd(v17, HIDWORD(v17), 0, dword_10E410);
  v19 = double_add(v15, HIDWORD(v15), v18, HIDWORD(v18));
  v20 = aeabi_dadd(v19, HIDWORD(v19), 0, dword_10E414);
  v21 = aeabi_dadd(v20, HIDWORD(v20), dword_10E400, dword_10E404);
  v22 = aeabi_dsub(v21, HIDWORD(v21), 0, dword_10E418);
  return (int)aeabi_dmul(v22);
}

