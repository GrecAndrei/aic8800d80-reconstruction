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

extern uint32_t off_111758;
extern uint32_t off_11175C;
extern uint32_t off_111760;
extern uint32_t off_111754;
extern uint32_t off_111764;
extern uint32_t off_111768;

// sub_1116E0 @ 0x1116e0, size 114 bytes
int sub_1116E0()
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

  v0 = *(uint32_t *)off_111758;
  v1 = (int *)off_11175C;
  v2 = off_111760;
  *(uint32_t *)(v0 + 4) = *(uint32_t *)off_111754;
  result = *v1;
  v2[709] = v0;
  v4 = *(uint32_t *)off_111764;
  *(uint8_t *)(result + 3) |= 0xC0u;
  v5 = v4 + 3200;
  do
  {
    *(uint8_t *)(v4 + 3) |= 0xC0u;
    v4 += 8;
  }
  while ( v4 != v5 );
  v6 = (char *)off_111768;
  v7 = off_111760;
  v8 = *((uint32_t *)off_111768 + 2);
  v9 = *(uint64_t *)off_111768;
  *(uint8_t *)(*(uint32_t *)off_111768 + 3) |= 0xC0u;
  *(uint8_t *)(HIDWORD(v9) + 3) |= 0xC0u;
  v10 = *(uint64_t *)(v6 + 12);
  *(uint8_t *)(v8 + 3) |= 0xC0u;
  *(uint8_t *)(v10 + 3) |= 0xC0u;
  *(uint8_t *)(HIDWORD(v10) + 3) |= 0xC0u;
  v7[581] = result;
  return result;
}

