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

extern uint32_t off_113188;
extern uint32_t off_11318C;
extern uint32_t off_11319C;

// rf_stream_start2_n_144 @ 0x113108, size 126 bytes
// Doc: rf_stream_start2_n_138 [rf]: Start RF stream channel 2 by zeroing struct and invoking stream start helper
// rf_stream_start2_n_138 [rf]: Start RF stream channel 2 by zeroing struct and invoking stream start helper
int  rf_stream_start2_n_144(int a1)
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

  if ( (*(uint32_t *)off_113188 & 0x2000000) != 0 )
  {
    memset_thunk((int *)off_11318C, 0xFFu, 4u);
  }
  else
  {
    v2 = (uint16_t *)off_11318C;
    memset_thunk((int *)off_11318C, 0xFFu, 4u);
    if ( patch_apply_n_34(v2) || (v4 = v2[1], v4 == 0xFFFF) || (v3 = *v2, v3 == 0xFFFF) )
      sub_12ECB0(rf_msg_handler_n230, v3, v4);
    else
      sub_12ECB0(rf_cmd_send_n33c, v3, v4);
  }
  v5 = rf_msg_handler_n238;
  v6 = off_11319C;
  *(uint32_t *)rf_stream_start2_n_b8 = *(uint32_t *)a1;
  v7 = (uint32_t *)rf_cmd_send_n334_1a0;
  v8 = rf_stream_start2_31a4;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v9 = *(uint8_t *)(a1 + 8);
    if ( *(uint8_t *)(a1 + 8) )
      v9 = 1;
    inited = mmio_init_block_clear(v7, v9);
    sub_12ECB0(v8, inited, v11);
  }
  while ( inited );
  return 0;
}

