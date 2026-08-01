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

extern uint32_t off_11427C;
extern uint32_t off_114280;
extern uint32_t dword_114284;

// process_task_queue @ 0x114234, size 72 bytes
// Doc: rf_fault_dump_n_500 [rf]: Dump RF fault information
// rf_fault_dump_n_500 [rf]: Dump RF fault information
int process_task_queue()
{
  uint32_t *v0; // r5
  void *v1; // r7
  int result; // r0
  int v3; // r6
  int v4; // r4

  v0 = off_11427C;
  v1 = off_114280;
  zero_8_bytes(*(uint32_t *)off_11427C + 628);
  result = zero_8_bytes(*v0 + 636);
  if ( *(uint16_t *)(*(uint32_t *)v1 + 8) )
  {
    v3 = dword_114284;
    v4 = 0;
    do
    {
      rx_packet_handler(v3, 0x6B8u);
      result = cmd_handler_a(*v0 + 628);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v1 + 8) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}

