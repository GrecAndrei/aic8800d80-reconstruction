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


extern uint32_t dword_10E4A8;
extern uint32_t dword_10E4B0;
extern uint32_t dword_10E4B8;
extern uint32_t dword_10E4C0;
extern uint32_t dword_10E4CC;
extern uint32_t dword_10E4D0;
extern uint32_t dword_10E4D4;
extern uint32_t off_10E4C8;

// sub_10E420 @ 0x10e420, size 130 bytes
int sub_10E420()
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

  v0 = off_10E4C8;
  *((uint32_t *)off_10E4C8 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_12752C(v0[4]);
  v2 = sub_127620(v1, *(uint64_t *)&dword_10E4A8);
  v3 = sub_127874(v2, *(uint64_t *)&dword_10E4B0);
  v4 = sub_1272B0(v3, *(uint64_t *)&dword_10E4A8);
  v5 = sub_127BE4(v4);
  v6 = sub_127570(v5);
  v7 = sub_127874(v6, *(uint64_t *)&dword_10E4B8);
  HIDWORD(v8) = dword_10E4CC;
  LODWORD(v8) = 0;
  v9 = sub_127620(v7, v8);
  HIDWORD(v10) = dword_10E4D0;
  LODWORD(v10) = 0;
  v11 = sub_127620(v9, v10);
  v12 = sub_127620(v11, *(uint64_t *)&dword_10E4C0);
  HIDWORD(v13) = dword_10E4D4;
  LODWORD(v13) = 0;
  v14 = sub_127874(v12, v13);
  return (int)COERCE_FLOAT(sub_127BE4(v14));
}
