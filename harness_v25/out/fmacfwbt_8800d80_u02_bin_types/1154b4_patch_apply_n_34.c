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

// patch_apply_n_34 @ 0x1154b4, size 12 bytes
// Doc: patch_apply_n_34 [patch]: Apply firmware patch table entry 34 via indirect load
// patch_apply_n_34 [patch]: Apply firmware patch table entry 34 via indirect load
int  patch_apply_n_34(int a1)
{
  return sub_1153B8(0x400000, a1, 4u);
}

