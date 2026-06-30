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

// sub_114D34 @ 0x114d34, size 10 bytes
// Doc: patch_apply_n_174 [patch]: Patch slot stub (NOP) applied to firmware image at runtime
// patch_apply_n_174 [patch]: Patch slot stub (NOP) applied to firmware image at runtime
int  sub_114D34(int a1)
{
  return rf_fault_dump_n4e8(1, a1, 4u);
}

