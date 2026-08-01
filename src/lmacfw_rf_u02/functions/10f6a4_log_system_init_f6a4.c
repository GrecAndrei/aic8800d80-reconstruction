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

extern uint32_t off_10F764;
extern uint32_t off_10F768;
extern uint32_t off_10F780;
extern uint32_t off_10F77C;
extern uint32_t dword_10F770;
extern uint32_t dword_10F76C;
extern uint32_t dword_10F778;
extern uint32_t dword_10F774;
extern uint32_t off_10F784;
extern uint32_t dword_10F798;
extern uint32_t dword_10F78C;
extern uint32_t dword_10F794;
extern uint32_t dword_10F790;
extern uint32_t dword_10F788;

// bt_state_dispatch @ 0x10f6a4, size 192 bytes
// Doc: bt_state_dispatch [util]: Initialize firmware logging subsystem
// bt_state_dispatch [util]: Initialize firmware logging subsystem
int bt_state_dispatch()
{
  uint8_t **v0; // r4
  int v1; // r3
  uint32_t *v2; // r3
  int v3; // r2
  uint64_t v4; // r0
  int v5; // r3
  uint32_t *v6; // r3
  int v7; // r2
  uint32_t *v8; // r3
  void *v9; // r2
  int ( **v10)(int); // r4
  int v11; // r0
  int v12; // r2
  int ( **v13)(int); // r5
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int ( **v17)(int); // r5
  int v18; // r0
  int inited; // r0
  int v20; // r0
  int v21; // r0

  v0 = (uint8_t **)off_10F764;
  v1 = **(uint8_t **)off_10F764;
  switch ( v1 )
  {
    case 1:
      v8 = off_10F768;
      v9 = off_10F780;
      *((uint32_t *)off_10F768 + 2) = off_10F77C;
      v8[3] = v9;
      break;
    case 2:
      v2 = off_10F768;
      v3 = dword_10F770;
      *((uint32_t *)off_10F768 + 6) = dword_10F76C;
      v2[7] = v3;
      break;
    case 3:
      v6 = off_10F768;
      v7 = dword_10F778;
      *((uint32_t *)off_10F768 + 8) = dword_10F774;
      v6[9] = v7;
      break;
  }
  bt_msg_init();
  v4 = mmio_write16();
  v5 = **v0;
  if ( v5 == 1 )
  {
    v17 = (int ( **)(int))off_10F768;
    *(uint32_t *)off_10F784 = dword_10F798;
    v18 = rx_packet_event(v4, HIDWORD(v4));
    inited = rf_lmac_init_n114(v18);
    v20 = rx_adv_event(inited);
    rx_channel_event(v20);
    v21 = v17[2](dword_10F78C);
    LODWORD(v4) = v17[3](v21);
    v5 = **v0;
  }
  if ( v5 == 2 )
  {
    v12 = dword_10F794;
    *(uint32_t *)off_10F784 = dword_10F790;
    v13 = (int ( **)(int))off_10F768;
    *(uint16_t *)(v12 + 8244) = 0;
    v14 = tx_event_handler();
    timer_event_handler(v14);
    v15 = v13[6](dword_10F78C);
    v16 = v13[7](v15);
    LODWORD(v4) = prepare_and_dispatch(v16);
    v5 = **v0;
  }
  if ( v5 == 3 )
  {
    v10 = (int ( **)(int))off_10F768;
    *(uint32_t *)off_10F784 = dword_10F788;
    controller_state_machine();
    v11 = v10[8](dword_10F78C);
    LODWORD(v4) = v10[9](v11);
  }
  return v4;
}

