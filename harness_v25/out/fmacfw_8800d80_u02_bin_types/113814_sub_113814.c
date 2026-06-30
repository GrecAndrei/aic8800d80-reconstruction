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

extern uint32_t off_113890;
extern uint32_t dword_113894;
extern uint32_t off_1138A4;
extern uint32_t off_113898;
extern uint32_t dword_1138A8;
extern uint32_t dword_11389C;

// sub_113814 @ 0x113814, size 124 bytes
// Doc: rf_stream_start_n4c8 [rf]: Starts RF stream by enabling engine and reading control structure
// rf_stream_start_n4c8 [rf]: Starts RF stream by enabling engine and reading control structure
int sub_113814()
{
  void *v0; // r7
  int result; // r0
  uint16_t *v2; // r9
  uint16_t *v3; // r6
  int v4; // r8
  int v5; // r11
  int16_t **v6; // r10
  uint16_t v7; // r5
  unsigned int v8; // r1
  int v9; // r2

  v0 = off_113890;
  result = sub_12D240(dword_113894);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
  {
    v2 = off_1138A4;
    v3 = off_113898;
    v4 = dword_1138A8;
    v5 = rf_stream_start2_n4bc_38ac;
    v6 = (int16_t **)rf_cmd_queue_next_38b0;
    v7 = 0;
    do
    {
      if ( !sub_10FB28(v4, (uint16_t)(v2[153] - 4)) )
      {
        msg_parse(v5, v7, v9);
        if ( **v6 < 0 )
          sub_12F46C(rf_msg_process_body_n_3a8, dword_11389C, 495);
      }
      result = list_push_tail(dword_113894);
      v8 = *(uint16_t *)(*(uint32_t *)v0 + 8);
      ++v7;
      ++*v3;
    }
    while ( v8 > v7 );
  }
  return result;
}

