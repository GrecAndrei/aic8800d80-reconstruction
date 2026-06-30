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

// bt_cmd_dispatch_wrapper @ 0x1238ac, size 12 bytes
// Doc: bt_cmd_dispatch_wrapper [bt]: BT command dispatch thunk returning 1
// bt_cmd_dispatch_wrapper [bt]: BT command dispatch thunk returning 1
int  bt_cmd_dispatch_wrapper(int a1, int a2)
{
  sub_125AC8(a2);
  return 1;
}

