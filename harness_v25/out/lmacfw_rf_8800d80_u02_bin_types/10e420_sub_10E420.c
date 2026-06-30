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

extern uint32_t off_10E4C8;
extern uint32_t dword_10E4A8;
extern uint32_t dword_10E4AC;
extern uint32_t dword_10E4B0;
extern uint32_t dword_10E4B4;
extern uint32_t dword_10E4B8;
extern uint32_t dword_10E4BC;
extern uint32_t dword_10E4CC;
extern uint32_t dword_10E4D0;
extern uint32_t dword_10E4C0;
extern uint32_t dword_10E4C4;
extern uint32_t dword_10E4D4;

// sub_10E420 @ 0x10e420, size 130 bytes
int sub_10E420()
{
  uint32_t *v0; // r2
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  int v4; // r0
  float v5; // r0
  uint64_t v6; // r0
  uint64_t v7; // r0
  uint64_t v8; // r0
  uint64_t v9; // r0
  uint64_t v10; // r0
  int v11; // r0

  v0 = off_10E4C8;
  *((uint32_t *)off_10E4C8 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_12752C(v0[4]);
  v2 = sub_127620(v1, HIDWORD(v1), dword_10E4A8, dword_10E4AC);
  v3 = sub_127874(v2, HIDWORD(v2), dword_10E4B0, dword_10E4B4);
  v4 = sub_1272B0(v3, HIDWORD(v3), dword_10E4A8, dword_10E4AC);
  v5 = sub_127BE4(v4);
  v6 = sub_127570(LODWORD(v5));
  v7 = sub_127874(v6, HIDWORD(v6), dword_10E4B8, dword_10E4BC);
  v8 = sub_127620(v7, HIDWORD(v7), 0, dword_10E4CC);
  v9 = sub_127620(v8, HIDWORD(v8), 0, dword_10E4D0);
  v10 = sub_127620(v9, HIDWORD(v9), dword_10E4C0, dword_10E4C4);
  v11 = sub_127874(v10, HIDWORD(v10), 0, dword_10E4D4);
  return (int)sub_127BE4(v11);
}

