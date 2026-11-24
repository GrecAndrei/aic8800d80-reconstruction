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


extern uint32_t off_113230;
extern uint32_t off_113234;
extern uint32_t off_113238;
extern uint32_t off_11323C;

// global_env_init @ 0x1131ac, size 130 bytes
int  global_env_init(int a1, int a2)
{
  uint8_t *v2; // r4
  uint8_t *v3; // r6
  uint32_t *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = off_113230;
  if ( *(uint8_t *)off_113230 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_113234;
  if ( *(uint8_t *)off_113234 )
  {
    printf_wrapper("err: %s state=%d\r\n", aUsbWlanRecv, *(uint8_t *)off_113234);
    return -3;
  }
  else
  {
    v4 = off_113238;
    *(uint8_t *)off_113234 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = ke_msg_handler_1(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      printf_wrapper("err: %s ret=%d\r\n", aUsbWlanRecv, v5);
      return -1;
    }
    else
    {
      *(uint8_t *)off_11323C = 1;
      if ( *v2 )
      {
        rf_reg_write_alias(0, 1, 0);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}
