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

// state_check_0x182ba0_b @ 0x12f448, size 82 bytes
int  state_check_0x182ba0_b(int result)
{
  int v1; // r4
  char *v2; // r0
  char *v3; // r5
  uint32_t *v4; // r4

  if ( **(uint8_t **)off_12F49C == 3 )
  {
    v1 = result;
    v2 = (char *)invoke_alt_handler();
    v3 = v2;
    if ( v2 )
    {
      *(uint32_t *)(v1 + 24) = 49374;
      memcpy_1(v2, (char *)v1, 0x1Cu);
      v4 = off_12F4A0;
      while ( !*(uint32_t *)off_12F4A0 )
        ;
      wlan_ioctl_handler_1(((uint32_t *)(uintptr_t)off_12F4A4)[0] + 604, (uint32_t *)v3 - 1);
      *v4 = 1;
      rf_cmd_reset();
    }
    else
    {
      return alloc_tx_event(aErrUfHostRxBuf);
    }
  }
  return result;
}
