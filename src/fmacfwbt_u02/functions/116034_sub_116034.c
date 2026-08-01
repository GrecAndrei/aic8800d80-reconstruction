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
extern uint32_t off_11616C;
extern uint32_t off_116168;
extern uint32_t dword_116170;
extern uint32_t off_116178;
extern uint32_t dword_116184;
extern uint32_t dword_11617C;
extern uint32_t off_116174;
extern uint32_t off_11615C;
extern uint32_t off_116160;
extern uint32_t off_116164;
extern uint32_t dword_116180;

// rx_check_buffers @ 0x116034, size 288 bytes
// Doc: sub_1216034 [util]: Loads pointer from 0x182c60 and reads its first byte
// sub_1216034 [util]: Loads pointer from 0x182c60 and reads its first byte
void rx_check_buffers()
{
  uint8_t **v0; // r4
  int v1; // r3
  uint8_t *v2; // r6
  int *v3; // r3
  uint8_t **v4; // r5
  char v5; // r0
  int v6; // r1
  void *v7; // r2
  char v8; // r0
  int v9; // r1
  void *v10; // r2
  int v11; // r0

  v0 = (uint8_t **)off_116154;
  if ( **(uint8_t **)off_116154 )
  {
    v1 = **(uint8_t **)off_116158;
    if ( v1 != 1 )
      goto LABEL_3;
    goto LABEL_12;
  }
  v2 = off_11616C;
  v3 = *((int **)off_116168 + 2);
  *(uint8_t *)off_11616C = 1;
  if ( !v3 )
  {
LABEL_10:
    v4 = (uint8_t **)off_116158;
    if ( **(uint8_t **)off_116158 == 3 )
      goto LABEL_4;
    state_check_feature(2, dword_116170);
    *v2 = 1;
    v1 = **v4;
    if ( v1 != 1 )
    {
LABEL_3:
      if ( v1 == 2 )
        return;
      goto LABEL_4;
    }
LABEL_12:
    if ( **v0 == 3 )
    {
      v8 = status_poll();
      v10 = off_116178;
      *(uint8_t *)off_116178 = v8;
      if ( v8 )
        ke_event_schedule(dword_116184, v9, v10);
      else
        ke_event_schedule(dword_11617C, v9, v10);
      if ( ll_util_get_state() )
        mmio_read_low_nibble();
      ((void (*)(void))hw_poll_flag)();
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
      v5 = status_poll();
      v7 = off_116178;
      *(uint8_t *)off_116178 = v5;
      if ( !v5 )
      {
        v11 = ke_event_schedule(dword_116180, v6, v7);
        hw_poll_flag(v11);
      }
      if ( (uint8_t)**v0 <= 1u )
        mmio_read_low_nibble();
    }
    return;
  }
  while ( !*((uint8_t *)v3 + 106) )
  {
    if ( *((uint8_t *)v3 + 108) )
      goto LABEL_20;
LABEL_17:
    v3 = (int *)*v3;
    if ( !v3 )
      goto LABEL_10;
  }
  if ( *((uint8_t *)v3 + 106) != 2 )
    goto LABEL_17;
LABEL_20:
  if ( **(uint8_t **)off_116158 != 3 )
    state_check_feature(2, dword_116170);
  *v2 = 0;
}

