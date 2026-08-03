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

extern uint32_t off_133A54;
extern uint32_t dword_133A5C;
extern uint32_t dword_133A58;

// sub_133A18 @ 0x133a18, size 58 bytes
int  sub_133A18(int a1, int a2)
{
  if ( **(int16_t **)off_133A54 >= 0 || msg_get_value(6u) == 7 )
  {
    sub_135C9C(a2);
    return 1;
  }
  else
  {
    sub_12F694(dword_133A5C, dword_133A58, 1012);
    sub_135C9C(a2);
    return 1;
  }
}

