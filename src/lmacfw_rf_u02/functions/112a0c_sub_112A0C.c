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


extern uint32_t dword_112B50;
extern uint32_t dword_112B54;
extern uint32_t off_112B40;
extern uint32_t off_112B44;
extern uint32_t off_112B48;
extern uint32_t off_112B4C;
extern uint32_t off_112B5C;
extern uint32_t off_112B64;
extern uint32_t off_112B78;

// tick_counter_update @ 0x112a0c, size 308 bytes
int  tick_counter_update(uint8_t *a1, unsigned int a2, int a3)
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

  v3 = (uint16_t *)off_112B40;
  v4 = (uint8_t *)off_112B44;
  v5 = off_112B48;
  ++*(uint16_t *)off_112B40;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *v4 = v6;
  *v5 = 0;
  if ( *v4 != 2 )
  {
    log_printf("usb wlan recv err %X %d\n", *v3, *v4);
    lookup_task_id(off_112B5C);
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
    if ( *(uint8_t *)off_112B4C )
      check_interrupt_flag(512, "R:%d\n", a2);
    if ( v9 == 17 )
    {
      v11 = off_112B78;
      if ( *((uint8_t *)off_112B78 + 2433) >= (unsigned int)*((uint8_t *)off_112B78 + 2434) )
      {
        log_printf(aErrNoRxMsgElem);
      }
      else
      {
        if ( v10 + 4 == a2 || a2 == v10 + 5 )
        {
          check_and_process();
          v12 = v11[2433];
          v13 = dword_112B54;
          v14 = (uint8_t)v11[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)dword_112B50
                               * (uint64_t)((unsigned int)(uint8_t)v11[2432] + 1)) >> 32) >> 5);
          v11[2432] = v14;
          v15 = &v11[20 * v14];
          v15[409] = a1 + 4;
          v15[412] = v10;
          v11[2433] = v12 + 1;
          check_kernel_state(v13, v15 + 408);
          set_busy_flag_alt(0x1000000);
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
  mem_free(&a1[-*(uint32_t *)off_112B64]);
  check_and_process();
  return 1;
}
