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

// patch_jump @ 0x12f748, size 4 bytes
// Doc: sub_122F748 [unknown]: Check if state byte equals 3
// sub_122F748 [unknown]: Check if state byte equals 3
// attributes: thunk
int  patch_jump(uint16_t *a1)
{
  return host_event_process(a1);
}

