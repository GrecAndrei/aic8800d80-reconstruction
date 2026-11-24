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


extern uint32_t off_114938;
extern uint32_t off_11493C;

// setup_patch_data @ 0x114914, size 36 bytes
int setup_patch_data()
{
  command_enqueue(0, 0, off_114938, off_11493C, 1);
  init_osal_objects();
  return ke_event_schedule_1(aSdioBtInit);
}
