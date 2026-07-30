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

extern uint32_t off_100B78;
extern uint32_t off_100B7C;
extern uint32_t dword_100B74;
extern uint32_t off_100B80;
extern uint32_t off_100B84;
extern uint32_t off_100B88;
extern uint32_t off_100B8C;

// sub_100B14 @ 0x100b14, size 94 bytes
uint32_t *sub_100B14()
{
  uint64_t v0; // r0
  unsigned int *v1; // r5
  unsigned int *v2; // r4
  int v3; // r0
  int v4; // r0
  int16_t v5; // r0
  uint32_t *v6; // r2
  uint32_t *v7; // r1
  uint32_t *result; // r0
  uint8_t *v9; // r5

  v0 = sub_142894();
  v1 = (unsigned int *)off_100B78;
  v2 = (unsigned int *)off_100B7C;
  v3 = sub_142BBC(v0, HIDWORD(v0), 0, dword_100B74);
  v4 = sub_1424DC(v3);
  v5 = sub_142EEC(v4);
  v6 = off_100B80;
  v7 = off_100B84;
  *v1 = (uint16_t)(v5 << 8) | *v1 & 0xFFFF00FF;
  result = off_100B88;
  v9 = off_100B8C;
  *v2 = *v2 & 0xFFFFF9FF | 0x200;
  *v6 |= 0x40000000u;
  *v6 |= 0x80000000;
  *v7 = 4096;
  *result |= 0x1000u;
  *v9 = 1;
  return result;
}

