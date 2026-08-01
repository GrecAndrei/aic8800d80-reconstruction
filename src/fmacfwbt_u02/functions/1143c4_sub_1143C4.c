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

extern uint32_t dword_1143CC;

// log_debug_c @ 0x1143c4, size 6 bytes
// Doc: sub_12143C4 [util]: Load and return a pointer to a global config structure (0x1672ac)
// sub_12143C4 [util]: Load and return a pointer to a global config structure (0x1672ac)
int  log_debug_c(int a1, int a2, int a3)
{
  return ke_event_schedule(dword_1143CC, a2, a3);
}

