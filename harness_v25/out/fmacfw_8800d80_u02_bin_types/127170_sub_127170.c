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

extern uint32_t off_127284;
extern uint32_t off_12727C;
extern uint32_t dword_127280;
extern uint32_t dword_127298;
extern uint32_t dword_12729C;
extern uint32_t dword_127288;
extern uint32_t off_12728C;
extern uint32_t dword_127294;
extern uint32_t dword_127290;

// sub_127170 @ 0x127170, size 266 bytes
int  sub_127170(int result)
{
  uint8_t *v1; // r5
  uint64_t v2; // r6
  int v3; // r4
  char v4; // r3
  int v5; // r4
  int v6; // r9
  int v7; // r10
  int v8; // r7
  int v9; // r3
  int v10; // r11
  int v11; // r1
  int v12; // r0

  v1 = off_127284;
  LODWORD(v2) = result;
  HIDWORD(v2) = *((uint32_t *)off_12727C + 4) + *(uint32_t *)(result + 20);
  if ( result != dword_127280 || (*((uint8_t *)off_127284 + 88) & 4) != 0 )
  {
    if ( *((uint32_t *)off_127284 + 10) != result )
    {
      result = sub_1019F0();
      HIDWORD(v2) += 4000 + result;
    }
    v3 = (uint8_t)v1[91];
    v4 = v1[88];
    *((uint64_t *)v1 + 10) = v2;
    if ( v3 )
    {
      v1[88] = v4 | 0x40;
    }
    else
    {
      v1[88] = v4 & 0xBF;
      bt_event_handler();
      result = sub_126714(SHIDWORD(v2), 0, 0);
      v5 = *((uint32_t *)v1 + 4);
      if ( v5 )
      {
        v6 = dword_127298;
        v7 = dword_12729C;
        v8 = dword_127288 - HIDWORD(v2);
        while ( 1 )
        {
          v10 = *(uint32_t *)(v5 + 4);
          result = v10 - sub_1019F0();
          if ( result + v8 >= 0 )
            break;
          v11 = *(uint32_t *)(v5 + 4);
          v12 = v6 + 1320 * *(uint8_t *)(v5 + 8);
          v9 = 102400;
          if ( *(uint8_t *)(v12 + 106) )
          {
            if ( *(uint8_t *)(v12 + 106) == 2 )
              v9 = *(uint16_t *)(v12 + 222) << 10;
            result = sub_126584(v12, v11 + v9, 0);
            v5 = *((uint32_t *)v1 + 4);
            if ( !v5 )
              break;
          }
          else
          {
            result = sub_126584(v12, v11 + *(uint32_t *)(v7 + 696 * *(uint8_t *)(v12 + 116) + 8), 0);
            v5 = *((uint32_t *)v1 + 4);
            if ( !v5 )
              break;
          }
        }
      }
      if ( *((uint32_t *)v1 + 11) )
      {
        if ( **(int16_t **)off_12728C < 0 && (v1[88] & 0xC) == 0 )
          return sub_12F46C(dword_127294, dword_127290, 1698);
      }
      else
      {
        return sub_1270CC(v2);
      }
    }
  }
  else
  {
    *((uint8_t *)off_127284 + 88) &= ~0x40u;
  }
  return result;
}

