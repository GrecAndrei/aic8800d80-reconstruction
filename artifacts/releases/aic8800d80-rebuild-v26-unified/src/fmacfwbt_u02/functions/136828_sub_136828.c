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

extern uint32_t off_13685C;
extern uint32_t off_136864;
extern uint32_t dword_136860;
extern uint32_t dword_136868;
extern uint32_t dword_13686C;

// sub_136828 @ 0x136828, size 52 bytes
uint32_t *sub_136828()
{
  if ( **(int16_t **)off_13685C >= 0 || !*((uint32_t *)off_136864 + 1) )
    return bt_xtal_init_check((uint32_t *)dword_136860);
  sub_12F694(dword_136868, dword_13686C, 46);
  return bt_xtal_init_check((uint32_t *)dword_136860);
}

