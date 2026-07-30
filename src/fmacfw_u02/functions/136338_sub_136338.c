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

extern uint32_t off_136370;
extern uint32_t dword_136378;
extern uint32_t dword_136374;

// sub_136338 @ 0x136338, size 56 bytes
// Doc: sub_1236338 [util]: Check firmware ready flag from shared state
// sub_1236338 [util]: Check firmware ready flag from shared state
int sub_136338()
{
  if ( **(int16_t **)off_136370 >= 0 || msg_get_value(7u) == 2 )
  {
    ipc_msg_post_init(0);
    return 0;
  }
  else
  {
    sub_12F46C(dword_136378, dword_136374, 388);
    ipc_msg_post_init(0);
    return 0;
  }
}

