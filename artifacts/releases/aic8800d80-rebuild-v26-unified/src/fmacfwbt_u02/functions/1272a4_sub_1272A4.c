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

extern uint32_t off_1272D0;
extern uint32_t off_1272D4;

// sub_1272A4 @ 0x1272a4, size 44 bytes
int sub_1272A4()
{
  char v0; // r3
  int result; // r0

  if ( *((uint8_t *)off_1272D0 + 89) )
  {
    v0 = *((uint8_t *)off_1272D0 + 89) - 1;
    *((uint8_t *)off_1272D0 + 89) = v0;
    if ( !v0 && *(uint8_t *)off_1272D4 == 1 )
    {
      *(uint8_t *)off_1272D4 = 0;
      fw_init_or_check_1221d44();
      return sub_12726C();
    }
  }
  return result;
}

