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

extern uint32_t dword_125EE8;
extern uint32_t dword_125ECC;
extern uint32_t dword_125ED0;
extern uint32_t dword_125ED4;
extern uint32_t dword_125ED8;
extern uint32_t dword_125EDC;
extern uint32_t dword_125EE0;
extern uint32_t off_125EE4;
extern uint32_t dword_125EEC;

// sub_125E18 @ 0x125e18, size 178 bytes
int  sub_125E18(int a1, int a2)
{
  uint8_t *v3; // r1
  uint8_t *v5; // r1
  int v6; // r0
  int v7; // r0
  int v8; // [sp+4h] [bp-4h]

  if ( a1 <= 1 )
  {
    sub_11F504(dword_125EE8);
    return -1;
  }
  else
  {
    if ( sub_1288C0(*(uint32_t *)(a2 + 4)) == 1 || sub_1288C0(*(uint32_t *)(a2 + 4)) == 2 )
    {
      if ( sub_1288C0(*(uint32_t *)(a2 + 4)) == 1 )
      {
        v3 = *(uint8_t **)(a2 + 4);
        if ( !v3 || !sub_1247A4((uint8_t **)dword_125ECC, v3) )
        {
LABEL_7:
          sub_11F504(dword_125ED0);
          return 0;
        }
      }
      else
      {
        if ( sub_1288C0(*(uint32_t *)(a2 + 4)) != 2 )
          return 0;
        v5 = *(uint8_t **)(a2 + 4);
        if ( !v5 || !sub_1247A4((uint8_t **)dword_125ED4, v5) )
          goto LABEL_7;
      }
      sub_11F504(dword_125ED8);
      v8 = *(uint32_t *)(a2 + 4);
      v6 = sub_1288C0(v8);
      sub_1282E8(dword_125EDC, v8, v6);
      sub_11F504(dword_125EE0, dword_125EDC);
      if ( (*(uint32_t *)off_125EE4 & 0x2000000) == 0 )
        sub_114844(dword_125EDC);
      return 0;
    }
    v7 = sub_1288C0(*(uint32_t *)(a2 + 4));
    sub_11F504(dword_125EEC, v7);
    return -1;
  }
}

