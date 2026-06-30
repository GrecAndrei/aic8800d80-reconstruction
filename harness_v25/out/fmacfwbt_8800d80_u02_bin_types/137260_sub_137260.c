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

// sub_137260 @ 0x137260, size 18 bytes
// Doc: init_subcall_0x137268 [util]: Trampoline that calls init helper and returns 0
// init_subcall_0x137268 [util]: Trampoline that calls init helper and returns 0
int  sub_137260(int a1, uint8_t *a2)
{
  if ( *a2 )
    bt_init_check_1827f4((uint8_t)*a2);
  return 0;
}

