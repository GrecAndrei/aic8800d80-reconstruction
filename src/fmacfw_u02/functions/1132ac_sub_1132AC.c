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

extern uint32_t off_11332C;
extern uint32_t off_113330;
extern uint32_t dword_113348;

// irq_state_load @ 0x1132ac, size 126 bytes
// Doc: rf_stream_start2_3306 [rf]: Start secondary RF stream via IPC and mailbox
// rf_stream_start2_3306 [rf]: Start secondary RF stream via IPC and mailbox
int  irq_state_load(int a1)
{
  uint16_t *v2; // r4
  int v3; // r1
  int v4; // r2
  uint8_t *v5; // r1
  uint8_t *v6; // r2
  uint32_t *v7; // r7
  int v8; // r6
  int v9; // r1
  int inited; // r4
  int v11; // r2

  if ( (*(uint32_t *)off_11332C & 0x2000000) != 0 )
  {
    memset((int *)off_113330, 0xFFu, 4u);
  }
  else
  {
    v2 = (uint16_t *)off_113330;
    memset((int *)off_113330, 0xFFu, 4u);
    if ( patch_get_field(v2) || (v4 = v2[1], v4 == 0xFFFF) || (v3 = *v2, v3 == 0xFFFF) )
      event_dispatch(rf_cmd_send_3334, v3, v4);
    else
      event_dispatch(rf_msg_handler_n248, v3, v4);
  }
  v5 = rf_stream_start2_33c;
  v6 = rf_cmd_process_n_218;
  *(uint32_t *)rf_cmd_send_n328 = *(uint32_t *)a1;
  v7 = (uint32_t *)rf_stream_start2_n_ac;
  v8 = dword_113348;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v9 = *(uint8_t *)(a1 + 8);
    if ( *(uint8_t *)(a1 + 8) )
      v9 = 1;
    inited = cmd_dispatch(v7, v9);
    event_dispatch(v8, inited, v11);
  }
  while ( inited );
  return 0;
}

