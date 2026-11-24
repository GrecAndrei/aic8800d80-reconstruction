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


extern uint32_t off_12EF1C;

// state_check_feature @ 0x12eef8, size 36 bytes
int state_check_feature(int a1, const char *fmt, ...)
{
  va_list varg_r2; // [sp+10h] [bp+8h] BYREF

  va_start(varg_r2, fmt);
  if ( ((uint16_t)a1 & **(uint16_t **)off_12EF1C) != 0 )
    return debug_printf(fmt, (unsigned int *)(*(void **)&(varg_r2)));
  return a1;
}
