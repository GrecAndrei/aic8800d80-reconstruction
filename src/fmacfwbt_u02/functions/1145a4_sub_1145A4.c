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


extern uint32_t dword_11467C;
extern uint32_t dword_114684;
extern uint32_t dword_114694;
extern uint32_t off_114664;
extern uint32_t off_114668;
extern uint32_t off_11466C;

// phy_calibrate_1 @ 0x1145a4, size 190 bytes
void  phy_calibrate_1()
{
  unsigned int v0; // r5
  int v1; // r4
  int v2; // lr
  unsigned int CPSR; // r1
  unsigned int v4; // r2
  unsigned int v5; // r5
  unsigned int v6; // r4
  unsigned int v7; // r4
  unsigned int v8; // r5
  int v9; // r1

  v0 = off_114664;
  v1 = *(uint32_t *)(*(uint32_t *)off_114664 + 16);
  ke_event_schedule_1("\nINT:%x,%x,%x", v1, *(uint32_t *)off_11466C, *(uint32_t *)off_114668);
  if ( (v1 & 1) != 0 )
    *(uint32_t *)(*(uint32_t *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  v4 = __get_CPSR();
  v5 = __get_CPSR();
  v6 = __get_CPSR();
  ke_event_schedule_1(aControl08xXpsr_0, CPSR, v4, v5, v6, __get_CPSR(), v2);
  if ( v5 )
  {
    ke_event_schedule_1(aWrongPsp);
    if ( !v6 )
      goto LABEL_5;
  }
  else if ( !v6 )
  {
    goto LABEL_5;
  }
  v7 = v6 & 0xFFFFFFF0;
  v8 = (dword_114694 - v7) >> 2;
  ke_event_schedule_1(aDumpmsp_0);
  v9 = v8;
  if ( v8 >= 0x100 )
    v9 = 256;
  rx_packet_handler_2(v7, v9, 4, 0);
LABEL_5:
  ke_event_schedule_1(aIser);
  rx_packet_handler_2(dword_11467C, 8, 4, 0);
  ke_event_schedule_1(aIspr);
  rx_packet_handler_2(dword_114684, 8, 4, 0);
  ke_event_schedule_1(aTim2);
  rx_packet_handler_2((int)REG_4050_1000, 16, 4, 0);
  check_op_mode();
}
