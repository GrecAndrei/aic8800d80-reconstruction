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

// flash_cmd_exec @ 0x1219f4, size 22 bytes
int  flash_cmd_exec(int a1, int a2, int a3)
{
  return dispatch_event_handler_1("\x9BWARNING (%s) at %s:%d\n", (const char *)a1, (const char *)a2, a3 & 0xFFFFF);
}
