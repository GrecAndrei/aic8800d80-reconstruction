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

extern uint32_t off_10E028;
extern uint32_t dword_10E008;
extern uint32_t dword_10E00C;
extern uint32_t dword_10E010;
extern uint32_t dword_10E014;
extern uint32_t dword_10E018;
extern uint32_t dword_10E01C;
extern uint32_t dword_10E02C;
extern uint32_t dword_10E030;
extern uint32_t dword_10E034;
extern uint32_t dword_10E020;
extern uint32_t dword_10E024;
extern uint32_t dword_10E038;

// radio_setup @ 0x10df08, size 252 bytes
// Doc: sub_120DF08 [unknown]: Unknown firmware helper at 0x120df08
// sub_120DF08 [unknown]: Unknown firmware helper at 0x120df08
int radio_setup()
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

  v0 = off_10E028;
  set_pin_mux(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = __aeabi_ui2d(v0[4]);
  v2 = __aeabi_dmul(v1, HIDWORD(v1), dword_10E008, dword_10E00C);
  v3 = __aeabi_ddiv(v2, HIDWORD(v2), dword_10E010, dword_10E014);
  v4 = __aeabi_dsub(v3, HIDWORD(v3), dword_10E008, dword_10E00C);
  v5 = ((int ( *)(int))double_to_float)(v4);
  set_pin_mux(2);
  v6 = off_10E028;
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  set_pin_mux(3);
  v8 = __aeabi_ui2d(v7);
  v9 = __aeabi_dmul(v8, HIDWORD(v8), dword_10E008, dword_10E00C);
  v10 = __aeabi_ddiv(v9, HIDWORD(v9), dword_10E010, dword_10E014);
  v11 = __aeabi_dsub(v10, HIDWORD(v10), dword_10E008, dword_10E00C);
  v12 = ((int ( *)(int))double_to_float)(v11);
  v13 = __aeabi_f2d(v12);
  v14 = __aeabi_ddiv(v13, HIDWORD(v13), dword_10E018, dword_10E01C);
  v15 = __aeabi_dmul(v14, HIDWORD(v14), 0, dword_10E02C);
  v16 = __aeabi_f2d(v5);
  v17 = __aeabi_ddiv(v16, HIDWORD(v16), dword_10E018, dword_10E01C);
  v18 = __aeabi_dmul(v17, HIDWORD(v17), 0, dword_10E030);
  v19 = __aeabi_dadd(v15, HIDWORD(v15), v18, HIDWORD(v18));
  v20 = __aeabi_dmul(v19, HIDWORD(v19), 0, dword_10E034);
  v21 = __aeabi_dmul(v20, HIDWORD(v20), dword_10E020, dword_10E024);
  v22 = __aeabi_ddiv(v21, HIDWORD(v21), 0, dword_10E038);
  return (int)double_to_float(v22);
}

