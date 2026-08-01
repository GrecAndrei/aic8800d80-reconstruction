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

extern uint32_t off_12C434;
extern uint32_t off_12C438;
extern uint32_t dword_12C440;
extern uint32_t dword_12C43C;

// get_alt_status_flag_c5 @ 0x12c3f8, size 60 bytes
void  get_alt_status_flag_c5(int a1, int a2, uint8_t *a3)
{
  int v3; // r4
  int v4; // r0

  if ( *((uint8_t *)off_12C434 + 197) )
  {
    v3 = *(uint32_t *)(*(uint32_t *)(a2 + 76) + 48);
    v4 = bt_packet_parser((*(uint32_t *)(v3 + 20) >> 11) & 7, *(uint32_t *)(v3 + 20) & 0x7F, a3);
    *(uint32_t *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(int16_t **)off_12C438 < 0 )
  {
    irq_disable_mmio_write(dword_12C440, dword_12C43C, 109);
  }
}

