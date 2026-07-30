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

// patch_apply_n_160 @ 0x114d4c, size 10 bytes
// Doc: patch_apply_n_160 [patch]: Apply firmware patch entry (variant n_160)
// patch_apply_n_160 [patch]: Apply firmware patch entry (variant n_160)
int  patch_apply_n_160(int a1)
{
  return rf_fault_dump_n4e8(4, a1, 0x14u);
}

