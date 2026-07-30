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

extern uint32_t dword_1405D8;

// sub_1405AC @ 0x1405ac, size 42 bytes
BOOL sub_1405AC()
{
  int v0; // r5

  v0 = dword_1405D8;
  if ( !*(uint32_t *)(dword_1405D8 + 6472) )
    return 1;
  if ( msg_get_value(0xBu) == 3 )
    return **(uint32_t **)(v0 + 6472) == 0;
  return 0;
}

