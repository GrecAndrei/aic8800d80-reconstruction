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


extern uint32_t off_12C574;
extern uint32_t off_12C578;
extern uint32_t off_12C580;

// rf_check_battery @ 0x12c538, size 60 bytes
void  rf_check_battery(int a1, int a2)
{
  uint8_t *v2; // r2
  int v3; // r4
  int v4; // r0

  if ( BYTE1(((uint32_t *)(uintptr_t)off_12C574)[49]) )
  {
    v3 = *(uint32_t *)(*(uint32_t *)(a2 + 76) + 48);
    v4 = rx_packet_handler((*(uint32_t *)(v3 + 20) >> 11) & 7, *(uint32_t *)(v3 + 20) & 0x7F, v2);
    *(uint32_t *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(uint16_t **)off_12C578 < 0 )
  {
    mmio_clear_register(off_12C580, (int)aTpcUpdateFrame_0, 109);
  }
}
