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


extern uint32_t dword_100B74;
extern uint32_t off_100B78;
extern uint32_t off_100B7C;
extern uint32_t off_100B80;
extern uint32_t off_100B84;
extern uint32_t off_100B88;
extern uint32_t off_100B8C;

// sub_100B14 @ 0x100b14, size 94 bytes
uint32_t * sub_100B14(int a1)
{
  uint64_t v1; // r0
  uint64_t v2; // r2
  unsigned int *v3; // r5
  unsigned int *v4; // r4
  uint64_t v5; // r0
  uint64_t v6; // r0
  uint16_t v7; // r0
  uint32_t *v8; // r2
  uint32_t *v9; // r1
  uint32_t *result; // r0
  uint8_t *v11; // r5

  v1 = sub_142894(a1);
  HIDWORD(v2) = dword_100B74;
  v3 = (unsigned int *)off_100B78;
  v4 = (unsigned int *)off_100B7C;
  LODWORD(v2) = 0;
  v5 = sub_142BBC(v1, v2);
  v6 = sub_1424DC(v5);
  v7 = sub_142EEC(v6);
  v8 = off_100B80;
  v9 = off_100B84;
  *v3 = (uint16_t)(v7 << 8) | *v3 & 0xFFFF00FF;
  result = off_100B88;
  v11 = off_100B8C;
  *v4 = *v4 & 0xFFFFF9FF | 0x200;
  *v8 |= 0x40000000u;
  *v8 |= 0x80000000;
  *v9 = 4096;
  *result |= 0x1000u;
  *v11 = 1;
  return result;
}
