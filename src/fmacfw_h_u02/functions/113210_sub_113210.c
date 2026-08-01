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

extern uint32_t off_113294;
extern uint32_t off_113298;
extern uint32_t dword_1132A8;
extern uint32_t dword_1132A4;
extern uint32_t off_11329C;
extern uint32_t dword_1132AC;
extern uint32_t off_1132A0;

// bt_get_state @ 0x113210, size 130 bytes
int  bt_get_state(int a1, unsigned int a2)
{
  uint8_t *v2; // r4
  uint8_t *v3; // r6
  uint32_t *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = off_113294;
  if ( *(uint8_t *)off_113294 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_113298;
  if ( *(uint8_t *)off_113298 )
  {
    debug_printf(dword_1132A8, dword_1132A4, *(uint8_t *)off_113298);
    return -3;
  }
  else
  {
    v4 = off_11329C;
    *(uint8_t *)off_113298 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = mac_read_queue_reg(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      debug_printf(dword_1132AC, dword_1132A4, v5);
      return -1;
    }
    else
    {
      *(uint8_t *)off_1132A0 = 1;
      if ( *v2 )
      {
        wlan_ctrl_check(0, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}

