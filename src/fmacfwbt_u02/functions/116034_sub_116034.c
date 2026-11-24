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


extern uint32_t off_116154;
extern uint32_t off_116158;
extern uint32_t off_11615C;
extern uint32_t off_116160;
extern uint32_t off_116164;
extern uint32_t off_116168;
extern uint32_t off_11616C;
extern uint32_t off_116174;
extern uint32_t off_116178;

// rx_check_buffers @ 0x116034, size 288 bytes
void  rx_check_buffers(int a1)
{
  uint8_t **v1; // r4
  uint8_t *v2; // r1
  int v3; // r3
  uint8_t *v4; // r6
  int *v5; // r3
  uint8_t **v6; // r5
  char v7; // r0
  char v8; // r0

  v1 = (uint8_t **)off_116154;
  v2 = *(uint8_t **)off_116154;
  if ( **(uint8_t **)off_116154 )
  {
    v3 = **(uint8_t **)off_116158;
    if ( v3 != 1 )
      goto LABEL_3;
    goto LABEL_12;
  }
  v4 = off_11616C;
  v5 = *((int **)off_116168 + 2);
  *(uint8_t *)off_11616C = 1;
  if ( !v5 )
  {
LABEL_10:
    v6 = (uint8_t **)off_116158;
    if ( **(uint8_t **)off_116158 == 3 )
      goto LABEL_4;
    state_check_feature(2, "lp=%d, ignore=%d\n", *v2, 1);
    *v4 = 1;
    v3 = **v6;
    if ( v3 != 1 )
    {
LABEL_3:
      if ( v3 == 2 )
        return;
      goto LABEL_4;
    }
LABEL_12:
    if ( **v1 == 3 )
    {
      v8 = status_poll();
      *(uint8_t *)off_116178 = v8;
      if ( v8 )
        ke_event_schedule_1(aWifiidleBtAllo);
      else
        ke_event_schedule_1(aWifiidleBtNotA);
      if ( ll_util_get_state() )
        mmio_read_low_nibble();
      hw_poll_flag();
      return;
    }
    if ( !ll_util_get_state() || *(uint8_t *)off_116174 )
      return;
LABEL_4:
    if ( mm_state_run()
      && !*((uint32_t *)off_11615C + 126)
      && (*(uint32_t *)off_116160 >> 25) & 1 | *((uint8_t *)off_116164 + 36)
      && !*((uint8_t *)off_116164 + 29)
      && mac_isr_handler() )
    {
      v7 = status_poll();
      *(uint8_t *)off_116178 = v7;
      if ( !v7 )
      {
        ke_event_schedule_1(aBt1);
        hw_poll_flag();
      }
      if ( (uint8_t)**v1 <= 1u )
        mmio_read_low_nibble();
    }
    return;
  }
  while ( !*((uint8_t *)v5 + 106) )
  {
    if ( *((uint8_t *)v5 + 108) )
      goto LABEL_20;
LABEL_17:
    v5 = (int *)*v5;
    if ( !v5 )
      goto LABEL_10;
  }
  if ( *((uint8_t *)v5 + 106) != 2 )
    goto LABEL_17;
LABEL_20:
  if ( **(uint8_t **)off_116158 != 3 )
    state_check_feature(2, "lp=%d, ignore=%d\n", *v2, 0);
  *v4 = 0;
}
