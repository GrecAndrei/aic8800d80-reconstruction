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

extern uint32_t off_12F49C;
extern uint32_t off_12F4A0;
extern uint32_t off_12F4A4;
extern uint32_t dword_12F4A8;

// state_check_0x182ba0_b @ 0x12f448, size 82 bytes
void  state_check_0x182ba0_b(int a1)
{
  int v2; // r0
  int v3; // r5
  uint32_t *v4; // r4

  if ( **(uint8_t **)off_12F49C == 3 )
  {
    v2 = invoke_alt_handler();
    v3 = v2;
    if ( v2 )
    {
      *(uint32_t *)(a1 + 24) = 49374;
      memcpy(v2, a1, 28);
      v4 = off_12F4A0;
      while ( !*(uint32_t *)off_12F4A0 )
        ;
      wlan_ioctl_handler_1(*(uint32_t *)off_12F4A4 + 604, (uint32_t *)(v3 - 4));
      *v4 = 1;
      rf_cmd_reset();
    }
    else
    {
      alloc_tx_event(dword_12F4A8);
    }
  }
}

