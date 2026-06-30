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

extern uint32_t off_128BC8;
extern uint32_t dword_128BDC;
extern uint32_t off_128BD0;
extern uint32_t off_128BCC;
extern uint32_t off_128BD4;
extern uint32_t dword_128BD8;

// sub_128B2C @ 0x128b2c, size 154 bytes
int  sub_128B2C(int a1, int a2, int a3)
{
  int v4; // r0
  int v5; // r1
  int v6; // r5
  uint8_t *v7; // r3
  int v8; // r2
  int v9; // r0
  int v11; // r1

  if ( (a2 & 0x800000) != 0 )
  {
    if ( a1 )
      *(uint8_t *)(a1 + 115) = 0;
    return 1;
  }
  else
  {
    v4 = (uint8_t)(*(uint8_t *)(a1 + 115) + 1);
    v5 = *(uint32_t *)off_128BC8;
    *(uint8_t *)(a1 + 115) = v4;
    if ( *(uint8_t *)(v5 + 1) == v4 )
    {
      v11 = dword_128BDC;
      *(uint8_t *)(a1 + 115) = 0;
      feature_guard_check(1024, v11);
      send_msg_to_host_c43(a1);
      return 1;
    }
    else
    {
      v6 = *(uint8_t *)(a1 + 108);
      if ( *(uint8_t *)(a1 + 108) )
      {
        sub_118DC4(*(uint8_t *)(a1 + 116), a3, a1);
        return 0;
      }
      else
      {
        v7 = off_128BD0;
        v8 = *((uint8_t *)off_128BCC + 2);
        *((uint8_t *)off_128BD0 + 28) = 1;
        if ( v8 )
          *(uint32_t *)off_128BD4 &= ~0x80000000;
        if ( v7[8] )
          --v7[8];
        v9 = dword_128BD8;
        v7[29] = 0;
        timestamp_remove(v9);
        *(uint32_t *)(a1 + 4) &= ~0x200u;
        return v6;
      }
    }
  }
}

