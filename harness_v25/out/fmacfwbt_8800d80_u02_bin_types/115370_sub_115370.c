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

// sub_115370 @ 0x115370, size 10 bytes
// Doc: patch_apply_n_174 [patch]: Empty patch/hook stub (NOP)
// patch_apply_n_174 [patch]: Empty patch/hook stub (NOP)
int  sub_115370(int a1)
{
  return patch_apply_526c(1, a1, 4u);
}

