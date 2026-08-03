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

extern uint32_t off_10F0A8;
extern uint32_t off_10F0AC;

// sub_10F05C @ 0x10f05c, size 74 bytes
void __noreturn sub_10F05C()
{
  int v0; // r2
  uint64_t v1; // kr00_8
  char *v2; // r3
  uint64_t v3; // r0
  int v4; // r4
  int v5; // r2
  uint64_t v6; // kr10_8

  v0 = *(uint32_t *)off_10F0A8;
  v1 = *(uint64_t *)(*(uint32_t *)off_10F0A8 + 24);
  v2 = (char *)off_10F0AC;
  LODWORD(v3) = *(uint32_t *)(*(uint32_t *)off_10F0A8 + 36);
  v4 = *(uint32_t *)(*(uint32_t *)off_10F0A8 + 32);
  *(uint32_t *)off_10F0AC = v1;
  v6 = *(uint64_t *)(v0 + 40);
  v5 = *(uint32_t *)(v0 + 44);
  HIDWORD(v3) = v6;
  *((uint32_t *)v2 + 1) = HIDWORD(v1);
  *((uint32_t *)v2 + 2) = v4;
  *(uint64_t *)(v2 + 12) = v3;
  *((uint32_t *)v2 + 5) = v5;
  sub_1032D0();
}

