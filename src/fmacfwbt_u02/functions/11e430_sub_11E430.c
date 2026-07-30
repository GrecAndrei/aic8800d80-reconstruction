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

extern uint32_t off_11E498;
extern uint32_t off_11E494;
extern uint32_t off_11E49C;
extern uint32_t off_11E4B8;
extern uint32_t off_11E4A0;
extern uint32_t off_11E4A8;
extern uint32_t off_11E4A4;
extern uint32_t off_11E4BC;
extern uint32_t off_11E4AC;
extern uint32_t off_11E4B0;
extern uint32_t dword_11E4B4;

// sub_11E430 @ 0x11e430, size 100 bytes
int sub_11E430()
{
  int *v0; // r2
  int v1; // r0
  uint32_t *v2; // r1
  uint32_t *v3; // r12
  uint64_t v4; // kr00_8
  uint32_t *v5; // r5
  uint32_t *v6; // r5
  int v7; // r1
  uint64_t v8; // kr08_8
  uint32_t *v9; // lr
  uint32_t *v10; // r7
  int *v12; // r4
  int v13; // r6
  int v14; // r3

  v0 = (int *)off_11E498;
  v1 = *(uint32_t *)off_11E494;
  v2 = off_11E49C;
  v3 = off_11E4B8;
  v4 = *(uint64_t *)*(uint32_t *)off_11E494;
  v5 = off_11E4A0;
  *(uint32_t *)off_11E498 = v4;
  *v5 = v4;
  *v2 = HIDWORD(v4) + v4 - 4;
  v6 = off_11E4A8;
  v7 = *v0;
  *(uint32_t *)off_11E4A4 = *v0;
  *v6 = v7;
  v8 = *(uint64_t *)(v1 + 8);
  v9 = off_11E4BC;
  v10 = off_11E4AC;
  v0[1] = HIDWORD(v4) + v4;
  v6[1] = v8;
  v12 = (int *)off_11E4B0;
  v0[2] = v4;
  v13 = dword_11E4B4;
  *v9 = HIDWORD(v8) + v8 - 4;
  *v3 = v8;
  *v10 = v8;
  v6[5] = v13;
  v14 = *v12;
  v0[4] = HIDWORD(v8) + v8;
  v0[3] = v8;
  v0[5] = v8;
  *v12 = v14 & 0x80000 | 0x78025;
  return HIDWORD(v8) + v8;
}

