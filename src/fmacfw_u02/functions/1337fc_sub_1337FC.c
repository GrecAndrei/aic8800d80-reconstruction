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

extern uint32_t off_133838;
extern uint32_t dword_133840;
extern uint32_t dword_13383C;

// sub_1337FC @ 0x1337fc, size 58 bytes
// Doc: sub_1233806 [util]: Trampoline stub with saved r4/lr
// sub_1233806 [util]: Trampoline stub with saved r4/lr
int  sub_1337FC(int a1, int a2)
{
  if ( **(int16_t **)off_133838 >= 0 || msg_get_value(6u) == 7 )
  {
    sub_135A80(a2);
    return 1;
  }
  else
  {
    sub_12F46C(dword_133840, dword_13383C, 1012);
    sub_135A80(a2);
    return 1;
  }
}

