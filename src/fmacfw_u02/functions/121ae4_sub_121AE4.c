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


extern uint32_t off_121BCC;
extern uint32_t off_121BD4;
extern uint32_t off_121BD8;
extern uint32_t off_121BE0;
extern uint32_t off_121BE4;
extern uint32_t off_121BE8;
extern uint32_t off_121BEC;
extern uint32_t off_121BF0;
extern uint32_t off_121BF4;
extern uint32_t off_121C04;

// shared_s16_worker @ 0x121ae4, size 230 bytes
int shared_s16_worker()
{
  int *v0; // r8
  int *v1; // r4
  int v2; // r3
  volatile unsigned int v3; // r7
  int v4; // r9
  unsigned int v5; // r3
  uint32_t *v6; // r0
  uint32_t *v7; // r1
  int v8; // r4
  int v9; // r3
  int result; // r0
  int v11; // r3
  int v12; // r3
  int v13; // r2

  if ( **(uint16_t **)off_121BCC < 0 && rx_rate_field_parse(0) == 4 )
    mmio_clear_register((int)aKeStateGetTask, (int)aMmForceIdleReq, 1799);
  check_status_bits(4, "force idle\r\n");
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_121BD4 = 1;
  }
  v0 = (int *)off_121C04;
  v1 = (int *)off_121BD8;
  ++*(uint32_t *)off_121C04;
  v2 = *v1;
  *v1 = 0;
  v3 = (*(volatile uint32_t *)0x40501010u);
  v4 = v2 & 0xF;
  while ( *v1 << 28 )
  {
    chip_status_read();
    v5 = (*(volatile uint32_t *)0x40501010u) - v3;
    if ( v5 > 0x7530 )
      check_status_bits(4, aIdleErr);
  }
  v6 = off_121BE4;
  v7 = off_121BE8;
  v8 = *(uint32_t *)off_121BE4;
  *((uint32_t *)off_121BE0 + 1) &= ~4u;
  if ( v4 && (*v7 & v8 & 4) == 0 )
  {
    while ( (*v7 & *v6 & 4) == 0 )
      ;
  }
  v9 = *((uint8_t *)off_121BEC + 90);
  *(uint32_t *)off_121BF0 = 4;
  if ( v9 )
    func_117a24();
  result = rx_phy_status_parse(0, 3);
  v11 = *v0;
  *((uint16_t *)off_121BF4 + 9) = 0;
  if ( v11 )
  {
    v12 = v11 - 1;
    v13 = *(uint32_t *)off_121BD4;
    *v0 = v12;
    if ( !v12 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  return result;
}
