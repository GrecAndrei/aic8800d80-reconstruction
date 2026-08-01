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

extern uint32_t off_1005A0;

// store_byte_value @ 0x10058c, size 18 bytes
int  store_byte_value(int a1)
{
  int result; // r0

  result = read_control_reg(a1);
  if ( *(uint8_t *)off_1005A0 != result )
    *(uint8_t *)off_1005A0 = result;
  return result;
}

