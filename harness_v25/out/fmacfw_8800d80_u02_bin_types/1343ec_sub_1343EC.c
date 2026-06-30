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

extern uint32_t off_134420;
extern uint32_t off_134428;
extern uint32_t dword_134424;
extern uint32_t dword_13442C;
extern uint32_t dword_134430;

// sub_1343EC @ 0x1343ec, size 52 bytes
uint32_t *sub_1343EC()
{
  if ( **(int16_t **)off_134420 >= 0 || !*((uint32_t *)off_134428 + 6) )
    return sub_12D240((uint32_t *)dword_134424);
  sub_12F46C(dword_13442C, dword_134430, 132);
  return sub_12D240((uint32_t *)dword_134424);
}

