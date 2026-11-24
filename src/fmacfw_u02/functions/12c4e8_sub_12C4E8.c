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


extern uint32_t off_12C528;
extern uint32_t off_12C52C;
extern uint32_t off_12C534;

// rf_check_temperature @ 0x12c4e8, size 64 bytes
void  rf_check_temperature(int a1, int a2)
{
  int v2; // r4
  int v3; // r0

  if ( BYTE1(((uint32_t *)(uintptr_t)off_12C528)[49]) )
  {
    v2 = *(uint32_t *)(*(uint32_t *)(a2 + 76) + 48);
    v3 = rx_packet_handler(
           (*(uint32_t *)(v2 + 20) >> 11) & 7,
           *(uint32_t *)(v2 + 20) & 0x7F,
           (uint8_t *)(*(uint32_t *)(a1 + 72) + 4));
    *(uint32_t *)(v2 + 36) = v3 | (v3 << 8);
  }
  else if ( **(uint16_t **)off_12C52C < 0 )
  {
    mmio_clear_register(off_12C534, (int)aTpcUpdateFrame, 92);
  }
}
