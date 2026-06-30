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

extern uint32_t dword_122F9C;
extern uint32_t dword_122F94;
extern uint32_t dword_122FA0;
extern uint32_t dword_122F98;

// sub_122F3C @ 0x122f3c, size 86 bytes
int  sub_122F3C(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r3
  unsigned int v6; // r5
  unsigned int v8; // r5

  if ( a1 )
  {
    if ( a1 == 1 )
    {
      v4 = a2 << 28;
      if ( !(a2 << 28) || (v4 = a2 & 0xFFFFFFF0, (a2 & 0xFFFFFFF0) != 0) )
      {
        msg_parse(dword_122F9C, a2, a3, v4, a4);
        return -11;
      }
      else
      {
        v6 = sub_113B5C((uint8_t)a2);
        msg_parse(dword_122F94, a2, v6);
      }
    }
    else
    {
      msg_parse(dword_122FA0);
      return -21;
    }
    return v6;
  }
  else
  {
    v8 = sub_113B4C();
    msg_parse(dword_122F98, v8);
    return v8;
  }
}

