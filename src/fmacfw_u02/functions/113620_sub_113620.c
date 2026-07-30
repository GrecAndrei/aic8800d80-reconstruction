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

extern uint32_t off_11369C;
extern uint32_t off_1136A0;
extern uint32_t dword_11368C;

// sub_113620 @ 0x113620, size 106 bytes
// Doc: rf_cmd_queue_next_n1b0 [rf]: Processes next pending RF command in queue
// rf_cmd_queue_next_n1b0 [rf]: Processes next pending RF command in queue
uint32_t * sub_113620(int a1)
{
  uint32_t *result; // r0
  uint32_t *v2; // r4
  int v3; // r0
  unsigned int v4; // r0

  switch ( a1 )
  {
    case 1:
      v2 = rf_stream_start2_n2a4;
      v3 = sub_143770(rf_stream_start2_n2a4, rf_stream_start2_n2a8_3698, 18);
      if ( *((uint8_t *)off_11369C + 370) && rf_fault_dump_n100(v3) )
      {
        v4 = rf_fault_dump_n114();
        v2[2] = ((HIWORD(v4) << 16) + 0x10000) | (uint16_t)v4;
        return v2;
      }
      else if ( *(uint16_t *)off_1136A0 == 0xFFFF || *((uint16_t *)off_1136A0 + 1) == 0xFFFF )
      {
        return rf_stream_start2_n2a4;
      }
      else
      {
        result = rf_stream_start2_n2a4;
        v2[2] = *(uint32_t *)off_1136A0;
      }
      break;
    case 6:
      return (uint32_t *)rf_cmd_queue_next_n1dc;
    case 15:
      return (uint32_t *)dword_11368C;
    default:
      return 0;
  }
  return result;
}

