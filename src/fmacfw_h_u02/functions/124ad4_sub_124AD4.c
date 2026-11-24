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


extern uint32_t off_124B60;
extern uint32_t off_124B64;
extern uint32_t off_124B68;
extern uint32_t off_124B6C;

// check_flag_bit @ 0x124ad4, size 140 bytes
int  check_flag_bit(uint8_t *a1)
{
  int v1; // r3

  v1 = *a1;
  if ( v1 << 28 )
    *(uint8_t *)off_124B60 = v1 & 1;
  if ( (v1 & 0xF0) != 0 )
    LOBYTE(((uint32_t *)(uintptr_t)off_124B64)[102]) = v1 & 0x10;
  if ( a1[1] )
    *(uint32_t *)off_124B68 = a1[1] | *(uint32_t *)off_124B68 & 0xFFFFFF00;
  if ( a1[2] )
    *(uint32_t *)off_124B6C = a1[2] | *(uint32_t *)off_124B6C & 0xFFFFFF00;
  if ( a1[3] )
    *(uint32_t *)off_124B68 = *(uint32_t *)off_124B68 & 0xFFF00FFF | (a1[3] << 12);
  if ( a1[4] )
    *(uint32_t *)off_124B6C = *(uint32_t *)off_124B6C & 0xFFF00FFF | (a1[4] << 12);
  alloc_tx_event(aSetVendorCca);
  return process_packet_params((int)a1, 5, 1, 0);
}
