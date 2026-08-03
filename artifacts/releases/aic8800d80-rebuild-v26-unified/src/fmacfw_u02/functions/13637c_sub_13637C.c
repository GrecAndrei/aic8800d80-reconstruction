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

extern uint32_t off_136408;
extern uint32_t dword_136418;
extern uint32_t dword_136410;
extern uint32_t off_13640C;
extern uint32_t dword_136414;

// sub_13637C @ 0x13637c, size 140 bytes
int sub_13637C()
{
  int16_t **v0; // r4

  v0 = (int16_t **)off_136408;
  if ( **(int16_t **)off_136408 < 0 && sub_12CE88(7u) != 1 && sub_12CE88(7u) && sub_12CE88(7u) != 3 )
    sub_12F46C(dword_136418, dword_136410, 341);
  if ( sub_12CE88(7u) == 1 )
  {
    if ( **v0 < 0 && *((uint32_t *)off_13640C + 1) )
      sub_12F46C(dword_136414, dword_136410, 349);
    sub_13698C();
  }
  else if ( sub_12CE88(7u) == 3 )
  {
    sub_12CA10(7171, 13, 7);
    sub_12CD34(7u, 0);
  }
  return 0;
}

