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

extern uint32_t off_10F500;
extern uint32_t off_10F504;

// sub_10F4B8 @ 0x10f4b8, size 70 bytes
void __noreturn sub_10F4B8()
{
  uint64_t v0; // r0
  uint64_t v1; // kr00_8
  uint64_t *v2; // r3

  v0 = *(uint64_t *)(*(uint32_t *)off_10F500 + 32);
  v1 = *(uint64_t *)(*(uint32_t *)off_10F500 + 24);
  v2 = off_10F504;
  *((uint32_t *)off_10F504 + 4) = *(uint32_t *)(*(uint32_t *)off_10F500 + 44);
  *v2 = v1;
  v2[1] = v0;
  sub_10C2E4();
}

