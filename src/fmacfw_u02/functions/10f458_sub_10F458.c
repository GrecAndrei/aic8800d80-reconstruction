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

extern uint32_t off_10F518;
extern uint32_t off_10F51C;
extern uint32_t off_10F534;
extern uint32_t dword_10F530;
extern uint32_t dword_10F524;
extern uint32_t dword_10F520;
extern uint32_t dword_10F52C;
extern uint32_t dword_10F528;
extern uint32_t off_10F538;
extern uint32_t dword_10F54C;
extern uint32_t dword_10F540;
extern uint32_t dword_10F548;
extern uint32_t dword_10F544;
extern uint32_t dword_10F53C;

// rf_wait_ready @ 0x10f458, size 192 bytes
int rf_wait_ready()
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
  int v19; // r0
  int v20; // r0
  int v21; // r0

  v0 = (uint8_t **)off_10F518;
  v1 = **(uint8_t **)off_10F518;
  switch ( v1 )
  {
    case 1:
      v8 = off_10F51C;
      v9 = off_10F534;
      *((uint32_t *)off_10F51C + 2) = dword_10F530;
      v8[3] = v9;
      break;
    case 2:
      v2 = off_10F51C;
      v3 = dword_10F524;
      *((uint32_t *)off_10F51C + 6) = dword_10F520;
      v2[7] = v3;
      break;
    case 3:
      v6 = off_10F51C;
      v7 = dword_10F52C;
      *((uint32_t *)off_10F51C + 8) = dword_10F528;
      v6[9] = v7;
      break;
  }
  tx_send_packet();
  v4 = rf_timer_init();
  v5 = **v0;
  if ( v5 == 1 )
  {
    v17 = (int ( **)(int))off_10F51C;
    *(uint32_t *)off_10F538 = dword_10F54C;
    v18 = get_link_rate(v4, HIDWORD(v4));
    v19 = get_modulation_type(v18);
    v20 = get_link_tx_power(v19);
    get_link_channel(v20);
    v21 = v17[2](dword_10F540);
    LODWORD(v4) = v17[3](v21);
    v5 = **v0;
  }
  if ( v5 == 2 )
  {
    v12 = dword_10F548;
    *(uint32_t *)off_10F538 = dword_10F544;
    v13 = (int ( **)(int))off_10F51C;
    *(uint16_t *)(v12 + 8244) = 0;
    v14 = ke_state_get_fast();
    ke_state_get(v14);
    v15 = v13[6](dword_10F540);
    v16 = v13[7](v15);
    LODWORD(v4) = store_byte_field(v16);
    v5 = **v0;
  }
  if ( v5 == 3 )
  {
    v10 = (int ( **)(int))off_10F51C;
    *(uint32_t *)off_10F538 = dword_10F53C;
    process_task_queue();
    v11 = v10[8](dword_10F540);
    LODWORD(v4) = v10[9](v11);
  }
  return v4;
}

