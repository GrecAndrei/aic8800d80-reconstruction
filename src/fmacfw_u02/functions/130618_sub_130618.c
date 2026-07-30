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

extern uint32_t off_13063C;

// sub_130618 @ 0x130618, size 36 bytes
int sub_130618()
{
  int result; // r0

  *((uint8_t *)off_13063C + 1) = 0;
  result = sub_12C8B4(1070, 1);
  if ( result )
    return sub_12C73C(1070, 1);
  return result;
}

