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

extern uint32_t off_13463C;
extern uint32_t off_134644;
extern uint32_t off_134640;
extern uint32_t dword_134648;
extern uint32_t dword_13464C;

// sub_134608 @ 0x134608, size 52 bytes
uint32_t *sub_134608()
{
  if ( **(int16_t **)off_13463C >= 0 || !*((uint32_t *)off_134644 + 6) )
    return bt_xtal_init_check(off_134640);
  sub_12F694(dword_134648, dword_13464C, 132);
  return bt_xtal_init_check(off_134640);
}

