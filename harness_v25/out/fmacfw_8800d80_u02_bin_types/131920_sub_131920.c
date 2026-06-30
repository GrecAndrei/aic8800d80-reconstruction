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

extern uint32_t off_131968;
extern uint32_t dword_131974;
extern uint32_t dword_131970;
extern uint32_t off_13196C;

// sub_131920 @ 0x131920, size 70 bytes
int  sub_131920(int a1, int a2, unsigned int a3)
{
  int v4; // r1

  if ( **(int16_t **)off_131968 < 0 && msg_get_value(a3) != 1 )
    sub_12F46C(dword_131974, dword_131970, 822);
  v4 = *((uint16_t *)off_13196C + 4);
  if ( v4 != 255 )
    sub_12CA10(5146, v4, a3);
  sub_12CD34(a3, 0);
  return 0;
}

