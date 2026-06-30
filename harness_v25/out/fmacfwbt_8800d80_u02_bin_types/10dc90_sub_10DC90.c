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

extern uint32_t dword_10DCE0;
extern uint32_t off_10DCE4;
extern uint32_t dword_10DCE8;

// sub_10DC90 @ 0x10dc90, size 78 bytes
int  sub_10DC90(int a1)
{
  int v1; // r4
  int result; // r0
  BOOL v3; // r4
  int v4; // r5

  v1 = BYTE2(a1);
  result = sub_10DA7C(dword_10DCE0, BYTE2(a1));
  if ( v1 == 3 )
  {
    v3 = sub_10DB84(3);
    if ( v3 )
    {
      v4 = 1;
    }
    else
    {
      if ( *((uint8_t *)off_10DCE4 + 369) )
        sub_10DB58(2);
      else
        sub_10DB6C(2);
      v4 = 2;
    }
    sub_10DA7C(dword_10DCE8, v3);
    return sub_10D204(v4);
  }
  return result;
}

