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

extern uint32_t off_12BE64;
extern uint32_t off_12BE68;
extern uint32_t dword_12BE80;
extern uint32_t dword_12BE7C;
extern uint32_t off_12BE6C;
extern uint32_t off_12BE90;
extern uint32_t off_12BE94;
extern uint32_t dword_12BE98;
extern uint32_t off_12BE70;
extern uint32_t off_12BE74;
extern uint32_t off_12BE78;
extern uint32_t dword_12BE84;
extern uint32_t dword_12BE8C;
extern uint32_t dword_12BEAC;
extern uint32_t dword_12BEA8;
extern uint32_t dword_12BEA4;
extern uint32_t dword_12BEA0;
extern uint32_t dword_12BE9C;
extern uint32_t dword_12BE88;

// sub_12BD4C @ 0x12bd4c, size 280 bytes
int  sub_12BD4C(int a1, int a2)
{
  void *v2; // r2
  int v3; // r4
  int result; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r0
  int v10; // r2
  char *v11; // r4
  int v12; // r1
  int v13; // r2

  v2 = off_12BE64;
  v3 = *(uint32_t *)off_12BE64;
  *(uint32_t *)off_12BE68 = *(uint32_t *)off_12BE64;
  result = v3 << 21;
  if ( (v3 & 0x400) != 0 )
  {
    sub_12E948(dword_12BE80, a2, v2);
    while ( 1 )
      ;
  }
  v5 = v3 << 23;
  if ( (v3 & 0x100) == 0 )
  {
    v6 = v3 << 22;
    if ( (v3 & 0x200) == 0 )
      goto LABEL_4;
LABEL_13:
    sub_12E948(dword_12BE7C, v5, v6);
    while ( 1 )
      ;
  }
  result = sub_11D694();
  v6 = v3 << 22;
  if ( (v3 & 0x200) != 0 )
    goto LABEL_13;
LABEL_4:
  if ( (v3 & 0x10) != 0 )
  {
    sub_116DF4(4);
    result = sub_11735C(4);
  }
  if ( (v3 & 0x2F) != 0 )
  {
    if ( *(uint8_t *)off_12BE6C )
    {
      v11 = (char *)off_12BE90;
      sub_102AD0(*((uint8_t *)off_12BE90 + 411));
      v12 = v11[411];
      *((uint8_t *)off_12BE94 + 9) = v12;
      return sub_12E948(dword_12BE98, v12, v13);
    }
    if ( *(uint8_t *)off_12BE70 )
    {
      result = *(uint32_t *)off_12BE74 << 28;
      if ( result )
        *((uint8_t *)off_12BE70 + 6) = 1;
    }
  }
  v7 = **(int16_t **)off_12BE78;
  if ( v7 < 0 )
  {
    if ( (v3 & 1) != 0 )
    {
      v8 = dword_12BE84;
      v9 = dword_12BE8C;
      v10 = 760;
    }
    else if ( (v3 & 2) != 0 )
    {
      v8 = dword_12BE84;
      v9 = dword_12BEAC;
      v10 = 761;
    }
    else
    {
      v7 = v3 << 29;
      if ( (v3 & 4) != 0 )
      {
        v8 = dword_12BE84;
        v9 = dword_12BEA8;
        v10 = 762;
      }
      else
      {
        result = v3 << 28;
        if ( (v3 & 8) != 0 )
        {
          v8 = dword_12BE84;
          v9 = dword_12BEA4;
          v10 = 763;
        }
        else if ( (v3 & 0x80) != 0 )
        {
          v8 = dword_12BE84;
          v9 = dword_12BEA0;
          v10 = 765;
        }
        else if ( (v3 & 0x40) != 0 )
        {
          v8 = dword_12BE84;
          v9 = dword_12BE9C;
          v10 = 767;
        }
        else
        {
          v7 = v3 << 26;
          if ( (v3 & 0x20) == 0 )
            return result;
          v8 = dword_12BE84;
          v9 = dword_12BE88;
          v10 = 769;
        }
      }
    }
    return sub_12F2C8(v9, v8, v10, v7);
  }
  return result;
}

