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


extern uint32_t dword_11360C;
extern uint32_t off_113604;
extern uint32_t off_113608;
extern uint32_t off_113614;
extern uint32_t off_11361C;

// set_mode_flag @ 0x113558, size 172 bytes
int  set_mode_flag(int a1, int a2, int a3)
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

  v3 = (uint8_t *)off_113604;
  if ( a3 )
    v4 = 3;
  else
    v4 = 2;
  *(uint8_t *)off_113604 = v4;
  if ( *v3 == 2 )
  {
    v5 = off_113608;
    v6 = *(uint8_t *)off_113608;
    *v3 = 0;
    if ( v6 )
    {
      v7 = dword_11360C;
      v8 = dword_11360C - 8;
      do
      {
        while ( 1 )
        {
          v9 = mem_word_load(v7);
          v10 = *(uint32_t *)(v9[1] + 4);
          --*v5;
          cmd_handler_a(v8, v9);
          v11 = *(uint8_t *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(uint16_t *)off_113614;
          unknown_func_12d104(128);
          if ( !*v5 )
            goto LABEL_12;
        }
        if ( v11 == 1 )
        {
          is_controller_mode((uint32_t *)v10);
        }
        else
        {
          log_printf("###err### %x\r\n", v10);
          send_msg(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
LABEL_12:
    check_init_flag();
    return 1;
  }
  else
  {
    log_printf("usb wlan send err %d\n", *v3);
    is_current_task(off_11361C);
    return 1;
  }
}
