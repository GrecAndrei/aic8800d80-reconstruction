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


extern uint32_t dword_10E130;
extern uint32_t dword_10E138;
extern uint32_t dword_10E140;
extern uint32_t dword_10E148;
extern uint32_t dword_10E154;
extern uint32_t dword_10E158;
extern uint32_t dword_10E15C;
extern uint32_t off_10E150;

// sub_10E0A8 @ 0x10e0a8, size 130 bytes
int sub_10E0A8()
{
  uint32_t *v0; // r2
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  uint64_t v4; // r0
  unsigned int v5; // r0
  uint64_t v6; // r0
  uint64_t v7; // r0
  uint64_t v8; // r2
  uint64_t v9; // r0
  uint64_t v10; // r2
  uint64_t v11; // r0
  uint64_t v12; // r0
  uint64_t v13; // r2
  uint64_t v14; // r0

  v0 = off_10E150;
  *((uint32_t *)off_10E150 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_142874(v0[4]);
  v2 = sub_142968(v1, *(uint64_t *)&dword_10E130);
  v3 = sub_142BBC(v2, *(uint64_t *)&dword_10E138);
  v4 = sub_1425F8(v3, *(uint64_t *)&dword_10E130);
  v5 = sub_142F2C(v4);
  v6 = sub_1428B8(v5);
  v7 = sub_142BBC(v6, *(uint64_t *)&dword_10E140);
  HIDWORD(v8) = dword_10E154;
  LODWORD(v8) = 0;
  v9 = sub_142968(v7, v8);
  HIDWORD(v10) = dword_10E158;
  LODWORD(v10) = 0;
  v11 = sub_142968(v9, v10);
  v12 = sub_142968(v11, *(uint64_t *)&dword_10E148);
  HIDWORD(v13) = dword_10E15C;
  LODWORD(v13) = 0;
  v14 = sub_142BBC(v12, v13);
  return (int)COERCE_FLOAT(sub_142F2C(v14));
}
