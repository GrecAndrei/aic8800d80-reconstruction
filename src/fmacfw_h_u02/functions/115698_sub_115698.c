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

extern uint32_t off_1157F4;
extern uint32_t off_1157F8;
extern uint32_t dword_115804;
extern uint32_t off_1157FC;
extern uint32_t off_115808;

// rx_packet_pending @ 0x115698, size 346 bytes
void  rx_packet_pending(int a1, int a2)
{
  int v2; // r3
  int v3; // r1
  int v4; // r0
  uint32_t *v5; // r3

  v2 = **(uint16_t **)off_1157F4;
  if ( (v2 & 1) != 0 )
    ((void ( *)(int, int, int))loc_12F054)(a1, a2, v2 << 31);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1157F8 = 1;
  }
  v3 = dword_115804;
  ++*(uint32_t *)off_1157FC;
  check_feature_flag(1024, v3);
  v4 = irq_disable_global_3(0x80000000);
  rf_radio_calibrate(v4);
  v5 = off_115808;
  *(uint32_t *)off_115808 &= 0xFFFFFFu;
  *v5 |= 0x10u;
  while ( 1 )
    ;
}

