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

extern uint32_t off_10CEE8;
extern uint32_t off_10CEE4;
extern uint32_t off_10CEEC;
extern uint32_t off_10CEF0;

// sub_10CEC0 @ 0x10cec0, size 34 bytes
int sub_10CEC0()
{
  int v0; // r3
  int result; // r0

  v0 = *(uint32_t *)off_10CEE8 + 4 * (*((uint8_t *)off_10CEE4 + 16) + 136);
  *(uint32_t *)off_10CEEC = 32;
  result = *(uint32_t *)(v0 + 4);
  if ( result )
    return 1;
  *(uint32_t *)off_10CEF0 = 32;
  return result;
}

