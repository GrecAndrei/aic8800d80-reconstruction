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
extern uint32_t dword_11346C;
extern uint32_t off_113470;
extern uint32_t dword_113474;
extern uint32_t dword_113478;

// rf_cmd_process @ 0x1133b4, size 172 bytes
// Doc: rf_msg_handler_n4ce [rf]: Handle incoming RF messages from host
// rf_msg_handler_n4ce [rf]: Handle incoming RF messages from host
int  rf_cmd_process(int ed40, int a2, int a3)
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

  v3 = (uint8_t *)rf_stream_start2_n214;
  if ( a3 )
    v4 = 3;
  else
    v4 = 2;
  *(uint8_t *)rf_stream_start2_n214 = v4;
  if ( *v3 == 2 )
  {
    v5 = rf_mem_read_n_480;
    v6 = *(uint8_t *)rf_mem_read_n_480;
    *v3 = 0;
    if ( v6 )
    {
      v7 = dword_113468;
      v8 = dword_11346C;
      v9 = dword_113468 - 8;
      do
      {
        while ( 1 )
        {
          v10 = *(uint32_t *)(*(uint32_t *)(sub_12D4F8(v7) + 4) + 4);
          --*v5;
          list_push_tail(v9);
          v11 = *(uint8_t *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(uint16_t *)off_113470;
          ed40 = irq_nesting_or(128);
          if ( !*v5 )
            goto rf_msg_handler_n4d0;
        }
        if ( v11 == 1 )
        {
          ed40 = log_free_dispatch_2((uint32_t *)v10);
        }
        else
        {
          log_printf(v8);
          ed40 = rf_mem_read_ed40(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
rf_msg_handler_n4d0:
    phy_reg_init_n_2c4(ed40, a2);
    return 1;
  }
  else
  {
    v13 = ed40;
    log_printf(dword_113474, *v3);
    sub_114024(dword_113478, v13, a2, *v3);
    return 1;
  }
}

