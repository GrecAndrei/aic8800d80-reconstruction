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

extern uint32_t off_1336B0;
extern uint32_t dword_1336B8;
extern uint32_t dword_1336B4;

// sub_13367C @ 0x13367c, size 52 bytes
int  sub_13367C(int a1)
{
  int v2; // r0

  if ( **(int16_t **)off_1336B0 >= 0 || (a1 = sub_12CD48(6u), a1 == 10) )
  {
    sub_134CB0(a1);
    return 0;
  }
  else
  {
    v2 = sub_12F32C(dword_1336B8, dword_1336B4, 1038);
    sub_134CB0(v2);
    return 0;
  }
}

