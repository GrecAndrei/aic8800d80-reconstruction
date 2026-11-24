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


extern uint32_t off_115098;
extern uint32_t off_11509C;
extern uint32_t off_1150A0;
extern uint32_t off_1150A4;

// bt_driver_init @ 0x115018, size 116 bytes
void  bt_driver_init()
{
  int *v0; // r4
  int v1; // r3
  uint8_t *v2; // r5

  v0 = (int *)off_115098;
  dispatch_event_handler_1("\x9A%s - build: %s\n", aV6911, aLaJul032024153);
  if ( *(uint32_t *)off_11509C )
  {
    mmio_set_reg_0x70001408();
    if ( *(uint16_t *)(*v0 + 8) )
      pmu_write_clock_ctrl(*(uint16_t *)(*v0 + 8));
  }
  if ( **(uint8_t **)off_1150A0 == 2 )
  {
    v1 = *v0;
    *(uint8_t *)(v1 + 6) = 2;
    *(uint8_t *)(v1 + 3) = 1;
  }
  bt_module_init(*(uint16_t *)(*v0 + 4));
  if ( !*(uint8_t *)(*v0 + 3) )
    clear_irq_flag();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v2 = off_1150A4;
  while ( 1 )
  {
    if ( *(uint8_t *)(*v0 + 3) )
      memory_barrier_write();
    if ( !*v2 )
      process_event_queue();
    exit_critical_section();
  }
}
