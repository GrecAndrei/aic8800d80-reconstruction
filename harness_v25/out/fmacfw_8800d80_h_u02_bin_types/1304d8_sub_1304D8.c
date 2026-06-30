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

extern uint32_t off_1304FC;

// sub_1304D8 @ 0x1304d8, size 36 bytes
int sub_1304D8()
{
  int result; // r0

  *((uint8_t *)off_1304FC + 1) = 0;
  result = sub_12C774(1070, 1);
  if ( result )
    return sub_12C5FC(1070, 1);
  return result;
}

