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
extern uint32_t dword_124B70;

// check_flag_bit @ 0x124ad4, size 140 bytes
int  check_flag_bit(uint8_t *a1, void *a2)
{
  int v2; // r3
  unsigned int v3; // r2

  v2 = *a1;
  v3 = v2 << 28;
  if ( v2 << 28 )
  {
    v3 = (unsigned int)off_124B60;
    a2 = (void *)(v2 & 1);
    *(uint8_t *)off_124B60 = v2 & 1;
  }
  if ( (v2 & 0xF0) != 0 )
  {
    v3 = (unsigned int)off_124B64;
    *((uint8_t *)off_124B64 + 408) = v2 & 0x10;
  }
  if ( a1[1] )
  {
    a2 = off_124B68;
    v3 = *(uint32_t *)off_124B68 & 0xFFFFFF00;
    *(uint32_t *)off_124B68 = a1[1] | v3;
  }
  if ( a1[2] )
  {
    a2 = off_124B6C;
    v3 = *(uint32_t *)off_124B6C & 0xFFFFFF00;
    *(uint32_t *)off_124B6C = a1[2] | v3;
  }
  if ( a1[3] )
  {
    a2 = off_124B68;
    v3 = *(uint32_t *)off_124B68 & 0xFFF00FFF;
    *(uint32_t *)off_124B68 = v3 | (a1[3] << 12);
  }
  if ( a1[4] )
  {
    a2 = off_124B6C;
    v3 = *(uint32_t *)off_124B6C & 0xFFF00FFF;
    *(uint32_t *)off_124B6C = v3 | (a1[4] << 12);
  }
  alloc_tx_event(dword_124B70, a2, v3);
  return process_packet_params(a1, 5, 1, 0);
}

