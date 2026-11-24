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


extern uint32_t dword_115E84;
extern uint32_t dword_115E88;
extern uint32_t dword_115E8C;
extern uint32_t dword_115E98;
extern uint32_t dword_115EA0;
extern uint32_t dword_115EA4;
extern uint32_t dword_115EA8;
extern uint32_t dword_115EB0;
extern uint32_t dword_115EB4;
extern uint32_t dword_115EB8;
extern uint32_t dword_115EBC;
extern uint32_t dword_115EC0;
extern uint32_t dword_115EC4;

// mac_status_check @ 0x115d28, size 346 bytes
uint32_t * mac_status_check(int a1, int a2)
{
  int *v2; // r4
  uint32_t *v3; // r3
  volatile unsigned int v4; // r1
  unsigned int v5; // r1
  int v6; // r3
  uint32_t *v7; // r5
  unsigned int v8; // r5
  uint32_t *v9; // r1
  uint32_t *v10; // r0
  uint64_t v11; // kr00_8
  uint32_t *result; // r0
  int v13; // r1
  int v14; // r1
  int v15; // r3
  int v16; // r7
  int v17; // r6
  int v18; // r2
  volatile unsigned int v19; // r3

  if ( (**(uint16_t **)dword_115E84 & 1) != 0 )
    radio_init_2();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)dword_115E88 = 1;
  }
  v2 = (int *)dword_115E8C;
  ++*(uint32_t *)dword_115E8C;
  state_check_feature(1024, "%s\r\n", aRwnxlResetEvt);
  set_system_flag_2(0x80000000);
  mac_config_clear();
  v3 = (uint32_t *)dword_115E98;
  *(uint32_t *)dword_115E98 &= 0xFFFFFFu;
  *v3 |= 0x10u;
  v4 = (*(volatile uint32_t *)0x40501010u);
  v5 = v4 + 100;
  do
    v6 = v5 - (*(volatile uint32_t *)0x40501010u);
  while ( v6 >= 0 );
  v7 = (uint32_t *)dword_115EA0;
  *(uint32_t *)dword_115EA0 |= 0x111u;
  controller_init();
  *(uint32_t *)dword_115E98 &= ~0x10u;
  *v7 &= 0xFFFFFEEE;
  check_isr_handler();
  if ( !hci_cmd_send_short(0) )
    set_system_flag_2(0x2000000);
  v8 = dword_115EA4;
  si_detach();
  if ( *(uint8_t *)v8 && !*(uint8_t *)dword_115EA8 && *(uint8_t *)(v8 + 6) )
  {
    v16 = (char)(*(uint8_t *)(v8 + 5) + (*(uint8_t *)dword_115EC4 & 3));
    v17 = *(char *)(v8 + 7) + v16;
    if ( v17 >= *(char *)(v8 + 4) )
      LOBYTE(v17) = *(uint8_t *)(v8 + 4);
    write_mmio_byte(v17);
    v18 = *(uint16_t *)(v8 + 8);
    v19 = (*(volatile uint32_t *)0x40501010u);
    *(uint8_t *)(v8 + 7) = v17;
    *(uint8_t *)(v8 + 0xB) = 1;
    ke_event_lock((uint32_t *)(v8 + 12), v19 + 60000 * v18);
    ke_event_schedule_1("update %d, %d\r\n", (char)v17, v16);
  }
  *(uint8_t *)(v8 + 6) = 0;
  state_check_feature(1024, aResetDone);
  if ( mac_irq_check() )
    set_system_flag_1(0x80000);
  v9 = (uint32_t *)dword_115EB8;
  v10 = (uint32_t *)dword_115EBC;
  v11 = *(uint64_t *)(*(uint32_t *)dword_115EB0 + 8);
  *(uint32_t *)dword_115EB4 = v11;
  *v9 = HIDWORD(v11) + v11 - 4;
  *v10 = v11;
  v9[2] = v11;
  result = (uint32_t *)dword_115EC0;
  v13 = *v2;
  *(uint32_t *)(dword_115EC0 + 0x14) = v11;
  result[3] = v11;
  result[4] = HIDWORD(v11) + v11;
  if ( v13 )
  {
    v14 = v13 - 1;
    v15 = *(uint32_t *)dword_115E88;
    *v2 = v14;
    if ( !v14 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  return result;
}
