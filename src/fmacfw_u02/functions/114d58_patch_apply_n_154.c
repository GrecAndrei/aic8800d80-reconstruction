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

// ke_event_send_0x40 @ 0x114d58, size 10 bytes
// Doc: patch_apply_n_150 [patch]: NOP patch slot placeholder
// patch_apply_n_150 [patch]: NOP patch slot placeholder
int  ke_event_send_0x40(int a1)
{
  return ke_task_handler(32, a1, 4u);
}

