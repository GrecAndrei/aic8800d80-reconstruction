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

extern uint32_t off_112ED8;
extern uint32_t off_112EDC;
extern uint32_t dword_112EE0;
extern uint32_t dword_112EE4;
extern uint32_t off_112EE8;
extern uint32_t dword_112EEC;
extern uint32_t dword_112EF0;

// set_event_mode @ 0x112e28, size 174 bytes
int  set_event_mode(int f594, int a2, int a3)
{
  uint8_t *v3; // r5
  char v4; // r3
  uint8_t *v5; // r4
  int v6; // r3
  int v7; // r5
  int v8; // r7
  int v9; // r6
  int v10; // r8
  int v11; // r3
  int v13; // r4

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
      v8 = dword_112EE4;
      v9 = dword_112EE0 - 8;
      do
      {
        while ( 1 )
        {
          v10 = *(uint32_t *)(*(uint32_t *)(list_pop_front(v7) + 4) + 4);
          --*v5;
          check_kernel_state(v9);
          v11 = *(uint8_t *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(uint16_t *)off_112EE8;
          f594 = set_busy_flag_alt(1024);
          if ( !*v5 )
            goto LABEL_12;
        }
        if ( v11 == 1 )
        {
          f594 = mem_free((uint32_t *)v10);
        }
        else
        {
          log_printf(v8);
          f594 = handle_ipc_request(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
LABEL_12:
    process_event(f594, a2);
    return 1;
  }
  else
  {
    v13 = f594;
    log_printf(dword_112EEC, *v3);
    lookup_task_id(dword_112EF0, v13, a2, *v3);
    return 1;
  }
}

