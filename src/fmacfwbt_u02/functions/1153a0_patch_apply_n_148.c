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

// patch_apply_n_148 @ 0x1153a0, size 10 bytes
// Doc: patch_apply_n_140 [patch]: Begins a patch routine saving r4-r7 and lr
// patch_apply_n_140 [patch]: Begins a patch routine saving r4-r7 and lr
int  patch_apply_n_148(int a1)
{
  return patch_apply_526c(64, a1, 4u);
}

