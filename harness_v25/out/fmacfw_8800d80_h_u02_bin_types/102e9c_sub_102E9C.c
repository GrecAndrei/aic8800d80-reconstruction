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

extern uint32_t off_102ECC;

// sub_102E9C @ 0x102e9c, size 48 bytes
int sub_102E9C()
{
  uint64_t v0; // kr00_8
  int v1; // r4

  v0 = *(uint64_t *)((char *)off_102ECC + 4);
  v1 = *(uint32_t *)off_102ECC;
  sub_102E08(0, 32, 0x10u, SHIDWORD(v0));
  sub_102E08(0, 48, 0x10u, v0);
  return sub_102E08(0, 64, 0x10u, v1);
}

