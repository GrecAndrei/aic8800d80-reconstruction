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

extern uint32_t off_134E00;

// sub_134DF0 @ 0x134df0, size 14 bytes
// Doc: sub_1234df0 [unknown]: Generic FMAC stub function with constant setup
// sub_1234df0 [unknown]: Generic FMAC stub function with constant setup
int sub_134DF0()
{
  if ( *((uint8_t *)off_134E00 + 4) )
    return sub_134A90();
  else
    return sub_134914();
}

