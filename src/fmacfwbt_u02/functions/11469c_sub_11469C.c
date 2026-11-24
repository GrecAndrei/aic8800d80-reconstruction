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


extern uint32_t off_1146C8;

// invoke_callback @ 0x11469c, size 44 bytes
int  invoke_callback(int *a1)
{
  int result; // r0

  if ( *(uint32_t *)off_1146C8 )
    return check_abort_flag(off_1146C8, a1);
  result = sys_control((int)(a1 + 1), *a1);
  if ( result )
  {
    ke_event_schedule_1("sdio bt MB send err %d\n", result);
    return check_abort_flag(off_1146C8, a1);
  }
  return result;
}
