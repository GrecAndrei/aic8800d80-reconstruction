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


extern uint32_t dword_1151F4;
extern uint32_t dword_1151F8;
extern uint32_t dword_1151FC;
extern uint32_t dword_115208;
extern uint32_t dword_115210;
extern uint32_t dword_115214;
extern uint32_t dword_115218;
extern uint32_t dword_115220;
extern uint32_t dword_115224;

// mmio_wait_flag @ 0x1150a8, size 330 bytes
int  mmio_wait_flag(int a1, int a2)
{
  uint32_t *v2; // r4
  uint32_t *v3; // r3
  volatile unsigned int v4; // r1
  unsigned int v5; // r1
  int v6; // r3
  uint32_t *v7; // r5
  unsigned int v8; // r5
  int result; // r0
  int v10; // r3
  int v11; // r2
  int v12; // r7
  int v13; // r6
  int v14; // r2
  volatile unsigned int v15; // r3

  if ( (**(uint16_t **)dword_1151F4 & 1) != 0 )
    rf_init_phy();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)dword_1151F8 = 1;
  }
  v2 = (uint32_t *)dword_1151FC;
  ++*(uint32_t *)dword_1151FC;
  check_interrupt_flag(1024, "%s\r\n", aRwnxlResetEvt);
  enter_critical_section_1(0x80000000);
  rf_cmd_wait();
  v3 = (uint32_t *)dword_115208;
  *(uint32_t *)dword_115208 &= 0xFFFFFFu;
  *v3 |= 0x10u;
  v4 = (*(volatile uint32_t *)0x40501010u);
  v5 = v4 + 100;
  do
    v6 = v5 - (*(volatile uint32_t *)0x40501010u);
  while ( v6 >= 0 );
  v7 = (uint32_t *)dword_115210;
  *(uint32_t *)dword_115210 |= 0x111u;
  rf_acquire();
  *(uint32_t *)dword_115208 &= ~0x10u;
  *v7 &= 0xFFFFFEEE;
  chip_id_is_one();
  if ( !flash_write_byte(0) )
    enter_critical_section_1(0x2000000);
  v8 = dword_115214;
  find_link_in_list();
  if ( *(uint8_t *)v8 && !*(uint8_t *)dword_115218 && *(uint8_t *)(v8 + 6) )
  {
    v12 = (char)(*(uint8_t *)(v8 + 5) + (*(uint8_t *)dword_115224 & 3));
    v13 = *(char *)(v8 + 7) + v12;
    if ( v13 >= *(char *)(v8 + 4) )
      LOBYTE(v13) = *(uint8_t *)(v8 + 4);
    gpio_config(v13);
    v14 = *(uint16_t *)(v8 + 8);
    v15 = (*(volatile uint32_t *)0x40501010u);
    *(uint8_t *)(v8 + 7) = v13;
    *(uint8_t *)(v8 + 0xB) = 1;
    ke_enter_critical((uint32_t *)(v8 + 12), v15 + 60000 * v14);
    dispatch_event_handler_1("update %d, %d\r\n", (char)v13, v12);
  }
  *(uint8_t *)(v8 + 6) = 0;
  check_interrupt_flag(1024, aResetDone);
  if ( *(uint32_t *)dword_115220 )
    set_busy_flag_alt(0x2000);
  result = timer_event_check();
  if ( result )
    result = set_busy_flag_alt(0x400000);
  if ( *v2 )
  {
    v10 = *v2 - 1;
    v11 = *(uint32_t *)dword_1151F8;
    *v2 = v10;
    if ( !v10 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}
