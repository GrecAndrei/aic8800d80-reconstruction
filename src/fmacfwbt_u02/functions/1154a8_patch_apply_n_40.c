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

// patch_apply_n_40 @ 0x1154a8, size 10 bytes
// Doc: patch_apply_n_40 [patch]: Patch apply trampoline writing 4 bytes to 0x400000 region
// patch_apply_n_40 [patch]: Patch apply trampoline writing 4 bytes to 0x400000 region
int  patch_apply_n_40(int a1)
{
  return sub_1153B8(2, a1, 6u);
}

