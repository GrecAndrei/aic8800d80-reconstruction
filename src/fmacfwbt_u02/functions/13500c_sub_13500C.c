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

extern uint32_t off_13501C;

// sub_13500C @ 0x13500c, size 14 bytes
// Doc: sub_123500C [unknown]: Stub: compares r5 against 0x38 and moves value
// sub_123500C [unknown]: Stub: compares r5 against 0x38 and moves value
int sub_13500C()
{
  if ( *((uint8_t *)off_13501C + 4) )
    return bt_state_poll_n_cac();
  else
    return sub_134B30();
}

