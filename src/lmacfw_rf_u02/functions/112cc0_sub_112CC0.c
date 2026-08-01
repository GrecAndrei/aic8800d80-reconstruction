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

extern uint32_t off_112D64;
extern uint32_t off_112D68;
extern uint32_t dword_112D7C;
extern uint32_t dword_112D78;
extern uint32_t off_112D6C;
extern uint32_t off_112D70;
extern uint32_t dword_112D80;
extern uint32_t off_112D74;

// send_control_packet @ 0x112cc0, size 164 bytes
int  send_control_packet(int a1, unsigned int a2)
{
  uint8_t *v2; // r4
  uint8_t *v3; // r5
  int v4; // r3
  uint32_t *v5; // r2
  int v6; // r0
  int v7; // r2

  v2 = off_112D64;
  if ( *(uint8_t *)off_112D64 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_112D68;
  if ( *(uint8_t *)off_112D68 )
  {
    log_printf(dword_112D7C, dword_112D78, *(uint8_t *)off_112D68);
    return -3;
  }
  else
  {
    v4 = *(char *)off_112D6C;
    *(uint8_t *)off_112D68 = 1;
    v5 = off_112D70;
    if ( v4 )
    {
      *((uint32_t *)off_112D70 + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((uint32_t *)off_112D70 + 713) |= 1u;
    }
    v6 = rf_channel_update_dup(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      log_printf(dword_112D80, dword_112D78, v6);
      return -1;
    }
    else
    {
      *(uint8_t *)off_112D74 = 1;
      if ( *v2 )
      {
        rf_enable_tx_patch_dup(0, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}

