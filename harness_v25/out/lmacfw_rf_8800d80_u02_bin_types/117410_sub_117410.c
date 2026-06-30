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

extern uint32_t dword_117488;
extern uint32_t off_11748C;
extern uint32_t dword_117490;
extern uint32_t off_1174AC;
extern uint32_t off_117494;
extern uint32_t off_117498;
extern uint32_t off_1174B0;
extern uint32_t off_1174B4;
extern uint32_t off_11749C;
extern uint32_t off_1174A0;
extern uint32_t off_1174A4;
extern uint32_t dword_1174A8;

// sub_117410 @ 0x117410, size 118 bytes
int sub_117410()
{
  int v0; // r3
  uint32_t *v1; // r2
  uint32_t *v2; // r12
  int *v3; // r5
  uint32_t *v4; // r4
  uint32_t *v5; // r8
  uint32_t *v6; // lr
  uint32_t *v7; // r7
  int v8; // r3
  uint32_t *v9; // r6
  uint32_t *v10; // r5
  int v11; // r3
  uint64_t v12; // r0

  v0 = dword_117488;
  v1 = off_11748C;
  HIDWORD(v12) = dword_117490;
  v2 = off_1174AC;
  v3 = (int *)off_117494;
  v4 = off_117498;
  *(uint32_t *)off_11748C = dword_117488;
  LODWORD(v12) = v0 + 24832;
  *v3 = v0;
  *v4 = v0 + 24884;
  v5 = off_1174B0;
  v6 = off_1174B4;
  v1[2] = v0;
  v7 = off_11749C;
  v8 = *v1;
  v9 = off_1174A0;
  *v5 = *v1;
  *v6 = v8;
  *v2 = HIDWORD(v12);
  v10 = off_1174A4;
  *v7 = HIDWORD(v12) + 664;
  *v9 = HIDWORD(v12);
  v4[6] = HIDWORD(v12);
  v4 -= 0x2000;
  *v10 = dword_1174A8;
  v11 = *(uint32_t *)((char *)v4 + 0xFFFFFF40);
  v1[3] = HIDWORD(v12);
  v1[1] = v12 + 56;
  LODWORD(v12) = HIDWORD(v12) + 668;
  *((uint64_t *)v1 + 2) = v12;
  *(v4 - 48) = v11 & 0x80000 | 0x78025;
  return v12;
}

