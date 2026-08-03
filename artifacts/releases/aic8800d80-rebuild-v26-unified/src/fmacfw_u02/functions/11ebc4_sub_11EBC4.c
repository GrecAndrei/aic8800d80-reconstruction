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

extern uint32_t off_11EBF4;
extern uint32_t off_11EBF0;
extern uint32_t off_11EBF8;

// sub_11EBC4 @ 0x11ebc4, size 44 bytes
int sub_11EBC4()
{
  uint32_t *v0; // r2
  int result; // r0

  v0 = off_11EBF4;
  *(uint32_t *)off_11EBF0 = 0x10000;
  *v0 &= ~0x10000u;
  result = sub_12D104(0x80000);
  if ( *(uint8_t *)off_11EBF8 )
    return sub_1222C0(result);
  return result;
}

