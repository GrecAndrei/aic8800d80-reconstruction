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

extern uint32_t off_136284;
extern uint32_t dword_13628C;
extern uint32_t dword_136288;

// sub_13623C @ 0x13623c, size 70 bytes
int sub_13623C()
{
  if ( **(int16_t **)off_136284 < 0 && msg_get_value(7u) != 3 && msg_get_value(7u) )
    sub_12F46C(dword_13628C, dword_136288, 442);
  if ( msg_get_value(7u) == 3 )
    sub_136820(3);
  return 0;
}

