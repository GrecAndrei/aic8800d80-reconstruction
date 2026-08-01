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

extern uint32_t off_121C9C;
extern uint32_t dword_121CB8;
extern uint32_t dword_121CB4;
extern uint32_t off_121CA0;
extern uint32_t off_121CA4;
extern uint32_t off_121CA8;
extern uint32_t off_121CAC;
extern uint32_t off_121CB0;

// shared_s16_check @ 0x121c08, size 148 bytes
int shared_s16_check()
{
  int *v1; // r4
  int v2; // r3
  int v3; // r2

  if ( **(int16_t **)off_121C9C < 0 && (rx_rate_field_parse(0) == 3 || !rx_rate_field_parse(0)) )
    mmio_clear_register(dword_121CB8, dword_121CB4, 1862);
  if ( rx_rate_field_parse(0) == 2 )
  {
    *(uint32_t *)off_121CA0 = 48;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_121CA4 = 1;
    }
    v1 = (int *)off_121CA8;
    ++*(uint32_t *)off_121CA8;
    unknown_func_12d14c(0x2000000);
    if ( (*(uint32_t *)off_121CAC & 4) != 0 )
      *(uint32_t *)off_121CB0 = 4;
    if ( *v1 )
    {
      v2 = *v1 - 1;
      v3 = *(uint32_t *)off_121CA4;
      *v1 = v2;
      if ( !v2 )
      {
        if ( v3 )
          __enable_irq();
      }
    }
  }
  return rx_phy_status_parse(0);
}

