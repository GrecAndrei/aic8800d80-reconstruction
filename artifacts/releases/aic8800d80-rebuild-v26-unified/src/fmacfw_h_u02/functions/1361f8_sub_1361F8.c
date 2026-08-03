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

extern uint32_t off_136230;
extern uint32_t dword_136238;
extern uint32_t dword_136234;

// sub_1361F8 @ 0x1361f8, size 56 bytes
int sub_1361F8()
{
  if ( **(int16_t **)off_136230 >= 0 || sub_12CD48(7u) == 2 )
  {
    sub_1365F4(0);
    return 0;
  }
  else
  {
    sub_12F32C(dword_136238, dword_136234, 388);
    sub_1365F4(0);
    return 0;
  }
}

