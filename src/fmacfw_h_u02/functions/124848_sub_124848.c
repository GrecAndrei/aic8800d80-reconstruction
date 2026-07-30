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

extern uint32_t dword_1248D0;
extern uint32_t off_1248CC;
extern uint32_t off_1248D4;
extern uint32_t off_1248D8;
extern uint32_t off_1248DC;
extern uint32_t dword_1248E0;

// sub_124848 @ 0x124848, size 132 bytes
int  sub_124848(uint16_t *a1)
{
  int v1; // r3
  int *v2; // r2
  int v4; // r0
  int *v5; // r5
  int *v6; // r7
  int v7; // r6
  int v8; // r1
  int v9; // r5
  int *v10; // r0

  v1 = dword_1248D0;
  v2 = *(int **)off_1248CC;
  v4 = *a1;
  v5 = (int *)off_1248D4;
  v6 = (int *)off_1248D8;
  v7 = a1[2];
  *v2 = **(uint32_t **)off_1248CC & dword_1248D0 | (v4 << 12);
  *v5 = *v5 & v1 | (v4 << 12);
  v8 = a1[1];
  v2[1] = v2[1] & v1 | (v8 << 12);
  v9 = a1[3];
  *v6 = *v6 & v1 | (v8 << 12);
  v2[2] = v2[2] & v1 | (v7 << 12);
  v10 = (int *)off_1248DC;
  v6[1] = v6[1] & v1 | (v7 << 12);
  v2[3] = v2[3] & v1 | (v9 << 12);
  *v10 = v1 & *v10 | (v9 << 12);
  sub_120368();
  sub_12E948(dword_1248E0, *a1, a1[1]);
  return 0;
}

