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

extern uint32_t off_115E84;
extern uint32_t off_115E88;
extern uint32_t dword_115E94;
extern uint32_t off_115E8C;
extern uint32_t off_115E98;

// mac_status_check @ 0x115d28, size 346 bytes
// Doc: sub_1215D28 [unknown]: Unknown function in fmacfwbt firmware
// sub_1215D28 [unknown]: Unknown function in fmacfwbt firmware
void  mac_status_check(int a1, int a2)
{
  int v2; // r3
  int v3; // r1
  int v4; // r0
  uint32_t *v5; // r3

  v2 = **(uint16_t **)off_115E84;
  if ( (v2 & 1) != 0 )
    radio_init(a1, a2, v2 << 31);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_115E88 = 1;
  }
  v3 = dword_115E94;
  ++*(uint32_t *)off_115E8C;
  state_check_feature(1024, v3);
  v4 = set_system_flag_2(0x80000000);
  mac_config_clear(v4);
  v5 = off_115E98;
  *(uint32_t *)off_115E98 &= 0xFFFFFFu;
  *v5 |= 0x10u;
  while ( 1 )
    ;
}

