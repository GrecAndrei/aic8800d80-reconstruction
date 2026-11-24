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


extern uint32_t off_12F5DC;
extern uint32_t off_12F5E0;
extern uint32_t off_12F5E4;

// check_chip_mode @ 0x12f588, size 82 bytes
int  check_chip_mode(int result)
{
  int v1; // r4
  char *v2; // r0
  char *v3; // r5
  uint32_t *v4; // r4

  if ( **(uint8_t **)off_12F5DC == 3 )
  {
    v1 = result;
    v2 = (char *)controller_config_read();
    v3 = v2;
    if ( v2 )
    {
      *(uint32_t *)(v1 + 24) = 49374;
      memcpy(v2, (char *)v1, 0x1Cu);
      v4 = off_12F5E0;
      while ( !*(uint32_t *)off_12F5E0 )
        ;
      cmd_handler_a(((uint32_t *)(uintptr_t)off_12F5E4)[0] + 604, (uint32_t *)v3 - 1);
      *v4 = 1;
      gpio_set_pin7();
    }
    else
    {
      return event_dispatch(aErrUfHostRxBuf);
    }
  }
  return result;
}
