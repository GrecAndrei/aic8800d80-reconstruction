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

extern uint32_t off_133A88;
extern uint32_t dword_133AA0;
extern uint32_t dword_133A9C;
extern uint32_t off_133A8C;
extern uint32_t off_133A90;
extern uint32_t dword_133A94;
extern uint32_t dword_133A98;

// sub_13397C @ 0x13397c, size 266 bytes
int sub_13397C()
{
  int v0; // r2
  unsigned int v1; // r3
  uint8_t *v2; // r3
  uint8_t *v4; // r4
  int v5; // r3
  int v6; // r1
  int v7; // [sp+0h] [bp-Ch] BYREF
  int v8; // [sp+4h] [bp-8h] BYREF

  if ( **(int16_t **)off_133A88 < 0 && sub_12CD48(6u) != 4 && sub_12CD48(6u) != 10 )
    sub_12F32C(dword_133AA0, dword_133A9C, 697);
  if ( sub_12CD48(6u) == 10 )
  {
    v4 = off_133A8C;
    v5 = *((uint8_t *)off_133A8C + 4);
    *(uint32_t *)(*((uint32_t *)off_133A8C + 2) + 472) = 0;
    if ( v5 )
    {
      sub_12C8D0(6148, 13, 6);
      v4[4] = 0;
    }
    sub_12C84C(*(uint32_t *)v4 + 12);
    v6 = (uint8_t)v4[33];
    *(uint32_t *)v4 = 0;
    if ( v6 )
    {
      v7 = 0;
      v8 = 0;
      sub_134334(&v7, &v8);
      sub_134480(v7, v8, 0);
    }
    else
    {
      sub_12CBF4(6u, 0);
    }
    return 0;
  }
  else
  {
    v0 = *((uint32_t *)off_133A8C + 4);
    v1 = *(uint8_t *)(v0 + 59);
    if ( v1 == 2 )
    {
      if ( (*(uint32_t *)(v0 + 48) & 0x40) != 0 )
      {
        sub_135224();
        v2 = off_133A90;
        if ( *((uint8_t *)off_133A90 + 13) )
        {
LABEL_6:
          if ( (v2[15] & 1) != 0 )
          {
            sub_12C4A4(6155, 6, dword_133A94);
            sub_10D0F4();
          }
        }
        return 0;
      }
LABEL_5:
      sub_135028(1, 0);
      v2 = off_133A90;
      if ( *((uint8_t *)off_133A90 + 13) )
        goto LABEL_6;
      return 0;
    }
    if ( v1 <= 2 )
      goto LABEL_5;
    if ( v1 == 3 )
    {
      sub_135710(dword_133A98);
      if ( *((uint8_t *)off_133A90 + 13) )
        *((uint8_t *)off_133A90 + 15) |= 2u;
      return 0;
    }
    sub_134CC4(1);
    return 0;
  }
}

