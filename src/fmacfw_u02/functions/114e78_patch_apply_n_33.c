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

// patch_get_field @ 0x114e78, size 12 bytes
// Doc: patch_apply_n_30 [patch]: apply firmware patch with signed-offset lookup and conditional branch
// patch_apply_n_30 [patch]: apply firmware patch with signed-offset lookup and conditional branch
int  patch_get_field(int a1)
{
  return ke_task_handler_large(0x400000, a1, 4u);
}

