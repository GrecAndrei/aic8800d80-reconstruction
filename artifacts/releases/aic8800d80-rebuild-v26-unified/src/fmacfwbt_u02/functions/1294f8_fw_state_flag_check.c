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

extern uint32_t off_129590;
extern uint32_t dword_129598;
extern uint32_t dword_129594;
extern uint32_t off_1295A0;
extern uint32_t off_12959C;
extern uint32_t off_1295A4;
extern uint32_t off_1295A8;
extern uint32_t off_1295AC;
extern uint32_t off_1295B4;
extern uint32_t off_1295B0;

// fw_state_flag_check @ 0x1294f8, size 150 bytes
// Doc: fw_state_flag_check [util]: Check firmware global state flag at 0x190d1c
// fw_state_flag_check [util]: Check firmware global state flag at 0x190d1c
void  fw_state_flag_check(int a1)
{
  uint8_t *v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r1
  int v5; // r0
  uint32_t *v6; // r3

  v1 = off_129590;
  if ( *(uint8_t *)off_129590 )
  {
    v2 = *(uint8_t *)(a1 + 29);
    if ( v2 != 255 && *(uint8_t *)(a1 + 27) != 255 )
    {
      v3 = dword_129598 + 1320 * *(uint8_t *)(dword_129594 + 696 * v2 + 34);
      if ( !*(uint8_t *)(v3 + 106) )
      {
        if ( *(uint8_t *)(v3 + 108) )
        {
          v4 = *((uint32_t *)off_1295A0 + 4);
          v5 = *(uint16_t *)(*(uint32_t *)off_12959C + 54);
          *((uint32_t *)off_129590 + 5) = v3;
          v1[29] = 3;
          timestamp_update_4f60((int)(v1 + 12), v4 + v5);
          if ( (*(uint32_t *)off_1295A4 & 4) != 0 )
          {
            if ( *((uint8_t *)off_1295A8 + 190) )
            {
              if ( **(uint8_t **)off_1295AC == 2 )
              {
                v6 = off_1295B4;
                *(uint32_t *)off_1295B0 &= ~0x200u;
                *v6 &= ~1u;
                *v6 &= ~0x80u;
              }
            }
            bt_msg_post_n2cc();
          }
        }
      }
    }
  }
}

