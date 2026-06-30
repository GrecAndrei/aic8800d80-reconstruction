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

extern uint32_t off_118E2C;
extern uint32_t dword_118E30;
extern uint32_t dword_118E34;

// sub_118D80 @ 0x118d80, size 172 bytes
int  sub_118D80(int a1, int a2, int a3)
{
  int16_t **v3; // r8
  int v4; // r10
  int v5; // r9
  int v9; // r4
  int v10; // r1

  v3 = (int16_t **)off_118E2C;
  v4 = dword_118E30;
  v5 = dword_118E34;
  while ( 1 )
  {
    v9 = sub_12D4F8(a2);
    if ( !v9 )
      break;
    while ( 1 )
    {
      v10 = *(uint32_t *)(v9 + 76);
      if ( *(uint32_t *)(v9 + 68) )
      {
        *(uint32_t *)(v10 + 4) = 2080374784;
      }
      else if ( *(int *)(v10 + 4) >= 0 )
      {
        *(uint32_t *)(v10 + 4) = 0x40000000;
      }
      if ( *(uint16_t *)(v9 + 4) )
        break;
      sub_119120(v9);
      v9 = sub_12D4F8(a2);
      if ( !v9 )
        return rx_buf_init_n168();
    }
    *(uint32_t *)(v10 + 4) |= 0x800000u;
    flag_check_1218170(v9, (uint32_t *)(v10 + 4));
    sub_1164CC(v9);
    if ( sub_13B01C(v9, 1) )
    {
      if ( **v3 < 0 && !a3 )
        sub_12F694(v5, v4, 1105);
      list_push_tail(a3);
    }
    else
    {
      fmac_bt_event_handler(a1, v9);
    }
  }
  return rx_buf_init_n168();
}

