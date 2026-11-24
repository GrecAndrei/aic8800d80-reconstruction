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


extern uint32_t dword_112EE0;
extern uint32_t off_112ED8;
extern uint32_t off_112EDC;
extern uint32_t off_112EE8;
extern uint32_t off_112EF0;

// set_event_mode @ 0x112e28, size 174 bytes
int  set_event_mode(int a1, int a2, int a3)
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

  v3 = (uint8_t *)off_112ED8;
  if ( a3 )
    v4 = 3;
  else
    v4 = 2;
  *(uint8_t *)off_112ED8 = v4;
  if ( *v3 == 2 )
  {
    v5 = off_112EDC;
    v6 = *(uint8_t *)off_112EDC;
    *v3 = 0;
    if ( v6 )
    {
      v7 = dword_112EE0;
      v8 = dword_112EE0 - 8;
      do
      {
        while ( 1 )
        {
          v9 = list_pop_front(v7);
          v10 = *(uint32_t *)(v9[1] + 4);
          --*v5;
          check_kernel_state(v8, v9);
          v11 = *(uint8_t *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(uint16_t *)off_112EE8;
          set_busy_flag_alt(1024);
          if ( !*v5 )
            goto LABEL_12;
        }
        if ( v11 == 1 )
        {
          mem_free((uint32_t *)v10);
        }
        else
        {
          log_printf("###err### %x\r\n", v10);
          handle_ipc_request(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
LABEL_12:
    process_event();
    return 1;
  }
  else
  {
    log_printf("usb wlan send err %d\n", *v3);
    lookup_task_id(off_112EF0);
    return 1;
  }
}
