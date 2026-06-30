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

extern uint32_t dword_10DD48;
extern uint32_t off_10DD4C;
extern uint32_t dword_10DD50;

// sub_10DCF8 @ 0x10dcf8, size 78 bytes
int  sub_10DCF8(int a1)
{
  int v1; // r4
  int result; // r0
  BOOL v3; // r4
  int v4; // r5

  v1 = BYTE2(a1);
  result = sub_10DAE4(dword_10DD48, BYTE2(a1));
  if ( v1 == 3 )
  {
    v3 = sub_10DBEC(3);
    if ( v3 )
    {
      v4 = 1;
    }
    else
    {
      if ( *((uint8_t *)off_10DD4C + 369) )
        sub_10DBC0(2);
      else
        sub_10DBD4(2);
      v4 = 2;
    }
    sub_10DAE4(dword_10DD50, v3);
    return sub_10D26C(v4);
  }
  return result;
}

