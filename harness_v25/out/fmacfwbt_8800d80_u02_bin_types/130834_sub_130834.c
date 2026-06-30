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

extern uint32_t off_130858;

// sub_130834 @ 0x130834, size 36 bytes
int sub_130834()
{
  int result; // r0

  *((uint8_t *)off_130858 + 1) = 0;
  result = sub_12CADC(1070, 1);
  if ( result )
    return sub_12C964(1070, 1);
  return result;
}

