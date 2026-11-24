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


extern uint32_t dword_11327C;
extern uint32_t dword_113280;
extern uint32_t off_11326C;
extern uint32_t off_113270;
extern uint32_t off_113274;
extern uint32_t off_113278;
extern uint32_t off_113288;
extern uint32_t off_113290;
extern uint32_t off_1132A8;

// read_periph_status @ 0x113104, size 360 bytes
int  read_periph_status(uint8_t *a1, unsigned int a2, int a3)
{
  uint16_t *v3; // r7
  uint8_t *v4; // r6
  uint8_t *v5; // r4
  char v6; // r2
  int v9; // r8
  int v10; // r6
  uint8_t *v11; // r8
  char v12; // r5
  int v13; // r0
  unsigned int v14; // r3
  uint32_t *v15; // r3

  v3 = (uint16_t *)off_11326C;
  v4 = (uint8_t *)off_113270;
  v5 = off_113274;
  ++*(uint16_t *)off_11326C;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *v4 = v6;
  *v5 = 0;
  if ( *v4 != 2 )
  {
    log_printf("usb wlan recv err %X %d\n", *v3, *v4);
    is_current_task(off_113288);
    return 1;
  }
  *v4 = 0;
  if ( a2 <= 3 )
  {
    log_printf("len err %X %d\n", *v3, a2);
  }
  else
  {
    v9 = a1[2];
    v10 = *a1 | (a1[1] << 8) & 0xF00;
    if ( *(uint8_t *)off_113278 )
      check_status_bits(512, "R:%d\n", a2);
    if ( v9 == 1 )
    {
      if ( a2 == v10 || v10 + 1 == a2 )
      {
        timer_delay_1();
        check_packet_length((int)(a1 + 4));
        unknown_func_12d104(512);
        return 1;
      }
      log_printf("wdl err %X %d %d\n", *v3, v10, a2);
    }
    else if ( v9 == 17 )
    {
      v11 = off_1132A8;
      if ( *((uint8_t *)off_1132A8 + 2433) >= (unsigned int)*((uint8_t *)off_1132A8 + 2434) )
      {
        log_printf(aErrNoRxMsgElem);
      }
      else
      {
        if ( v10 + 4 == a2 || a2 == v10 + 5 )
        {
          timer_delay_1();
          v12 = v11[2433];
          v13 = dword_113280;
          v14 = (uint8_t)v11[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)dword_11327C
                               * (uint64_t)((unsigned int)(uint8_t)v11[2432] + 1)) >> 32) >> 5);
          v11[2432] = v14;
          v15 = &v11[20 * v14];
          v15[409] = a1 + 4;
          v15[412] = v10;
          v11[2433] = v12 + 1;
          cmd_handler_a(v13, v15 + 408);
          unknown_func_12d104(0x400000);
          return 1;
        }
        log_printf("wml err %X %d %d\n", *v3, v10, a2);
      }
    }
    else
    {
      log_printf("type err %X %X %d %d\r\n", *v3, v9, v10, a2);
    }
  }
  is_controller_mode(&a1[-*(uint32_t *)off_113290]);
  timer_delay_1();
  return 1;
}
