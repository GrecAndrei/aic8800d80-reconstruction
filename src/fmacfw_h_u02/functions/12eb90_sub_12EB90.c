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

extern uint32_t off_12EBB4;

// check_feature_flag @ 0x12eb90, size 36 bytes
int check_feature_flag(int result, int a2, ...)
{
  va_list varg_r2; // [sp+10h] [bp+8h] BYREF

  va_start(varg_r2, a2);
  if ( ((uint16_t)result & **(uint16_t **)off_12EBB4) != 0 )
    return stack_struct_init(a2, (int)varg_r2);
  return result;
}

