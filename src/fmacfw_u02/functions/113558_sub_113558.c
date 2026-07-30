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

extern uint32_t off_113604;
extern uint32_t off_113608;
extern uint32_t dword_11360C;
extern uint32_t dword_113610;
extern uint32_t off_113614;
extern uint32_t dword_113618;
extern uint32_t dword_11361C;

// sub_113558 @ 0x113558, size 172 bytes
int  sub_113558(int a1, int a2, int a3)
{
  uint8_t *v3; // r5
  char v4; // r3
  uint8_t *v5; // r4
  int v6; // r3
  int v7; // r5
  int v8; // r7
  int v9; // r6
  int v10; // r8
  int v11; // r3
  int v13; // r4

  v3 = (uint8_t *)off_113604;
  if ( a3 )
    v4 = 3;
  else
    v4 = 2;
  *(uint8_t *)off_113604 = v4;
  if ( *v3 == 2 )
  {
    v5 = off_113608;
    v6 = *(uint8_t *)off_113608;
    *v3 = 0;
    if ( v6 )
    {
      v7 = dword_11360C;
      v8 = dword_113610;
      v9 = dword_11360C - 8;
      do
      {
        while ( 1 )
        {
          v10 = *(uint32_t *)(*(uint32_t *)(sub_12D2D0(v7) + 4) + 4);
          --*v5;
          sub_12D248(v9);
          v11 = *(uint8_t *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(uint16_t *)off_113614;
          a1 = sub_12D104(128);
          if ( !*v5 )
            goto LABEL_12;
        }
        if ( v11 == 1 )
        {
          a1 = sub_110008((uint32_t *)v10);
        }
        else
        {
          sub_10DC24(v8);
          a1 = sub_12EB18(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
LABEL_12:
    sub_1134B4(a1, a2);
    return 1;
  }
  else
  {
    v13 = a1;
    sub_10DC24(dword_113618, *v3);
    sub_1141C8(dword_11361C, v13, a2, *v3);
    return 1;
  }
}

