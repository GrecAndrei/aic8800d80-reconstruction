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

extern uint32_t dword_125FF8;
extern uint32_t dword_125FDC;
extern uint32_t dword_125FE4;
extern uint32_t dword_125FE8;
extern uint32_t dword_125FEC;
extern uint32_t off_125FF0;
extern uint32_t dword_125FE0;
extern uint32_t dword_125FF4;

// rf_lmac_dispatch_n5a8 @ 0x125f58, size 130 bytes
// Doc: rf_lmac_dispatch_n5a8 [ipc]: Branch on argument value 1, likely LMAC task dispatcher
// rf_lmac_dispatch_n5a8 [ipc]: Branch on argument value 1, likely LMAC task dispatcher
int  rf_lmac_dispatch_n5a8(int a1, int a2)
{
  uint8_t *v3; // r1
  int v5; // r0
  int v6; // [sp+4h] [bp-4h]

  if ( a1 <= 1 )
  {
    msg_parse(dword_125FF8);
    return -1;
  }
  else if ( sub_1288C0(*(uint32_t *)(a2 + 4)) == 2 )
  {
    v3 = *(uint8_t **)(a2 + 4);
    if ( v3 && rf_state_load((uint8_t **)dword_125FDC, v3) )
    {
      msg_parse(dword_125FE4);
      v6 = *(uint32_t *)(a2 + 4);
      v5 = sub_1288C0(v6);
      sub_1282E8(dword_125FE8, v6, v5);
      msg_parse(dword_125FEC, dword_125FE8);
      if ( (*(uint32_t *)off_125FF0 & 0x2000000) == 0 )
        sub_114874(dword_125FE8);
      return 0;
    }
    else
    {
      msg_parse(dword_125FE0);
      return 0;
    }
  }
  else
  {
    msg_parse(dword_125FF4);
    return -1;
  }
}

