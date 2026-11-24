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

// debug_printf @ 0x10dae4, size 28 bytes
int debug_printf(const char *fmt, ...)
{
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, fmt);
  return stack_struct_init(fmt, (unsigned int *)(*(void **)&(varg_r1)));
}
