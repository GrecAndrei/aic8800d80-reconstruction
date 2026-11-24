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


extern uint32_t dword_113468;
extern uint32_t off_113460;
extern uint32_t off_113464;
extern uint32_t off_113470;
extern uint32_t off_113478;

// rf_calib_mode_set @ 0x1133b4, size 172 bytes
int  rf_calib_mode_set(int a1, int a2, int a3)
{
  uint8_t *v3; // r5
  char v4; // r3
  uint8_t *v5; // r4
  int v6; // r3
  int v7; // r5
  int v8; // r6
  uint32_t *v9; // r0
  int v10; // r8
  int v11; // r3

  v3 = (uint8_t *)off_113460;
  if ( a3 )
    v4 = 3;
  else
    v4 = 2;
  *(uint8_t *)off_113460 = v4;
  if ( *v3 == 2 )
  {
    v5 = off_113464;
    v6 = *(uint8_t *)off_113464;
    *v3 = 0;
    if ( v6 )
    {
      v7 = dword_113468;
      v8 = dword_113468 - 8;
      do
      {
        while ( 1 )
        {
          v9 = list_pop_front(v7);
          v10 = *(uint32_t *)(v9[1] + 4);
          --*v5;
          check_abort_flag(v8, v9);
          v11 = *(uint8_t *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(uint16_t *)off_113470;
          set_system_flag_1(128);
          if ( !*v5 )
            goto LABEL_12;
        }
        if ( v11 == 1 )
        {
          memory_pool_free((uint32_t *)v10);
        }
        else
        {
          printf_wrapper("###err### %x\r\n", v10);
          rx_packet_handler_2(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
LABEL_12:
    rf_calib_init();
    return 1;
  }
  else
  {
    printf_wrapper("usb wlan send err %d\n", *v3);
    band_is_supported(off_113478);
    return 1;
  }
}
