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

extern uint32_t dword_10DE88;
extern uint32_t off_10DE8C;
extern uint32_t dword_10DE90;

// ble_phy_decode @ 0x10de38, size 78 bytes
int  ble_phy_decode(int a1)
{
  int v1; // r4
  int result; // r0
  BOOL v3; // r4
  int v4; // r5

  v1 = BYTE2(a1);
  result = log_printf(dword_10DE88, BYTE2(a1));
  if ( v1 == 3 )
  {
    v3 = gpio_read_bit(3);
    if ( v3 )
    {
      v4 = 1;
    }
    else
    {
      if ( *((uint8_t *)off_10DE8C + 369) )
        gpio_set_bit(2);
      else
        gpio_clear_bit(2);
      v4 = 2;
    }
    log_printf(dword_10DE90, v3);
    return check_arg_one(v4);
  }
  return result;
}

