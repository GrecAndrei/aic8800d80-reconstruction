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


extern uint32_t dword_10E008;
extern uint32_t dword_10E010;
extern uint32_t dword_10E018;
extern uint32_t dword_10E020;
extern uint32_t dword_10E02C;
extern uint32_t dword_10E030;
extern uint32_t dword_10E034;
extern uint32_t dword_10E038;
extern uint32_t off_10E028;

// sub_10DF08 @ 0x10df08, size 252 bytes
int sub_10DF08()
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

  v0 = off_10E028;
  sub_10DD70(1);
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_142A50(v0[4]);
  v2 = sub_142B44(v1, *(uint64_t *)&dword_10E008);
  v3 = sub_142D98(v2, *(uint64_t *)&dword_10E010);
  v4 = sub_1427D4(v3, *(uint64_t *)&dword_10E008);
  v5 = sub_143108(v4);
  sub_10DD70(2);
  v6 = off_10E028;
  v0[1] = 1;
  while ( v6[7] != 1 )
    ;
  v6[7] = 1;
  v7 = v6[4];
  sub_10DD70(3);
  v8 = sub_142A50(v7);
  v9 = sub_142B44(v8, *(uint64_t *)&dword_10E008);
  v10 = sub_142D98(v9, *(uint64_t *)&dword_10E010);
  v11 = sub_1427D4(v10, *(uint64_t *)&dword_10E008);
  v12 = sub_143108(v11);
  v13 = sub_142A94(v12);
  v14 = sub_142D98(v13, *(uint64_t *)&dword_10E018);
  HIDWORD(v15) = dword_10E02C;
  LODWORD(v15) = 0;
  v16 = sub_142B44(v14, v15);
  v17 = sub_142A94(v5);
  v18 = sub_142D98(v17, *(uint64_t *)&dword_10E018);
  HIDWORD(v19) = dword_10E030;
  LODWORD(v19) = 0;
  v20 = sub_142B44(v18, v19);
  v21 = sub_1427D8(v16, v20);
  HIDWORD(v22) = dword_10E034;
  LODWORD(v22) = 0;
  v23 = sub_142B44(v21, v22);
  v24 = sub_142B44(v23, *(uint64_t *)&dword_10E020);
  HIDWORD(v25) = dword_10E038;
  LODWORD(v25) = 0;
  v26 = sub_142D98(v24, v25);
  return (int)COERCE_FLOAT(sub_143108(v26));
}
