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

extern uint32_t off_10E090;
extern uint32_t dword_10E070;
extern uint32_t dword_10E074;
extern uint32_t dword_10E078;
extern uint32_t dword_10E07C;
extern uint32_t dword_10E080;
extern uint32_t dword_10E084;
extern uint32_t dword_10E094;
extern uint32_t dword_10E098;
extern uint32_t dword_10E09C;
extern uint32_t dword_10E088;
extern uint32_t dword_10E08C;
extern uint32_t dword_10E0A0;

// sub_10DF70 @ 0x10df70, size 252 bytes
int sub_10DF70()
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

  v0 = off_10E090;
  sub_10DDD8(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_142874(v0[4]);
  v2 = sub_142968(v1, HIDWORD(v1), dword_10E070, dword_10E074);
  v3 = sub_142BBC(v2, HIDWORD(v2), dword_10E078, dword_10E07C);
  v4 = sub_1425F8(v3, HIDWORD(v3), dword_10E070, dword_10E074);
  v5 = ((int ( *)(int))sub_142F2C)(v4);
  sub_10DDD8(2);
  v6 = off_10E090;
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  sub_10DDD8(3);
  v8 = sub_142874(v7);
  v9 = sub_142968(v8, HIDWORD(v8), dword_10E070, dword_10E074);
  v10 = sub_142BBC(v9, HIDWORD(v9), dword_10E078, dword_10E07C);
  v11 = sub_1425F8(v10, HIDWORD(v10), dword_10E070, dword_10E074);
  v12 = ((int ( *)(int))sub_142F2C)(v11);
  v13 = sub_1428B8(v12);
  v14 = sub_142BBC(v13, HIDWORD(v13), dword_10E080, dword_10E084);
  v15 = sub_142968(v14, HIDWORD(v14), 0, dword_10E094);
  v16 = sub_1428B8(v5);
  v17 = sub_142BBC(v16, HIDWORD(v16), dword_10E080, dword_10E084);
  v18 = sub_142968(v17, HIDWORD(v17), 0, dword_10E098);
  v19 = sub_1425FC(v15, HIDWORD(v15), v18, HIDWORD(v18));
  v20 = sub_142968(v19, HIDWORD(v19), 0, dword_10E09C);
  v21 = sub_142968(v20, HIDWORD(v20), dword_10E088, dword_10E08C);
  v22 = sub_142BBC(v21, HIDWORD(v21), 0, dword_10E0A0);
  return (int)sub_142F2C(v22);
}

