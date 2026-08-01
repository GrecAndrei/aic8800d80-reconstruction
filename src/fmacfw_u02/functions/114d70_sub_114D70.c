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

// ke_task_handler_short @ 0x114d70, size 10 bytes
// Doc: patch_apply_n_134 [patch]: Apply behavioral patch variant 134 with stack frame setup
// patch_apply_n_134 [patch]: Apply behavioral patch variant 134 with stack frame setup
int  ke_task_handler_short(int a1)
{
  return ke_task_handler(128, a1, 4u);
}

