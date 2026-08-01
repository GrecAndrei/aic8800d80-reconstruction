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

// ke_event_send_0x400000 @ 0x114e6c, size 10 bytes
// Doc: patch_apply_n398 [patch]: Apply firmware patch 398 to BT/LMAC region (SCB base 0xe000ed00)
// patch_apply_n398 [patch]: Apply firmware patch 398 to BT/LMAC region (SCB base 0xe000ed00)
int  ke_event_send_0x400000(int a1)
{
  return ke_task_handler_large(2, a1, 6u);
}

