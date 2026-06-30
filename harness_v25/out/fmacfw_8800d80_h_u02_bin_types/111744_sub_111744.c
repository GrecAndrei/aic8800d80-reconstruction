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

extern uint32_t off_1117BC;
extern uint32_t off_1117C0;
extern uint32_t off_1117C4;
extern uint32_t off_1117B8;
extern uint32_t off_1117C8;
extern uint32_t off_1117CC;

// sub_111744 @ 0x111744, size 114 bytes
int sub_111744()
{
  int v0; // r3
  int *v1; // r2
  uint32_t *v2; // r1
  int result; // r0
  int v4; // r3
  int v5; // r1
  char *v6; // r3
  uint32_t *v7; // r4
  int v8; // r6
  uint64_t v9; // kr00_8
  uint64_t v10; // kr08_8

  v0 = *(uint32_t *)off_1117BC;
  v1 = (int *)off_1117C0;
  v2 = off_1117C4;
  *(uint32_t *)(v0 + 4) = *(uint32_t *)off_1117B8;
  result = *v1;
  v2[709] = v0;
  v4 = *(uint32_t *)off_1117C8;
  *(uint8_t *)(result + 3) |= 0xC0u;
  v5 = v4 + 3200;
  do
  {
    *(uint8_t *)(v4 + 3) |= 0xC0u;
    v4 += 8;
  }
  while ( v4 != v5 );
  v6 = (char *)off_1117CC;
  v7 = off_1117C4;
  v8 = *((uint32_t *)off_1117CC + 2);
  v9 = *(uint64_t *)off_1117CC;
  *(uint8_t *)(*(uint32_t *)off_1117CC + 3) |= 0xC0u;
  *(uint8_t *)(HIDWORD(v9) + 3) |= 0xC0u;
  v10 = *(uint64_t *)(v6 + 12);
  *(uint8_t *)(v8 + 3) |= 0xC0u;
  *(uint8_t *)(v10 + 3) |= 0xC0u;
  *(uint8_t *)(HIDWORD(v10) + 3) |= 0xC0u;
  v7[581] = result;
  return result;
}

