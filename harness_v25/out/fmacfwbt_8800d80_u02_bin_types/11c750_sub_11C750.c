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

extern uint32_t off_11C784;
extern uint32_t off_11C78C;
extern uint32_t off_11C788;

// sub_11C750 @ 0x11c750, size 52 bytes
int sub_11C750()
{
  int result; // r0
  int v1; // r4
  int *v2; // r2
  int v3; // r3

  result = sub_12072C();
  if ( (*(uint32_t *)off_11C784 & 0x8000) != 0 && (v1 = result, (result = chip_feature_check()) != 0) && v1 )
  {
    v2 = (int *)off_11C78C;
    v3 = *(uint32_t *)off_11C78C;
    *((uint32_t *)off_11C788 + 4) = v1;
    *v2 = v3 | 0x80;
  }
  else
  {
    *((uint32_t *)off_11C788 + 4) = 0;
  }
  return result;
}

