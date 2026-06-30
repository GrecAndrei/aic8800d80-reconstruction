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

// patch_apply_n_16c_537c @ 0x11537c, size 10 bytes
// Doc: sub_1213FD8 [util]: Allocate 0x20-byte buffer and initialize
// sub_1213FD8 [util]: Allocate 0x20-byte buffer and initialize
int  patch_apply_n_16c_537c(int a1)
{
  return patch_apply_526c(2, a1, 0xCu);
}

